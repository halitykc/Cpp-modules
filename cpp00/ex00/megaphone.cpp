




#include <iostream>


char to_upper(char c) {

    if (c >= 'a' && 'z' >= c)
        return (c - ' ');
    else
        return (c);
}

void    print_upper(char *argv) {

    int i;

    i = -1;
    while (argv[++i])
        std::cout << to_upper(argv[i]) ;
}


int main(int argc, char  *argv[])
{
    int i;

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        i = 0;
        while (argv[++i])
            print_upper(argv[i]);
        std::cout << std::endl;

    }
    
    return 0;
}
