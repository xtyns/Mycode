clear;clc;close all;
%输入数据
M=readmatrix("area.xlsx");
x=M(:,2:4);
y=M(:,5:end);

p=x';
t=y';
%归一化
[pn,input_str]=mapminmax(p);% 输入数据归一化,pn为归一化后的数据，input_str为归一化参数
[tn,output_str]=mapminmax(t);

%搭建网络
net=newff(pn,tn,[3 7 2],{'purelin','logsig','purelin'}); % 输入层3个神经元，隐藏层7个神经元，输出层2个神经元
%10轮显示一回结果
net.trainParam.show=10; 
%学习速度0.05
net.trainParam.lr=0.05;
%最大训练次数
net.trainParam.epochs=5000;
%均方误差
net.trainParam.goal=0.65*10^(-3);
%取消6次无变化终止
net.divideFcn='';
%开始训练
net=train(net,pn,tn);

%% 原始数据结果测试
%利用训练好的网络，基于原始数据对BP网络仿真
an=sim(net,pn); %仿真结果
%反归一化
a =mapminmax('reverse',an,output_str); %将仿真结果反归一化

x=M(:,1)';
newk=a(1,:);
newh=a(2,:);
subplot(2,1,1);plot(x,newk,'r-o',x,y(:,1),'b--+')
legend('网络输出客运量','实际客运量')
xlabel('年份');
ylabel('客运量/万人')

subplot(2,1,2);plot(x,newh,'r-o',x,y(:,2),'b--+')
legend('网络输出货运量','实际货运量')
xlabel('年份');
ylabel('货运量/万吨')