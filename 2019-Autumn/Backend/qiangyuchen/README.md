# task01 的描述文件
## 学习git的笔记  
>1. 路径的跳转：  
>>- `cd` 文件名：向前跳转到文件夹  
>>- `cd .. `退到上一层  
***
>2. 文件夹的创建及文件夹内文件的创建与修改：  
>>- `mkdir `创建文件夹（等同于右击新建文件夹）  
>>- `vi` 创建，修改文件（例如：txt文件，md文件等等）   
      退出vi模式的方法先按esc，再输入  
 `:wq`[^:wq]:退出并保存]  
 `:q!`[^强制退出不保存]  
 `:q`[^退出不保存]  
>3. 将文件夹变为版本库：`git init`   
*** 
>4. 工作区，暂存区，版本库  
>>- `git add`:将工作区的文件上传到暂存区
>>- `git commit`:将暂存区的文件上传到版本库
>>- `$ git remote add origin git@github.com:michaelliao/learngit.git`:  ***michaelliao***改为自己的GitHub用户名，***learngit***改为想要建立联系的远端版本库名称。注意：要现在GitHub账号中创建一个远端版本库，在用这行代码去建立本地与远端的联系  
>>- `git push`:在建立联系后以后的上传远端数据库可以直接用`git push origin master`来进行。  
>>    - ps: fork后clone下载的版本库，本地与远程版本库已经建立联系，可以直接进行下一步`git push`  
>>- `git status`:查看工作区暂存区状态  
>>    - ps：`git status`显示的代码中会有对于撤销修高的代码提示！！
>>- 场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令`git checkout -- 文件名`。  
>> 场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令`git reset HEAD <文件名>`，文件就回到了场景1，第二步按场景1操作。
>>- `git diff HEAD -- 文件名`:查看工作区（新）与版本库（旧）中的区别。  
>>    - `HEAD`其实是一个指针，指向最新版本。
***  
>5. 分支：
>>- `git branch`:查看分支  
>>- `git branch 分支名`:创建分支  
>>- `git checkout 分支名`或者`git switch 分支名`：切换分支  
>>- `git checkout -b 分支名`：创建并切换到此分支。  
>>- `git merge 分支名`：合并分支。注意：要在master分支进行合并！！！
>>- `git branch -d 分支名`：删除分支。
>>- 合并分支时，加上`--no-ff`参数就可以用普通模式合并，合并后的历史有分支，能看出来曾经做过合并，而`fast forward`合并就看不出来曾经做过合并。（例：`git merge --no-ff -m"第一次合并" dev`）  
***
+ git与markdown在今后会很常用，不需要刻意的背下这些代码，在使用过程中逐渐熟练常用代码即可。  
此处附学习来源以供以后查阅：  
  - `git:`https://www.liaoxuefeng.com/wiki/896043488029600/900388704535136
  - `markdown:`https://www.runoob.com/markdown/md-code.html
## 遇到的问题  
1. 对于删除各个地方（工作区，暂存区，版本库）的文件有些弄不明白。  
2. 能够理解git add 和git commit 的过程，但有些不能明白文件在各个地方的区别。我即使不add和commit，文件也在我的文件夹中，只是不能push。