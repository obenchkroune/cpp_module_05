#include "Intern.h"

const std::string Intern::m_forms[3] = {
	"shrubbery creation",
	"presidential pardon",
	"robotomy request"
};

AForm* (Intern::*const Intern::makeFunctions[3])(const std::string&) const = {
	&Intern::makeShruberryCreationForm,
	&Intern::makePresidentialPardonForm,
	&Intern::makeRobotomyRequestForm
};

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	AForm *form = NULL;

	for (int i = 0; i < 3; i++) {
		if (name == m_forms[i]) {
			
			form = (this->*makeFunctions[i])(target);
		}
	}
	if (!form)
		std::cout << "Unknown form name: " << name << std::endl; 
	else
		std::cout << "Intern creates form: \n" << *form << std::endl;
	return form;
}

AForm *Intern::makeShruberryCreationForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}
