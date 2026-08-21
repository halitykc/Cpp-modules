
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>


int main()
{
    std::cout << "-----------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat patron("Boss", 1);

        Bureaucrat employee("Worker", 150);

        Bureaucrat amele("amele", 75);

        ShrubberyCreationForm form1("home");
        ShrubberyCreationForm form2("garden");
        ShrubberyCreationForm form3("office");
        ShrubberyCreationForm form4("park");

        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << patron << std::endl;
        std::cout << employee << std::endl;
        std::cout << amele << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
        std::cout << form4 << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        employee.signForm(form1);
        employee.signForm(form2);
        employee.signForm(form3);
        employee.signForm(form4);
        std::cout << "-----------------------------------------------------" << std::endl;
        patron.signForm(form1);
        patron.signForm(form2);
        patron.signForm(form3);
        patron.signForm(form4);
        std::cout << "-----------------------------------------------------" << std::endl;
        employee.executeForm(form1);
        employee.executeForm(form2);
        employee.executeForm(form3);
        employee.executeForm(form4);
        std::cout << "-----------------------------------------------------" << std::endl;
        patron.executeForm(form1);
        patron.executeForm(form2);
        patron.executeForm(form3);
        patron.executeForm(form4);
        std::cout << "-----------------------------------------------------" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------------" << std::endl;
    return (0);
}