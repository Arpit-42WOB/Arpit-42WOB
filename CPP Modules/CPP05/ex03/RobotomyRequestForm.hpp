#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string const _target;
	void _executeAction() const;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();
};

#endif