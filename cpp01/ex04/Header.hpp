


#ifndef HEADER_HPP
#define HEADER_HPP 


#include <iostream>
#include <fstream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class ChangeFile {

    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
        std::string _buffer;
    public:
        ChangeFile ( char *argv[] );
        ~ChangeFile( void );
        std::string getFilename( void );
        std::string getS1( void );
        std::string getS2( void );
        std::string readAll( std::ifstream& infile );
        std::string changeContent( void );

};

ChangeFile::ChangeFile(char *argv[]) {

    this->_filename = argv[1]; 
    this->_s1 = argv[2]; 
    this->_s2 = argv[3]; 
    std::cout << CYAN << "Constructor called, variables set!" RESET << std::endl;

}

ChangeFile::~ChangeFile( void ) {

    std::cout << MAGENTA << "Destructor called" RESET << std::endl;
}

std::string     ChangeFile::getFilename( void ) {

    return (this->_filename);
}

std::string     ChangeFile::getS1( void ) {

    return (this->_s1);
}

std::string     ChangeFile::getS2( void ) {

    return (this->_s2);
}

std::string     ChangeFile::readAll( std::ifstream& infile ) {

    std::string line;

    while (std::getline(infile, line))
    {
        this->_buffer += line + "\n";
    }
    std::cout << GREEN << "=> File read !" RESET << std::endl;
    return (this->_buffer);
}

std::string     ChangeFile::changeContent( void ) {

    size_t  position = this->_buffer.find(this->_s1);
    while (position != std::string::npos)
    {
        this->_buffer.erase(position, this->_s1.length());
        this->_buffer.insert(position, this->_s2);
        position = this->_buffer.find(this->_s1, position + this->_s2.length());
    }
    std::cout << GREEN << "=> Changes applied to the new file!" RESET << std::endl;

    return (this->_buffer);
}


#endif