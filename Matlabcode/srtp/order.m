clc;
clear;
i=1;
n=100
while i<=n
k=1;
while k<=50

sigma=1/i

v=6+1*randn(1,i)
global L;
L=500;
global lamda;
lamda=0.1;
global tao;
tao=2;
A(k,i)=sum(2/3*sigma.^2*L./v./(1-sigma*lamda*tao));
k=k+1
end
i=i+1
end
B=mean(A)
x=1:1:n

plot(x,B);
%需求的TTO与人数的关系






