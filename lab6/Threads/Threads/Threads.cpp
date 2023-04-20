#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>

//Functions for task 1
void sum(int& result)
{
    result = 0;
    for (int i = 1; i <= 100; i++)
    {
        result += i;
    }
}

void product(int& result)
{
    result = 1;
    for (int i = 1; i <= 10; i++)
    {
        result *= i;
    }
}

void Task1()
{
    int sum_result, product_result;
    std::thread t1(sum, std::ref(sum_result));
    std::thread t2(product, std::ref(product_result));
    t1.join();
    t2.join();
    std::cout << "Sum: " << sum_result << std::endl;
    std::cout << "Product: " << product_result << std::endl;
}


//Variables for task 2
int balance = 0;
std::mutex mtx1;

//Functions for task 2
void deposit(int amount)
{
    mtx1.lock();
    balance += amount;
    mtx1.unlock();
}

void withdraw(int amount)
{
    mtx1.lock();
    balance -= amount;
    mtx1.unlock();
}

void Task2()
{
    std::thread t1(deposit, 1000);
    std::thread t2(withdraw, 500);
    std::thread t3(deposit, 1500);
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Final balance: " << balance << std::endl;
}


//Functions for task 3
void increment(std::atomic<int>& counter, int numIncrements)
{
    for (int i = 0; i < numIncrements; ++i)
    {
        counter++;
    }
}

void Task3()
{
    std::atomic<int> counter(0);
    const int numThreads = 4;
    int numIncrementsPerThread = 100000;

    std::thread threads[numThreads];
    for (int i = 0; i < numThreads; ++i)
    {
        threads[i] = std::thread(increment, ref(counter), numIncrementsPerThread);
    }

    for (int i = 0; i < numThreads; ++i)
    {
        threads[i].join();
    }

    std::cout << "Final counter value: " << counter << std::endl;
}



//Variables for task 4
const int N = 10;
std::mutex mtx2;
std::condition_variable cv;
bool is_even_turn = true;

//Functions for task 4
void printEven()
{
    for (int i = 0; i < N; i += 2)
    {
        std::unique_lock<std::mutex> lock(mtx2);
        cv.wait(lock, [] { return is_even_turn; });
        std::cout << i << " ";
        is_even_turn = false;
        cv.notify_one();
    }
}

void printOdd()
{
    for (int i = 1; i < N; i += 2)
    {
        std::unique_lock<std::mutex> lock(mtx2);
        cv.wait(lock, [] { return !is_even_turn; });
        std::cout << i << " ";
        is_even_turn = true;
        cv.notify_one();
    }
}

void Task4()
{
    std::thread t1(printEven);
    std::thread t2(printOdd);
    t1.join();
    t2.join();
}

int main()
{
    Task1();
    Task2();
    Task3();
    Task4();
    return 0;
}