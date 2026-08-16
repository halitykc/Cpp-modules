#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- 42 MODULE 05 - EX01 TESTLERI ---\n" << std::endl;

    try {
        // 1. Bürokratımızı ve Formlarımızı Yaratalım
        Bureaucrat patron("Ahmet", 42);
        
        // Ahmet (42) bu formu imzalayabilir çünkü form 50 istiyor (Ahmet'in rütbesi daha yüksek/sayıca küçük)
        Form izinDilekcesi("Izin Dilekcesi", 50, 50);
        
        // Ahmet (42) bu formu İMZALAYAMAZ çünkü form 10 istiyor (Sadece en yüksek 10 rütbe)
        Form cokGizliBelge("Cok Gizli Belge", 10, 10);

        std::cout << "--- BASLANGIC DURUMLARI ---" << std::endl;
        std::cout << patron; // Bureaucrat operator<< testi
        std::cout << "\n";
        std::cout << izinDilekcesi; // Form operator<< testi
        std::cout << cokGizliBelge;

        std::cout << "\n--- TEST 1: BASARILI IMZA ---" << std::endl;
        patron.signForm(izinDilekcesi);
        std::cout << izinDilekcesi; // Imza durumunun Yes (1) oldugunu gormeliyiz

        std::cout << "\n--- TEST 2: BASARISIZ IMZA (GradeTooLow) ---" << std::endl;
        patron.signForm(cokGizliBelge);
        std::cout << cokGizliBelge; // Imza durumunun No (0) kaldigini gormeliyiz

    } catch (std::exception &e) {
        std::cerr << "Genel Hata: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: HATALI FORM YARATMA (GradeTooHigh) ---" << std::endl;
    try {
        // Form imzalamak icin 0 rütbe (gecersiz) istiyor!
        Form hataliForm("Bozuk Form", 0, 50); 
    } catch (std::exception &e) {
        std::cerr << "Hata yakalandi: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: HATALI FORM YARATMA (GradeTooLow) ---" << std::endl;
    try {
        // Form calistirmak icin 200 rütbe (gecersiz) istiyor!
        Form hataliForm2("Bozuk Form 2", 50, 200); 
    } catch (std::exception &e) {
        std::cerr << "Hata yakalandi: " << e.what() << std::endl;
    }

    std::cout << "\nTestler tamamlandi!" << std::endl;
    return 0;
}