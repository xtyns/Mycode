#### 第十一题--C++与python的区别
# Python 使用内置的print函数来输出,不需要
# 指定格式化类型。可以直接将变量或常量作为
# 参数传递给print函数。Python还提供了多种
# 字符串格式化方法,使得输出更为灵活和直观。
print("hello world")


### 数据类型
# 整数类型
count = 10  
# 浮点类型
average = 89.5  
# 字符类型（实际上是长度为1的字符串）, 
grade = 'A' 
# 字符串
name = "Alice"  
# 布尔类型
is_passed = True
print("Count:", count)
print("Average:", average)  
print("Grade:", grade)  
print("Name:", name) 
print("Passed:", is_passed)


### 变量类型的动态变化
# 初始赋值为整数
variable=42
print(variable, type(variable))
# 将变量类型改为浮点数
variable=42.0
print(variable, type(variable))


### 循环结构
# for循环
for i in range(5):
    print("Number:",i)
# while循环
i=0
while i<5:
    print("Number:",i)
    i+=1
# 迭代字符串列表
text="hello"
for char in text:
    print(char)
#迭代列表
numbers=[10,20,30,40,50]
for number in numbers:
    print("Number:",number)
    
 
### 数组和列表   
#定义列表
numbers=[1,2,3,4,5]
#直接访问列表元素
for i,number in enumerate(numbers):
    print(f"Element {i}: is {number}")
#添加元素
numbers.append(6)
#删除指定位置元素
del numbers[2]
#插入元素
numbers.insert(2,7)
#输出列表
print("Updated list:",numbers)


### 函数定义
#函数定义
def add(a,b):
    return a+b
#函数调用
result=add(2,3)
print("Result:",result)
#带有默认参数的函数
def greet(name,message="hello"):
    print(f"{message}, {name}!")
greet("Alice")
greet("Bob","welcome")
#带有可变参数的函数
def sum_all(*args):
    total=sum(args)
    print("Total:",total)
sum_all(1,2,3,4,5)


##### 第十二题--在 IDLE 中输入简单的代码，进行简单的编程实验，并掌握 Python 中的运算符与内置函数


"""程序一: 编写程序，输入任意大的自然数，输出各位数字之和。"""
num=input('输入数据源:')
print(sum(map(int, num)))
"""程序二：输入一个三角形的三边长，求三角形面积。"""
from math import sqrt 
a,b,c=input('输入三角形第一条边长度:'),input('输入三角形第二条边长度:'),input('输入三角形第三条边长度:')
a,b,c=int(a),int(b),int(c)
p=(a+b+c)/2
area=sqrt(p*(p-a)*(p-b)*(p-c))
print(f'三角形面积为{area}')
"""程序三：写程序，使用 while 计算 1 到 100 的总和"""
sum_num=0
i=1
while i<=100:
    sum_num+=i
    i+=1
print(f"结果为{sum_num}")
