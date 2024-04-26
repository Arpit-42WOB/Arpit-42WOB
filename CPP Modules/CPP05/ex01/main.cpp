#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat Officer_A("Officer A", 60);
	Bureaucrat Officer_B("Officer B", 40);
	Form Form_1("Form 1", 50, 50);
	Form Form_2("Form 2", 100, 100);
	
	std::cout << Officer_A << std::endl;
	std::cout << Officer_B << std::endl;
	std::cout << Form_1 << std::endl;
	std::cout << Form_2 << std::endl;

	Officer_B.signForm(Form_2);
	Officer_A.signForm(Form_1);
	
	return 0;
}
