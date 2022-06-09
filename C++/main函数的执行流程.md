问：main 函数执行以前，还会执行什么代码？
>全局对象的构造函数会在main 函数之前执行。

main函数执行之前，主要就是初始化系统相关资源：
>设置栈指针
初始化静态static变量和global全局变量，即.data段的内容
将未初始化部分的全局变量赋初值：数值型short，int，long等为0，bool为FALSE，指针为NULL等等，即.bss段的内容
全局对象初始化，在main之前调用构造函数，这是可能会执行前的一些代码
将main函数的参数argc，argv等传递给main函数，然后才真正运行main函数

main函数执行之后：
>全局对象的析构函数会在main函数之后执行；
