// src/test_Intern.cpp

#include <iostream>
#include "Intern.h"
#include "Bureaucrat.h"

int main() {
    Intern someRandomIntern;
	Bureaucrat b("Jhon Wick", 1);
	std::cout << b << std::endl;

	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	b.signForm(*rrf);
	std::cout << *rrf << std::endl;
	b.executeForm(*rrf);

	delete rrf;
    return 0;
}
