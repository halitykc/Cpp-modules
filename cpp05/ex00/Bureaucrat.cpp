
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): _name("None"), _grade(50) {

}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :_name(name) {


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

const char*  Bureaucrat::GradeTooHigh::what() const throw() {

    return "Grade too High";

}

const char*  Bureaucrat::GradeTooLow::what() const throw() {

    return "Grade too Low";
    
}