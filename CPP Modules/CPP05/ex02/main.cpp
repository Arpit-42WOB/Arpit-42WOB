#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main (void)
{
	Bureaucrat Officer_A("Officer A", 1);
	Bureaucrat Officer_B("Officer B", 150);
	ShrubberyCreationForm Form_1("Form 1");
	RobotomyRequestForm Form_2("Form 2");
	PresidentialPardonForm Form_3("Form 3");
	
	std::cout << Officer_A << std::endl;
	std::cout << Officer_B << std::endl;
	std::cout << Form_1 << std::endl;
	std::cout << Form_2 << std::endl;
	std::cout << Form_3 << std::endl;

	Officer_A.signForm(Form_2);
	Officer_A.signForm(Form_1);
	Officer_A.signForm(Form_3);
	Officer_A.executeForm(Form_1);
	Officer_A.executeForm(Form_2);
	Officer_A.executeForm(Form_3);
	
	return 0;
}