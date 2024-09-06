clear;clc;close all;
%输入数据
M=readmatrix("area.xlsx");
x=M(:,2:4);
y=M(:,5:end);

%% 相关参数设置
%噪声强度
NoiseVar=0.01;
%最大训练次数
MaxEpochs=5e+4;
%拟合误差
E0=1e-3;
%学习速率
eta=0.01;
%隐含层神经元个数
Num=10;
%输入层输入函数
g1=@(x)x;
%隐含层输入函数
g2=@(x)1./(1+exp(-x));
%输出层输入函数
g3=@(x)x;

%% 算法主体
%数据归一化
[nx,mx]=size(x);
[ny,my]=size(y);
I1=(x-min(x))./(max(x)-min(x));
yn=(y-min(y))./(max(y)-min(y));

%权向量与偏差初始化
W1=rand(mx,Num);
B1=rand(1,Num);
W2=rand(Num,my);
B2=rand(1,my);


for i =1:MaxEpochs
    %噪声生成/防止过拟合
    yn_new=yn+rand(ny,my)*NoiseVar;
    %计算输入层
    O1=g1(I1);
    %计算隐含层
    I2=O1*W1+B1;
    O2=g2(I2);
    %计算输出层
    I3=O2*W2+B2;
    O3=g3(I3);
    %计算能量函数
    E=sumsqr(yn_new-O3);
    disp(['E =',num2str(E)])

    if E<E0,break,end
    
    %计算梯度差值
    Delta2=yn_new-O3;
    Delta1=O2.*(1-O2).*(Delta2*W2');
    dW2=eta*O2'*Delta2;
    dB2=eta*sum(Delta2, 1);
    
    dW1=eta*O1'*Delta1;
    dB1=eta*sum(Delta1, 1);
    
    W1=W1+dW1;
    W2=W2+dW2;
    B1=B1+dB1;
    B2=B2+dB2;
end

%% 制图与误差评估
y_hat=O3.*(max(y)-min(y))+min(y);
y_label={'客运量/万人';'货运量/万吨'};

for i =1:my
subplot(2,1,i);
plot(M(:,1),y(:,i),'r-o',M(:,1),y_hat(:,i),'b-.+')
legend('实际数值','预测数值')
xlabel('year')
ylabel(y_label(i))
grid on
disp(['***第',num2str(i),'组变量误差分析：'])
ErrorAssess(y(:,i),y_hat(:,i))

end
