clear;clc;
d=0.2;
x1=[0,d];
y1=[0,0.5];

x2=d:0.01:20;
y2=0.5*(exp(-(x2)/11)-exp(-(d./(x2+1))/11)+1);

x=[x1,x2];
y=[y1,y2];
plot(x,y)
grid on;
