
import os
os.system("cls")
import numpy as np
import math

n =20;

P=np.zeros(n+1)

for k in range(n+1):
    P[k]=math.comb(n,k)*0.5**n

print(P)

# 绘图
import matplotlib.pyplot as plt
plt.plot(P)
plt.show()

CumP=np.cumsum(P)
print(CumP)
lP=CumP.tolist()
lP.append(1)
lP.insert(0,0)
CumP=np.array(lP)

x=np.array(range(n+3))-1
plt.plot(x,CumP)
plt.show()