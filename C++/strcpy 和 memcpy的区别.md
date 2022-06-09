- 复制内容不同，memcpy可以复制任何存于内存的内容
- 复制方法不同，strcpy不需要指定长度，memcpy需要传参
- 用途不同，复制字符串用strcpy，其他考虑memcpy

手动实现strcpy
```
char *strcpy(char *strDest, const char *strSrc)
{
	if ( strDest == NULL || strSrc == NULL)
		return NULL ;
	if ( strDest == strSrc)
		return strDest ;
	char *tempptr = strDest ;
	while( (*strDest++ = *strSrc++) != ‘/0’)	return tempptr ;
}
```

问：memcpy的源地址与目的地址有交集会有影响吗，如何解决？
>从最后一个字节倒着开始复制。