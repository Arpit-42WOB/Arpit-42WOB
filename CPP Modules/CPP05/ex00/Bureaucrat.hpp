#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <iosfwd>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int grade);
	void decrementGrade(int grade);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif