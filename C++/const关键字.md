问：请说出const与#define相比，有何优点？
```
const作用：定义常量、修饰函数参数、修饰函数返回值三个作用。被Const修饰的东西都受到强制保护，可以预防意外的变动，能提高程序的健壮性。
1）const常量有数据类型，而宏常量没有数据类型。
2）编译器可以对前者进行类型安全检查。而对后者只进行字符替换，没有类型安全检查，并且在字符替换可能会产生意料不到的错误。
3）有些集成化的调试工具可以对const 常量进行调试，但是不能对宏常量进行调试
#define只是用来做文本替换的，编译期概念。 存在于程序的代码段，无类型检测。
const存在于程序的数据段，在堆栈分配空间，是一个运行时的概念，可以做类型检查。
```
问：const 有什么作用？
- const用于定义常量，可以进行数据静态类型安全检查
- const用于修饰函数形参，当传入自定义类型和抽象类型时，应该用const&，避免产生临时对象，提高效率
- const修饰函数的返回值，则返回值不能被修改
- const修饰类的成员函数
- 对于全局变量，const存于全局区，对于字面值常量，存于常量存储区，对于局部变量，存于栈区
>(重要！)类的成员函数后面加 const，表明这个函数不会对这个类对象的数据成员（准确地说是非静态数据成员）作任何改变。