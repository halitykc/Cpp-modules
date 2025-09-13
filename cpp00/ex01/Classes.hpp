


#ifndef CLASSES_HPP
#define CLASSES_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define WIDTH 10

#include <iostream>
#include <iomanip>

class Contact {

    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkest_secret;
    public:
        void    add_firstname(std::string first_name);
        void    add_lasttname(std::string last_name);
        void    add_nickname(std::string nick_name);
        void    add_phone(std::string phone);
        void    add_secret(std::string darkest_secret);
        void    print_all(void);
        std::string    get_firstname(void);
        std::string    get_lasttname(void);
        std::string    get_nickname(void);
        std::string    get_phone(void);
        std::string    get_secret(void);
};

class Phonebook {

    private:
        Contact contact[8];
        int index;
        int isempty;
    public:
        Phonebook(void);
        void    add_to_contact(Contact contact);
        void    print_contact(int index);
        int     is_empty(void);
        void    printf_firstfour(void);

};

bool    any_chars(std::string n);
bool    any_digit(std::string n);
void    add_contact(Phonebook* phonebook);
void    search_contact(Phonebook phonebook);

#endif