#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::_executeAction() const
{
	std::cout << "some drilling noises" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
