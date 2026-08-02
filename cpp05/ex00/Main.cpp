


#include "Bureaucrat.hpp"



int main()
{

    Bureaucrat buro("Halit", 1);

    std::cout << buro << std::endl;

    try
    {
        Bureaucrat burso("Halit", 0);
        
        buro.increGrade();
        std::cout << buro;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}
