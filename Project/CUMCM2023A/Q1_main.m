clear;clc;close all;
% 镜面数据输入
Mirror_pos=readmatrix("附件.xlsx");
Mirror_pos=[Mirror_pos,zeros(length(Mirror_pos),1)];
% scatter(Mirror_pos(:,1),Mirror_pos(:,2))
% xlabel('x轴')
% ylabel('y轴')
% axis square
% grid on
%% 信息输入
% 月标准日
month_day=[(1:12)',ones(12,1)*21];
% 春分
D0_day=[3 21];
% 当地经度
longitude=deg2rad(98.5);
% 当地纬度
phi=deg2rad(39.4);
% 当地海拔(km)
altitude=3;
% 日采样点
ST=[9 10.5 12 13.5 15];

% 镜场最大半径
Rmax=350;
% 镜场最小半径
Rmin=100;

% 定日镜尺寸宽度
width_size=6;
% 定日镜尺寸高度
height_size=6;
% 定日镜安装高度
height_install=4;
% 镜面反射率
eta_ref=0.92;

% 吸收塔高度
height_tower=80;
% 吸收塔集热器高度
height_collector=8;
% 吸收塔直径
diameter=7;

% 网格一维采样量
net_num=10;
% 太阳常数
G0=1.366;

% 光锥生成光线总量
Num_light=20;
% 光锥的半角展宽
sigma=9.3e-3;
% 光锥角幅度
tau=2*pi;


%% 太阳光线向量参数计算
function result = date_sum(day)
% 该函数计算该日期为该年的第几天
days=0;
days_of_month=[31 28 31 30 31 30 31 31 30 31 30 31]'; % 每月的天数
for i = 1:day(1)
    if i<day(1)
       days=days+days_of_month(i);
    else
       days=days+day(2);
    end
end
result =days;
end

% 计算出与春分的相差时间
D0=date_sum(D0_day);
for i = 1:length(month_day)
    D(i)=date_sum(month_day(i,:))-D0;
    if D(i)<0
        D(i)=D(i)+365;
    end
end

D=D';
% 太阳赤纬角
delta=asin(sin(2*pi*D/365)*sin(2*pi*23.45/360));
% 太阳时角
omiga=pi/12*(ST-12); 
% 太阳高度角
alpha_s=asin(cos(delta).*cos(phi).*cos(omiga)+sin(delta).*sin(phi)); % m为日期，n为日采样点
% 太阳方位角
gamma_s=real(acos(((sin(delta)-sin(alpha_s).*sin(phi))./(cos(alpha_s).*cos(phi)))));% m为日期，n为日采样点

%% 镜面折射向量/汇集光线向量计算
focos_pos=[0,0,height_tower+0.5*height_collector];
Mirror_center_pos=Mirror_pos+[0,0,height_install];
% 镜面反射向量
vector_reflection=focos_pos-Mirror_center_pos;
% 计算镜面中心到集热器中心的距离
for i=1:length(vector_reflection)
    d_HR(i,1)=norm(vector_reflection(i,:));
end
% 单位化镜面反射向量
vector_unit_reflection=vector_reflection./d_HR;
% 大气透射率计算
eta_at=(0.99321 - 0.0001176*d_HR + 1.97*10^-8 *d_HR).*(d_HR<=1000);

%% 计算光能效率

% 时均平均余弦效率内存分配
eta_cos_timemean=zeros(1,length(ST));
% 时均阴影遮挡效率内存分配
eta_sb_timemean=zeros(1,length(ST));
% 时均截断效率内存分配
eta_trunc_timemean=zeros(1,length(ST));
% 时均光学效率内存分配
eta_timemean=zeros(1,length(ST));
% 阴影判断预分配内存
shadow_judge=zeros(1,length(Mirror_center_pos));
% 热功率内存分配
E_field=zeros(length(gamma_s),length(ST));


for i =1:length(gamma_s) % 指定月
    % 计算以北为x轴，东为y轴的坐标系下太阳的光线向量
   vector_sunlight=[
       -cos(alpha_s(i,:)).*cos(gamma_s(i,:));
       -cos(alpha_s(i,:)).*sin(gamma_s(i,:));
       -sin(alpha_s(i,:))
       ]; %规律：光线呈现出对称性

   T=zeros(3,length(Mirror_pos)*3);
  for j=1:length(ST) % 指定时间
   % 镜面法向量
   vector_specular_normal=-vector_sunlight(:,j)'+vector_unit_reflection;
   % 计算最大阴影搜索范围
   d_max_shadow=height_size./2./sin(alpha_s(i,:))+height_install./tan(alpha_s(i,:));
   % 对镜面法向量单位化并且计算反射向量对地面的夹角
   angle_reflection=zeros(length(vector_specular_normal),1); %预分配内存
   for k=1:length(vector_specular_normal)
       vector_specular_normal(k,:)=vector_specular_normal(k,:)/norm(vector_specular_normal(k,:));
       angle_reflection(k,1)=asin(vector_unit_reflection(k,:)*[0,0,1]');
   end
   % 计算最大遮挡搜索范围
  d_max_occlusion=height_size./2*(1./tan(angle_reflection)+1./sin(angle_reflection));

   % 余弦效率
   eta_cos=-vector_specular_normal*vector_sunlight(:,j);
   % 时均平均余弦效率
   eta_cos_timemean(j)=mean(eta_cos);
   % 阴影遮挡效率 预分配内存
   eta_sb=zeros(1,length(Mirror_center_pos));
  % 光锥坐标系到地面坐标系的矩阵转换关系式
   T_light=[
       sin(gamma_s(i,j)),-sin(alpha_s(i,j))*cos(gamma_s(i,j)),cos(alpha_s(i,j))*cos(gamma_s(i,j));
       -cos(gamma_s(i,j)),-sin(alpha_s(i,j))*sin(gamma_s(i,j)),cos(alpha_s(i,j))*sin(gamma_s(i,j));
       0,cos(alpha_s(i,j)),sin(alpha_s(i,j))];

   eta_trunc=zeros(1,length(Mirror_center_pos)); % 分配内存
   
   % DNI计算
   a=0.4237 - 0.00821*(6 -altitude)^2;
   b = 0.5055 + 0.00595*(6.5 - altitude)^2;
   c = 0.2711 + 0.01858*(2.5 - altitude)^2;
   DNI=G0*(a+b*exp(-c/sin(alpha_s(i,j))));
   % % 变换矩阵
   for k=1:length(Mirror_center_pos)
    z_recent=vector_specular_normal(k,:);
    AH_recent=asin(z_recent(3));
    EH_recent=asin(z_recent(2)/cos(AH_recent));
    T_recent=[ 
    -sin(EH_recent),-sin(AH_recent)*cos(EH_recent),cos(AH_recent)*cos(EH_recent);
    cos(EH_recent),-sin(AH_recent)*sin(EH_recent),cos(AH_recent)*sin(EH_recent);
    0,cos(AH_recent),sin(AH_recent)
    ];
    T(1:3,3*k-2:3*k)=T_recent;
   end
   % 塔阴影遮挡率
   d_max_tower_shadow=(height_collector+height_tower)/tan(alpha_s(i,j));
   eta_sb_tower=1-d_max_tower_shadow*diameter/(pi*(Rmax^2-Rmin^2));
   
   for k=1:length(Mirror_center_pos) % 指定定日镜
      
       recent_pos=Mirror_center_pos(k,:);
       % 定日镜网格采样
       net_position_x=linspace(-width_size/2,width_size/2,net_num);
       net_position_y=linspace(-height_size/2,height_size/2,net_num);
       % 定日镜网格中心采样
       net_position_x=(net_position_x(1:end-1)+net_position_x(2:end))/2;
       net_position_y=(net_position_y(1:end-1)+net_position_y(2:end))/2;
       % 有效光点记录
       net_effective_light=ones(net_num-1,net_num-1);

        % 现位置变换矩阵
        T_recent=T(3,3*k-2:3*k);
        % 截断吸收数
        Num_trunc=0;
        Num_all=0;

       % 阴影遮挡定日镜判断
       
       % 可能造成阴影的定日镜坐标获取
       shadow_judge=sqrt(sum((recent_pos-Mirror_center_pos).^2,2))<=d_max_shadow(j) ...
            & ((recent_pos-Mirror_center_pos))*vector_sunlight(:,j)<0;
       % && norm(cross(recent_pos-Mirror_center_pos(l,:),vector_sunlight(:,j)'.*[1,1,0]))/norm(vector_sunlight(:,j)'.*[1,1,0])<width_size;
       
       code_specular=find(shadow_judge);
       % 对判断后的定日镜进行阴影分析
 for m=1:length(code_specular)
           aim_pos=Mirror_center_pos(code_specular(m),:);
           T_aim=T(1:3,3*m-2:3*m);
           for x_num=1:net_num-1
               for y_num=1:net_num-1
                   %坐标存储
                   x=net_position_x(x_num);
                   y=net_position_y(y_num);
                   % 目标位置变换矩阵
                   P_recent=[x;y;0];

                   P_abs=T_recent*P_recent+recent_pos';
                   P_aim=T_aim'*(P_abs-aim_pos');
                   vector_aim_sunlight=T_aim'*vector_sunlight(:,j);
                   vector_ref_aim_sunlight=T_aim'*vector_unit_reflection(k,:)';
                   area_light_aim=[
                       (vector_aim_sunlight(3)*P_aim(1)-vector_aim_sunlight(1)*P_aim(3))/vector_aim_sunlight(3);
                       (vector_aim_sunlight(3)*P_aim(2)-vector_aim_sunlight(2)*P_aim(3))/vector_aim_sunlight(3);
                       ];
                   area_ref_light_aim=[
                       (vector_ref_aim_sunlight(3)*P_aim(1)-vector_ref_aim_sunlight(1)*P_aim(3))/vector_ref_aim_sunlight(3);
                       (vector_ref_aim_sunlight(3)*P_aim(2)-vector_ref_aim_sunlight(2)*P_aim(3))/vector_ref_aim_sunlight(3);
                       ];
                   if abs(area_light_aim(1))<=width_size/2 && abs(area_light_aim(2))<=height_size/2 ...
                           || abs(area_ref_light_aim(1))<=width_size/2 && abs(area_ref_light_aim(2))<=height_size/2
                       net_effective_light(x_num,y_num)=0;
                   end

               end
           end


       end
       
  
       % 单位定日镜阴影遮挡率计算
       eta_sb(k)=sum(sum(net_effective_light))/(net_num-1)^2*eta_sb_tower;
       % 截断效率计算
       for l =1:Num_light
           sigma_light=rand*sigma;
           tau_light=rand*tau;
           % sigma_light=0;
           % 光锥光线
           vector_light_cone=[sin(sigma_light)*cos(tau_light);sin(sigma_light)*sin(tau_light);cos(sigma_light)];
           vector_light_cone_abs=-T_light*vector_light_cone;
           % 随机镜面坐标
           x_num=randi(net_num-1);
           y_num=randi(net_num-1);
           x=net_position_x(x_num);
           y=net_position_y(y_num);
           if net_effective_light(x_num,y_num)==0
               continue;
           end
           P_recent=[x;y;0];
           % P_recent=[0;0;0];
           % 镜面坐标对应的地面坐标
           P_abs=T_recent*P_recent+recent_pos';
           % 反射光锥光线
           cos_theta=-vector_specular_normal(k,:)*vector_light_cone_abs;
           vector_ref_light_cone=2*cos_theta*vector_specular_normal(k,:)'+vector_light_cone_abs;
           % 判断是否被吸收
           d_min_tower=abs([vector_ref_light_cone(2),-vector_ref_light_cone(1),0]*P_abs/norm([vector_ref_light_cone(2),-vector_ref_light_cone(1),0]));
           % d_min_tower
           Num_all=Num_all+1;
           if d_min_tower<=diameter/2
               a=vector_ref_light_cone(1)^2+vector_ref_light_cone(2)^2;
               b=2*vector_ref_light_cone(1)*P_abs(1)+vector_ref_light_cone(2)*P_abs(2);
               c=P_abs(1)^2+P_abs(2)^2-diameter^2/4;
               t(1)=(-b+sqrt(b^2-4*a*c))/(2*a);
               t(2)=(-b+sqrt(b^2+4*a*c))/(2*a);
               z_range=abs(t*vector_ref_light_cone(3)+P_abs(3));
               
               if sum(z_range(1)>=height_tower && z_range(1)<=height_tower+height_collector)>=1
                   Num_trunc=Num_trunc+1;
               else         
               end
               
           else 
               
           end
       end
       % 截断效率计算
       if Num_all==0
           eta_trunc(k)=0;
       end
       eta_trunc(k)=Num_trunc/Num_all;
   end
   % 光学效率计算
   eta=eta_sb.*eta_cos'.*eta_at'.*eta_trunc.*eta_ref;

   % 时均光学效率
   eta_timemean(j)=mean(eta);
   % 时均阴影遮挡效率
   eta_sb_timemean(j)=mean(eta_sb);
   % 时均截断效率效率
   eta_trunc_timemean(j)=mean(eta_trunc);
   % 热功率累加
   A=width_size.*height_size*ones(1,length(Mirror_center_pos));
   E_field(i,j)=DNI*A*eta'/sum(A);
  end

  disp(['第',num2str(i),'月','数据:'])
  % 日均平均余弦效率
  eta_cos_daymean(i)=mean(eta_cos_timemean);
  disp(['eta_cos:',num2str(eta_cos_daymean(i))])
  % 日均阴影遮挡效率
  eta_sb_daymean(i)=mean(eta_sb_timemean);
  disp(['eta_sb:',num2str(eta_sb_daymean(i))])
  % 日均截断遮挡效率
  eta_trunc_daymean(i)=mean(eta_trunc_timemean);
  disp(['eta_trunc:',num2str(eta_trunc_daymean(i))])
  % 日均光学效率
  eta_daymean(i)=mean(eta_timemean);
  disp(['eta:',num2str(eta_daymean(i))])
  % 月热功率
  E_field_month=mean(E_field,2);
  disp(['E_field:',num2str(E_field_month(i))])
  
end
%%
plot(1:length(Mirror_center_pos),eta)
writematrix([eta_daymean',eta_cos_daymean',eta_sb_daymean',eta_trunc_daymean',E_field_month],'result1.xlsx')

% 年平均光学效率
disp('年平均光学效率')
mean(eta_daymean)
% 年平均余弦效率
disp('年平均余弦效率')
mean(  eta_cos_daymean)
% 年平均阴影遮挡效率
disp('年平均阴影遮挡效率')
mean(  eta_sb_daymean)
% 年平均截断效率
disp('年平均截断效率')
mean(  eta_trunc_daymean)
% 年平均热功率
disp('年平均热功率')
mean(E_field_month)


