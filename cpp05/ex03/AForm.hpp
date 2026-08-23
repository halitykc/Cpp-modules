


#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat;

class AForm
{
private:
    const std::string   _formName;
    bool                _signed;
    const int           _minGradeToSign;
    const int           _minGradeToExec;
public:
    AForm(void); //ok
    AForm(const std::string& name, const int minGradeS, const int minGradeToE); //ok
    AForm(const AForm& copy); //ok
    AForm& operator=(const AForm& other); //ok
    virtual ~AForm(); //ok

    virtual void execute(Bureaucrat const &exec) const = 0;

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
    class NoSignedFormException: public std::exception {

        public:
            virtual const char* what() const throw();
    };
};


std::ostream& operator<<( std::ostream& o, const AForm& form);


#endif