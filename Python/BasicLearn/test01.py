#python逻辑基础
import os 
os.system('cls')
"""清屏"""
# 提示用户输入名字

print("\"Hello\","+" 'world'!")
# name = input(f"请输入您的名字：{123}")
name = "邓宁"

# 打印问候语
print("Hello, " + name , "!")
# 数据类型
print(type(name),type(name) is str) #type()函数可以获取变量的类型
name = 1
print(type(name),type(name) is str)
# 数据类型转换
print(int("123") , str(456) , float(1)) #int()函数可以将字符串转换为整数，str()函数可以将整数转换为字符串，float()函数可以将整数转换为浮点数
print(10**2,10//2,10%3,2/3) #**表示幂运算 //表示整除 %表示取余
# 字符串格式化
print("Hello, %f %s!" % (name,'world'))  # %s 表示字符串 %d 表示整数 %f 表示浮点数
print("Hello, {}{}!".format(name,name)) # {} 表示占位符
print(f"Hello, {name}{name}!") # f"" 表示格式化字符串
# 格式化精度控制
print("Hello, %5d %8.2f!" % (123,123))  # %5d 表示宽度为5的整数,  %-5d 表示左对齐宽度为5的整数 %8.3f 表示宽度为8，精度为3的浮点数
# 比较运算符
print(1==1,1!=1,1>1,1<1,1>=1,1<=1,1 and 0,1 or 0,not 1)
#if语句
import random
num=random.randint(1,10) #生成1-10之间的随机整数
if int(input("输入数字"))<num: #嵌套条件判断
    print("1>0")
    print('此处有缩进')
elif 1==1: #多条件判断
    print("1==1")
    print('此处有缩进+')
else:   #都不满足
    print("1<0")
    print('此处有缩进++')
# 循环语句
n=1
while n<=5: #while循环
    print(n)
    n+=1
for i in range(6): #for循环（数据集）字符串遍历：字符一个一个取出
    print(i)
# break和continue语句 break用于跳出循环，continue用于跳过本次循环
#序列类型，列表、元组、字符串
n=1;m=5;step=1
list=range(n,m,step) #生成n到m-1的整数序列,step为步长
#转义字符与print输出
print("Hello,\nworld!") #\n表示换行
print("Hello,\tworld!") #\t表示制表符（对齐）
print("Hello,\"world\"!") #\"表示双引号
print("Hello,world!",end='\n') #end=''表示不换行,end='\n'表示换行
#函数
def add(a,b): #定义函数
    """两数相加

    Args:
        a (数字): 一个数
        b (数字): 另一个数

    Returns:
        两数相加结果
    """
    return a+b #返回值，若无return语句，则返回None,None等同于False，return语句可以返回多个值，返回多个值时，返回的是一个元组
result=add(1,2) #调用函数
