import os
os.system('cls')

import numpy as np
import random

# 读取excel文件
import pandas as pd
data = pd.read_excel('result1.xlsx')
# 转化为numpy数组
data = np.array(data)
# 矩阵转置
data = data.T



# 折线图
from pyecharts.charts import Line
from pyecharts import options as opts

#数据输入,y为二维数组
x=['一月','二月','三月','四月','五月','六月','七月','八月','九月','十月','十一月','十二月']
y=data.tolist()
y_name=['光学效率','余弦效率','阴影遮挡效率','截断效率','单位面积热功率']
n=len(y)

#得到一个Line对象
line=Line()
#添加x轴数据
line.add_xaxis(x)
#添加y轴数据
for i in range(n):
    line.add_yaxis(y_name[i],y[i],linestyle_opts=opts.LineStyleOpts(width=1, curve=0.1, type_='solid'),label_opts=opts.LabelOpts(is_show=False))
#设置全局配置项
line.set_global_opts(
    title_opts={'text':'不同月份光学效率与热功率', 'left':'center', 'top':'top'},
    toolbox_opts={'show':True},
    datazoom_opts=[{'type':'slider'}], 
    xaxis_opts={'name':'月份'},
    yaxis_opts={'name':'效率/单位面积热功率'},
    legend_opts=opts.LegendOpts(
        is_show=True,
        type_="scroll",
        orient="vertical",
        pos_left="right",
        pos_top="top",
        textstyle_opts=opts.TextStyleOpts(color='black', font_size=15),
    ),
    # visualmap_opts=opts.VisualMapOpts( 
    #     is_show=True,
    # ),

)
#生成图片文件
line.render('plot.html')


