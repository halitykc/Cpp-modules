#include <iostream>
#include <vector>

int main() {
    // C++98 uyumlu eleman ekleme
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::vector<int>::iterator it;
    it = numbers.begin();

    // İteratörün gösterdiği DEĞER (Çıktı: 1)
    std::cout << "Ilk elemanin degeri: " << *it << std::endl;

    // Vektörün içindeki ilk elemanın HAFIZA ADRESİ
    std::cout << "Ilk elemanin adresi: " << &*it << std::endl;

    // Sağlaması: Direkt 0. indeksin adresine bakıyoruz, üsttekiyle AYNI olmalı.
    std::cout << "numbers[0] adresi:   " << &numbers[0] << std::endl;

    return 0;
}
