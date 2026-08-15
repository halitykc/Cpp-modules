

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw() {

    return "Grade too High";
}

const char* Form::GradeTooLowException::what() const throw() {

    return "Grade too Low";
}

Form::Form(void): _formName(""), _signed(false), _minGradeToSign(5), _minGradeToExec(10) {

}

Form::Form(const std::string& name, const int minGradeS, const int minGradeToE) : _formName(name), _signed(false), _minGradeToSign(minGradeS), _minGradeToExec(minGradeToE) {

    if (minGradeS < 1)
        throw Form::GradeTooHighException();
    if  (minGradeS > 150)
        throw Form::GradeTooLowException();
    if (minGradeToE < 1)
        throw Form::GradeTooHighException();
    if  (minGradeToE > 150)
        throw Form::GradeTooLowException();

}

Form::Form(const Form& copy): _formName(copy._formName), _signed(copy._signed), _minGradeToSign(copy._minGradeToSign) ,_minGradeToExec(copy._minGradeToExec){


}

Form& Form::operator=(const Form& other) {

    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form() {

}

void Form::beSigned(Bureaucrat& Buro) {

    if (Buro.getGrade() > this->_minGradeToSign)
        throw Form::GradeTooLowException();
    
    this->_signed = true;
}

std::string Form::getName() const {

    return this->_formName;
}

int Form::getMinGrade() const {

    return this->_minGradeToSign;
}

int Form::getMinExec() const {

    return this->_minGradeToExec;
}

bool Form::isSigned() const {

    return this->_signed;
}

std::ostream& operator<<( std::ostream& os, const Form& form) {

    os << "Form Name " << form.getName() << std::endl;
    os << "Form is signed: " << form.isSigned() << std::endl;
    os << "Form min grade to sign: " << form.getMinGrade() << std::endl;
    os << "Form min grade to execute: " << form.getMinExec() << std::endl;

    return os;
}
