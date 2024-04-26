#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	if (formName == "ShrubberyCreationForm")
		return (new ShrubberyCreationForm(target));
	else if (formName == "RobotomyRequestForm")
		return (new RobotomyRequestForm(target));
	else if (formName == "PresidentialPardonForm")
		return (new PresidentialPardonForm(target));
	else
	{
		std::cout << "Form " << formName << " not found" << std::endl;
		return (NULL);
	}
}
