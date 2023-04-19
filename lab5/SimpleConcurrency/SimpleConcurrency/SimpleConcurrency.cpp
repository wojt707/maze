#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>
#include <numeric>
#include <queue>

#include "Functions.h"

int main()
{
    /** Task 1 */
    std::cout << "Task 1" << std::endl;

    std::packaged_task<int(int)> task(slow_operation);
    std::future<int> f = task.get_future();

    std::thread t1(std::move(task), 2);

    /** Task 2 */
    std::cout << "Task 2" << std::endl;
    const int numThreads = 4;
    const int arrSize = 1000000;
    std::vector<int> v_big(arrSize);

    //for (int i = 0; i < arrSize; i++)
    //    v_big[i] = random_value();
    std::generate(v_big.begin(), v_big.end(), random_value);

    std::vector<int> partialSums(numThreads);
    std::vector<std::thread> threads(numThreads);

    const int chunkSize = arrSize / numThreads;

    for (int i = 0; i < numThreads; ++i)
        threads[i] = std::thread(sumArray, v_big, i * chunkSize, (i + 1) * chunkSize, std::ref(partialSums[i]));

    for (auto& t : threads)
        t.join();
    //int sum = 0;
    //for (auto& v : v_big)
        //sum += v;
    int finalSum = std::accumulate(partialSums.begin(), partialSums.end(), 0);
    std::cout << "Final sum: " << finalSum << "\n";
    //std::cout << "Final sum: " << sum << "\n";


    /** Task 3 */
    std::cout << "Task 3" << std::endl;
        // Define incoming requests
    std::vector<std::string> requests = { "request1", "request2", "request3", "request4" };

    // Serve requests concurrently
    std::vector<std::future<std::string>> futures;
    for (const auto& request : requests)
        futures.push_back(std::async(handle_request, request));

    // Wait for all futures to complete and combine the results
    std::vector<std::string> results;
    for (auto& future : futures)
        results.push_back(future.get());

    // Send back combined results to the client
    std::cout << "Combined results:\n";
    for (const auto& res : results)
        std::cout << res << "\n";
    std::cout << std::endl;


    /** Task 4 v1 */
    std::cout << "Task 4" << std::endl;
    std::promise<int> promiseObj_v1;
    std::future<int> futureObj_v1 = promiseObj_v1.get_future();

    std::thread producerThread(producer_v1, std::move(promiseObj_v1));
    std::thread consumerThread(consumer_v1, std::move(futureObj_v1));

    

    /** Task 1 once more*/
    int result = f.get();
    std::cout << "Task 1 was running in the backgroung and now ended " << result << std::endl;
    t1.join();
    producerThread.join();
    consumerThread.join();

    return 0;
}