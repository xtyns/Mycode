clear;clc;
x0=[10;0;0];
A=[];
b=[];
Aeq=[];
beq=[];
lb=[0;0;0];
ub=[];

[x,y] = fmincon('fun',x0,A,b,Aeq,beq,lb,ub,'Nonf');
disp('When');x
disp('have the opt fval:'),disp(y);