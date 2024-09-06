clc,clear
%函数型拟合求解-需要数据和参考函数
%%%%%%%%数据输入
tdata=linspace(100,1000,10);
ydata=1e-2*[454 499 535 565 590 610 626 639 650 650];
x0=[0.2,0.2,0.2];

%%%%%%%%
opts=optimset('lsqcurvefit');
opts=optimset(opts,'PrecondBandWidth',10);

x=lsqcurvefit(@curve,x0,tdata,ydata,[],[],opts);
y=curve(x,tdata);
hold on
plot(tdata,y,'.-')
plot(tdata,ydata)
%% 拟合优度

e=y-ydata;ybar=mean(ydata);
n=size(y,2);p=1;
disp('总平方和:'),TSS=sum((y-ybar).^2)
disp('残差平方和:'),RSS=sum(e.^2)
disp('决定系数:'),R=sqrt(1-RSS/TSS)
disp('校正决定系数:'),R_adjusted=1-(1-R^2)*(n-1)/(n-p-1)
disp('均方误差:'),MSE=RSS/n
disp('平均绝对百分比误差(自带百分号):'),MAPE=sum(abs(e./y))/n*100