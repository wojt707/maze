#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <string>
#include <map>

void task1() {
	std::cout << "Task 1\n";
	std::vector<int> input = { 14, 127, 21, 7, 6, 3, 90, 1, 12, 13, 17, 4, 5, 9 };
	int count = std::count_if(input.begin(), input.end(), [](int i) { return i > 10; });
	std::cout << "\tNumber of elements greater than 10: " << count << std::endl;

	// Place for solution

	int rangeCount = std::ranges::count_if(input, [](int i) { return i > 10; });

	std::cout << "\tNumber of elements greater than 10: " << rangeCount << std::endl;

	// --------
}

void task2() {
	std::cout << "Task 2\n";

	// Place for solution
	auto inp = std::ranges::views::iota(0, 100);

	auto divisibleBy3 = [](int i) {return i % 3 == 0; };
	auto notDivisibleBy7 = [](int i) {return i % 7; };
	auto greaterThan12 = [](int i) {return i > 12; };
	

	auto outp = inp
		| std::ranges::views::filter(divisibleBy3)
		| std::ranges::views::filter(notDivisibleBy7)
		| std::ranges::views::filter(greaterThan12);

	std::cout << '\t';
	for (auto el : outp)
		std::cout << el << ' ';

	std::cout << std::endl;

	// --------
}

void task3() {
	std::cout << "Task 3\n";
	std::vector<int> numbers{ 2, 5, 10, 1, 3, 7, 12, 1, 0, 9, 11, 18, 2, 4, 8, 7 };

	// Place for solution

	auto view = numbers
		| std::views::chunk_by(
			[](int x, int y) { return x <= y; });

	std::cout << '\t';
	for (auto group : view) {
		std::cout << "[";
		for (const auto num: group)
			std::cout << num << ' ';
		std::cout << "] ";
	}

	std::cout << std::endl;

	// --------
}


void task4()
{
	std::cout << "Task 4\n";
	std::map<std::string, double> heights{ {"Smith", 1.76}, {"Brown", 1.68}, {"Jones", 1.81},
		{"Baker", 1.77}, {"Parker", 1.65}, {"Cooper", 1.79}, {"Fisher", 1.69} };
	// Place for solution
	
	auto higherThan170 = [](double height) { return height > 1.70; };

	auto values = heights 
		| std::ranges::views::values
		| std::ranges::views::filter(higherThan170);

	std::cout << '\t';

	for (const auto& v : values)
		std::cout << v << " ";

	std::cout << std::endl;

	// --------
}

void task5() {
	std::cout << "Task 5\n";
	std::string input = "Once upon a time, in a beautiful forest, there lived three animal friends: a rabbit named Rolly, a squirrel named Sammy, and a bird named Benny."
		"One day, Rolly found a little kitten all alone in the forest. The kitten looked lost and scared. Rolly felt sorry for the kitten and decided to take her home. Sammy and Benny were excited to meet the new member of their friend group."
		"The kitten was so small and cute that they all loved her instantly. They took turns playing with her and taking care of her. Rolly made sure that the kitten had plenty of food to eat, while Sammy and Benny made a cozy little bed for her."
		"Days went by, and the kitten grew bigger and stronger. She loved playing with her new friends and would always snuggle with them at night. One day, as they were all playing together, they saw a group of dogs approaching them. The dogs looked mean and angry."
		"Rolly, Sammy, and Benny were terrified. They knew they had to protect the kitten. Rolly quickly came up with a plan. He told the kitten to climb up a tree and stay there until they came back."
		"The three friends bravely faced the dogs and managed to scare them away. When they returned to the tree, they saw the kitten safe and sound, waiting for them. The kitten was grateful to her friends for protecting her."
		"The moral of the story is that true friendship means caring for each other and protecting each other, no matter what.";

	// Place for solution

	// --------
}

int main()
{
	// Task 1
	// Convert the code below to use a simpler syntax(std::ranges are needed) :
	// Two results should be the same.
	task1();

	// Task 2
	// Create a view containing numbers from 0 to 100 by means of std::views::iota.
	// Using views and filters, filter out (in one result) numbers from the vector:
	//   - numbers divisible by 3 AND
	//   - not divisible by 7 AND
	//   - greater than 12
	task2();

	// Task 3
	// Chunk the vector. In each chunk, the numbers should be in increasing order.
	task3();

	// Task 4
	// Show the heights of the people that are higher than 1.70. Use std::views::values.
	task4();

	// Task 5
	// Find the most common word in a string.
	// Split string into words, and then find the most common word in the string.
	// In case of ties, output any of the most common words.
	task5();

	return 0;
}