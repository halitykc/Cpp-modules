

#include "Classes.hpp"



/*MEMBER FUNCTIONS*/
void    Contact::add_firstname(std::string first_name) {

    this->firstname = first_name;
}

void    Contact::add_lasttname(std::string last_name) {

    this->lastname = last_name;
}

void    Contact::add_nickname(std::string nick_name) {

    this->nickname = nick_name;
}

void    Contact::add_phone(std::string phone) {

    this->phonenumber = phone;
}

void    Contact::print_all( void ) {

    std::cout << GREEN "⌂ Firstname : " RESET << this->firstname << std::endl;
    std::cout << GREEN "⌂ Lastname : " RESET << this->lastname << std::endl;
    std::cout << GREEN "⌂ Nickname : " RESET << this->nickname << std::endl;
    std::cout << GREEN "⌂ Phonenumber : " RESET << this->phonenumber << std::endl;
    std::cout << GREEN "⌂ Darkest Secret: " RESET << this->darkest_secret << std::endl;
}

std::string    Contact::get_firstname(void) {

    return (this->firstname);
}

std::string    Contact::get_lasttname(void) {

    return (this->lastname);
}
std::string    Contact::get_nickname(void) {

    return (this->nickname);
}

std::string    Contact::get_phone(void) {

    return (this->phonenumber);
}

std::string    Contact::get_secret(void) {

    return (this->darkest_secret);
}


void    Contact::add_secret(std::string darkest_secret) {

    this->darkest_secret = darkest_secret;
}

Phonebook::Phonebook( void ){

    this->index = 0;
    this->isempty = 1;
}

void    Phonebook::add_to_contact(Contact contact) {
    
    this->index = this->index % 8;
    this->contact[index] = contact;
    this->index++;

    if (this->isempty == 1)
        this->isempty = 0;
}

void    Phonebook::print_contact(int index) {

    if (!contact[index].get_firstname().empty())
        contact[index].print_all();
    else
        std::cout << RED "Invalid Index" RESET<< std::endl;

}

int    Phonebook::is_empty(void) {

    return (this->isempty);
}

/* NON_MEMBER FUNCTIONS*/


bool    any_chars(std::string n) {

    int i;

    i = -1;
    while (n[++i])
        if (n[i] > '9' || n[i] < '0')
            return false;
    return true;
    
}

bool    any_digit(std::string n) {

    int i;

    i = -1;
    while (n[++i])
    {
        if (n[i] < '9' && n[i] > '0')
            return true;
    }
    return false;
}

void    add_contact(Phonebook* phonebook) {

    Contact contact;
    std::string f,l,n,p,d;

    std::cout << BLUE "\tFirstname= " RESET;
    std::getline(std::cin, f);

    if (f.empty() || any_digit(f))
    {
        std::cout << RED "firstname can't have empty fields or a number" RESET << std::endl;
        return;
    }

    std::cout << BLUE "\tLastname= " RESET;
    std::getline(std::cin, l);
    
    if (l.empty() || any_digit(l))
    {
        std::cout << RED "Lastname can't have empty fields or a number" RESET << std::endl;
        return;
    }
    
    std::cout << BLUE "\tNickname= " RESET;
    std::getline(std::cin, n);
    
    if (n.empty())
    {
        std::cout << RED "Nickname can't have empty fields" RESET << std::endl;
        return;
    }
    
    std::cout << BLUE "\tPhone= " RESET;
    std::getline(std::cin, p);
    
    if (p.empty() || !any_chars(p))
    {
        std::cout << RED "Phone can't have empty fields or 'A-Z'" RESET << std::endl;
        return;
    }
    
    std::cout << BLUE "\tSecret= " RESET;
    std::getline(std::cin, d);
    
    if (d.empty())
    {
        std::cout << RED "Secret can't have empty fields" RESET << std::endl;
        return;
    }
    
    contact.add_firstname(f);
    contact.add_lasttname(l);
    contact.add_nickname(n);
    contact.add_phone(p);
    contact.add_secret(d);

    phonebook->add_to_contact(contact);
}

std::string minmize(std::string str) {

    std::string ministr;

    if (str.length() > WIDTH)
    {
        ministr = str.substr(0, WIDTH - 1) + ".";
        return (ministr);
    }
    return (str);
}

void    Phonebook::printf_firstfour(void) {

    std::cout<< YELLOW "|" << std::setw(WIDTH) << "Index"
              << "|" << std::setw(WIDTH) << "Firstname"
              << "|" << std::setw(WIDTH) << "Lastname"
              << "|" << std::setw(WIDTH) << "Nickname"
              << "|" << std::setw(WIDTH) << "Phone"
              << "|" << std::setw(WIDTH) << "Secret"
              << "|" RESET << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (contact[i].get_firstname().empty())
            break;
        std::cout << YELLOW "|" RESET << std::setw(WIDTH) << i
                  << YELLOW "|" RESET << std::setw(WIDTH) << minmize(contact[i].get_firstname())
                  << YELLOW "|" RESET << std::setw(WIDTH) << minmize(contact[i].get_lasttname())
                  << YELLOW "|" RESET << std::setw(WIDTH) << minmize(contact[i].get_nickname())
                  << YELLOW "|" RESET << std::setw(WIDTH) << minmize(contact[i].get_phone())
                  << YELLOW "|" RESET << std::setw(WIDTH) << minmize(contact[i].get_secret())
                  << YELLOW "|" RESET << std::endl;
    }
}

void    search_contact(Phonebook phonebook) {

    std::string index;
    int i;

    if (phonebook.is_empty())
    {
        std::cout << YELLOW "Contacts are empty! Use 'ADD' to add some :D" RESET << std::endl;
        return;
    }
    else
        phonebook.printf_firstfour();

    std::cout << YELLOW "index = " RESET; 
    std::getline(std::cin, index);
    
    if (!any_chars(index))
    {
        std::cout << RED "Only numbers nigga" RESET << std::endl;
        return;
    }
    i = atoi(index.c_str());
    if (i >= 8)
    {
        std::cout << RED "Out of range nigga" RESET << std::endl;
        return;
    }
    
    phonebook.print_contact(i);

}