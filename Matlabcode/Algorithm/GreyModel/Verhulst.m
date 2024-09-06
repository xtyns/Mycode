function X1_w = Verhulst(X1,nums)
%VerHulst模型适用于S型、种群繁殖、疾病传播
n=length(X1);
for i=2:n
    X0(i,1)=X1(i)-X1(i-1); %累减
end
for i=2:n
    Z1(i-1,1)=(X1(i)+X1(i-1))/2; %紧邻均值
end
u=regress(X0(2:n),[-Z1,Z1.^2]); %GM(1,1)灰微分模型求解
f=@(x)(u(1)*X1(1))./(u(2)*X1(1)+(u(1)-u(2)*X1(1))*exp(u(1)*(x-1))); %预测函数
f(2)

%预测原始数据
X1_w=f((1:nums)');
X0_w(1)=X0(1);
for i=2:nums
    X0_w(i,1)=X1_w(i)-X1_w(i-1);
end

end

