// Case 2，std::terminate()函数提前终止进程

#include <iostream>
#include <thread>
#include <stdexcept>

void threadFunction()
{
    std::cout << "Thread is running...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟工作
    std::cout << "Thread finished its work.\n";
}

int main()
{
    try
    {
        std::thread t(threadFunction); // 线程对象 t 在 try 块中启动。
        std::cout << "Main thread is performing an operation...\n";

        // 模拟一个可能抛出异常的操作
        throw std::runtime_error("An error occurred!");

        // 如果没有异常，这里会调用 join()
        t.join(); // join() 被跳过
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;

        // 因为异常，这里没有调用 join()
    }

    std::cout << "Main thread ended without waiting for the thread.\n";
    return 0;
}
