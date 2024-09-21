#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <iostream>

class Form;

class Bureaucrat {
public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(Form& f);

	/* Exceptions */
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	const std::string m_name;
	int m_grade;

	void checkGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& b);

#endif
