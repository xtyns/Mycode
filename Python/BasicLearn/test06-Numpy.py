import os
os.system('cls')

# jupter notebook-> shift+Enter 快速执行
####### Math #######
from math import *
# 数学的基本函数，如sin、cos、tan、log、ceil、factorial、pow

####### Numpy #######
# Numerical python 
# # SciPy-Scientific Python (统计计算/科学计算)
# # Matplotlib-矩阵绘图库
import numpy as np
### array.* 操作
## array 的变换操作
Marray = np.array([1, 2, 3, 4]) # list2array
Mlist=Marray.tolist() # array2list

## array 的基本操作
# 矩阵的初始化，1、list2array 2、.arange 3、.zeros 4、.ones 5、.eye 6、.empty
# reshape-矩阵变形,shape-矩阵形状,ndim-矩阵维度,size-矩阵元素个数
a = np.arange(15).reshape(3, 5) # arange(15.),表示浮点型
a.size
a.ndim
a.shape

a.itemsize # 每个元素的字节数
a.dtype.name # 矩阵元素的数据类型
a.astype(float) # 转换数据类型

## array的运算-一般是点运算
a = np.array([pi, 2, 3, 4])
b = np.array([5, 6, 7, 8])
c = a + b
print(c)
c = np.add(a, b)
print(c)
c=np.abs(a)
print(c)
c=a**2+a**b
print(c)
# array的数学运算
# np.sin, np.cos, np.tan, np.log, np.ceil, np.factorial, np.power
print(np.sin(a))
print(np.cos([0,1]))
print(np.cos(1+np.array([1,2])))
# array的统计运算
# np.sum, np.mean, np.std, np.var, np.min, np.max, np.argmin, np.argmax
# np.average, np.median, np.cumsum, np.cumprod, np.diff, np.nonzero
# 分别是：求和、均值、标准差、方差、最小值、最大值、最小值索引、最大值索引、
# 平均值、中位数、累计和、累计积、差分、非零元素索引
import matplotlib.pyplot as plt
x = np.linspace(start=-10, stop=10, num=101)
plt.plot(x, np.absolute(x))
plt.show()
# array的索引和切片
A=np.arange(9).reshape(3,3)
print(A)
print(A[[0,2],[0,2]]) # 对应点索引
print(A[[0,2],:2]) # 切片索引
# 其他
line=np.linspace(start=0, stop=10, num=1000)
print(line)

# 计算矩阵的逆
A = np.array([[1, 2], [3, 4]])
A_inv = np.linalg.inv(A)

print(A_inv)