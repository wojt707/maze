#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     
#include <time.h>
#include <cstdlib>

namespace fs = std::filesystem;

/*

https://en.cppreference.com/w/cpp/filesystem

Quick guide:

	- Creating path variable with diffrent methodes:
		fs::path path{"Hello"};             => Hello
		path /= "Training";                 => Hello\Training
		path = path / "Modern" / "Cpp17";   => Hello\Training\Modern\Cpp17
		path.append("Programming.txt");     => Hello\Training\Modern\Cpp17\Programming.txt

	or:
		use functions like: fs::path path = fs::curent_path()

	- directory iterator loop:
		for(const auto& entry : fs::directory_iterator(base_path) {put code here}
		where:
		- entry -> all the elements inside the directory
		- base_path -> path to directory which we want to itarate through.

	- Rename a file:
		std::filesystem::rename(old_file_path, old_file_path.parent_path() / new_name);

*/

/*
Task 1: Create a variable that stores the path to your solution (.cpp file). Decpomose it to obtain the following:
	- root path
	- parentpath
	- filename
	- stem
	- extension
*/
void task1() {
	//Create variable bellow

	fs::path currentPath = fs::current_path();
	currentPath.append("main.cpp");
	fs::path root = currentPath.root_path();
	fs::path parent = currentPath.parent_path();
	fs::path filename = currentPath.filename();
	fs::path stem = currentPath.stem();
	fs::path extension = currentPath.extension();
	//  C:\projects\POLSLrepo_sem4\lab3\filesystem\filesystem\main.cpp

	std::cout << "Decomposition:\n\n";

	//Print path components bellow

	std::cout << currentPath << std::endl
		<< root << std::endl
		<< parent << std::endl
		<< filename << std::endl
		<< stem << std::endl
		<< extension << std::endl;
}

/*
Task 2: Create a variable that stores the path to your solution or .exe file (filesystem::current_path), use an iterator to print all the elements in this directory.
	Create two loops one for regular files and another for directories.
*/
void task2() {

	fs::path currentPath = fs::current_path();

	for (const auto& entry : fs::directory_iterator(currentPath)) {
		if (entry.is_regular_file()) {
			std::cout << "file: " << entry.path() << std::endl;
		}
	}
	for (const auto& entry : fs::directory_iterator(currentPath)) {
		if (entry.is_directory()) {
			std::cout << "directory: " << entry.path() << std::endl;
		}
	}


}

/*
Task 3: Create a directory "temp\dir\subdir". Next:
	a. Create a .txt file in temp directory temp\file.txt
	Use std::ofstream(<path_to_directory>).put("Hello Wrold"); -> You have to include fstream library for this to work.
	b. Copy the .txt file into the same directory, change it's name.
	c. Rename the initial .txt file with the use of: filesystem::rename()
	d. Copy the "dir" directory into the same directory, change it's name. (Copy non recursively)
	e. Copy the entire "temp" directory recursively into temp\copy directory (filesystem::copy_options::recursive)

	Your files should like like this after the operation:
		temp holds 2 files and 3 directories, two of which have subdirectories
		temp\file1.txt          //Example .txt file name
		temp\file2.txt
		temp\dir2               //Example directory name -> Without recursion.
		temp\dir
		temp\dir\subdir
		temp\copy\              //Contains recursive copy of the directory, contians all subdirectories and files

*/
void task3() {

	if (fs::exists("temp")) {
		//std::cout << "already exists\n";
		fs::remove_all("temp");
	}

	fs::create_directories("temp/dir/subdir");

	std::ofstream("temp\\file.txt").put('x');

	fs::copy("temp\\file.txt", "temp\\file2.txt");

	fs::rename("temp\\file.txt", "temp\\renamed.txt");

	fs::copy("temp\\dir", "temp\\dir2");

	fs::copy("temp", "temp\\copy1"/*, fs::copy_options::recursive */ );

	std::cout << "All objects created" << std::endl;

	std::system("tree temp");



}

/*
Task 4: Initial code generates a lot of diffrent files inside a new directory. Remove only the .cpp files. Than cout the number of files inside the directory.
*/
void task4() {
	if (fs::exists("test")) {
		fs::remove_all("test");
	}

	srand(time(NULL));
	std::filesystem::create_directories("test");
	for (size_t i = 0; i < rand() % 100; i++) {
		std::ofstream("test\\filet" + std::to_string(i) + ".txt").put('a');
		std::ofstream("test\\filep" + std::to_string(i) + ".py").put('a');
		std::ofstream("test\\filec" + std::to_string(i) + ".cpp").put('a');
	}
	//Do not edit the code above it generates files.

	for (const auto& entry : fs::directory_iterator("test")) {
		if (entry.path().extension() == ".cpp") 
			fs::remove(entry.path());
	}

}

/*
Task 5: Remove directories created in task 3 and 4.
*/
void task5() {
	if (fs::exists("temp"))
		fs::remove_all("temp");
	if (fs::exists("test"))
		fs::remove_all("test");

	std::cout << "removed all" << std::endl;

}

int main(int, char**) {

	std::cout << "Task 1\n";
	task1();
	std::cout << "Task 2\n";
	task2();
	std::cout << "Task 3\n";
	task3();
	std::cout << "Task 4\n";
	task4();
	std::cout << "Task 5\n";
	task5();

	return 0;
}
