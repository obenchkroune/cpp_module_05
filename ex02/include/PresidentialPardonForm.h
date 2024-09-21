#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& b) const;

private:
	std::string m_target;
};

#endif
