clear;clc;close all;

x_min=-5;
x_max=5;
pieces=1e+3;

x=linspace(x_min,x_max,pieces);

f=@(x)0.5.*exp(-x.^2).*sin(10*x).^2;

plot(x,f(x));
xlabel('x');
ylabel('y');
axis square;
grid on
