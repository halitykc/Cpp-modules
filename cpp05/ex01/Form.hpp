


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat;

class Form
{
private:
    const std::string   _formName;
    bool                _signed;
    const int           _minGradeToSign;
    const int           _minGradeToExec;
public:
    Form(void); //ok
    Form(const std::string& name, const int minGradeS, const int minGradeToE); //ok
    Form(const Form& copy); //ok
    Form& operator=(const Form& other); //ok
    ~Form(); //ok

    void    beSigned(Bureaucrat& Buro); //ok
    std::string getName() const; //ok
    int getMinGrade() const; //ok
    int getMinExec() const; //ok
    bool isSigned() const; //ok



    class GradeTooHighException: public std::exception {

        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {

        public:
            virtual const char* what() const throw();
    };
};


std::ostream& operator<<( std::ostream& o, const Form& form);


#endif