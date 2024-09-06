function [fitresult, gof] = createFit(hue, index)
%CREATEFIT(HUE,INDEX)
%  创建一个拟合。
%
%  要进行 '无标题拟合 1' 拟合的数据:
%      X 输入: hue
%      Y 输出: index
%  输出:
%      fitresult: 表示拟合的拟合对象。
%      gof: 带有拟合优度信息的结构体。
%
%  另请参阅 FIT, CFIT, SFIT.

%  由 MATLAB 于 07-Aug-2024 22:03:12 自动生成


%% 拟合: '无标题拟合 1'。
[xData, yData] = prepareCurveData( hue, index );

% 设置 fittype 和选项。
ft = fittype( 'exp1' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';
opts.StartPoint = [18.4665675547167 -0.0258883382425944];

% 对数据进行模型拟合。
[fitresult, gof] = fit( xData, yData, ft, opts );

% 绘制数据拟合图。
figure( 'Name', '无标题拟合 1' );
h = plot( fitresult, xData, yData );
legend( h, 'index vs. hue', '无标题拟合 1', 'Location', 'NorthEast', 'Interpreter', 'none' );
% 为坐标区加标签
xlabel( 'hue', 'Interpreter', 'none' );
ylabel( 'index', 'Interpreter', 'none' );
grid on


