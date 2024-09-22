clear;clc;close all;
%%%%%根据问题一的代码，动态演示盘入过程（不考虑碰撞且无掉头区域）
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




%% 龙头设置/离散化
len=a*(theta.*sqrt(theta.^2+1)/2+log(theta+sqrt(theta.^2+1))/2);
% 龙头时间
t=0:2:440;
v=100;
pos=len(end)
pos=pos*ones(1,length(t))-v.*t;
pos(end)
pos_index=zeros(1,length(pos));
% 板凳龙参数
r=27.5;
L0=341-r*2;
L=220-r*2;

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
    hold off
    disp(['龙长:',num2str(length(body_index)-1)])
    pause(0.01);
end

