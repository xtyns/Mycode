clear;clc;close all;
%输入数据
X=[92.810 97.660 98.800 99.281 99.537 99.537 99.817 100.000]';
%输入预测数据
In_numbers=15;
%%%%%%%%%%%%%%%
X_w=GM11(X,In_numbers); %灰色GM(1,1)模型
% X_w=Verhulst(X,In_numbers);%灰色Verhulst模型

hold on
n=length(X);
plot(1:n,X,'b*','LineWidth',0.8);plot(1:In_numbers,X_w,'r','LineWidth',1);
grid on; 
axis tight;
xlabel('x');
ylabel('y');
legend('原始数列','模型数列')

disp('预测值:'),[X_w,(1:In_numbers)']

%% 误差分析
%方法一：相对误差
e=X_w(1:n)-X;
det=e./X;
Q=mean(det);
%方法二：方差比
S1=std(X);
C=std(e)/S1;
%方法三：小概率误差
S1_new=S1*0.6745;
p=sum(abs(e-mean(e))<S1_new)/n;
level='Null';
if Q<0.01 && C<0.35 && p>0.95
    level ='I';
else if Q<0.050 && C<0.50 && p<0.80
        level='II';
else if Q<0.10 && C<0.65 && p<0.70
        level='III';
else if Q>0.20 && C>0.80 && p<0.60
        level='IV';
end
end
end
end
disp(['灰色模型的精确度等级为',num2str(level),'级']);

%% 拟合优度


Xbar=mean(X);
p=1;
disp('总平方和:'),TSS=sum((X-Xbar).^2)
disp('残差平方和:'),RSS=sum(e.^2)
disp('决定系数:'),R=sqrt(1-RSS/TSS)
disp('校正决定系数:'),R_adjusted=1-(1-R^2)*(n-1)/(n-p-1)
disp('均方误差:'),MSE=RSS/n
disp('平均绝对百分比误差(自带百分号):'),MAPE=sum(abs(e./X))/n*100



