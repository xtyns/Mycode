function [X, x0] = K_means(X, x0)
%该函数根据每个聚类对象的均值(中心对象),计算每个对象与这些中心对象的距离;
% 并根据最小距离重新对相应对象进行划分
% 再重新计算每个(有变化)聚类的均值(中心对象)
[n,m]=size(X);
[k,m]=size(x0);
list=zeros(n,1);counts=zeros(k,1); %分类计数器
for i=1:1:n %距离分类器
    for j=1:1:k
    d(j)=norm(X(i,:)-x0(j,:));
    end
    md=min(d);
    for j=1:1:k
        if md==d(j) 
            list(i)=j;
            counts(j)=counts(j)+1;
        end
    end
end

x1=zeros(k,m);
for i=1:1:k %类取平均值
    for j=1:1:n
        if list(j)==i
            x1(i,:)=x1(i,:)+X(j,:);
        end
    end
    x1(i,:)=x1(i,:)/counts(i);
end
%迭代
if x1==x0
    x0=x1;
    disp('分类表（表示每一样本的所属类别）：'),disp(list);
    disp('计数表（表示每一类别所含样本数目）：'),disp(counts);
else
  [X, x0] = K_means(X, x1);
end
