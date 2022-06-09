在C语言中，NULL通常被定义为：#define NULL ((void *)0)，所以说NULL实际上是一个空指针。

但在C++程序中的NULL中，实际上编译器提供的头文件做了相应的处理：
```
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif            
```
可见，在C++中，NULL实际上是0，为解决NULL代指空指针存在的二义性问题，在C++11版本(2011年发布)中引入了nullptr 关键字来代指空指针！