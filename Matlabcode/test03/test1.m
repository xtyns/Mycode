clc
clear

X =input('plz input 1xn vector of X:')
EX =zeros(size(X))
n =0;
while ~(n>100)
    EX =EX+X.^n/factorial(n)
    n=n+1
end
EX
exp(X)
% edit test1.m
