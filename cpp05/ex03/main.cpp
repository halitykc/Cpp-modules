#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "-------" << std::endl;
    Intern stajyer;
    Bureaucrat patron("Patron", 1);
    
    std::cout << "\n--- OK---" << std::endl;
    AForm* rrf = stajyer.makeForm("robotomy request", "Mahmut");
    
    if (rrf != NULL)
    {
        try 
        {
            patron.signForm(*rrf);
            patron.executeForm(*rrf);
        }
        catch (std::exception &e) 
        {
            std::cout << "Exception : " << e.what() << std::endl;
        }
        
        delete rrf; 
    }

    std::cout << "\n--- NOK ---" << std::endl;
    AForm* unknownForm = stajyer.makeForm("Job Application form", "HR");
    
    if (unknownForm != NULL)
    {
        delete unknownForm;
    }

    std::cout << "\n------" << std::endl;
    return 0;
}