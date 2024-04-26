#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::_executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file;

	file.open(filename.c_str(), std::ofstream::binary | std::ofstream::trunc);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
}
