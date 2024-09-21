#ifndef INTERN_H
#define INTERN_H

#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string& name, const std::string& target) const;
	
private:
	static const std::string m_forms[3];
	static AForm* (Intern::* const makeFunctions[3])(const std::string&) const;

	AForm *makeShruberryCreationForm(const std::string& target) const;
	AForm *makePresidentialPardonForm(const std::string& target) const;
	AForm *makeRobotomyRequestForm(const std::string& target) const;
};

#endif
