#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
public:
	Form(const std::string& name, int grade_to_sign, int grade_to_exec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	void beSigned(const Bureaucrat& b);
	
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
	const int m_grade_to_sign;
	const int m_grade_to_exec;
	bool m_is_signed;

	void checkGrade(int grade) const;
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
