clear,clc;
n=10000000
A=0,B=0,C=0,D=0;
for i =1:n
    rad=randi(6,[3,1]);
    A=(max(rad)==4)+A;
    B=(sum(rad==2)>=1)+B;
    C=(sum(rad<4)==2)+C;
    D=(sum(rad==4)==0)+D;
end

P(1)=A/n
P(2)=B/n
P(3)=C/n
P(4)=D/n
P_Re=[37/216,91/216,3/8,125/216]
% P(1)=5*factorial(4)/5^4
% P(2)=(10*3*12+10*6)/5^4
% P(3)=10*2*4/5^4
% P(4)=5/5^4
% sum(P)