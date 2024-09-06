clear;clc;
f = @(x)(-1).^(x-1)./x;
Sn=[];
e=inf;
n=0;
while e>0.0001
    n=n+1;
    Sn=[Sn;sum(f(1:1:n))];
    if n>2
        e =abs(Sn(n)-Sn(n-1));
    end
end

S=(Sn(n)+Sn(n-1))/2;
i=0;T=0;
while i ~=n
    i=i+1;
    T=T+S-Sn(i);
end

T0=0.5-log(2)/log(exp(1));
%%
clear;clc;
f = @(x)2*x./(x.^2-1)
Sn=[];
e=inf;
n=0;
while e>0.0001
    n=n+1;
    Sn=[Sn;sum(f(1:1:n))];
    if n>2
        e =abs(Sn(n)-Sn(n-1));
    end
end
