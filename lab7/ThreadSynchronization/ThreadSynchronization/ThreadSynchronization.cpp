#include <iostream>
#include <barrier>
#include <semaphore>
#include <thread>
#include <vector>
#include <random>


//Task 1
const int numSensors = 4;
//YOUR SOLUTION GOES HERE. Declare a barrier
std::barrier temperatureBarrier{ numSensors };

std::vector<double> sensorReadings;
double averageTemperature = 0;

void sensorThread(int sensorID) {
    //YOUR SOLUTION GOES HERE
    //Simulate the measurement generating a random temperature value
    //Hint: use uniform_real_distribution
    
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    std::uniform_real_distribution<double> doubleDistro(0.0, 40.0);

    //Store the reading in the sensorReadings structure
    sensorReadings[sensorID] = doubleDistro(gen);

    //Reach a barrier
    temperatureBarrier.arrive_and_wait();
}

void calculateAverageTemperature() {
    //Calculate the average temperature using the shared data
    double sum = 0;
    for (const auto& temp : sensorReadings) {
        sum += temp;
    }
    averageTemperature = sum / numSensors;
}

//Task 2
const int numThreads = 4;
//YOUR SOLUTION GOES HERE. Declare a barrier
std::barrier workerBarrier{ numThreads };

void workerTask(int workerID) {
    //YOUR SOLUTION GOES HERE
    //Simulate some work done by a worker

    std::cout << "Worker " << workerID << " working." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    //Reach the barrier

    workerBarrier.arrive_and_wait();
}

//Task 3
const int numSeats = 5;
//YOUR SOLUTION GOES HERE. Declare a semaphore
std::counting_semaphore<numSeats> freeSeats(numSeats);

void customer(int customerID) {
    std::cout << "Customer " << customerID << " is waiting for a seat." << std::endl;
    //YOUR SOLUTION GOES HERE
    //Acquire a seat
    freeSeats.acquire();

    //Simulate a costumer eating
    std::cout << customerID << " ordering." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    
    //Finish eating and release the seat
    std::cout << customerID << " ended eating." << std::endl;

    freeSeats.release();
}

//Task 4
//YOUR SOLUTION GOES HERE. Declare a semaphore
std::binary_semaphore printer(1);

void printPage(const std::string& page, int pageID) {
    //YOUR SOLUTION GOES HERE
    //Acquire the printer semaphore
    printer.acquire();
    
    //Simulate printing
    std::cout << pageID << " printing." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    //Release the printer semaphore
    printer.release();
}

void Task1() {
    std::cout << "Task 1" << std::endl;
    std::vector<std::thread> sensorThreads;
    sensorReadings.resize(numSensors);

    for (int i = 0; i < numSensors; ++i) {
        sensorThreads.emplace_back(sensorThread, i);
    }

    for (auto& thread : sensorThreads) {
        thread.join();
    }

    calculateAverageTemperature();

    std::cout << "Average Temperature: " << averageTemperature << std::endl;
}

void Task2() {
    std::cout << "Task 2" << std::endl;
    std::thread workers[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        workers[i] = std::thread(workerTask, i);
    }

    for (int i = 0; i < numThreads; ++i) {
        workers[i].join();
    }

    std::cout << "All worker threads have completed. A product is assembled." << std::endl;
}

void Task3() {
    std::cout << "Task 3" << std::endl;
    const int numCustomers = 10;
    std::thread customers[numCustomers];

    for (int i = 0; i < numCustomers; ++i) {
        customers[i] = std::thread(customer, i);
    }

    for (int i = 0; i < numCustomers; ++i) {
        customers[i].join();
    }

    std::cout << "All customers have finished their meals." << std::endl;
}

void Task4() {
    std::cout << "Task 4" << std::endl;
    const int numPages = 5;
    std::thread printers[numPages];

    for (int i = 0; i < numPages; ++i) {
        printers[i] = std::thread(printPage, "Page", i + 1);
    }

    for (int i = 0; i < numPages; ++i) {
        printers[i].join();
    }

    std::cout << "All pages have been printed." << std::endl;
}

int main()
{
    //Task 1
    //Calculate the average temperature in town after reading the data from different sensors (threads).
    Task1();

    //Task2
    //A group of workers (threads) make different components of a product.
    //Wait until all workers have finished their components and assemble a final product.
    Task2();

    //Task3
    //Simulate a scenario: people wait in line to be seated in a restaurant.
    //Use semaphore to coordinate the access to the limited number of seats.
    Task3();

    //Task4
    //Simulate a scenario: we need to print a number of pages. 
    //A printer can only print one page at a moment.
    Task4();

    return 0;
}