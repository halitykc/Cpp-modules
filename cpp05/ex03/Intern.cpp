
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {

    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {

    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern &other) {

    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {

    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeShrubberyCreationForm(const std::string &target) {

    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string &target) {

    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string &target) {

    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {

    std::string func_list[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*func_form[3])(const std::string &) = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm
    };

    for (int i = 0; i < 3; i++) {
        if (formName == func_list[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return func_form[i](target);
        }
    }
    std::cout << "Intern cannot create " << formName << " cus doesnt exist." << std::endl;
    return nullptr;
}
