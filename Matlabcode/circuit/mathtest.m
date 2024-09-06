clc;clear;
a=(exp(pi)-exp(-pi))/4/pi-1;
s=0;
for i=1:1:100
    s=s+pi^(4*i)/factorial(4*i+1);
    s;
end

s0=dsolve('D4y-y=x','y(0)=0','Dy(0)=0','D2y(0)=0','D3y(0)=0','x');


%dsolve(e,c,x) or dsolve(e1,e2…en,c1,c2…cn,x)
%例如:y=dsolve('D2y+x*y=0','y(1)=1','x')
