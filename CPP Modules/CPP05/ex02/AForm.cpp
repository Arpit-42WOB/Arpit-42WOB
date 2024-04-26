#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _gradeToSign(1), _gradeToExecute(1)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	_signed = false;
}

AForm::AForm(AForm const &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

AForm &AForm::operator=(AForm const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (_signed)
		throw AForm::FormAlreadySignedException();
	else if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	_executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form is " << (form.isSigned() ? "" : "not ") << "signed";
	return out;
}