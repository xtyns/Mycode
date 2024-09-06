function ErrorAssess(y_hat,y)
n=length(y);
ybar=mean(y);
e=y_hat-y;
p=1;
% 显示总平方和TSS  
TSS=sum((y-ybar).^2);
disp(['总平方和TSS:', num2str(TSS)]);  
  
% 显示残差平方和RSS  
RSS=sum(e.^2);
disp(['残差平方和RSS:', num2str(RSS)]);  
  
% 计算决定系数R  
R = sqrt(1 - sum(e.^2) / sum((y-ybar).^2));  
disp(['决定系数R:', num2str(R)]);  
  
% 计算校正决定系数R_adjusted  
R_adjusted = 1 - (1 - R^2) * (n-1) / (n-p-1);  
disp(['校正决定系数R_adjusted:', num2str(R_adjusted)]);  
  
% 计算均方误差MSE  
MSE = sum(e.^2) / n;  
disp(['均方误差MSE:', num2str(MSE)]);  
  
% 计算平均绝对百分比误差MAPE  
MAPE = sum(abs(e./y)) / n * 100;  
disp(['平均绝对百分比误差MAPE:', num2str(MAPE), '%']);

end

