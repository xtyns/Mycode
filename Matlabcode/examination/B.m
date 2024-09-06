clc,clear
tdata=linspace(100,1000,10);
ydata=1e-2*[454 499 535 565 590 610 626 639 650 650];
x0=[0.2,0.2,0.2];

opts=optimset('lsqcurvefit');
opts=optimset(opts,'PrecondBandWidth',10);



x=lsqcurvefit(@curve,x0,tdata,ydata,[],[],opts);
y=curve(x,tdata);
hold on
plot(tdata,y,'.-')
plot(tdata,ydata)