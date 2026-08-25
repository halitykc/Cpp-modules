#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "------\n" << std::endl;

    try {
        Bureaucrat patron("Ahmet", 42);
        
        Form dayoffform("Day Off Form", 50, 50);
        
        Form topSecretForm("Top Secret Form", 10, 10);

        std::cout << "--- Start ---" << std::endl;
        std::cout << patron;
        std::cout << "\n";
        std::cout << dayoffform;
        std::cout << topSecretForm;

        std::cout << "\n--- OK ---" << std::endl;
        patron.signForm(dayoffform);
        std::cout << dayoffform; 

        std::cout << "\n--- NOK (GradeTooLow) ---" << std::endl;
        patron.signForm(topSecretForm);
        std::cout << topSecretForm; 

    } catch (std::exception &e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n--- Fail (GradeTooHigh) ---" << std::endl;
    try {
        
        Form brokenForm("Broken Form", 0, 50); 
    } catch (std::exception &e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n--- Fail (GradeTooLow) ---" << std::endl;
    try {
        Form brokenForm2("Broken Form 2", 50, 200); 
    } catch (std::exception &e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n----------------!" << std::endl;
    return 0;
}