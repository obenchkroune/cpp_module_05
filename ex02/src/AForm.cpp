#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_exec)
	: m_name(name), m_grade_to_sign(grade_to_sign),
	  m_grade_to_exec(grade_to_exec), m_is_signed(false)
{
	this->checkGrade(m_grade_to_sign);
	this->checkGrade(m_grade_to_exec);
}

AForm::AForm(const AForm &other)
	: m_name(other.m_name), m_grade_to_sign(other.m_grade_to_sign),
	  m_grade_to_exec(other.m_grade_to_exec), m_is_signed(other.m_is_signed)
{
}

AForm &AForm::operator=(const AForm &other)
{
	(void)other;
	return *this;
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return m_name;
}

bool AForm::getIsSigned() const
{
	return m_is_signed;
}

int AForm::getGradeToSign() const
{
	return m_grade_to_sign;
}

int AForm::getGradeToExec() const
{
	return m_grade_to_exec;
}

void AForm::beSigned(const Bureaucrat &b)
{
	this->checkSignRequirements(b);
	m_is_signed = true;
}

void AForm::checkGrade(int grade) const
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

void AForm::checkSignRequirements(const Bureaucrat &b) const
{
	if (b.getGrade() > m_grade_to_sign)
		throw AForm::GradeTooLowException();
}

void AForm::checkExecRequirements(const Bureaucrat &b) const
{
	if (b.getGrade() > m_grade_to_exec)
		throw AForm::GradeTooLowException();
	if (!m_is_signed)
		throw AForm::FormNotSignedException();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Bureaucrat's grade is too high";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	return out 
		<< "===================" << f.getName() << "===================" << '\n'
		<< "Status: " << (f.getIsSigned() ? "Signed!" : "Not Signed") << '\n'
		<< "Grade To Execute: " << f.getGradeToExec() << '\n'
		<< "Grade To Sign: " << f.getGradeToSign() << '\n';
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}
