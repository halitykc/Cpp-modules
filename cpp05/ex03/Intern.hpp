
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {

    private:
        static AForm* makeShrubberyCreationForm(const std::string &target) ;
        static AForm* makeRobotomyRequestForm(const std::string &target) ;
        static AForm* makePresidentialPardonForm(const std::string &target) ;

    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target) const;

};



#endif