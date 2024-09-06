function [x,fval,exitflag]=Branch(filename,x0,A,b,Aeq,beq,lb,ub,Nonfname,code)
%该函数为分支定界法的主要函数，进行分支定界的迭代运算
options=optimset('display','off');
[x,fval,exitflag]=fmincon(filename,x0,A,b,Aeq,beq,lb,ub,Nonfname,options);
n=length(lb);

if exitflag<0   %可解性检验
    disp(['code-',code,' this branch cannot find out vaild x']);
    fval=inf;
    return;
end

test=0;i=1;
while i<=n  %整数查询与新的上下界赋值
 if x(i)~=floor(x(i))
    ub0=ub;
    ub0(i)=floor(x(i));
    lb0=lb;
    lb0(i)=ceil(x(i));
    test=i;
    i=n;
 end
 i=i+1;
end

if test==0  %如果全部为整数解，则返回有效解
    disp(['code-',code,' find out a vaild x. ','fval= ']);
    disp(fval)
    return;
end

%下分支
[x1,fval1,exitflag1]=Branch(filename,x0,A,b,Aeq,beq,lb,ub0,Nonfname,[code,'0']);

%上分支
[x2,fval2,exitflag2]=Branch(filename,x0,A,b,Aeq,beq,lb0,ub,Nonfname,[code,'1']);

if fval1>=fval2
    fval=fval2;
    x=x2;
    exitflag=exitflag2;
else
     fval=fval1;
    x=x1;
    exitflag=exitflag1;
end


end
