clear;clc;close all;

%根据遗传算法的最优化问题的求解
%非线性约束条件
res=@(x)[
    1.5+x(:,1).*x(:,2)-x(:,1)-x(:,2),   -x(:,1).*x(:,2)-10];
%目标函数

f=@(x)exp(x(:,1)).*(4*x(:,1).^2+2*x(:,2).^2+4*x(:,1).*x(:,2)+2*x(:,2)+1)+(sum(res(x)>0,2)*100);
Type='Min';
% f=@(x)200*exp(-0.05*x).*sin(x);
% Type='Max';

%上下限
U=[1;1]*1e+1;
L=[-1;-1]*1e+1;
% U=[2];
% L=[-2];

n=size(L,1);
%%%%%若要提高精度可以扩大种群规模和进化代数、调节适应度函数、择优算法
% 种群规模
Nmax=100;
%初始种群规模
Nmin=20;
%计算精度等级
Calculation_Accuracy=4;
%交配概率
pc=0.8;
%进化代数
G=500;
%突变概率
pm=0.01;

%%%%%%%%%%%%%%%%
%编码
N=Nmin;
Max_code=(U-L)*10^Calculation_Accuracy;
pieces_index=zeros(n,1);

for j =1:n
    while true
        if (Max_code(j)<=(2^pieces_index(j)-1)) && (Max_code(j)>2^(pieces_index(j)-1))
            break
        else
            pieces_index(j)=pieces_index(j)+1;
        end
    end
end

%初始数据生成
disp('初始种群:'),
scro=round(rand(N,1)*(2.^pieces_index)')
%%%%% 新种群复制/选择
for k=1:G
    pm0=pm; %初始化突变概率
    Decode=@(x)x./(2.^pieces_index)'.*(U'-L')+L';
    fitness=@(x) f(Decode(x)); %标准适应度函数
    eval=fitness(scro);
    if Type=='Min'
        y_eval(k)=min(eval);
    else
        y_eval(k)=max(eval);
    end
    y_mean(k)=mean(eval);
    x=Decode(scro(find(eval==y_eval(k),1),:));
    disp(['第',num2str(k),'种群中的解:',num2str(y_eval(k)),'. x = [ ',num2str(x),' ]']);
    %适应度调整
    if Type=='Min'
        eval=max(eval)-eval+min(eval);
    end
    if k<floor(G*0.5)
        eval=nthroot(eval,3); %弱化个体差异
        pm0=pm*3; %增加突变概率，获取更多基因型个体
    end
    if k>floor(G*0.5) %强化个体差异，增强优质个体的显著性
        %eval-min(eval)只关注数据的差值，+1).^10和*10^(使大数据更大，-1使小数据更小，后项为偏离值
        eval=((eval-min(eval))*10^(Calculation_Accuracy+3)+1)-1+10^-Calculation_Accuracy; 

        %最值择优算法
        % eval(find(eval==max(eval),1))=eval(find(eval==max(eval),1))*N;
        % pm0=pm*100;
        % else if (k>floor(k/3*2))
        %         eval=((eval-min(eval))*(Calculation_Accuracy+10)+1).^10-1+10^-Calculation_Accuracy; 
    end

    
    %轮盘选择法
    P=(eval)/sum(eval);
    Q=cumsum(P);
    
    find_pos=find(eval==max(eval),1);
    finest_line=scro(find_pos,:);
    scro_new=[finest_line;finest_line;finest_line]; %最值保留择优
    for i =1:N-size(find_pos,1)*3
        t_rand=rand(1,1);
        pos=find(t_rand<=Q,1);
        scro_new=[scro_new;scro(pos,:)];
    end
    
    %%%%% 交配过程
    
    %基因突变
    for i= 1:n
    Mutgene=rand(N,pieces_index(i))<pm0;
    scro_new2=dec2bin(scro_new(:,i),pieces_index(i));
    pos_line=find(Mutgene);
    pos_square=[ceil(pos_line/pieces_index(i)),mod(pos_line,pieces_index(i))+(mod(pos_line,pieces_index(i))==0)*pieces_index(i)];
    for j =1:length(pos_line)
        if scro_new2(pos_square(j,1),pos_square(j,2))=='0'
            scro_new2(pos_square(j,1),pos_square(j,2))='1';
        else
            scro_new2(pos_square(j,1),pos_square(j,2))='0';
        end
    end
    scro_new(:,i)=bin2dec(scro_new2);
    end
    %自由交配
    mating_num=round(N*pc); %交配次数
    for i =1:mating_num
        %选出交配个体
        list=rand(N,1);
        sort_list=sort(list);
        mating_individual=scro_new(find(list<=sort_list(2)),:);
        for j=1:n
            %二进制化
                mat1=dec2bin( mating_individual(1,j),pieces_index(j));
                mat2=dec2bin( mating_individual(2,j),pieces_index(j));
                cut=randi([1,pieces_index(j)]);
                temp=mat1(cut:end);
                mat1(cut:end)=mat2(cut:end);
                mat2(cut:end)=temp;
                line(1,j)=bin2dec(mat1);
                % line(2,j)=bin2dec(mat2);
        end
    scro_new=[scro_new;line];
    N=N+1;
    end
    if N>Nmax
        scro_new(1:Nmax-N,:)=[];
        N=Nmax;
    end
    scro=scro_new;
    
end

%%%%% 制图
hold on

subplot(2,1,1);
y_pos=10:G;
plot(y_pos,y_eval(y_pos),"LineWidth",1);
xlabel('种群代数')
ylabel('最优目标值')
legend('种群适应度的最优值')

subplot(2,1,2);
plot(y_pos,y_mean(y_pos),"LineWidth",0.1,"Color",[1 0 0]); %种群的平均适应度
xlabel('种群代数')
ylabel('最优目标值')
legend('种群适应度的平均值')
if Type=='Min'
    disp(['Best val: ',num2str(min(y_eval))])
else
    disp(['Best val: ',num2str(max(y_eval))])
end
grid on


