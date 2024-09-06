clear,clc;
Bc=30:20:150;
V=1.5:1:7.5;
V0x=[1.5023,2.5063,3.4958,4.4896,5.5074,6.5102,7.5233];
dV=V-V0x;
ksi=-dV;

plot(V,ksi)
xlabel('U(V)')
ylabel('\epsilon')
grid on
axis([1.5,7.5,-0.015,0.025])

max(ksi)
max(V)
gama=max(ksi)/max(V)*100;
