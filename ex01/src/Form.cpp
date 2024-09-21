#include "Form.h"
#include "Bureaucrat.h"

Form::Form(const std::string &name, int grade_to_sign, int grade_to_exec)
	: m_name(name), m_grade_to_sign(grade_to_sign),
	  m_grade_to_exec(grade_to_exec), m_is_signed(false)
{
	this->checkGrade(m_grade_to_sign);
	this->checkGrade(m_grade_to_exec);
}

Form::Form(const Form &other)
	: m_name(other.m_name), m_grade_to_sign(other.m_grade_to_sign),
	  m_grade_to_exec(other.m_grade_to_exec), m_is_signed(other.m_is_signed)
{
}

Form &Form::operator=(const Form &other)
{
	(void)other;
	return *this;
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return m_name;
}

bool Form::getIsSigned() const
{
	return m_is_signed;
}

int Form::getGradeToSign() const
{
	return m_grade_to_sign;
}

int Form::getGradeToExec() const
{
	return m_grade_to_exec;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > m_grade_to_sign)
		throw Form::GradeTooLowException();
	m_is_signed = true;
}

void Form::checkGrade(int grade) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade is too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Bureaucrat's grade is too high";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	return out 
		<< "===================" << f.getName() << "===================" << '\n'
		<< "Status: " << (f.getIsSigned() ? "Signed!" : "Not Signed") << '\n'
		<< "Grade To Execute: " << f.getGradeToExec() << '\n'
		<< "Grade To Sign: " << f.getGradeToSign() << '\n';
}
