#include "Bureaucrat.h"
#include "Form.h"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: m_name(name), m_grade(grade)
{
	this->checkGrade(m_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: m_name(other.m_name), m_grade(other.m_grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other) {
		m_grade = other.m_grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
	return m_name;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

void Bureaucrat::incrementGrade()
{
	this->checkGrade(m_grade - 1);
	m_grade--;
}

void Bureaucrat::decrementGrade()
{
	this->checkGrade(m_grade + 1);
	m_grade++;
}

void Bureaucrat::signForm(Form &f)
{
	try {
		f.beSigned(*this);
		std::cout << m_name << " signed " << f.getName() << '\n';
	} catch (std::exception& e) {
		std::cout
			<< m_name << " couldn't sign " << f.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::checkGrade(int grade) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	return out << b.getName() << ", bureaucrat grade " << b.getGrade();
}
