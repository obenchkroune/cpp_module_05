#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	
	void execute(const Bureaucrat& executor) const;

private:
	std::string m_target;
};

#endif
