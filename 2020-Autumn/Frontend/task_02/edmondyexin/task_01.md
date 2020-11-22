# task_01 致敬页

**Build a Tribute Page**

内容

* 了解和使用基本的html语法
* 使用部分元素构建页面
* 了解ID选择器 类选择 标签选择器的使用
* 了解a标签的使用
* 了解input标签的使用
* 了解表单元素的使用

[项目地址]()

## HTML

### 基础概念

是一种超文本语言，由不同的元素来描述，并可嵌套文字、图片等信息呈现到网页上

### 基础结构

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <title>Title</title>
    <link rel="stylesheet" href="./style/index.css" />
</head>

<body>
 <p>
     html
 </p>
</body>

</html>
```

* ```<!DOCTYPE> ``` 声明文档类型 后面`html`表示改文档为`html`类型，表示支持`html`类型的功能特性等
* `html`根元素 
  * 一般会通过声明语言类型来方便引擎的搜索

* `head` 头部元素 用于保存元数据
  *  元数据 也就是`meta` 这个标签中包含的一些信息
     * `charset="utf-8" `表示文件的编码类型为`utf-8`，这样生产的`html`网页才可以正确的生成文字
     * `title` 表示网站的标题
     * `link` 一般用来导入`css`样式 `rel`关联一个样式表  `href`表示要关联文件的地址

### 表单元素

常见表单元素如下

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8"/>
        <title>网页标题</title>
    </head>
    <body>
        <form method="POST" action="#">
            <div>
                <input type="text"/> 
            </div>
            <div>
                <input type="text" placeholder="Account">
            </div>
            <div>
                <input type="password" placeholder="Password">
            </div>
            <div>
                <input type="text" disabled/> 
            </div>
            <div>
                <button>login</button>
            </div>  
        </form>
    </body>
</html>   

### 选择器

* 类型 选择 ID

* ```html
  tag_name{
  }
  
  .class_name{
  }
  
  @id{
  }
  ```

* 标签选择器

  * ```html
    tag[attribute_name]{
    }
    ```

* 伪类

  * ```
    tag_name::after{
    }
    ```

* 全局选择器 

  * 选择文档所有内容

  * ```html
    *{
    }
    ```

    

* 字符串匹配选择器

  * ```html
    tag[arttr^="match_str"] <!-- 匹配一个开头为match——str的属性元素-->
    
    tag[arttr$="match_str"] <!-- 匹配一个开头为match——str的属性元素-->
    
    tag[arttr*="match_str"] <!-- 匹配一个开头为match——str的属性元素-->
    
    
    ```

#### 关系选择器

##### 后代选择器

空格字符分开

##### 子代关系选择器

`>`

##### 邻接兄弟

`+`

