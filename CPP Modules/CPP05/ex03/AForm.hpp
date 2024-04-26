#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <iosfwd>

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

	virtual void _executeAction() const = 0;
public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	virtual ~AForm();
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat const &bureaucrat);
	void execute(Bureaucrat const &executor) const;
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif