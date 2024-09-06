clear; clc;

% 泊松分布参数
phi = 3; 

% 模拟订单到达次数
num = 1000;

% 记录订单到达时间
arrival_time = zeros(1,num); 

% 初始化第一个订单到达时间
arrival_time(1) = 0;

% 模拟订单到达
for i = 2:num
  
   % 生成随机数服从指数分布
   random_time = -log(rand)/phi;  
   
   % 计算下一个订单到达时间
   arrival_time(i) = arrival_time(i-1) + random_time;
   
end

% 输出订单到达时间序列
arrival_time

subplot(1,2,1); plot(arrival_time)

subplot(1,2,2); plot(arrival_time(i-1))

%%
syms x
t =x^3 + x^2
f=@(x)t
fplot(t)


