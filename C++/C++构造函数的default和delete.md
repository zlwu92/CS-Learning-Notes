- C++11中，当类中含有不能默认初始化的成员变量时，可以禁止默认构造函数的生成，
- myClass()=delete;//表示删除默认构造函数
- myClass()=default;//表示默认存在构造函数，同时提供默认版本和带参自定义版本
- 当类中含有不能默认拷贝成员变量时，可以禁止默认构造函数的生成，
- myClass(const myClass&)=delete;//表示删除默认拷贝构造函数，即不能进行默认拷贝
- myClass & operatir=(const myClass&)=delete;//表示删除默认拷贝构造函数，即不能进行默认拷贝

问：C++中delete this是对象先析构还是delete语句先返回？
>先析构。