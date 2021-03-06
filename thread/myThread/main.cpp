#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include <condition_variable>
class ThreadClass
{
public:
    ThreadClass()
    {
        m_data = 0;
    }
    void setData()     //子线程 1 入口
    {
        while(1)
        {
            std::cout<<"set data: ";
            std::lock_guard<std::mutex> threadGuard(m_threadMutex);

            m_dataQueue.push(m_data++);
            std::cout<<m_data<<std::endl;

            m_condVariable.notify_one();  // 唤醒wait()
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    void readData()     //子线程 2 入口
    {
        while (1)
        {

            std::unique_lock<std::mutex> threadGuard(m_threadMutex);
            // 使用wait() 等待，一旦set线程调用notify_one()，
            // wait(),被唤醒，获得锁，然后判断lambda表达式，如果成立则执行下面的程序，如果不成立，则释放锁，并且线程阻塞在这里
            m_condVariable.wait(threadGuard, [this] {
                if(!m_dataQueue.empty())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            });

            auto x = m_dataQueue.front();
            m_dataQueue.pop();
            threadGuard.unlock();  //获取完数据将锁释放。
            std::cout<<"data now is "<<x<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
private:
    int m_data;
    std::queue<int> m_dataQueue;
    std::mutex m_threadMutex;
    std::condition_variable m_condVariable;
};
int main()
{
    ThreadClass T;
    //注意参数的传递方式，先传入入口函数，然后传入类对象的this指针
    std::thread t1(&ThreadClass::setData,&T);
    std::thread t2(&ThreadClass::readData,&T);
    t1.join();
    t2.join();
    return 0;
}


