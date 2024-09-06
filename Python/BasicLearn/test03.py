#python函数、文件与、异常与模块
import os
os.system('cls')
#函数进阶
"""多个返回值"""
def myfunc(a,b):
    return a+b,a-b #返回多个值,返回元组
print(myfunc(10,20)[0]) #返回元组第一个值
"""多种传参方式"""
myfunc(10,20) #位置传参
myfunc(a=10,b=20) #关键字传参
myfunc(10,b=20) #混合传参
"""默认参数/缺省参数"""
def myfunc(a=0,b=0): #默认参数，默认值都在最后面
    return a+b
print(myfunc(10)) #默认参数
"""不定长参数"""
def myfunc(*args): #*args表示不定长参数，可以传入任意多个参数，返回元组
    print(args)
myfunc(10,20,30,40) #传入多个参数
def myfunc(**kwargs): #**kwargs表示关键字参数，返回字典
    print(kwargs)
myfunc(name='小王',age=12,gender='男') #传入多个关键字参数
"""函数作为参数传入"""
def myfunc1(a,b):
    return a+b
def myfunc2(func,a,b):
    return func(a,b)
print(myfunc2(myfunc1,10,20)) #将函数作为参数传入
"""lambda表达式/匿名函数"""
#lambda 参数列表: 表达式,可以作为函数参数
print(myfunc2(lambda x,y:x+y,10,20))

#文件操作
"""文件打开与关闭"""
#open(file, mode='r', buffering=-1, encoding=None)
#file: 文件路径, mode: 打开模式, buffering: 缓冲区大小, encoding: 编码格式
#r: 只读, w: 写入, a: 追加, b: 二进制, t: 文本, x: 创建新文件
"""
open('Python\BasicLearn\Text.txt','r',encoding='utf-8') #打开文件，如果文件不存在则报错,只读取
open('Python\BasicLearn\Text.txt','w',encoding='utf-8') #打开文件，如果文件不存在则创建,如果文件存在则清空
open('Python\BasicLearn\Text.txt','a',encoding='utf-8') #打开文件，如果文件不存在则创建,如果文件存在则在末尾追加
"""
try:
    txt=open('Python\BasicLearn\Text.txt','r',encoding='utf-8') #打开文件
    print(txt.read(5)) #读取前5个字符文件内容，默认全部,多次调用会从上次读取的位置开始读取
    print(txt.readline()) #读取一行文件内容
    print(txt.readlines()) #读取全部行内容，返回列表
    txt.close() #关闭文件
except FileNotFoundError: #文件不存在时执行
    print('文件不存在')
import time
time.sleep(1) #等待1秒——时间

for i in open('Python\BasicLearn\Text.txt','r',encoding='utf-8'): #打开文件，逐行读取
    print(i)
with open('Python\BasicLearn\Text.txt','r',encoding='utf-8') as txt: #打开文件，自动关闭文件
    print(txt.read()) #读取文件全部内容
"""文件写入"""
txt=open('Python\BasicLearn\Text.txt','w',encoding='utf-8') #打开文件，如果文件不存在则创建,如果文件存在则清空
txt.write('Hello World!\n') #写入文件内容
txt.flush() #刷新文件缓冲区，将内容写入文件
txt.close() #关闭文件
"""文件追加"""
txt=open('Python\BasicLearn\Text.txt','a',encoding='utf-8') #打开文件，如果文件不存在则创建,如果文件存在则在末尾追加
for i in range(10):
    txt.write(f'Hello World! {i}\n') #写入文件内容
txt.flush()
txt.close() #关闭文件
# PS: 写入时用split(' ')转化成列表

#异常与捕获
"""
try:
    可能发生异常的代码
except 异常类型1:
    发生异常类型1时执行的代码
except 异常类型2:
    发生异常类型2时执行的代码
except (异常类型1, 异常类型2):  #通过元组来捕获多个异常
    发生异常类型1或异常类型2时执行的代码
else:
    没有发生异常时执行的代码
finally:
    无论是否发生异常都会执行的代码
"""

#模块
#模块是Python中组织代码的方式，可以将代码分成多个文件，每个文件就是一个模块，模块可以导入其他模块的代码
#[from 模块名] import [模块/变量/函数/类/*] [as 别名] *表示导入模块中的所有内容
import time #导入time模块
import time as t #导入time模块并重命名为t
from time import sleep #从time模块中导入sleep函数, sleep换成*表示导入time模块中的所有内容
time.sleep(1) #调用time模块中的sleep函数
sleep(1) #调用sleep函数
"""自定义模块"""
import test01 #导入自定义模块test01
from test01 import * #从test01模块中导入myfunc函数,会执行test01.py中的代码
if __name__ == '__main__': #如果当前模块是主模块，则执行以下代码，在于其他模块中不会执行
    print('test01') #输出test01
# __all__ = ['myfunc'] # 函数、变量等的列表指定模块中可以被导入的内容，默认为所有内容.__all__即为模块的公共接口*（public）

#python包
# 包是一个包含多个模块的文件夹，文件夹中必须包含一个__init__.py文件，该文件可以是一个空文件，用于标识该文件夹是一个包
# import 包名.模块名 #导入包中的模块
# from 包名 import 模块名 #从包中导入模块,or *表示导入包中的所有模块
# from 包名.模块名 import 函数名 #从包中的模块中导入函数
# 包名.模块名.函数名 #调用函数
# __all__放入__init__.py中，表示该包中的公共接口
"""
安装第三方包
科学计算中常用: numpy
数据分析常用: pandas
图像可视化常用: matplotlib,pyecharts
大数据计算采用: pyspark,hadoop,
人工智能常用: tensorflow,pytorch
命令提示符中->pip install 包名
命令提示符中->pip uninstall 包名
命令提示符中->pip install -i https://pypi.tuna.tsinghua.edu.cn/simple 包名 #使用清华镜像源安装
"""