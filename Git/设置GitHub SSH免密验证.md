SSH协议是一种常见的登录协议，github除了支持HTTPS协议同步仓库之外，也支持SSH。

使用这个协议的好处是：我们不用push或者pull代码时每次输入账号密码。

[使用SSH连接到GitHub](https://docs.github.com/cn/authentication/connecting-to-github-with-ssh)

**步骤**

1.生成密钥对

公钥是上传到github服务器上的，私钥是保存在本地的。

所谓SSH验证，就是服务器利用它保存到的公钥和本地的私钥进行配对验证，通过才允许连接。

`ssh-keygen -t rsa -b 4096 -C "your_email@example.com"`

一路回车enter，会发现SSH密钥对默认生成在/home/user/.ssh目录下。

&nbsp;

2.将公钥添加到Github

>个人账户->SSH and GPG keys->New SSH Key->粘贴公钥于此

&nbsp;

3.测试是否成功
`ssh -T git@github.com`
