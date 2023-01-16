# 1. ***自我介绍***
### [这是我的QQ空间，点进来看看吧](https://user.qzone.qq.com/1262990154/main)
##### ~~别忘给我空间点个赞哦~~
---
- *姓名：赵非凡*
- *性别：男*
- *年龄：18*
- *爱好：唱跳rap篮球*
- *专业：物联网*
---
# 2.这是我第一次设计的网页代码 
- ### 这是HTML部分
```
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
<link rel="stylesheet" href="RGB.css">
    <title>RGB</title>
</head>
<body>
    <a href="http://mms0.baidu.com/it/u=1132090007,2582207530&fm=253&app=120&f=JPEG&fmt=auto&q=75?w=503&h=500" target="_blank">LOG IN</a>
</body>
</html>
```
- ### 这是css部分
```
body {
    background-color: black;
}

* {
    margin: 0;
    padding: 0;
}

a {
    text-decoration: none;
    position: absolute;
    left: 50%;
    top:50%;
    transform: translate(-50%,-50%);
font-size: 24px;
background: linear-gradient(90deg,#72D08B,pink,#5191BA);
width: 400px;
height: 100px;
color: aliceblue;
text-align: center;
line-height: 100px;
border-radius: 50px;
background-size: 400%;


}
a::before{
    content: "";
    background: linear-gradient(90deg,#72D08B,pink,#5191BA);
    position: absolute;
    left: -5px;
    right: -5px;
    top: -5px;
    bottom: -5px;
    border-radius: 55px;
    filter: blur(20px);
    z-index:-1;
    background-size: 400%;
}
a:hover{
    animation: sun 8s infinite;
}
a:hoverz::before{
    animation: sun 8s infinite;
}
@keyframes sun{
    100%{
        background-position: -400% 0;
    }
}
```
- ### 展示效果如下图

>![不会用图床所以随便找了个图片哈哈不知道为什么预览页面图片显示不出来]("https://pic3.zhimg.com/v2-58d652598269710fa67ec8d1c88d8f03_r.jpg?source=1940ef5c")
---
# 3. 个人信息
身高|体重|学历|
:-:|:-:|:-:|
170|54|本科
---
# 4.按照流程来评价一下吧
```flow
st=>start: please start your review
op=>operation: Is my first markdown a good try?
cond=>condition: yes or no?
e=>end: thanks
st->op->cond
cond(yes)->e
cond(no)->op
&```