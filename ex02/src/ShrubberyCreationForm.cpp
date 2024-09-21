#include "ShrubberyCreationForm.h"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("shrubbery creation", 145, 137), m_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()),
	  m_target(other.m_target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other) {
		m_target = other.m_target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	this->checkExecRequirements(b);
	std::ofstream tree((m_target + "_shrubbery").c_str());
	tree << "\n"
            "/~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\\n";
	tree.close();
}
