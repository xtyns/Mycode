clear,clc;close all;
% 进化代数
T=100;
lb=[-10,-10];
ub=[10,10];
%%%%%%%%%%%
options = optimoptions('ga', ...  
        'PopulationSize', 100, ... % 种群规模
        'MaxGenerations',T,... %进化代数
        'CrossoverFraction', 0.8, ... % 交配比例
        'PlotFcn', @gaplotbestf); % 绘图函数 
[x,fval,reason,output,finnal_pop]=ga(@fun,2,[],[],[],[],lb,ub,[],options);
%进行二次接力进化
options = optimoptions('ga', ...  
        'PopulationSize', 100, ... % 种群规模  
        'MaxGenerations',T,... %进化代数
        'InitialPopulationMatrix',finnal_pop,... %初始化 
        'CrossoverFraction', 0.8, ... % 交叉比例 
        'PlotFcn', @gaplotbestf); % 绘图函数 
[x,fval,reason,output,finnal_pop]=ga(@fun,2,[],[],[],[],lb,ub,[],options);
Bestx=x
BestFval=fval
