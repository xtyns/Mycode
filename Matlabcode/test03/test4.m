clc
clear
t=linspace(0,2*pi,50)
r=ones(size(t))
x=cos(t)'*r
y=sin(t)'*r

z=ones(size(x)).*linspace(-2,2,50)
meshc(x,y,z)
% hold on
% mesh(x,z,y)
% axis([-2,2,-2,2,-2,2])
% z1=z
% z2=y
% grid on
% 
% l=abs(z1-z2)<=0.1   %两曲面坐标差小于1的点
% lx=l.*x;ly=l.*y;lz=l.*z;    %交线方程
% plot3(lx(l~=0),ly(l~=0),lz(l~=0))
%% 

clc
clear
[x,y]=meshgrid(linspace(-10,10,50))

z=x.^2+y.^2
surfc(x,y,z)
% hold on
%% 

[x,y,z]=peaks(100)
waterfall(x,y,z)
%% 
[x,y,z]=sphere(20)
z(:,1:5)=NaN
mesh(x,y,z)

axis([-2,2,-2,2,-2,2])
axis square

%% 
[x,y,z]=



