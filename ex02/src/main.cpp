#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"

void testShrubberyCreationForm();
void testPresidentialPardonForm();
void testRobotomyRequestForm();

int main() {
	testShrubberyCreationForm();
	testPresidentialPardonForm();
	testRobotomyRequestForm();
	return 0;
}

void testShrubberyCreationForm() {
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

void testPresidentialPardonForm() {
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

void testRobotomyRequestForm() {
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
