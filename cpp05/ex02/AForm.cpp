

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {

    return "Grade too High";
}

const char* AForm::GradeTooLowException::what() const throw() {

    return "Grade too Low";
}

AForm::AForm(void): _formName(""), _signed(false), _minGradeToSign(5), _minGradeToExec(10) {

}

AForm::AForm(const std::string& name, const int minGradeS, const int minGradeToE) : _formName(name), _signed(false), _minGradeToSign(minGradeS), _minGradeToExec(minGradeToE) {

    if (minGradeS < 1)
        throw AForm::GradeTooHighException();
    if  (minGradeS > 150)
        throw AForm::GradeTooLowException();
    if (minGradeToE < 1)
        throw AForm::GradeTooHighException();
    if  (minGradeToE > 150)
        throw AForm::GradeTooLowException();

}

AForm::AForm(const AForm& copy): _formName(copy._formName), _signed(copy._signed), _minGradeToSign(copy._minGradeToSign) ,_minGradeToExec(copy._minGradeToExec){


}

AForm& AForm::operator=(const AForm& other) {

    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {

}

void AForm::beSigned(Bureaucrat& Buro) {

    if (Buro.getGrade() > this->_minGradeToSign)
        throw AForm::GradeTooLowException();
    
    this->_signed = true;
}

std::string AForm::getName() const {

    return this->_formName;
}

int AForm::getMinGrade() const {

    return this->_minGradeToSign;
}

int AForm::getMinExec() const {

    return this->_minGradeToExec;
}

bool AForm::isSigned() const {

    return this->_signed;
}

std::ostream& operator<<( std::ostream& os, const AForm& form) {

    os << "Form Name " << form.getName() << std::endl;
    os << "Form is signed: " << form.isSigned() << std::endl;
    os << "Form min grade to sign: " << form.getMinGrade() << std::endl;
    os << "Form min grade to execute: " << form.getMinExec() << std::endl;

    return os;
}
