# task_02  调查表格

# 

## [项目地址](https://codepen.io/edmondyexin/details/OJXBdeJ)

## 收获

* 总结
  * 每次写css就觉得自己是一个傻子
  * 对于响应式布局的使用还不够熟悉 对于各种百分比的元素使用不是很熟练
  * 对于简写形式进行样式的重叠并没有做的很好
* 任务链接：https://codepen.io/edmondyexin/pen/OJXBdeJ
* [link](https://codepen.io/edmondyexin/pen/OJXBdeJ)

了解css的常见元素和使用

#### 伪类/伪元素

* 伪类

  * ```html
    tag:nth-child(n){
    
    tag:first-child{
    }
    <!-- 前面用:-->
    ```

* 伪元素（常见）

  * ```html
    tag::after{
    content:'';
    display:blcok;
    }
    
    tag::before{
    content:'';
    }
    
    tag::first-line{
    }
    tag::nth-child(`${num}`){
    
    }
    ```

### 盒模型

* 组成

  * Content Box	对应是设置的宽度和高度
  * Padding box
  * Border box
  * Margin box 空间创建的异常来源：外边距折叠
    * https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Box_Model/Mastering_margin_collapsing

  **盒模型的大小是content box 再加上padding和border 决定的**

  虽然margin不会计入盒模型的大小，但是会在页面占据的空间，也就是盒子的外部空间

  如果我们需要得到content-box的大小，通过设置

  ```html
  .box{
  box-sizing:border-box;
  }
  ```

  

#### Block box

* 特点
  * 盒子在内联1方向山扩展并占据父容器的所有可用空间
  * 自动占据一行
  * 可以设置width和height属性
  * padding margin border有效 且会占据空间

#### Inline box

* 不换行
* width height不可设置 靠内容填充
* margin的上下不可设置 

#### display：inline-block

* usage：一个可以设置宽高 margin 上下的内联元素

### 常见问题处理

* background url设置背景图片处理

  * 

  * ```css
    background:url("https://w.wallhaven.cc/full/vg/wallhaven-vg7lv3.jpg");
    //根据需求设置宽度和长度
        width: 100%;
        height: 100%;
    // 根据实际查看自己所想要的效果
        background-size: cover;// background-size:100% 100%;
    ```

  * 

* 左右分块

  * float:left/right

  * 清除浮动

    * 相应的元素添加伪类

    * ```css
      ::after{
          content="";
          clear:both;
      }
      ```

* 优先级判定

  * z-index：设置相当于PS中改变图层的先后顺序

* 元素居中

  * 对于含右.container 的子元素
    * `test-align:center`
  * 块元素居中对齐
    * `margin: 0 auto;`
  * 防止图片无法加载等异常，显示相对于的文本信息
    * `<img alt="#">`

* ### 颜色设计

  * 互补色

    * 色盘相对

    * | color             | 对应color           |
      | ----------------- | ------------------- |
      | 橙色`#FF7D00`     |                     |
      | 蓝绿色`#00FFFF`   |                     |
      | 数枚红`#FF007D`   |                     |
      | 红色(`#FF0000`)   | 蓝绿色（`#00FFFF`） |
      | 绿色（`#00FF00`） | 品红色（`#FF00FF`)  |
      | 蓝色（`#0000FF`） | 黄色（`#FFFF00`）   |
      |                   |                     |

    * 线性渐变

      * `backgroun:linear-gradinet(gradient_direction,color1,color_2,.. othrt color)`

  ## 字体颜色

  正文文本的对比度设置在`4.5：1`比较合适（对比度：颜色的相对亮度值）

  ## 响应式布局

  由于移动端和PC端以及各种手机的屏幕都是不一样的我们通常一个页面会根据页面的大小会显示不一样的界面

  | 范围（px） | 适用对象          |
  | ---------- | ----------------- |
  | <=600      | 超小型设备 手机   |
  | 600-768    | 纵向平板和大手机  |
  | 768-992    | 中型设备 横向平板 |
  | 992-1200   | 笔记本/台式       |
  | >1200      | 超大型设备        |

  * **注意max-width大的断点放上面，min-width小断点放上面**

  ### 内部图片自适应布局

  ```css
  img{
      max-width:100%;
      // 用最大宽度适应父亲元素的宽度
      display:block;
      // 将其更改为块级元素 
      height:auto;
      // 保持图片原来的宽高比例
  }
  ```

  文本大小设置

  * em
  * px

  视窗单位做响应式排版

  * vw  视窗宽度
  * vh   视窗高度
  * vmin 其中较小
  * vmax 其中较大尺寸