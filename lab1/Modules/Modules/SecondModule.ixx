export module SecondModule;

import <iostream>;

void privateFunction() {
	std::cout << "Hello world!" << std::endl;
};

export void publicFunction() {
	privateFunction();
}