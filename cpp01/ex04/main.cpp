



#include "Header.hpp"



int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << YELLOW << "Usage ./program filename s1 s2" RESET << std::endl;
        return 1;
    }

    ChangeFile file(argv);
    std::string content;
    
    std::ifstream infile(file.getFilename());
    if (!infile)
    {
        std::cerr << RED << "Error: infile" RESET << std::endl;
        return (1);
    }
    content =  file.readAll(infile);
    infile.close();

    std::ofstream outfile(file.getFilename() + ".replace");
    if (!outfile)
    {
        std::cerr << RED << "Error: outfile" RESET << std::endl;
        return (1);
    }
    outfile << file.changeContent();
    outfile.close();
    
    return 0;
}
