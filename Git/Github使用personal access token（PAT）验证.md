**1.添加PAT**

https://github.com/settings/tokens

生成PAT之后要及时复制，离开页面之后就看不到了，只能更新，登陆的时候用PAT代替密码就可以了。

**2.在Git中缓存凭据**

`#默认缓存15分钟

git config --global credential.helper cache

#可以更改默认的密码缓存时限

git config --global credential.helper 'cache --timeout=3600'`

之后git push也不用输入PAT了。