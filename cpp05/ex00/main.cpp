#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- (Happy Path) ---" << std::endl;
    try {
        Bureaucrat ahmet("Ahmet", 42);
        std::cout << ahmet << std::endl;

        std::cout << "Ahmet Grade Up..." << std::endl;
        ahmet.increGrade();
        std::cout << ahmet << std::endl;

        std::cout << "Ahmet Grade  Down..." << std::endl;
        ahmet.decreGrade(); 
        std::cout << ahmet << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exeption : " << e.what() << std::endl;
    }
    std::cout << "\n";


    std::cout << " (Constructor) ---" << std::endl;
    try {
        std::cout << "Trying Grade 0 Patron..." << std::endl;
        Bureaucrat patron("Patron", 0);
        
        
        std::cout << patron << std::endl; 
    }
    catch (std::exception &e) {
        std::cerr << "Exeption : " << e.what() << std::endl;
    }
    std::cout << "\n";


    std::cout << "--- Grade Borderline ---" << std::endl;
    try {
        std::cout << "Trying Grade 1 King..." << std::endl;
        Bureaucrat king("King", 1);
        std::cout << king << std::endl;

        std::cout << "Trying to increase King's grade..." << std::endl;
        king.increGrade();
        
        std::cout << "You wont see this message" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exeption : " << e.what() << std::endl;
    }
    std::cout << "\n";


    std::cout << "--- Grade Borderline ---" << std::endl;
    try {
        std::cout << "Trying Grade 150 Intern..." << std::endl;
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;

        std::cout << "Intern's grade is being decreased..." << std::endl;
        intern.decreGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exeption : " << e.what() << std::endl;
    }
    std::cout << "\n";

    return 0;
}