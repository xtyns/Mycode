clear;clc;close all;
% 城市坐标
city=readmatrix("city_axis.xlsx");
%求得城市距离
d=pdist(city(:,2:3));
d=squareform(d);

%% 模拟退火参数
T0=200;
Tf=0.01;
Markov_length=100000;

alpha=nthroot(Tf/T0,Markov_length);
t=T0;
test=1;

%% 算法部分
%初始排列
n=size(city,1);
S=1:n;
while t>Tf
    E_old=List_Length(S,d);
    %扰动函数
    if rand<0.5
        %二交换
        list=rand(1,n);
        list_sort=sort(list);
        swith_num=find(list_sort(2)>=list);
        S_new=S;
        S_new(swith_num(1))=S(swith_num(2));
        S_new(swith_num(2))=S(swith_num(1));
    else
        %三交换
        list=rand(1,n);
        list_sort=sort(list);
        swith_num=find(list_sort(3)>=list);
        temp1=S(swith_num(2)+1:swith_num(3));
        temp2=S(swith_num(1):swith_num(2));
        S_new=S;
        S_new(swith_num(1):swith_num(3))=[temp1,temp2];
    end
    E_new=List_Length(S_new,d);
    %MetroPolis接受准则
    delta=E_new-E_old;
    if delta<0
        P=1;
        S_best=S;
    else
        P=exp(-delta/t);
    end
    if rand< P
        S = S_new;
        disp(['接受新序列,路径值为',num2str(E_new)]);
        E_array(test)=E_new;
    else
        disp(['保持旧序列,路径值为',num2str(E_old)]);
        E_array(test)=E_old;
    end
        
    t=t*alpha;
    test=test+1;
end
%结果展示
disp(['共运行',num2str(length(E_array)),'次']);
disp(['alpha为:',num2str(alpha)]);
disp(['最优路径:',num2str(S_best)]);
disp(['最优路径长度:',num2str(min(E_array))]);
%运行结果图
subplot(1,2,1)
plot(E_array)
xlabel('运行次数');
ylabel('路径长度')
title('运行次数与路径长度关系');
grid on
axis square
%最终结果路径图
subplot(1,2,2)
scatter(city(:,2), city(:,3),20,'filled','o');
hold on
line(city(S_best,2), city(S_best,3),S_best);  
xlabel('x轴');
ylabel('y轴');
title('路径图(z表示城市序号)');
grid on
axis square