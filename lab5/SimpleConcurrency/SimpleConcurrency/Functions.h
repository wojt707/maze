#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <future>

/** Task 1 */
int slow_operation(int x);

/** Task 2 */
int random_value();
void sumArray(const std::vector<int> &arr, int start, int end, int &result);

/** Task 3 */
std::string handle_request(const std::string& request);

/** Task 4 */
void producer_v1(std::promise<int> &&promiseObj);
void consumer_v1(std::future<int> &&futureObj);

#endif
