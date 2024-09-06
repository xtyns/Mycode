function l = List_Length(S,d)
n=length(S);
l=0;
for i =1:n-1
    l=l+d(S(i),S(i+1));
end

end

