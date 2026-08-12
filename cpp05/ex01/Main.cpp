#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- TEST 1: Sorunsuz Calisan Burokrat (Happy Path) ---" << std::endl;
    try {
        Bureaucrat ahmet("Ahmet", 42);
        std::cout << ahmet << std::endl; // Operator<< testimiz

        std::cout << "Ahmet terfi aliyor..." << std::endl;
        ahmet.increGrade(); // 42 -> 41 olmali
        std::cout << ahmet << std::endl;

        std::cout << "Ahmet ceza aliyor..." << std::endl;
        ahmet.decreGrade(); // 41 -> 42 olmali
        std::cout << ahmet << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    }
    std::cout << "\n";


    std::cout << "--- TEST 2: Yaratilis (Constructor) Sirasinda Hata ---" << std::endl;
    try {
        std::cout << "Derecesi 0 olan bir Patron yaratilmaya calisiliyor..." << std::endl;
        Bureaucrat patron("Patron", 0); // Burada bomba patlamali!
        
        // Eger ustteki satir patlarsa, alt satir ASLA okunmaz.
        std::cout << patron << std::endl; 
    }
    catch (std::exception &e) {
        // Bomba buraya duser ve program cokmekten kurtulur.
        std::cerr << "Yakalandi! -> " << e.what() << std::endl;
    }
    std::cout << "\n";


    std::cout << "--- TEST 3: Terfi Sınırını (increGrade) Asma Hatasi ---" << std::endl;
    try {
        std::cout << "Derecesi 1 olan bir Kral yaratiliyor..." << std::endl;
        Bureaucrat kral("Kral", 1);
        std::cout << kral << std::endl;

        std::cout << "Kral terfi ettirilmeye calisiliyor..." << std::endl;
        kral.increGrade(); // Zaten 1, burada bomba patlamali!
        
        std::cout << "Bu yazi asla ekranda gorunmeyecek." << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Yakalandi! -> " << e.what() << std::endl;
    }
    std::cout << "\n";


    std::cout << "--- TEST 4: Dusurulme Sınırını (decreGrade) Asma Hatasi ---" << std::endl;
    try {
        std::cout << "Derecesi 150 olan bir Stajyer yaratiliyor..." << std::endl;
        Bureaucrat stajyer("Stajyer", 150);
        std::cout << stajyer << std::endl;

        std::cout << "Stajyerin rütbesi dusurulmeye calisiliyor..." << std::endl;
        stajyer.decreGrade(); // Zaten 150, burada bomba patlamali!
    }
    catch (std::exception &e) {
        std::cerr << "Yakalandi! -> " << e.what() << std::endl;
    }
    std::cout << "\n";

    return 0;
}