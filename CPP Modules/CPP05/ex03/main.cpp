#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main (void)
{
	try
	{

	Bureaucrat Boss("Boss", 1);
	Bureaucrat Officer("Officer", 50);
	Bureaucrat Clerk("Clerk", 150);
	Intern first_intern;
	AForm *form1 = first_intern.makeForm("ShrubberyCreationForm", "Form 1");
	AForm *form2 = first_intern.makeForm("RobotomyRequestForm", "Form 2");
	AForm *form3 = first_intern.makeForm("PresidentialPardonForm", "Form 3");

	std::cout << *form1 << std::endl << std::endl;
	std::cout << *form2 << std::endl << std::endl;
	Clerk.signForm(*form1);
	std::cout << *form1 << std::endl << std::endl;
	Clerk.executeForm(*form1);

	std::cout << *form1 << std::endl << std::endl;
	Officer.signForm(*form1);
	std::cout << *form1 << std::endl << std::endl;
	Officer.executeForm(*form1);
	std::cout << *form1 << std::endl << std::endl;

	std::cout << *form2 << std::endl << std::endl;
	Officer.signForm(*form2);
	Officer.executeForm(*form2);
	std::cout << *form2 << std::endl << std::endl;

	std::cout << *form3 << std::endl << std::endl;
	Boss.executeForm(*form3);
	std::cout << *form3 << std::endl << std::endl;

	if (form1)
		delete form1;
	if (form2)
		delete form2;
	if (form3)
		delete form3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	return 0;
}
