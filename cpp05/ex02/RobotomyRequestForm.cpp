
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default") {

    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target) {

    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), _target(copy._target) {

    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {

    if (this != &other) {
        this->AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}


void RobotomyRequestForm::execute(Bureaucrat const &exec) const {

    if (!this->isSigned())
        throw AForm::NoSignedFormException();
    if (exec.getGrade() > this->getMinExec())
        throw AForm::GradeTooLowException();

    std::cout << "Grrrrrrr... Brrrrrrrr..Brr..." << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
}