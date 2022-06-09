git常用命令: 
```
新增文件的命令：git add file或者git add .
提交文件的命令：git commit –m或者git commit –a
查看工作区状况：git status –s
拉取合并远程分支的操作：git fetch/git merge或者git pull
查看提交记录命令：git reflog
通过git pull命令，拉取远程分支上的代码并合并到本地分支，目的是消除冲突
git fetch branch是把名为branch的远程分支拉取到本地；
git pull branch是在fetch的基础上，把branch分支与当前分支进行merge；因此pull = fetch + merge。
如何把本地仓库的内容推向一个空的远程仓库？
git remote add origin XXXX
git push origin master
```