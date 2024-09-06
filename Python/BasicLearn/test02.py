#python数据容器
import os
os.system('cls')
# 数据容器：list列表、tuple元组、str字符串、set集合、dic字典
# list列表
list1 = [1, 2, 3, 4, 5]
print(list1)
list2 = [1, 'a', True]
for i in range(3):
    temp = list2[i] # 列表的索引从0开始，反向索引从-1开始，嵌套列表用list2[0][1]表示
    print(temp,'in',list2,'type is',type(temp))
"""引用列表的复数元素"""
print(list1[0:3:1]) # 切片，从索引0开始，到索引3（不包括3）结束，步长为1,步长可为负数，表示从后往前取
print(list1[1::2]) # 从索引1开始，到列表末尾结束，步长为2
#  :用于提取列表中的所有元素。:: 用于提取列表中的部分元素，可以指定起始索引、结束索引和步长。都表示提取方向
print(list1[-2::]) # 从索引-2开始，到列表末尾结束，步长为1
print(list1[::-1]) # 从列表末尾开始，到索引0结束，步长为-1，即反向提取列表中的所有元素
print(list1[::2]) # 从索引0开始，到列表末尾结束，步长为2
print(list1[::]) # 获取列表所有元素
print(list1[3:]) # 从索引3开始，到列表末尾结束，步长为1
print(list1[:3]) # 从索引0开始，到索引3结束，步长为1
"""列表的常用方法"""
print('index(1):',list1.index(1)) # 查找元素在列表中的索引
len(list1) # 获取列表长度
max(list1) # 获取列表中最大值
min(list1) # 获取列表中最小值
sum(list1) # 获取列表中所有元素的和
list1.append(6) # 在列表末尾添加元素
list1.insert(0, 0) # 在指定位置插入元素
len(list1) # 获取列表长度
list1.remove(1) # 删除第一个指定元素
del list1[0] # 删除指定索引的元素
print('pop:',list1.pop(0)) # 删除指定索引的元素,并返回该元素的值
list1.clear() # 清空列表
list1.sort(reverse=True) # 排序，默认升序，reverse=True为降序
list1.reverse() # 反转列表
list1.copy() # 复制列表
list1.count(1) # 统计元素在列表中出现的次数
list1.extend([6,7,8])# 在列表末尾添加另一个列表中的所有元素
print('result:',list1)
# tuple元组 ，元组中的元素不可修改
tuple1 = (1, 2, 3, 4, 5)
print(f"元组：{tuple1}")
"""tuple1同理于list，只是元组中的元素不可修改"""
# str字符串
str1 = 'hello world'
print(f"字符串：{str1}")
print(str1[0:5]) # 字符串的索引从0开始，反向索引从-1开始，嵌套字符串用str1[0][1]表示
"""字符串同list一样,也有切片、索引、常用方法等操作,只是字符串是不可变的"""
list3=list(str1) # 将字符串转换为列表,此时可以修改列表中的元素
print('替换:',str1.replace('world','python')) # 输出替换字符串中的子串
print('分割:',str1.split(' ') )# 将字符串按照指定的分隔符分割成多个字符串并存入列表
print('端去除:',str1.strip("hwle od") ) # 有输入参数时,去除字符串两端的指定字符(默认空格).rstrip()去除右边的空格,lstrip()去除左边的空格
# set集合，集合中的元素无序且不重复
set1 = {1, 2, 3, 4, 5}
set() # 创建一个空集合
print(f"集合：{set1}")
"""集合的常用方法"""
set1.add(0) # 添加元素
set1.remove(1) # 删除元素
set1.pop() # 随机删除一个元素,并返回该元素的值
set1.clear() # 清空集合
set1.update({7,8,9}) # 添加多个元素
set1.discard(2) # 删除元素，如果元素不存在，则不执行任何操作

len(set1) # 获取集合长度
set1.union({7,8,9}) # 返回两个集合的并集
set1.difference({1,2,3}) # 返回两个集合的差集
set1.intersection({1,2,3}) # 返回两个集合的交集
set1.symmetric_difference({1,2,3}) # 返回两个集合的对称差集
print(set1.isdisjoint({1,2,3})) # 判断两个集合是否没有交集
print(set1.issubset({1,2,3})) # 判断一个集合是否是另一个集合的子集
set1.issuperset({1,2,3}) # 判断一个集合是否是另一个集合的超集
# dic字典，字典中的元素以键值对的形式存储，键值对之间用冒号分隔，键值对之间用逗号分隔，整个字典用大括号括起来
#键值对key-value,key是唯一的，value可以重复
dic1 = {'name': 'Tom', 'age': 18, 'gender': 'male'}
print(f"字典：{dic1}")
"""字典的索引"""
dic1['name'] # 获取指定键的值
dic1.get('name') # 获取指定键的值，如果键不存在，则返回None
"""字典嵌套"""
dic2 = {'name': 'Tom', 'age': 18, 'gender': 'male', 'hobby': {'music': 'pop', 'sport': 'basketball'}}
print(dic2['hobby']['music']) # 获取嵌套字典中的值
"""字典的常用方法"""
dic1['height']= 180 # 添加键值对,如果键已存在，则更新键对应的值
dic1.update({'name': 'Jerry'}) # 更新字典中的键值对，如果键不存在，则添加键值对
dic1.pop('name') # 删除指定键的键值对,并返回该键对应的值
dic1.popitem() # 删除字典中的最后一个键值对，并返回该键值对
dic1.clear() # 清空字典
dic1={'name': 'Tom', 'age': 18, 'gender': 'male'}

len(dic1) # 获取字典长度
print(dic1.keys()) # 获取字典的所有键
print(dic1.values()) # 获取字典的所有值
print(dic1.items()) # 获取字典的所有键值对
for key, value in dic1.items():
    print(key, value) # 遍历字典的键值对
for key in dic1: # or for key in dic1.keys():
    print(key) # 遍历字典的键



      
