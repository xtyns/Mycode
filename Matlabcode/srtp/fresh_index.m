clc;clear    
Hmax=42.9;    %前置参数
Hmin=124;
kref=0.0021;
Ea=138443;
R=8.314;
Tref=288.15;
T=25+273.15;
H0=83.9;

day=15;

t=linspace(0,day,100);  %常温下色调关系函数
k=kref*exp((Ea/R)*(1/Tref-1/T));

H1 =Hmax+(Hmin-Hmax)./(1+(exp(k*t*(Hmin-Hmax))*(Hmin-H0)/(H0-Hmax)));

hold on
plot(t,H1);
xlabel('天数/d')
ylabel('色调')
legend()
title('图1：西红柿的色调与时间的关系')

T=20+273.15;       %20摄氏度下色调关系函数
k=kref*exp((Ea/R)*(1/Tref-1/T));
H2 =Hmax+(Hmin-Hmax)./(1+(exp(k*t*(Hmin-Hmax))*(Hmin-H0)/(H0-Hmax)));
plot(t,H2);

T=288.15;          %适宜参考温度下色调关系函数
k=kref*exp((Ea/R)*(1/Tref-1/T));
H3 =Hmax+(Hmin-Hmax)./(1+(exp(k*t*(Hmin-Hmax))*(Hmin-H0)/(H0-Hmax)));
plot(t,H3);


legend('25摄氏度常温下','20摄氏度下','15摄氏度适宜参考温度下')


axis square
grid on

hue=[115,83,72.85,61.8,48,41.3,37]
index=1:1:7
%%
a=16.86;b=-0.024;
M=[a*exp(b*H1);a*exp(b*H2);a*exp(b*H3)] %成熟度与色调的拟合指数拟合函数

hold off
plot(t,M);    %成熟度与时间的关系函数
xlabel('天数/d')
ylabel('成熟程度')
legend('25摄氏度常温下','20摄氏度下','15摄氏度适宜参考温度下')
title('图1：西红柿的成熟程度与时间的关系')

axis square
grid on

%%
%当天数趋于无穷时时，成熟程度趋于42.9,M趋于6.0215.分别设为Hm，Mm.
%当天数趋于0时，成熟程度趋于83.9，M趋于2.2509.分别设为H0,M0
tp=inf;t0=0;
H0=Hmax+(Hmin-Hmax)./(1+(exp(k*t0*(Hmin-Hmax))*(Hmin-H0)/(H0-Hmax)));
Hm=Hmax+(Hmin-Hmax)./(1+(exp(k*tp*(Hmin-Hmax))*(Hmin-H0)/(H0-Hmax)));
M0=a*exp(b*H0);Mm=a*exp(b*Hm);
% 新鲜率alpha=(Mm-M)/Mm
alpha=(Mm-M)/(Mm-M0);
%%

plot(t,alpha);    %新鲜率与时间的关系函数
xlabel('天数/d')
ylabel('新鲜率')
legend('25摄氏度常温下','20摄氏度下','15摄氏度适宜参考温度下')
title('图2：西红柿的新鲜率与时间的关系')

axis square
grid on


