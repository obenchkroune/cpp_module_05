#include "Bureaucrat.h"
#include "Form.h"

#define RED "\033[1;31m"
#define RESET "\033[0m"

int main() {
	Form f1("Form 1", 10, 5);
	Form f2("Form 2", 1, 1);
	Bureaucrat b1("Jhon Wick", 1);
	Bureaucrat b2("Jason", 15);

	b1.signForm(f2); // OK
	b2.signForm(f1); // should not be able to sign f1
	return 0;
}
