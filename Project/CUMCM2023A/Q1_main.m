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
% 当地海拔
altitude=3000;
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
height_diameter=7;

% 网格一维采样量
net_num=10;
% 太阳常数
G0=1.366e+3;

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

% length(gamma_s)
for i =1
    % 计算以北为x轴，东为y轴的坐标系下太阳的光线向量
   vector_sunlight=[
       -cos(alpha_s(i,:)).*sin(gamma_s(i,:));
       -cos(alpha_s(i,:)).*cos(gamma_s(i,:));
       -sin(alpha_s(i,:))
       ] %规律：光线呈现出对称性
   % 镜面法向量
   for j=length(vector_sunlight)
        vector_specular_normal=-vector_sunlight(:,j)'+vector_unit_reflection;
   end
   % 计算最大阴影搜索范围
   d_max_shadow=height_size./2./sin(alpha_s(i,:))+height_install./tan(alpha_s(i,:));
   % 对镜面法向量单位化并且计算反射向量对地面的夹角
   for j=1:length(vector_specular_normal)
       vector_specular_normal(j,:)=vector_specular_normal(j,:)/norm(vector_specular_normal(j,:));
       angle_reflection(j,1)=asin(vector_unit_reflection(j,:)*[0,0,1]');
   end
   % 计算最大遮挡搜索范围
  d_max_occlusion=height_size./2*(1./tan(angle_reflection)+1./sin(angle_reflection));
  for j=1:length(ST)
   % 余弦效率
   eta_cos=-vector_specular_normal*vector_sunlight(:,j);
   % 日平均余弦效率
   eta_cos_daymean=mean(eta_cos);
   
   for k=1:length(Mirror_center_pos)
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
        z_recent=vector_specular_normal(k,:);
        AH_recent=asin(z_recent(3));
        EH_recent=asin(z_recent(2)/cos(AH_recent));
        T_recent=[ 
        -sin(EH_recent),-sin(AH_recent)*cos(EH_recent),cos(AH_recent)*cos(EH_recent);
        cos(EH_recent),-sin(AH_recent)*sin(EH_recent),cos(AH_recent)*sin(EH_recent);
        0,cos(AH_recent),sin(AH_recent)
        ];
       % 阴影遮挡定日镜判断
       for l=1:length(Mirror_center_pos)
           % 可能造成阴影的定日镜坐标获取
           shadow_judge(l)=norm(recent_pos-Mirror_center_pos(l,:))<=d_max_shadow(j)...
               && ((recent_pos-Mirror_center_pos(l,:)))*vector_sunlight(:,j)<0;
           specular_code=find(shadow_judge);
           for m=1:length(specular_code)
               aim_pos=Mirror_center_pos(specular_code(m),:);
               for x_num=1:net_num-1
                   for y_num=1:net_num-1
                       %坐标存储
                       x=net_position_x(x_num);
                       y=net_position_y(y_num);
                       % 目标位置变换矩阵
                       P_recent=[x;y;0];
                       z_aim=vector_specular_normal(specular_code(m),:);
                       AH_aim=asin(z_aim(3));
                       EH_aim=asin(z_aim(2)/cos(AH_aim));
                       T_aim=[
                            -sin(EH_aim),-sin(AH_aim)*cos(EH_aim),cos(AH_aim)*cos(EH_aim);
                            cos(EH_aim),-sin(AH_aim)*sin(EH_aim),cos(AH_aim)*sin(EH_aim);
                            0,cos(AH_aim),sin(AH_aim)
                            ];
                       P_abs=T_recent*P_recent+recent_pos';
                       P_aim=T_aim'*(P_abs-aim_pos');
                       vector_aim_sunlight=T_aim'*vector_sunlight(:,j);
                       area_light_aim=[
                           (vector_aim_sunlight(3)*P_aim(1)-vector_aim_sunlight(1)*P_aim(3))/vector_aim_sunlight(3),
                           (vector_aim_sunlight(3)*P_aim(2)-vector_aim_sunlight(2)*P_aim(3))/vector_aim_sunlight(3),
                           ];
                       if abs(area_light_aim(1))<=width_size/2 && abs(area_light_aim(2))<=height_size/2 
                           net_effective_light(x_num,y_num)=0;
                       end
                     
                   end
               end
           end
       end
       eta_trun=sum(sum(net_effective_light))/(net_num-1)^2
                  % sum(shadow_judge)
   end
  end

  
end



% EH=-pi/2;% 定日镜北方向逆时针转动
% AH=0; % 定日镜仰角转动
% T=[
%     -sin(EH),-sin(AH)*cos(EH),cos(AH)*cos(EH);
%     cos(EH),-sin(AH)*sin(EH),cos(AH)*sin(EH);
%     0,cos(AH),sin(AH)
%     ];
% T*[1;0;0]
% T*[0;1;0]
% T*[0;0;1]


