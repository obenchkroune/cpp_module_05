#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"

void ShrubberyCreationForm_test();
void PresidentialPardonForm_test();
void RobotomyRequestForm_test();

int main() {
	ShrubberyCreationForm_test();
	PresidentialPardonForm_test();
	RobotomyRequestForm_test();
	return 0;
}

void ShrubberyCreationForm_test() {
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;

		ShrubberyCreationForm form("Home");
		std::cout << form << std::endl;

		bob.signForm(form);
		bob.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;

		ShrubberyCreationForm form("Office");
		std::cout << form << std::endl;

		alice.signForm(form);
		alice.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void PresidentialPardonForm_test() {
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;

		PresidentialPardonForm form("Home");
		std::cout << form << std::endl;

		bob.signForm(form);
		bob.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;

		PresidentialPardonForm form("Office");
		std::cout << form << std::endl;

		alice.signForm(form);
		alice.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void RobotomyRequestForm_test() {
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;

		RobotomyRequestForm form("Home");
		std::cout << form << std::endl;

		bob.signForm(form);
		bob.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;

		RobotomyRequestForm form("Office");
		std::cout << form << std::endl;

		alice.signForm(form);
		alice.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
