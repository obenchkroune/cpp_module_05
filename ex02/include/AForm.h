#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
public:
	AForm(const std::string& name, int grade_to_sign, int grade_to_exec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	virtual void execute(Bureaucrat const & executor) const = 0;
	
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

	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw();
	};
	
private:
	const std::string m_name;
	const int m_grade_to_sign;
	const int m_grade_to_exec;
	bool m_is_signed;

protected:
	void checkGrade(int grade) const;
	void checkSignRequirements(const Bureaucrat& b) const;
	void checkExecRequirements(const Bureaucrat& b) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
