#数据可视化
import os
os.system('cls')
# Echarts——pyecharts可视化库

#json数据格式
# 是一种轻量级的数据交换格式，是多种语言间交互与传递数据的一种方式 python->json->C++
# 列表+字典,与python语法相似
import json
data = {
    'name':'张三',
    'age':18,
    'gender':'男',
    'hobby':['篮球','足球','乒乓球']
}
data=json.dumps(data,ensure_ascii=False) #将python数据类型转化为json数据类型
date=json.loads(data) #将json数据类型转化为python数据类型
