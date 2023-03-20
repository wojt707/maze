// Laboratory2.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <regex>


void task1() {
    /*
    Task 1
    For the given example string:
    a) replace the word "car" with the word "vehicle".
    */
    std::string ex("At midnight, the pair passed the hidden police car on their way to the mansion.");
    std::regex re("(car)");
    std::cout << regex_replace(ex, re, "vehicle") << std::endl;
    //       completed
}

void task2() {
    /*
    Task 2
    Some words in this text are accidentally repeated. Remove the doubles:
    */
    std::string text = "Tomas thought it was fair fair. It was right that he should be punished, and working as an astronomer had"
        " become almost the same as prison prison. After a few years the world forgot about him, or at least decided to leave him alone."
        " Every evening evening he would watch the sun go down. It vanished below the horizon horizon exactly eight minutes and twenty seconds"
        " after it actually descended below the curve of the Earth Earth. The laws of physics remained the same, much to Tomas's daily relief"
        " relief. Light still travelled at the same speed as it always had. He hadn't changed reality that much or, at least, he hoped he"
        " hadn't. If light travels at a certain speed, he thought,perhaps absence absence of light travels at the same speed.";
    // Regular expression pattern to match repeated words
    std::regex pattern("\\b(\\w+)(\\W+\\1)", std::regex_constants::icase);



    // Replace all repeated words with a single instance of the word
    std::string result = std::regex_replace(text, pattern, "$1");

    // Output the modified text
    std::cout << result << std::endl;

}


void task3() {
    /*
    Task 3
    Match numbers containing floating point. Skip those that don't:
    */
    std::string text = "pi(number) = 3.14\n"
        "Standard atmosphere 101325 Pa\n"
        "e (number) =2.71\n"
        "Acceleration of gravity = 9.80665 m/s^2\n"
        "Earth to the moon distance = 384 400 km\n";

    std::regex pattern("\\d+\\.\\d+", std::regex_constants::icase);
    std::smatch matches;
    std::string::const_iterator start = text.cbegin();

    while (std::regex_search(start, text.cend(), matches, pattern))
    {
        std::cout << '\t' << matches[0].str() << std::endl;
        start = matches.suffix().first;
    }
}

void task4() {
    /*
    Task 4
    */
    std::regex number_pattern(R"(\d+)");


    std::cout << "Enter a string: ";
    std::string input;
    std::getline(std::cin, input);

    // Use regex_search to find the first number in the input string

    std::smatch firstMatch;

    if(std::regex_search(input.cbegin(), input.cend(), firstMatch, number_pattern)) 
        std::cout << "First found number: " << firstMatch[0] << std::endl;
    else
        std::cout << "Number not found" << std::endl;
}

void task5() {
    /*
    Task 5
    You have a string that represents a person's name in the format "first name last name". Write a program that uses regex to extract the
    first name and last name from the input string. Assuming that the input string is in the correct format, you can use the following
    regular expression pattern to extract the firstand last name :
    ^ (\S + )\s + (\S + )$
    */

    std::regex pattern("^\\s*(\\S+)\\s+(\\S+)\\s*$");


    std::cout << "Enter name and surname: ";
    std::string nameAndSurname;
    std::getline(std::cin, nameAndSurname);
    std::smatch match;

    //std::cout << std::regex_search(nameAndSurname, pattern) << std::endl;

    if (std::regex_match(nameAndSurname, match, pattern)) {
        std::string name = match[1];
        std::string surname = match[2];
        
        std::cout << "Name: " << name << ',' << std::endl;
        std::cout << "Surname: " << surname << ',' << std::endl;
         
    }
    else
        std::cout << "Name and surname provided in incorrect format" << std::endl;

}


int main()
{
    std::cout << std::endl << "Task 1: " << std::endl;
    task1();
    std::cout << std::endl << "Task 2: " << std::endl;
    task2();
    std::cout << std::endl << "Task 3: " << std::endl;
    task3();
    std::cout << std::endl << "Task 4: " << std::endl;
    task4();
    std::cout << std::endl << "Task 5: " << std::endl;
    task5();
}


