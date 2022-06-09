问：C++11之后返回std::vector时会自动调用std::move吗？
会优化。但这种情况不会调用move的构造。现代编译器会对此做优化，准确说是会发生拷贝消除(copy elison)，copy elision的成本比低开销的move还要低。

问：STL如何实现vector？
- vector支持随机访问，内部使用动态数组来实现
- 当进行insert或push_back操作时，如果此时内存不够用，会动态的重新分配，一般是当前大小的1.5~2倍，然后把原来的内容拷贝过去
- 内部有allocator类进行内存管理，不需要程序员手动操作。

问：vector的push_back过程详解？
- 一般对容器的内存分配和构造是分开的2个过程，STL有专门的空间配置器负责分配内存，
  而构造则是通过placement new在已申请的内存上进行的
- 调用 拷贝构造函数 把a赋值给vec的finish迭代器指向的内存，说白了就是vec中存放的a和上面定义的a对象已经不是一个东西了。
- 默认初始化的vector是不分配内存空间的，当push_back发现vector空间不足以容纳新元素时，就会分配新的空间（通常是加倍），
  将数据移动到新空间时就会发生 移动构造函数，而当我们用vs.reserve()预留足够的空间时，就不会发生移动构造函数了。

问：使用reserve来避免不必要的重新分配
- reserve成员函数能使你把重新分配的次数减少到最低限度，从而避免了重新分配和指针、迭代器、引用失效带来的开销
- reserve()用来保留（扩充）容量，他并不改变容器的有限元素个数；
- resize()则调整容器大小（size, 有效元素的个数），而且有时候会增大容器的容量。
- capacity容量是为了减少那些使用连续空间（线性空间）存储元素的容器在增加元素时重新分配内存空间的次数的一种机制

std::nth_element(std::begin(numbers), std::begin(numbers) + count, std::end(numbers) , std::greater<>());

总结一下你的排序选择：
- 如果你需要在vector、string、deque或数组上进行完全排序，你可以使用sort或stable_sort。
- 如果你有一个vector、string、deque或数组，你只需要排序前n个元素，应该用partial_sort。
- 如果你有一个vector、string、deque或数组，你需要鉴别出第n个元素或你需要鉴别出最前的n个元素，
- 而不用知道它们的顺序，nth_element是你应该注意和调用的。
- 如果你需要把标准序列容器的元素或数组分隔为满足和不满足某个标准，你大概就要找partition或stable_partition。
- 如果你的数据是在list中，你可以直接使用partition和stable_partition，你可以使用list的sort来代替sort和stable_sort。
- 如果你需要partial_sort或nth_element提供的效果，你就必须间接完成这个任务，但正如我在上面勾画的，会有很多选择。

问：vector中的erase方法与algorithm中的remove有什么区别？
- erase是真正删除了元素，迭代器不能访问了
- remove只是简单的把要remove的元素移到了容器的最后，无法做到真正的删除

另外，capacity()返回的就是包括缓冲区在内的空间大小，而size()返回的就是当前实际使用的空间大小。

如果想强制释放那就新建一个空的vector，然后对这个vector使用swap讲内存交换，那么原来的vector就会释放。