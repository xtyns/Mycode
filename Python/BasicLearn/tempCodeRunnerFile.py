import os
os.system('cls')

from math import *
import numpy as np
import pandas as pd
####### Pandas #######
## 数据处理与分析库 ##
# Pandas 的主要数据结构是 Series （一维数据）与 DataFrame（二维数据）
# Pandas 是基于 NumPy 的，所以 Pandas 的数据结构是建立在 NumPy 的数组之上的

frame =pd.DataFrame(np.arange(12.).reshape((4,3)),columns=['col1','col2','col3'],index=['Mary','Aliee','Tom','Mike'])
series2=pd.Series(range(3),index=['b','e','f'])