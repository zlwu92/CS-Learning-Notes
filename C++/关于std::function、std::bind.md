【std::function】

可以把std::function看做一个函数对象，用于表示函数这个抽象概念。

std::function的实例可以存储、复制和调用任何可调用对象，存储的可调用对象称为std::function的目标。

使用参考如下实例代码：

`std::function<void(int)> f; // 这里表示function的对象f的参数是int，返回值是void。`

从上面可以看到std::function的使用方法，当给std::function填入合适的参数表和返回值后，它就变成了可以容纳所有这一类调用方式的函数封装器。

【std::bind】

使用std::bind可以将可调用对象和参数一起绑定，绑定后的结果使用std::function进行保存，并延迟调用到任何我们需要的时候。