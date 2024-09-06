# 柱状图
import os
os.system('cls')
from pyecharts.charts import Bar
from pyecharts import options as opts

# 输入x,y数据源
x=['衬衫', '羊毛衫', '雪纺衫', '裤子', '高跟鞋', '袜子'] 
y=[5, 20, 36, 10, 75, 90]
time_list=list(range(1998,2001))
n=len(time_list)

# 创建bar对象
bar=Bar()
bar.add_xaxis(x)
bar.add_yaxis('商家', y,label_opts=opts.LabelOpts(position='right'))

bar.set_global_opts(
    title_opts=opts.TitleOpts(title='主标题', subtitle='副标题'),
    xaxis_opts=opts.AxisOpts(name='销售量'),
    yaxis_opts=opts.AxisOpts(name='货品')
    
)
bar.reversal_axis()
# 生成bar
out_path='Python\Graphs\Temp'
bar.render(out_path+'\\bar.html')


