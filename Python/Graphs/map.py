# 地图
import os
os.system('cls')
from pyecharts.charts import Map
from pyecharts import options as opts

map = Map()
data = [
    ("广东省", 1000),
    ("山东省", 900),
    ("江苏省", 400), 
    ("浙江省", 100), 
    ("湖南省", 60),
    ("上海市", 500),
    ("云南省", 400),
    ("四川省", 900),
    ("河南省", 3000),
]
map.add("测试地图", data, "china")
map.set_global_opts(
    title_opts=opts.TitleOpts(title="Map-中国地图"),
    visualmap_opts=opts.VisualMapOpts(
        is_show=True,
        is_piecewise=True,
        pieces=[
            {"min": 0, "max": 9, "label": "0-9", "color": "#CCFFFF"},
            {"min": 10, "max": 99, "label": "10-99", "color": "#FFFF99"},
            {"min": 100, "max": 499, "label": "100-499", "color": "#FF9966"},
            {"min": 500, "max": 999, "label": "500-999", "color": "#FF6666"},
            {"min": 1000, "max": 4999, "label": "1000-4999", "color": "#CC3333"},
            {"min": 5000, "label": "5000以上", "color": "#FF3333"},
        ]
        ),
)

# 生成html文件
out_path='Python\Graphs\Temp'
map.render(out_path+'\\map.html')
