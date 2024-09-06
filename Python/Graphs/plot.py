# 折线图
import os
os.system('cls')
from pyecharts.charts import Line
from pyecharts import options as opts

#数据输入,y为二维数组
x=['衬衫','羊毛衫','雪纺衫','裤子','高跟鞋','袜子']
y=[[5,20,36,10,75,90],[15,10,26,15,75,40],[25,30,36,20,75,80]]
y_name=['商家A','商家B','商家C']
n=len(y)

#得到一个Line对象
line=Line()
#添加x轴数据
line.add_xaxis(x)
#添加y轴数据
for i in range(n):
    line.add_yaxis(y_name[i],y[i],linestyle_opts=opts.LineStyleOpts(width=1, curve=0.1, type_='solid'))
#设置全局配置项
line.set_global_opts(
    title_opts={'text':'不同商家的销售情况','subtext':'月度总结', 'left':'center', 'top':'top'},
    toolbox_opts={'show':True},
    datazoom_opts=[{'type':'slider'}], 
    xaxis_opts={'name':'商品种类'},
    yaxis_opts={'name':'销售量'},
    legend_opts=opts.LegendOpts(
        is_show=True,
        type_="scroll",
        orient="vertical",
        pos_left="right",
        pos_top="top",
        textstyle_opts=opts.TextStyleOpts(color='black', font_size=15),
    ),
    visualmap_opts=opts.VisualMapOpts( 
        is_show=True,
    ),

)
#生成图片文件
out_path='Python\Graphs\Temp'
line.render(out_path+'\\plot.html')


