#ifndef PRESEDENTIALPARDONFORM_HPP
# define PRESEDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>


class PresidentialPardonForm : public AForm
{
private:
	std::string const _target;
	void _executeAction() const;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
};

#endif