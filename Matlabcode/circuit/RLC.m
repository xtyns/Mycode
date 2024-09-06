clc;clear;


U=150;
I=0.26;
P=5;
aZ=U/I;
r=P/I^2;
X=sqrt(aZ^2-r^2);
Y=I/U;
phi=atan(X/r)/pi*180;
cphi=cos(phi);

L0=1/(2*pi*50*I)*sqrt(U^2-(P/I)^2);

L=1/(2*pi*50*0.26)*sqrt(150^2-(5/0.26)^2);
Z0=2*pi*50*L;
%% 
clc;clear;

U=150;
I=0.46;
P=4;
aZ=U/I;
r=P/I^2;
X=sqrt(aZ^2-r^2);
Y=I/U;
phi=atan(X/r)/pi*180;
cphi=cos(phi);

C0=1/(2*pi*50*U)*sqrt(I^2-(P/U)^2);


C=1/(2*pi*50*150)*sqrt(0.46^2-(4/150)^2);

%% 
clc;clear;

U=150;
I=0.98;
P=91;
aZ=U/I;
r=P/I^2;
X=sqrt(aZ^2-r^2);
Y=I/U;
phi=atan(X/r)/pi*180;
cphi=cos(phi);

%% 
clc;clear;

U=150;
I=0.22;
P=8;
aZ=U/I;
r=P/I^2;
X=sqrt(aZ^2-r^2);
Y=I/U;
phi=atan(X/r)/pi*180;
cphi=cos(phi);
%%

clear;clc;
L=100*10^-3;C=3.3*10^-9;
dt=92*10^-6;
wdp=2*pi/dt;
w0=1/sqrt(L*C);
alphap=1/dt;
R=2300.0
alpha=R/(2*L);
gA=(alphap-alpha)/alpha

wd=sqrt(w0^2-alpha^2);
gW=(wdp-wd)/wd
