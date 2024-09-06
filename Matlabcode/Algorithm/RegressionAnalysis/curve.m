function f = curve(x,tdata)
%更改回归/拟合函数
f=x(1)+x(2)*exp(-0.02*x(3)*tdata);
end

