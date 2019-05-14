#直接在D盘建立一个“test.txt”文件
path="D:\\"
full_path=path+'test.txt'
file=open(full_path,'w')
a='''一张褪色的照片，
    好像带给我一点点怀念。
    巷尾老爷爷卖的热汤面，
    味道弥漫过旧旧的后院；
    流浪猫睡熟在摇晃秋千，
    夕阳照了一遍他咪着眼；
    那张同桌寄的明信片，
    安静的躺在课桌的里面。'''
file.write(a)
file.close()
file=open(full_path,'r')
file.read()
file.close()
file=open(full_path,'r')
file.readline()
file.close
with open(full_path,'r') as file:
		file.readlines()
	
