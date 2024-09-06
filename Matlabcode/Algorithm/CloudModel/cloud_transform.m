function [x,y,Ex,En,He]=cloud_transform(y_spor,N)
%逆向云发生器（获取数据的特征）+正向云发生器（将数据特征表示出来）
% ——x表示云滴、y表示隶属度（钟形）Ex为期望，En为熵，He为超熵
%逆向云发生器-分析数据
Ex=mean(y_spor);
En=sqrt(pi/2).*mean(abs(y_spor-Ex));
He=sqrt(var(y_spor)-En.^2);

%正向云发生器-产生云滴
for q=1:N
    Enn=randn(1).*He+En;
    x(q)=randn(1).*Enn+Ex;
    y(q)=exp(-(x(q)-Ex).^2./(2.*Enn.^2));
end


