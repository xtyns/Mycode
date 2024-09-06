clear;clc;
l=10;
dt=1;


tm=100
t=1:dt:tm
f =@(k)l.^k./factorial(k)*exp(-l);
ft=f((t))
p=sum(ft*dt);
plot(t,ft)