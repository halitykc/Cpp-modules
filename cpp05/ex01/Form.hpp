


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
    Form(const Form& copy);
    Form& operator=(const Form& other);
    ~Form();

    void    beSigned(Bureaucrat& Buro);
    std::string getName() const;
    int getMinGrade() const;
    int getMinExec() const;
    bool isSigned() const;



    class GradeTooHighException: public std::exception {

        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowExeption: public std::exception {

        public:
            virtual const char* what() const throw();
    };
};


std::ostream& operator<<( std::ostream& o, const Form& form);


#endif