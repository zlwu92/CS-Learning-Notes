问：final和override的作用，以及使用场合（提问概率：★★）
>final:禁止继承该类或者覆盖该虚函数
override:必须覆盖基类的匹配的虚函数

>场合（final）:不希望这个类被继承，比如vector，编码者可能不够了解vector的实现，或者说编写者不希望别人去覆盖某个虚函数
场合（override）:第一种，在使用别人的函数库，或者继承了别人写的类时，想写一个新函数，可能碰巧与原来基类的函数名称一样，被编译器误认为要重写基类的函数。
第二种情况是想覆写一个基类的函数，但是不小心参数不匹配或者名字拼错，结果导致写了一个新的虚函数