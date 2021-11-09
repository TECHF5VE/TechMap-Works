# 进入TechF5ve首次作业记录

## 学习Git和Github的使用

​      我之前接触过Github,但也只是在Github上看看项目代码和各种教程，并没有过自己创建过repository，也没有仔细研究过git，甚至以为Git和Github是一回事情。总的来说，之前我没有系统的学习过Git和Github,但是经过这次比较系统的学习之后，我开始慢慢熟悉Git和Github的工作方式。

 当然学习过程中我也遇到了一些问题：

### **Q1.国内登录github不稳定怎么办？**

​    国内github的DNS污染太严重，不采取任何措施可能会连不上github

​    <u>***解决方法：***</u>

  **1.1修改host：**

   **获取所有github网址的IP地址：**

   https://github.com.ipaddress.com/
   https://fastly.net.ipaddress.com/github.global.ssl.fastly.net
   https://github.com.ipaddress.com/assets-cdn.github.com

   **windows的hosts路径：**

   <u>C:\Windows\System32\drivers\etc\hosts</u>

   **hosts配置（可自行修改）：**

   <u>140.82.114.4 github.com</u>
   <u>199.232.5.194 github.global.ssl.fastly.net</u>
   <u>185.199.108.153 assets-cdn.github.com</u>
   <u>185.199.109.153 assets-cdn.github.com</u>
   <u>185.199.110.153 assets-cdn.github.com</u>
   <u>185.199.111.153 assets-cdn.github.com</u>

   **刷新DNS缓存：**

   键盘 wind + R 输入cmd 回车
   键入`ipconfig /flushdns`

  **1.2.使用VPN** **~~（别举报我）~~：**

​    我用的是Ghelper，基本没有什么大问题，就是clone远程库到本地git的时候有些不稳定，可能会报错，只要多试几次就行了

### **Q2.不熟悉Git操作怎么办？**

​    <u>***解决方法：***</u>

   1.不能怕麻烦，多操练，删了装，装了删，熟悉流程

   2.熟悉常用的十几个git指令

   3.翻翻Git官方文档or自己查阅资料

## 个人简介

   **姓名：**丁晨凯 ~~aka.C1ri007~~

   **专业/班级：**计算机 2001

   **爱好:**足球/烘咖/游戏

————————————————————————————分割线———————————————————————————————

以下是一些想说的话：

​        本菜鸟很荣幸能进入TechF5ve这个对计算机技术和设计痴迷的一个团体，我希望自己能在这样一个大佬云集的团队里不断学习技术，把大佬们作为目标，不断提升自己的水平，希望自己也能为TechF5ve做出一点贡献.

​                                                                                                             END