

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {



    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat& operator=(const Bureaucrat& buro);
        ~Bureaucrat();


        std::string    getName() const;
        int            getGrade() const;

        void    increGrade();
        void    decreGrade();


        class GradeTooHigh : public std::exception {

            public:
                virtual const char* what() const throw();
        };
        class GradeTooLow : public std::exception {

            public:
                virtual const char* what() const throw();
        };
    
        
        void    signForm( Form& form);
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat& buro);

#endif