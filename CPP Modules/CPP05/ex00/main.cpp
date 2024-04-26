#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat first("John", 25);
	Bureaucrat second("Jones", 100);
	try
	{
		Bureaucrat three("Jack", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat four("Pooh", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << first << std::endl;
	std::cout << second << std::endl;

	first = second;

	std::cout << first << std::endl;
	std::cout << second << std::endl;

	std::cout << "Grading Starts" << std::endl << std::endl;
	std::cout << "Before: " << first << std::endl;
	try
	{
		std::cout << "Incrementing 10" << std::endl;
		first.incrementGrade(10);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Now: " << first << std::endl << std::endl;

	try
	{
		std::cout << "Incrementing 120" << std::endl;
		first.incrementGrade(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Now: " << first << std::endl << std::endl;

	try
	{
		std::cout << "Decrementing 10" << std::endl;
		first.decrementGrade(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Now: " << first << std::endl << std::endl;

	try
	{
		std::cout << "Decrementing -120" << std::endl;
		first.decrementGrade(-120);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "After: " << first << std::endl << std::endl;
	return 0;
}