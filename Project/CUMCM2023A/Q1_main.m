clear;clc;close all;
%数据输入
Mirror_pos=readmatrix("附件.xlsx")

scatter(Mirror_pos(:,1),Mirror_pos(:,2))
xlabel('x轴')
ylabel('y轴')
axis square
grid on

