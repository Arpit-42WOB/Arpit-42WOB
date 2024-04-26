#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <stdexcept>

class AForm;

class Intern
{
public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();
	AForm *makeForm(const std::string &formName, const std::string &target);
	class FormNotFoundException : public std::exception
	{
		virtual const char *what() const throw();
	};

};

#endif