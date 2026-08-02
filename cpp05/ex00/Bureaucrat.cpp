
#include "Bureaucrat.hpp"


const char*  Bureaucrat::GradeTooHigh::what() const throw() {

    return "Grade too High";

}

const char*  Bureaucrat::GradeTooLow::what() const throw() {

    return "Grade too Low";
    
}

Bureaucrat::Bureaucrat(): _name("None"), _grade(50) {

}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :_name(name) {

    if  (grade < 1)
    {
        throw Bureaucrat::GradeTooHigh();
    }
    if  (grade > 150)
    {
        throw Bureaucrat::GradeTooLow();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
    
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& buro) {

    if ( this != &buro)
    {
        this->_grade = buro._grade;
    }

    return *this;
}

Bureaucrat::~Bureaucrat() {

}


std::string Bureaucrat::getName() const {

    return _name;
}

int         Bureaucrat::getGrade() const {

    return _grade;
}

void        Bureaucrat::increGrade() {

    if (_grade == 1)
        throw Bureaucrat::GradeTooHigh();
    _grade--;
}

void        Bureaucrat::decreGrade() {

    if (_grade == 150)
    {
        throw Bureaucrat::GradeTooLow();
    }
    
    _grade++;
}

