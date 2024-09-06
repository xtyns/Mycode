#类与对象
import os
os.system("cls")

#类定义
class Student:
    # 类属性
    name = None
    age = None
    gender = None
    # 类方法/类成员
    def say_hi(self): #def 方法名(self，参数1，参数2，...): #self表示类的实例
        print("你好，我叫%s" % self.name)
#对象定义
# stu1 = Student()
