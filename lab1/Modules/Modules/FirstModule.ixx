export module FirstModule;

import <iostream>;

export void add(double a, double b)
{
    std::cout << "a + b = " << a + b << std::endl;
}

export void substract(double a, double b)
{
    std::cout << "a - b = " << a - b << std::endl;
}

export void multiply(double a, double b)
{
    std::cout << "a * b = " << a * b << std::endl;
}

export void even(int a)
{
    if (a % 2 == 0) std::cout << "c is even\n";
    else std::cout << "c is odd\n";
}