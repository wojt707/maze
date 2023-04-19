#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <thread>
#include <numeric>
#include "Functions.h"


int slow_operation(int x)
{
    std::this_thread::sleep_for(std::chrono::seconds(x));

    std::cout << "Waited for " << x << " seconds." << std::endl;
    return x;
}

/** Task 2 */
int random_value()
{
    const int MAX = { 100 };        ///This is the maximum number we want to generate.
    std::uniform_int_distribution<int> distro(0, MAX - 1);       ///This is the range of the number that we can choose from.
    static std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());     ///This is a random number engine class that generates pseudo-random numbers.

    return distro(engine);
}

void sumArray(const std::vector<int>& arr, int start, int end, int& result)
{
    result = std::accumulate(arr.begin() + start, arr.begin() + end, 0);
}

std::string handle_request(const std::string& request)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return "result for " + request;
}

void producer_v1(std::promise<int>&& promiseObj)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    promiseObj.set_value(31);
}

void consumer_v1(std::future<int>&& futureObj)
{
    std::cout << "The result is: " << futureObj.get() << std::endl;
}
