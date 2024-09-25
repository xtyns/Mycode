import os
os.system('cls')

from math import *
import numpy as np
import pandas as pd
# from pandas import *
####### Pandas #######
## 数据处理与分析库 ##
# Pandas 的主要数据结构是 Series （一维数据）与 DataFrame（二维数据）
# Pandas 是基于 NumPy 的，所以 Pandas 的数据结构是建立在 NumPy 的数组之上的

# series(一维),DataFrame(二维)
a = pd.Series([1,2,3,4,5],index=['a','b','c','d','e'])

print(a)
print(a.values)
print(a.index)
print(a[1])
print(a[1:3])

# DataFrame的数据输入可以为字典、列表、numpy数组
data = {'Name': ['Alice', 'Bob', 'Charlie'], 'Age': [25, 30, 35]}
df = pd.DataFrame(data,index=['a','b','c'])

print(df)
print(df['Name'])
print(df['Name'][1])
print(df['Name'][1:3])
print(df.loc['a'])
print(df.loc['a':'b'])
print(df.iloc[1])
print(df.iloc[1:3])
print(df.loc['a':'b','Name'])

# 文件读取/数据输入
Xdata = pd.read_excel('附件.xlsx') # DataFrame
# Xdata = pd.read_csv('附件.csv')
# Xdata = pd.read_json('附件.json')
# Xdata = pd.read_html('附件.html')
# Xdata = pd.read_sql('sql语句',数据库连接)

# 数据输出
Xdata.to_excel('附件.xlsx')
print(Xdata)
# 打印1到一百的偶数
print([i for i in range(1,101) if i%2==0])
