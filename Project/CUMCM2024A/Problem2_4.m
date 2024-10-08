clear;clc;close all;
%%%%%通过差分法计算速度
% 函数
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
if get_min>e*20
        P2=-1;
else
    P2=find(get_min==get);
end



end

%% 螺线设置
% 圈数
loop=16;
% 最大角度
Maxtheta=loop*2*pi;
% 螺线点数
long=100000; %10w外圈有1cm误差
% 圈点数
loop_num=floor(long/loop);
% 外圈误差
a=55/(2*pi);
disp('外圈误差：')
e=Maxtheta*a*2*pi/loop_num

% 坐标设置
theta=linspace(0,Maxtheta,long);
rho=theta*a;
[x,y]=P2N(rho,theta);
pos_all=[x;y];

% 网格设置
net_num=10;
net_max=ceil(max(x))+20;


%% 龙头设置/离散化
len=a*(theta.*sqrt(theta.^2+1)/2+log(theta+sqrt(theta.^2+1))/2);
% 龙头时间
%差分
dt=0.01
t=406-dt:dt:406;
v=100;
pos=len(end);
pos=pos*ones(1,length(t))-v.*t;
pos(end)
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

% 龙头时刻坐标
pos_P=[rho(pos_index);theta(pos_index)];
[x,y]=P2N(pos_P(1,:),pos_P(2,:));
pos_N=[x;y];
%% 时刻计算


% 计算各把手坐标
for i=1:length(t) 
    % 网格初始化
    net_point=zeros(net_max*2+1,net_max*2+1);
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
    
    % 绘图
    [x,y]=P2N(rho,theta);
    plot(x,y)
    hold on
    axis square
    if find(body_index==-1)
        body_index=body_index(1:find(body_index==-1)-1);
    end
    plot(x(body_index),y(body_index),'-o','LineWidth',1)
    % 前一时刻
    if i==1
        pos_all1=[x(body_index);y(body_index)];
    end
    % 后一时刻
    if i==2;
        pos_all2=[x(body_index);y(body_index)];
    end

    hold off
    disp(['t=',num2str(t(i)),'龙长:',num2str(length(body_index)-1)])

    for j = 1:length(body_index)-1
        pos1=[x(body_index(j)),y(body_index(j))];
        pos2=[x(body_index(j+1)),y(body_index(j+1))];
        vector12=pos1-pos2;
        vector12=vector12/norm(vector12);
        H=(pos1+pos2)/2;
        % 转换矩阵
        T=[
            vector12(1), vector12(2);
            -vector12(2), vector12(1)];
        % 网格
        net_y=linspace(-w/2,w/2,net_num);
        if j==1
            net_x=linspace(-(L0+2*r)/2,(L0+2*r)/2,net_num*5);
        else
            net_x=linspace(-(L+2*r)/2,(L+2*r)/2,net_num*5);
        end
        PNet=zeros(2,net_num*net_num);
        for m=net_x
            for n=net_y
                if abs(m)==max(net_x) || abs(n)==max(net_y)
                    PNet=[PNet,[m;n]];
                end
            end
        end
        PNet=floor(T'*PNet+H');
        hold on

       scatter(PNet(1,:),PNet(2,:))
       pause(0.00001)
        net_point(net_max+1+PNet(1,:),net_max+1+PNet(2,:))=net_point(net_max+1+PNet(1,:),net_max+1+PNet(2,:))+1;
    end
    hold off
end

% 速度
v=(pos_all2-pos_all1)/dt;


