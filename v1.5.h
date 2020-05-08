#ifndef V1_5_H_INCLUDED
#define V1_5_H_INCLUDED


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cctype>
#include <random>
#include <fstream>
#include <chrono>
#include <string>
#include <functional>  
#include <numeric>   
#include <sstream>

class Zmogus {
protected:
    std::string vardas;
    std::string pavarde;
    Zmogus() {};
public:
    virtual void setVardas(std::string v) = 0; 
    virtual void setPavarde (std::string p) = 0; 
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
};



class Studentas : public Zmogus{
public:
    int ndSkaicius;
    double galutinisVid;
    double galutinisMed;
    std::vector<int> namuDarbai;

private:
    int egzaminas;
public:
    Studentas()
    {
        ndSkaicius = 0;
        galutinisVid = 0;
        galutinisMed = 0;
        egzaminas = 0;
    }
    void setVardas(std::string);
    void setPavarde(std::string);
    void setEgzaminas(int);
    inline int getEgzaminas() const { return egzaminas; }
    ~Studentas() {
        std::cout << "\nDestr.";
    }
    friend bool operator<(const Studentas& a, const Studentas& b) {
        return bool(a.galutinisVid < b.galutinisVid);
    }
    Studentas(const Studentas& s);
    Studentas& operator=(const Studentas& s);
    int operator+(const Studentas& s);
    int operator-(const Studentas& s);
    int operator*(const Studentas& s);
    int operator/(const Studentas& s);

    friend std::ostream& operator<<(std::ostream& out, const Studentas& a) {
        out << std::left << std::setw(20) << a.getPavarde();
        out << std::left << std::setw(20) << a.getVardas();
        return out;
    }

};



void ifFail();
bool SortByPavarde(Studentas& a, Studentas& b);
bool SortByVid(Studentas& a, Studentas& b);
bool SortByMed(Studentas& a, Studentas& b);
Studentas generavimas(Studentas& b);
Studentas pazymiuIvedimas(std::string kaipIvestiPazymius, int i, Studentas& b);
Studentas pazymiuIvedimas2(std::string kaipIvestiPazymius, int i, Studentas& b);
void Spausdinimas(std::string vidurkisArMediana, std::vector<Studentas>& rezultatai, int kiekStudentu, std::string failas);
void SkirtytiStudentus(std::string vidurkisArMediana, std::vector<Studentas>& rezultatai, int kiekStudentu);
void vidurkisMediana(std::vector<Studentas>& rezultatai, int kiekStudentu, std::string sukurtiFailus, std::string vidurkisArMediana);
void Skaitymas(std::vector<Studentas>& rezultatai, int kiekStudentu, int nd, Studentas(*kazkoksIvedimas)(std::string, int, Studentas&), std::string sukurtiFailus, std::string vidurkisArMediana);
void Ivedimas(std::string arZinoKiek, std::vector<Studentas>& rezultatai, int kiekStudentu, std::string sukurtiFailus, std::string vidurkisArMediana);
void NuskaitytiIsFailo(std::vector<Studentas>& rezultatai, std::string pav, std::string sukurtiFailus, int& ndsk, std::string vidurkisArMediana);
void KiekyraStudentu(std::string arZinoKiek, std::vector<Studentas>& rezultatai, std::string sukurtiFailus, std::string vidurkisArMediana);
void duomenys(std::string arZinoKiek, std::vector<Studentas>& rezultatai, std::string sukurtiFailus);
void generuotiFailus(int& n, std::vector<Studentas>& rezultatai, int& ndSk, std::string pav);

#endif // V_1VECTOR_H_INCLUDED
