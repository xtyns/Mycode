LIST=[1,2,3,[4,5,6],{'year':2023,'month':10,'day':1},(7,8,9)]
LIST1=LIST.copy()
LIST1[1]=2024
print('copy的前后差异：')
print(LIST)
print(LIST1)