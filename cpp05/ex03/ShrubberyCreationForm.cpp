#include    "ShrubberyCreationForm.hpp"




ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _targetfile("default_target")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &targetfile): AForm("ShrubberyCreationForm", 145, 137), _targetfile(targetfile)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy), _targetfile(copy._targetfile)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->AForm::operator=(other);
        this->_targetfile = other._targetfile;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &exec) const
{
    if (!this->isSigned())
        throw AForm::NoSignedFormException();
    if (exec.getGrade() > this->getMinExec())
        throw AForm::GradeTooLowException();

    std::string tempname = this->_targetfile + "_shrubbery";
    std::ofstream file(tempname.c_str());
    if (!file)
    {
        std::cerr << "Error: Could not open file " << tempname << std::endl;
        return;
    }

    file << "                                              ." << std::endl;
    file << "                                   .         ;" << std::endl;
    file << "      .              .              ;%     ;;" << std::endl;
    file << "        ,           ,                :;%  %;" << std::endl;
    file << "         :         ;                   :;%;'     .," << std::endl;
    file << ",.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
    file << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "           `@%:.  :;%.         ;@@%;'" << std::endl;
    file << "             `@%.  `;@%.      ;@@%;" << std::endl;
    file << "               `@%%. `@%%    ;@@%;" << std::endl;
    file << "                 ;@%. :@%%  %@@%;" << std::endl;
    file << "                   %@bd%%%bd%%:;" << std::endl;
    file << "                     #@%%%%%:;;" << std::endl;
    file << "                     %@@%%%::;" << std::endl;
    file << "                     %@@@%(o);  . '" << std::endl;
    file << "                     %@@@o%;:(.,'" << std::endl;
    file << "                 `.. %@@@o%::;" << std::endl;
    file << "                    `)@@@o%::;" << std::endl;
    file << "                     %@@(o)::;" << std::endl;
    file << "                    .%@@@@%::;" << std::endl;
    file << "                    ;%@@@@%::;." << std::endl;
    file << "                   ;%@@@@%%:;;;." << std::endl;
    file << "               ...;%@@@@@%%:;;;;,.." << std::endl;

    file.close();
}

