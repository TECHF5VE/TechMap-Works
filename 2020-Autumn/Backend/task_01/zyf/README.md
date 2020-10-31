+ 创建空目录		mkdir xx
+ 进入目录			cd xx
+ 查看当前路径		pwd
+ 把当前目录变成仓库		git init
+ 把文件添加到暂存区 		git add xx
+ 把暂存区文件提交到仓库	git commit -m "备注"
+ 查看提交记录		git log
+ 查看操作记录		git reflog
+ 查看仓库状态		git status
+ 查看工作区的最新库的区别	git diff HEAD --xx
+ 丢弃工作区的修改(删除)	git checkout -- xx
+ 撤回暂存区的文件到工作区	git reset HEAD xx
+ 仓库退回上一个版本		git reset --hard HEAD^
+ 回到某个指定版本		git reset --hard 版本号的几位
+ 删除版本库中的文件		git rm xx
+ (删除完之后需要提交仓库)
+ 创建SSH Key		ssh-keygen -t rsa -C "youremail@example.com"
+ (github添加SSH)
+ 关联本地仓库		git remote add origin git@github.com:id/xx.git
+ 创建一个分支		git branch -M xx
+ 把本地仓库提交到远程仓库	git push origin xx
+ clone一个库到本地		git clone URL

**20-软件-张依凡**
