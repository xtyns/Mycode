clear,clc;close all;
% 进化代数
N=1745;
T=200;
lb=[-250,0,ones(1,N*2)*-350];
ub=[250,0,ones(1,N*2)*350];
%% %%%%%%%%%
options = optimoptions('ga', ...  
        'PopulationSize', 50, ... % 种群规模
        'MaxGenerations',T,... %进化代数
        'CrossoverFraction', 0.8, ... % 交配比例
        'PlotFcn', @gaplotbestf); % 绘图函数 
[x,fval,reason,output,finnal_pop]=ga(@fun,2*N+2,[],[],[],[],lb,ub,[],options);
%%
%进行二次接力进化
options = optimoptions('ga', ...  
        'PopulationSize', 100, ... % 种群规模  
        'MaxGenerations',T,... %进化代数
        'InitialPopulationMatrix',finnal_pop,... %初始化 
        'CrossoverFraction', 0.8, ... % 交叉比例 
        'PlotFcn', @gaplotbestf); % 绘图函数 
[x,fval,reason,output,finnal_pop]=ga(@fun,2*N+2,[],[],[],[],lb,ub,[],options);
%%
Bestx=x
BestFval=fval

% 塔坐标
focos_pos=[x(1),x(2),84];
% 镜面中心坐标
Mirror_center_pos=[x(3:2+N)',x(3+N:end)',4*ones(N,1)];

scatter(Mirror_center_pos(:,1),Mirror_center_pos(:,2))
%%
finnal_pop(1,[1,2])=[-250,0];
%%
finnal_pop(:,3:end)=finnal_pop(:,3:end)*0.9;
%%
Mirror_pos=readmatrix("附件.xlsx");
finnal_pop(1,:)=[-250;0;Mirror_pos(:,1);Mirror_pos(:,2)]';
