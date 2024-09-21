#include "RobotomyRequestForm.h"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("robotomy request", 72, 45), m_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()),
	  m_target(other.m_target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other) {
		m_target = other.m_target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	this->checkExecRequirements(b);
	std::cout << "Drilling noises......\n";
	if (time(0) % 2) {
		std::cout << m_target << " has been robotomized successfully\n";
	} else {
		std::cout << "the robotomy failed\n";
	}
}
