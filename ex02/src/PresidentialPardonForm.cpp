#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("presidential pardon", 25, 5), m_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()),
	  m_target(other.m_target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other) {
		m_target = other.m_target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const
{
	this->checkExecRequirements(b);
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox\n";
}
