#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _gradeToSign(1), _gradeToExecute(1)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::Form(Form const &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

Form &Form::operator=(Form const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.isSigned())
		out << "signed";
	else
		out << "not signed";
	out << " as grade to sign is: " << form.getGradeToSign() << " and grade to execute is: " << form.getGradeToExecute() << std::endl;
	return out;
}
