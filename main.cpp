#include "Header.h"

int main() {

    std::string arZinoKiek; // ar yra zinomas namu darbu skaicius
    std::vector<Studentas> rezultatai;
    rezultatai.reserve(10000);
    std::cout << "Jei norite sugeneruoti failus ir isskirstyti pagal galutinius rezultatus, iveskite 'sukurti': \n";
    std::cout << "Kitu atveju rasykit 'nenoriu': ";
    std::string sukurtiFailus;
    std::cin >> sukurtiFailus;
    while (std::cin.fail()) {
        ifFail();
        std::cin >> sukurtiFailus;
    }
    if (sukurtiFailus == "sukurti") {
        std::cout << "Kiek failu noresit generuoti?: ";
        int kiek;
        int n;
        int ndSk;
        std::string pav;
        std::cin >> kiek;
        while (kiek < 0 || kiek >5 || std::cin.fail())
        {
            ifFail();
            std::cin >> kiek;
        }
        std::cout << std::endl;
        std::string vidurkisArMediana;
        for (int i = 0; i < kiek; i++)
        { int g=1;
            std::cout << "Keliu studentu faila generuoti?: ";
            std::cin >> n;
            while (std::cin.fail())
            {
                ifFail();
                std::cin >> n;
            }
            pav = "Studentai" + std::to_string(n) + ".txt";
            std::cout << "Kiek sukurti namu darbu: ";
            std::cin >> ndSk;
            while (std::cin.fail())
            {
                ifFail();
                std::cin >> ndSk;
            }
            std::cout << "Norite gauti aritmetini vidurki (irasykite 'vidurki')\n ar mediana (irasykite 'mediana')?: ";
            std::cin >> vidurkisArMediana;
             for(int i=0; i<g; i++)
                {
                      if (vidurkisArMediana == "vidurki" || vidurkisArMediana == "mediana"){}
                     else {ifFail(); std::cin>> vidurkisArMediana; g++;}
                 }
            generuotiFailus(n, rezultatai, ndSk, pav);
            auto start = std::chrono::high_resolution_clock::now();
            NuskaitytiIsFailo(rezultatai, pav, sukurtiFailus, ndSk, vidurkisArMediana);
            auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
            std::chrono::duration<double> diff = end - start; // Skirtumas (s)
            std::cout << std::to_string(n) + " elementu nuskaitymas is failo uztruko: " << diff.count() << " s\n";
            vidurkisMediana(rezultatai, n, sukurtiFailus, vidurkisArMediana);
        }
    }
    else {
        std::cout << "Ar norite duomenis ivesti ranka, ar nuskaityti is failo?\n Jei ivesti ranka, irasykite 'ivesti', kitu atveju irasykite 'nuskaityti': ";
        duomenys(arZinoKiek, rezultatai, sukurtiFailus);
    }
    std::cout << "\nProgramos vykdymas baigtas";
 
}
