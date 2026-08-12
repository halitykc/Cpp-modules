

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {

    return "Grade too High";
}

const char* Form::GradeTooLowExeption::what() const throw() {

    return "Grade too Low";
}

Form::Form(void): _formName(""), _minGradeToSign(5), _minGradeToExec(10), _signed(false) {

}

Form::Form(const std::string& name, const int minGradeS, const int minGradeToE) : _formName(name), _minGradeToSign(minGradeS), _minGradeToExec(minGradeToExec), _signed(false) {



}

Form::Form(const Form& copy): _minGradeToExec(copy._minGradeToExec), _minGradeToSign(copy._minGradeToSign), _signed(false) {


}