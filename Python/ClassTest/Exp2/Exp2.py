import os
os.system('cls')

# 1、导入 keyword 模块，查看 Python 中的保留字/关键字。
import keyword
print(keyword.kwlist)

# 2、编写程序，输入一个自然数，输出它的二进制、八进制、十六进制形式
num = int(input("请输入一个自然数："))
print("二进制形式：", bin(num))
print("八进制形式：", oct(num))
print("十六进制形式：", hex(num))

# 3、按要求完成以下列表的操作。
str='123456789'
print(str)#输出字符串
print(str[0:8])#输出第一个到倒数第二个的所有字符
print(str[0])#输出字符串第一个字符
print(str[2:4])#输出从第三个开始到第六个的字符(不包含)
print(str[2:])#输出从第三个开始后的所有字符
print(str[1:4:2])#输出从第二个开始到第五个且每隔一个的字符(步长为2)
print(str,str)# 输出字符串两次

# 4、按要求完成以下对列表和元组的操作。
list = ['Chongqing', 'Uni', 1923, 2023]
list[1]='University' #'Uni'改为'University'
list.append('CHINA') # 列表最后添加 ‘CHINA’
print(list[4].lower())# 由列表输出‘china’
len(list)# 输出列表长度
tuple=tuple(list)# 将 list 列表转换为元组
print(type(tuple))# 用 type 打印出元组的类型
if tuple.count('Chongqing') >= 1: # 检查元组中是否有‘Chongqing’
    print('元组中有‘Chongqing’')
else:
    print('元组中没有‘Chongqing’')
    
# 5、请按要求完成以下字典的操作
# 建立一个介绍你自己姓名、年龄、学号、年级、班级（01 班）的字典
dict={'姓名':'严江伟','年龄':'22','学号':'20231071','年级':'2023级','班级':'01 班'}
dict['性别']='男' # 字典中加入性别信息
print(dict['年龄'])# 从字典中输出年龄（字符串类型）
print(dict.pop('学号'))# 从字典中输出学号，并从字典中删除
# 从字典中输出所有 key第三个key
t=0
for key in dict.keys():
    t+=1
    if t==3:
        print(key)
# 更新班级信息，“04 班” 改为 “数据科学 04 班”
dict['班级']='数据科学 04 班'

# 6、编程得到 1-50 内的奇数和与偶数和。
odd_sum = 0
even_sum = 0
for i in range(1, 51):
    if i % 2 == 0:
        even_sum += i
    else:
        odd_sum += i
print("奇数和为：", odd_sum)
print("偶数和为：", even_sum)

# 7、水仙花数是指一个 3 位数，它的每个位上的数字的 3 次幂之和等于它本身
# （例如：1^3 + 5^3+ 3^3 = 153）。输出所有的水仙花数。
Nmax=999
for i in range(100, Nmax+1):
    a = i // 100
    b = (i // 10) % 10
    c = i % 10
    if i == a**3 + b**3 + c**3:
        print(i)

# 8、请利用循环依次对 List 中的每个名字打印出 Hello, xxx!，List=[“Wangyifan”, “Lisa”,”Adam”]。
List=['Wangyifan', 'Lisa','Adam']
for i in List:
    print(f"Hello,{i}!")
    
# 9、创建一个列表，列表中的值分别为 1,5,8,-17,15,25,78,-5,36,50,40 计算列表中
# 前 5 个数和记为 A，计算列表中最后 5 个数的和记为 B，计算 A 和 B 的和并将
# 结果附加到创建列表的末尾，最后打印该列表的所有值。
list1=[1,5,8,-17,15,25,78,-5,36,50,40]
A=sum(list1[:5])
B=sum(list1[-5:])
list1.append(A+B)
print(list1)

# 10、张三是水果超市的老板，各种水果的价格如下（元/斤）：苹果：3.5 梨：4 
# 香蕉：2.5 西瓜：1.5 柚子：3.5 葡萄：4 哈密瓜：3。请你用字典为小明制作一
# 个水果价格表，并可以实现根据水果名称可以查询到这种水果的价格。
dict1={'苹果':3.5,'梨':4,'香蕉':2.5,'西瓜':1.5,'柚子':3.5,'葡萄':4,'哈密瓜':3}
name=input("请输入水果名称(用空格隔开)：")
name=name.split()
for i in name:
    print(f'{i}的价格为{dict1[i]}元/斤')

# 11、基于上题，如果你输入的水果名称不在上述水果类型中，程序就会报错。
# 请你对程序进行修改，实现当输入不存在的水果类型时，程序会输出”抱歉，本
# 店不出售该水果！”。
dict1={'苹果':3.5,'梨':4,'香蕉':2.5,'西瓜':1.5,'柚子':3.5,'葡萄':4,'哈密瓜':3}
name=input("请输入水果名称(用空格隔开)：")
name=name.split()
for i in name:
    if i in dict1:
        print(f'{i}的价格为{dict1[i]}元/斤')
    else:
        print(f'抱歉，本店不出售{i}！')
        continue

# 12、编写函数，实现输入 n 的值，求出 n 的阶乘。然后调用此函数计算 1! +2！
# +3！+……10！的结果，输出到屏幕上。
def factorial(n):
    if n==0:
        return 1
    else:
        return n*factorial(n-1)
print(sum(factorial(i) for i in range(1,11)))
# 13、自行创建一个包含数字、列表、字典、元祖的嵌套列表，对比使用赋值（“=”）
# 和拷贝（“copy”）方法的差异。
# 赋值（=）：当你使用赋值操作符将一个对象赋值给另一个变量时，实际上是
# 将对象的引用赋值给新的变量。这意味着两个变量指向同一个对象。对其中一
# 个变量的修改会影响到另一个变量。

# 拷贝（copy()）：当你使用拷贝方法（如 copy() 或 deepcopy()）时，会
# 创建一个新的对象，并将原始对象的内容复制到新对象中。这意味着两个对象
# 是独立的，对其中一个对象的修改不会影响到另一个对象。
LIST=[1,2,3,[4,5,6],{'year':2023,'month':10,'day':1},(7,8,9)]
LIST1=LIST.copy()
LIST1[1]=999
print('copy的前后差异：')
print(LIST)
print(LIST1)

LIST2=LIST
LIST2[1]=999
print('赋值的前后差异：')
print(LIST)
print(LIST2)

# 但是，copy之后的字典和元组都只copy了引用，所以修改后两个列表的字典和元组都发生了变化
LIST=[1,2,3,[4,5,6],{'year':2023,'month':10,'day':1},(7,8,9)]
LIST1=LIST.copy()
LIST1[4]['year']=2024
print('copy的前后差异：')
print(LIST)
print(LIST1)

LIST2=LIST
LIST2[4]['year']=2024
print('赋值的前后差异：')
print(LIST)
print(LIST2)