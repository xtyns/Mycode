clc,clear
t0=0;tf=60;

y0=[0;0.25]

[t,y]=ode45(@dfun,[t0,tf],y0)

subplot(1,2,1);plot(t,y(:,1));
subplot(1,2,2);plot(y(:,1),y(:,2));%相轨迹