clear;
clc;
close all;
% 计算出圆弧的坐标和长度与时间的关系。将盘入切入调头曲线的点的时刻设为0
% 根据对称性，画出盘出曲线。
% t设为-100:50:100，再进行数学模拟(由于点的离散性，某些结果可能失真，需要对结果数据进行处理）
function [x,y] = P2N(rho,theta)
% 极坐标化直角坐标
x=rho.*cos(theta);
y=rho.*sin(theta);
end

function P2=Get_index(P1,L,pos_all,e,loop_num,long)
recent=pos_all(:,P1);
dist=sqrt(sum((recent-pos_all).^2));
get=abs(dist-L);
get(1:P1)=get(1:P1)+L;
if P1+floor(loop_num/2)<=long
    get(P1+floor(loop_num/2):end)=get(P1+floor(loop_num/2):end)+L;
end
get_min=min(get);
if get_min>e*20*3
        P2=-1;
else
    P2=find(get_min==get);
end



end

%% 基本设置
% 圈数
loop=16;
% 最大角度
Maxtheta=loop*2*pi;
% 螺线点数
long=100000; %10w外圈有1cm误差
% 圈点数
loop_num=floor(long/loop);
% 设置a的搜索范围
a=170/(2*pi);


% 外圈误差
e=Maxtheta*a*2*pi/loop_num;

% 坐标设置
theta=linspace(0,Maxtheta,long);
rho=theta*a;
[x,y]=P2N(rho,theta);
pos_all=[x;y];
% 网格设置
net_num=10;
net_max=ceil(max(x))+20;

% 调取区域设置
R=450;
R_num=1000;
[xr,yr]=P2N(R,linspace(0,2*pi,R_num));


% 切入角度
alpha=atan(a/R);
% 小圆弧半径
R0=R/(3*cos(alpha));
% 掉头曲线长度
Lt=(pi-2*alpha)*3*R;



%% 龙头设置/离散化
% 龙头设置
len=a*(theta.*sqrt(theta.^2+1)/2+log(theta+sqrt(theta.^2+1))/2);
len0=a/2*(R/a*sqrt(R^2/a^2+1)+log(R/a+sqrt(R^2/a^2+1)));

% 龙头时间
pos=len(end);
v=100;
t=(pos-len0)/v;

pos=pos*ones(1,length(t))-v.*t;
pos_index=zeros(1,length(pos));
% 板凳龙参数
r=27.5;
L0=341-r*2;
L=220-r*2;
w=30;

% 龙头时刻指标
for i =1:length(pos)
    dif=abs(len-pos(i));
    dif_min=min(dif);
    pos_index(i)=find(dif==dif_min);
end


%   切入点
pos_P=[rho(pos_index);theta(pos_index)];
[x,y]=P2N(pos_P(1,:),pos_P(2,:));
pos_N=[x;y];

% 切入点角度
phi=atan(y/x)+pi;

%  圆弧坐标预导入
if mod(pos_index,2)==0
    rad_num=pos_index/2;
else
    rad_num=(pos_index-1)/2;
end
temp=len(pos_index);
temp_index=pos_index;
len=len-temp;
% 大圆弧计算
phi_p1=phi-alpha;
t0=linspace(0,pi-alpha,rad_num);
O1=pos_N-[cos(alpha),-sin(alpha);sin(alpha),cos(alpha)]*pos_N/R*2*R0;
x=2*R0*cos(phi_p1-t0)+O1(1);
y=2*R0*sin(phi_p1-t0)+O1(2);
pos_all(:,2*rad_num:-1:rad_num+1)=[x;y];
len(2*rad_num:-1:rad_num+1)=-t0*2*R0;
% 小圆弧计算
phi_p2=phi+2*alpha;
t0=linspace(0,pi-alpha,rad_num);
O2=-pos_N+[cos(alpha),-sin(alpha);sin(alpha),cos(alpha)]*pos_N/R*R0;
x=R0*cos(phi_p1+t0)+O2(1);
y=R0*sin(phi_p1+t0)+O2(2);
pos_all(:,rad_num:-1:1)=[x;y];
len(:,rad_num:-1:1)=-t0*R0-(pi-2*alpha)*2*R0;

len=len+temp;

% 龙头时间
pos=len(end);
v=100;
dt=-100:50:100;
t=(pos-len0)/v+dt;

pos=pos*ones(1,length(t))-v.*t;
pos_index=zeros(1,length(pos));
% 板凳龙参数
r=27.5;
L0=341-r*2;
L=220-r*2;
w=30;
% 盘出螺线
len=[len(1)-len(end:-1:temp_index)+len(temp_index),len];
% 龙头时刻指标
for i =1:length(pos)
    dif=abs(len-pos(i));
    dif_min=min(dif);
    pos_index(i)=find(dif==dif_min,1);
end
% 盘出螺线
pos_all=[[-pos_all(1,end:-1:temp_index),pos_all(1,:)];[-pos_all(2,end:-1:temp_index),pos_all(2,:)]];

%   切入点
x=pos_all(pos_index);
y=pos_all(pos_index);
pos_N=[x;y];


%% 时刻计算
long=length(pos_all);


% 计算各把手坐标
for i=1:length(t) 
    body_index=zeros(1,224);
    body_index(1)=pos_index(i);
    % 计算第二把手坐标
    body_index(2)=Get_index(body_index(1),L0,pos_all,e,loop_num,long);
    if body_index(2)==-1
        disp('此节结束')
        disp(['龙长:',num2str(0)])
        continue
    end
    % 计算龙身+龙尾把手坐标
    for j=2:223
        body_index(j+1)=Get_index(body_index(j),L,pos_all,e,loop_num,long);
        if body_index(j+1)==-1
            disp('此节结束')
            break
        end
    end
    
    % 绘图（把手坐标）
    x=pos_all(1,:);y=pos_all(2,:);
    % x_new=[-pos_all(1,end:-1:temp_index),x];y_new=[-pos_all(2,end:-1:temp_index),y];
    plot(x,y)
    hold on
    plot(xr,yr,'Color',[0,0,0],'LineWidth',3)
    axis square
    if find(body_index==-1)
        body_index=body_index(1:find(body_index==-1)-1);
    end
    plot(x(body_index),y(body_index),'-o','LineWidth',1)
    hold off
    disp(['t=',num2str(dt(i)),'龙长:',num2str(length(body_index)-1)])

    for j = 1:length(body_index)-1
        pos1=[x(body_index(j)),y(body_index(j))];
        pos2=[x(body_index(j+1)),y(body_index(j+1))];
        % 板凳系y轴向量
        vector12=pos1-pos2;
        vector12=vector12/norm(vector12);
        % 板凳系原点坐标
        H=(pos1+pos2)/2;
        % 板凳系转换矩阵
        T=[
            vector12(1), vector12(2);
            -vector12(2), vector12(1)];
        % 板凳坐标网格/板凳系
        net_y=linspace(-w/2,w/2,net_num);
        if j==1
            net_x=linspace(-(L0+2*r)/2,(L0+2*r)/2,net_num*5);
        else
            net_x=linspace(-(L+2*r)/2,(L+2*r)/2,net_num*5);
        end
        PNet=zeros(2,net_num*net_num);
        % 板凳的边界点选取
        for m=net_x
            for n=net_y
                if abs(m)==max(net_x) || abs(n)==max(net_y)
                    PNet=[PNet,[m;n]];
                end
            end
        end
        % 板凳席点投影到标准坐标
        PNet=floor(T'*PNet+H');
        % 板凳绘制
        % hold on
        % scatter(PNet(1,:),PNet(2,:))
        pause(0.00001)
        % 重叠判断
        if j==1
            net_point1=PNet;
        end
        if j>2
            net_point2=PNet;
            for k=1:length(net_point2)
                if sum(find(sum(abs(net_point2(:,k)-net_point1))<=1))>1
                    disp('发现重叠')
                    disp(['与第',num2str(j-1),'个龙身发生碰撞'])
                    break;
                end
            end
        end

    end
    hold off
end
%%
% temp_index
% 
% plot(x,y)
% axis square

