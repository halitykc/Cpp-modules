



#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _targetfile;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& targetfile);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const &exec) const;


};


#endif