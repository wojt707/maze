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

//TASK 1
//Create threads that call the sum and product functions using the given variables as parameters
void Task1()
{
    int sum_result = 0, product_result = 0;
    //Solution

    //--------
    std::cout << "Sum: " << sum_result << std::endl;
    std::cout << "Product: " << product_result << std::endl;
}


//Variables for task 2
int balance = 0;
std::mutex mtx1;

//Functions for task 2
void deposit(int amount)
{
    //Solution

    //--------
}

void withdraw(int amount)
{
    //Solution

    //--------
}

//TASK 2
//Create the deposit and withdraw functions that modify the balance variable. Use the mtx1 mutex to lock and unlock the threads in each function.
//Create a few threads that call the deposit and withdraw functions.
void Task2()
{
    //Solution

    //--------
    std::cout << "Final balance: " << balance << std::endl;
}


//Functions for task 3
void increment(std::atomic<int>& counter, int numberOfIncrements)
{
    for (int i = 0; i < numberOfIncrements; ++i)
    {
        counter++;
    }
}

//TASK 3
//Create 4 threads that call the increment function. Create a single atomic variable (counter) that is going to be incremented by all threads.
//Use the for loops to create the threads and join them.
void Task3()
{
    const int numberOfThreads = 4;
    int numberOfIncrementsPerThread = 100000;
    //Atomic Variable

    //---------------

    std::thread threads[numberOfThreads];
    for (int i = 0; i < numberOfThreads; ++i)
    {
        //Create threads here

        //-------------------
    }

    for (int i = 0; i < numberOfThreads; ++i)
    {
        //Join threads here

        //-----------------
    }

    //Print the final value of the counter

    //------------------------------------
}


//Variables for task 4
const int N = 10;
std::mutex mtx2;
std::condition_variable cv;
bool is_even_turn = true;

//TASK 4
//Write the code for printing even and odd numbers
//Use the condition variable cv and mutex mtx2 to synchronize the threads
//Use the is_even_turn variable to determine which thread should print the number
//Use std::unique_lock to lock the mutex
//Use the wait and notify_one functions
void printEven()
{
    for (int i = 0; i < N; i += 2)
    {
        //Solution

        //--------
    }
}

void printOdd()
{
    for (int i = 1; i < N; i += 2)
    {
        //Solution

        //--------
    }
}


//Create two threads that call the printEven and printOdd functions. Use the condition variable cv and mutex mtx2 to synchronize the threads.
void Task4()
{
    //Solution

    //--------
}

int main()
{
    Task1();
    Task2();
    Task3();
    Task4();
    return 0;
}