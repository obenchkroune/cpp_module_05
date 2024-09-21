#include "Bureaucrat.h"

#define RED "\033[1;31m"
#define RESET "\033[0m"

int main() {
	try {
		Bureaucrat b("Invalid", 0);
		std::cout << b << "\n";
	} catch (std::exception& e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}

	Bureaucrat b1("Jhon Wick", 1);
	Bureaucrat b2("Darius", 150);
	
	std::cout << b1 << "\n";
	std::cout << b2 << "\n";

	try {
		b1.incrementGrade();
		std::cout << "This should never be printed!\n";
	} catch (std::exception& e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}

	try {
		b2.incrementGrade();
		std::cout << b2 << '\n';
		b2.decrementGrade();
		b2.decrementGrade();
		std::cout << "This should never be printed!\n";
	} catch (std::exception& e) {
		std::cout << RED "Exception: " RESET << e.what() << std::endl;
	}
	return 0;
}
