问：关于this指针你知道什么？全说出来
- this指针是类的指针，指向对象的首地址。
- this指针只能在成员函数中使用，在全局函数、静态成员函数中都不能用this。
- this指针只有在成员函数中才有定义，且存储位置会因编译器不同有不同存储位置。

问：什么是this指针？
>对于一个类的实例来说，你可以看到它的成员函数、成员变量，对于一个实例本身，this是一个指针，它时时刻刻指向你这个实例本身。

作用域：this指针是编译器默认传给类中非静态函数的隐含形参，所以其作用域在非静态成员函数的函数体内。

this是一个常量指针，成员函数的其它参数正常都是存放在栈中。而this指针参数则是存放在 register 中。
- 类的非static函数是类的对象，含有this指针；而类的static函数属于类的本身，不含this指针
- friend函数是非成员函数，无法通过this指针获取