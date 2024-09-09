import os
os.system('cls')

import numpy as np
import random

# 读取excel文件
import pandas as pd
data = pd.read_excel('city_axis.xlsx')
# 转化为numpy数组
data = np.array(data)
data = data[:,1:]

# 相关参数
T0=200 # 初始温度
Tf=0.01 # 终止温度
Marcov_length=50000 # 马尔可夫链长度
alpha=np.power(Tf/T0,1/Marcov_length) # 降温系数
# 初始化
l=len(data)
Path0=np.arange(l)

# 计算出距离矩阵
dist=np.zeros((l,l))
for i in range(l):
    for j in range(l):
        dist[i,j]=np.sqrt((data[i,0]-data[j,0])**2+(data[i,1]-data[j,1])**2)
# 定义扰动函数
def perturbation(Path):
    path=np.copy(Path)
    if random.random()>0.5:
        # 二交换
        get_num=np.random.randint(0,l-1,2)
        i,j=get_num[0],get_num[1]
        path[i],path[j]=path[j],path[i] 
    else:
        if random.random()>0.5:
            # 三交换
            get_num=np.random.randint(0,l-1,size=3)
            get_num.sort()
            A=path[get_num[1]+1:get_num[2]+1]
            B=path[get_num[0]:get_num[1]+1]
            path[get_num[0]:get_num[2]+1]=np.concatenate((A,B))
        else:
            path=np.random.permutation(path)
    return path
# 定义根据路径列表计算距离的函数
def get_dist(Path):
    dist_sum=0
    for i in range(l-1):
        dist_sum+=dist[Path[i],Path[i+1]]
    return dist_sum


# 开始退火模拟
t=T0
Path=Path0
val=[]
num=0
while t>Tf:
    Path_new=perturbation(Path)
    delta_dist=get_dist(Path_new)-get_dist(Path)
    if delta_dist<0:
        Path=Path_new
    else:
        p = np.exp(-delta_dist/t)
        if random.random()<p:
            Path=Path_new
    t=t*alpha
    val=val+[get_dist(Path)]
    num+=1
    print(f'运行次数：{num}.当前值:{get_dist(Path)}')
    
# 绘制最终路线图
import matplotlib.pyplot as plt
plt.plot(data[Path,0],data[Path,1])
plt.scatter(data[Path,0],data[Path,1])
plt.title('My Plot')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.show()



# 输出最优路径
print(Path)
# 输出最优路径长度
print(get_dist(Path))
