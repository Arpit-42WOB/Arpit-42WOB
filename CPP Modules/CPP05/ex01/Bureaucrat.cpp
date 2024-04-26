#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade(int grade)
{
	if (grade < 0 || grade > 150 || grade >= _grade)
		throw Bureaucrat::GradeTooHighException();
	_grade -= grade;
}

void Bureaucrat::decrementGrade(int grade)
{
	if (grade < 0 || grade > 150 || grade + _grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += grade;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
