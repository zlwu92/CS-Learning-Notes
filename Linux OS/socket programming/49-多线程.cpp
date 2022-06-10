#include<iostream>
#include<mutex>
#include<condition_variable>
#include<string>
#include<thread>
using namespace std;
string res("");
mutex mtx;
bool done = false;
condition_variable A, B, C, D;
void fun_A(int times) 
{
    while (times--)
    {
        unique_lock<mutex> locker(mtx);
        A.wait(locker);
        res += 'A';
        locker.unlock();
        B.notify_one();
    }
    done = true;
}
void fun_B() 
{
    while (!done) 
    {
        unique_lock<mutex> locker(mtx);
        B.wait(locker);
        res += 'B';
        locker.unlock();
        C.notify_one();
    }
}
void fun_C() 
{
    while (!done) 
    {
        unique_lock<mutex> locker(mtx);
        C.wait(locker);
        res += 'C';
        locker.unlock();
        D.notify_one();
    }
}
void fun_D() 
{
    A.notify_all();
    while (!done) 
    {
        unique_lock<mutex> locker(mtx);
        D.wait(locker);
        res += 'D';
        locker.unlock();
        A.notify_all();
    }
}
int main() 
{
    int num;
    cin >> num;
    res = "";
    thread t1(fun_A, num);
    thread t2(fun_B);
    thread t3(fun_C);
    thread t4(fun_D);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout << res << endl;
    done = false;
    return 0;
}
/*
多线程实现生产者与消费者模式：
产生数据的模块称为生产者，处理数据的模块成为消费者。
还需要有一个缓冲区（一段内存区域）作为中介，
生产者产生的数据放入缓冲区，消费者从缓冲区读取数据并处理

3种关系
2个角色
1个交易场所

生产者-消费者模式之间的三种关系：
生产者-生产者：一个生产者往缓冲区放数据时另一个生产者就不能去访问这块空间
消费者-消费者：同样，两个消费者之间也是竞争的关系
生产者-消费者：生产者与消费者之间其实是一种同步与互斥的关系，
              假设只有一个生产者一个消费者时，只有生产者放入数据后消费者才能读取，
              消费者拿到数据后生产者才去生产，这就是一种同步；
              但当生产者生产数据的时候消费者就不能从缓冲区拿数据，
              或者消费者读数据的时候生产者就不能往缓冲区里写数据，
              否则很可能会导致两者都存/取数据失败，产生二义性问题。

生产者-单消费者的实现：
使用 互斥锁 + 条件变量 -> 总结：互斥锁实现的是线程之间的互斥，条件变量实现的是线程之间的同步。
条件变量 是在多线程程序中用来实现 “等待->唤醒” 逻辑的常用方法。
用 单链表 来模拟
生产者放入数据时进行头插，消费者消费数据时进行头删

当生产者线程生产数据时消费者线程就wait
当消费者被唤醒后，此时链表已经有数据（消费者等待成功），拿走结点
消费者读取数据的过程中生产者在wait
等到消费者读取数据完之后被唤醒，然后继续往缓冲区写入数据（循环………）
等待与被唤醒的过程就可以利用上述的pthread_cond_wait和pthread_cond_signal函数实现
#include<pthread.h>
while(!done)
{
    mutex_lock() -> cond_wait() -> product sth -> mutex_unlock() -> cond_signal()
}
int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
该函数用来在一个ConditionVariable上阻塞等待，做以下三步操作：①释放Mutex；②阻塞等待；③当被唤醒时，重新获得Mutex并返回。
*/