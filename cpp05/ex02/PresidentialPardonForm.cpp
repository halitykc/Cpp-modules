
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {

    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {

    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) : AForm(copy), _target(copy._target) {

    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {

    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &other) {
        this->AForm::operator=(other);
        this->_target = other._target;
    }

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &exec) const {

    if (!this->isSigned())
        throw AForm::NoSignedFormException();
    if (exec.getGrade() > this->getMinExec())
        throw AForm::GradeTooLowException();

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}