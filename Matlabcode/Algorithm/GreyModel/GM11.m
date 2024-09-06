function X0_w = GM11(X0,nums)
%GM(1,1)预测模型，适用于大多数模型
n=length(X0);
X1=cumsum(X0); %累加
for i=2:n
    Z1(i-1,1)=(X1(i)+X1(i-1))/2;
end
u=regress(X0(2:n),[-Z1,ones(n-1,1)]); %GM(1,1)灰微分模型求解
f=@(x)(X0(1)-u(2)/u(1))*exp(-u(1)*(x-1))+u(2)/u(1); %预测函数
%预测原始数据
X1_w=f((1:nums)');
X0_w(1)=X0(1);
for i=2:nums
    X0_w(i,1)=X1_w(i)-X1_w(i-1);
end

end

