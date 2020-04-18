#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cctype>
#include <random>

struct Studentas{
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;
};

void ifFail ()
{
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
std::cout << "Ivesta neteisingai, bandykite is naujo: ";
}

///Funkcija iskvieciama, jei nezinomas namu darbu skaicius
///Funkcija tikrina, ar pazymiu ivedimas parasytas tinkamai ir pagal pasirinkima, ar sugeneruoja pazymius, arba leidzia juos ivesti
Studentas pazymiuIvedimas (std::string kaipIvestiPazymius, int i, int sk, int ndSkaicius, Studentas a)
{ int input; //ivedamas arba generuojamas skaicius
      if (kaipIvestiPazymius == "sugeneruoti" || kaipIvestiPazymius == "Sugeneruoti")
        {     std::cout << "Kiek pazymiu norite sugeneruoti?: ";
              int kiek = 0; //kiek sugeneruot pazymiu
              std::cin >> kiek;
            while ( kiek <=0 || std::cin.fail())
             {   ifFail();
                 std::cin >> kiek;
             }

             if ( kiek > 0)
             {      std:: cout << "Namu darbu pazymiai: ";
                 for(int k=0; k<kiek; k++)
                {
                 input = 1 + (double)rand()/RAND_MAX * 10;
                 std:: cout  << input << " ";
                 a.namuDarbai.push_back(input);
                }

                a.egzaminas = 1 + (double)rand()/RAND_MAX * 10;
                std::cout << "\nEgzamino pazymys: " << a.egzaminas << "\n";
             }
        }
//---------------------------------------------------------------------------------------------------------------------------------

        else if (kaipIvestiPazymius == "Ivesti" || kaipIvestiPazymius == "ivesti")
    {
        std::cout << "Namu darbu pazymiai (ivedus paskutini pazymi turi but parasomas 0):" ;
        for(int k=0; k<sk; k++){ //sk paaiskinimas 198 eilutej
            std::cin >> input;
           while (input <0 || input > 10 || std::cin.fail())
            {ifFail();
                 std::cin >> input;
            }
               if (input != 0)
               {a.namuDarbai.push_back(input);
            sk++;}
        }

        ndSkaicius = --sk;
        std::cout << "Egzamino pazimys ";
        std::cin >> a.egzaminas;
         while (a.egzaminas <= 0 || a.egzaminas > 10 || std::cin.fail())
            {ifFail();
                std::cin >> a.egzaminas;
            }
    }

     else {     ifFail();
                std::cin >> kaipIvestiPazymius;
                pazymiuIvedimas (kaipIvestiPazymius, i, sk, ndSkaicius, a);
        }
        return a;
}

///Funkcija iskvieciama, kai zinomas namu darbu skaicius
///Funkcija tikrina, ar pazymiu ivedimas parasytas tinkamai ir pagal pasirinkima, ar sugeneruoja pazymius, arba leidzia juos ivesti
Studentas pazymiuIvedimas2(std::string kaipIvestiPazymius,int i,Studentas a,int kiekStudentu,int ndSkaicius){
int input; //ivestas arba sugeneruotas skaicius
      if (kaipIvestiPazymius == "sugeneruoti" || kaipIvestiPazymius == "Sugeneruoti")
        {   std:: cout << "Namu darbu pazymiai: ";
                 for(int k=0; k<ndSkaicius; k++)
                {
                 input = 1 + (double)rand()/RAND_MAX * 10;
                 std:: cout << input << " ";
                 a.namuDarbai.push_back(input);
                }
                a.egzaminas = 1 + (double)rand()/RAND_MAX * 10;
                std::cout << "\nEgzamino pazymys: " << a.egzaminas << "\n";
        }

    else if (kaipIvestiPazymius == "Ivesti" || kaipIvestiPazymius == "ivesti"){
        std::cout << "Namu darbu pazymiai: ";
        for(int k=0; k<ndSkaicius; k++){
            std::cin >> input;
            while (input <= 0 || input > 10 || std::cin.fail())
            {ifFail();
                std::cin >> input;
            }
           a.namuDarbai.push_back(input);
        }

        std::cout << "Egzamino pazymys ";
        std::cin >> a.egzaminas;

        while (a.egzaminas <= 0 || a.egzaminas > 10 || std::cin.fail())
            {   ifFail();
                std::cin >> a.egzaminas;
            }
    }

     else {     ifFail();
                std::cin >> kaipIvestiPazymius;
                pazymiuIvedimas2(kaipIvestiPazymius, i, a, kiekStudentu, ndSkaicius);
        }
    return a;
}


///Funkcija apskaiciuoja visu pazymiu vidurki ir mediana bei juos isspausdina
void vidurkisMediana (std::vector<Studentas>& rezultatai, int kiekStudentu, int ndSkaicius){
    std::string vidurkisArMediana;
    std::cout << "Norite gauti vidurki (iveskite 'vidurki') ar mediana (iveskite 'mediana')?: ";
    std::cin >> vidurkisArMediana;
    if (vidurkisArMediana == "vidurki" || vidurkisArMediana == "mediana"){
    double vid = 0; //vidurkis
    int isviso = 0; //bendra pazymiu suma
    isviso = ndSkaicius; //bendras visu pazymiu skaicius
    std::cout << std::left << std::setw(20) << "Pavarde ";
    std::cout << std::left << std::setw(20) << "Vardas ";
    if(vidurkisArMediana == "vidurki")std::cout << std::left << std::setw(15) << "Galutinis (Vid.) \n ";
    else if(vidurkisArMediana== "mediana")std::cout << std::left << std::setw(15) << "Galutinis (Med.)\n";
    std::cout << "------------------------------------------------------\n";
    for (int i = 0; i<kiekStudentu; i++)
        {  double nd = 0;
           for (int z=0; z<ndSkaicius; z++){
            nd += rezultatai[i].namuDarbai[z];
           }

             vid = (nd/isviso*0.4) + (rezultatai[i].egzaminas*0.6);
             rezultatai[i].galutinisVid = vid;
            std::sort(rezultatai[i].namuDarbai.begin(), rezultatai[i].namuDarbai.end());

            if (isviso%2==0)
                { int l = 0;
                  double med = 0; //mediana
                    l = (isviso - 2)/2; //pazymiu skaicius iki reikiamu skaitmenu
                    med = std::round ((((rezultatai[i].namuDarbai[l]+ rezultatai[i].namuDarbai[l+1])/2)*0.4) + (rezultatai[i].egzaminas*0.6));
                    rezultatai[i].galutinisMed = med;
                }
            else{
                int l = 0;
                double med = 0; //mediana
                l = isviso/2; //pazymiu skaicius iki reikiamu skaitmenu
                med = (rezultatai[i].namuDarbai[l]*0.4) + (rezultatai[i].egzaminas*0.6);
                rezultatai[i].galutinisMed = med;
            }
             std::cout << std::left << std::setw(20) << rezultatai[i].pavarde;
            std::cout << std::left << std::setw(25) << rezultatai[i].vardas;
            if(vidurkisArMediana == "vidurki") std::cout << std::left << std::setw(20) << std::setprecision(3) << rezultatai[i].galutinisVid;
            else if(vidurkisArMediana == "mediana") std::cout << std::left << std::setw(20) << std::setprecision(3) << rezultatai[i].galutinisMed;
            std::cout << std::endl;
        }
    }
      else {
        ifFail();
        vidurkisMediana(rezultatai,kiekStudentu,ndSkaicius);
    }
}


///I funkcija kreipiamasi jei yra nezinomas namu darbu skaicius ir ivedama, ar norima pazymius suvesti ranka, ar generuoti
void Skaitymas(std::vector<Studentas>& rezultatai, int kiekStudentu, int ndSkaicius){
std::string kaipIvestiPazymius; //ivedimo budas ranka arba generuojant
Studentas b, gal;
    for (int i = 0; i<kiekStudentu; i++)
    {   int sk = 1; //namu darbu skaicius, kuris didinamas ivedus nauja pazymi
         std::cout << "Vardas ";
        std::cin >> b.vardas;
        std::cout << "Pavarde ";
        std::cin >> b.pavarde;
        std::cout << "Ar norite pazymius irasyti ranka, ar atsitiktinai sugeneruoti?\n";
        std::cout << "Jei irasyti ranka, iveskite zodi 'ivesti'\n";
        std::cout << "Jei norite sugeneruoti atsitiktinai, iveskite zodi 'sugeneruoti': ";
        std::cin >> kaipIvestiPazymius;
        gal = pazymiuIvedimas(kaipIvestiPazymius, i, sk, ndSkaicius, b);
        rezultatai.push_back(gal);
        b = {}; gal = {};
    }
vidurkisMediana (rezultatai,kiekStudentu,ndSkaicius);

}

///Funkcija iskvieciama kai zinomas namu darbu skaicius ir ivedama, ar norima pazymius suvesti ranka, ar generuoti
void Skaitymas2(std::vector<Studentas>& rezultatai, int kiekStudentu, int ndSkaicius){
std::string kaipIvestiPazymius; //ivedimo budas ranka arba generuojant
Studentas b,gal;
    for (int i = 0; i<kiekStudentu; i++)
    {   std::cout << "Vardas ";
        std::cin >> b.vardas;
        std::cout << "Pavarde ";
        std::cin >> b.pavarde;
        std::cout << "Ar norite pazymius irasyti ranka, ar atsitiktinai sugeneruoti?\n";
        std::cout << "Jei irasyti ranka, iveskite zodi 'ivesti'\n";
        std::cout << "Jei norite sugeneruoti atsitiktinai, iveskite zodi 'sugeneruoti': ";
        std::cin >> kaipIvestiPazymius;
        gal = pazymiuIvedimas2(kaipIvestiPazymius, i, b, kiekStudentu, ndSkaicius);
        rezultatai.push_back(gal);
        b = {}; gal = {};
    }
    vidurkisMediana (rezultatai,kiekStudentu,ndSkaicius);
}

///Funkcijoje ivedama ar zinomas namu darbu skaicius ir tikrinama, ar ivestas atsakymas teisingas
///bei kreipiasi i kitas funkcijas ivykdzius salygas
void Ivedimas (std:: string arZinoKiek, int ndSkaicius, std::vector<Studentas>& rezultatai, int kiekStudentu){

     std::cin >> arZinoKiek; // ar yra zinomas namu darbu skaicius
    if (arZinoKiek == "Taip" || arZinoKiek == "taip")
        {   std::cout << "Iveskite namu darbu skaiciu: ";
            std::cin >> ndSkaicius;
            while (ndSkaicius <= 0 || std::cin.fail()) {
                   ifFail();
                     std::cin >> ndSkaicius; }
            if (ndSkaicius >= 1)
            Skaitymas2(rezultatai, kiekStudentu, ndSkaicius);
        }

   else if (arZinoKiek == "Ne" || arZinoKiek == "ne" )
        {   ndSkaicius = 1;
            Skaitymas(rezultatai,kiekStudentu, ndSkaicius);
        }
    else {
            ndSkaicius = 0;
            std::cout << "Atsakymas negalimas, bandykite dar karta: ";
            Ivedimas(arZinoKiek, ndSkaicius, rezultatai, kiekStudentu);
    }
}

///Funkcija tikrina, ar studentu ivestas kiekis yra geras
void KiekyraStudentu(int kiekStudentu, std::string arZinoKiek, int ndSkaicius){
    std::cin >> kiekStudentu;
    if (kiekStudentu >= 1 && kiekStudentu <= 1000)
    { std::vector<Studentas> rezultatai;
      rezultatai.reserve(kiekStudentu);
      rezultatai[kiekStudentu].namuDarbai.reserve(200);
        std:: cout << "Ar zinote namu darbu skaiciu? Jei zinote, parasykite 'taip', kitu atveju rasykite 'ne' ";
        Ivedimas(arZinoKiek, ndSkaicius, rezultatai, kiekStudentu);
    }
    else if (kiekStudentu <0 || kiekStudentu > 1000 || std::cin.fail() ) {
          ifFail();
            KiekyraStudentu(kiekStudentu, arZinoKiek, ndSkaicius);
    }
}

//--------------------------------------------------------------
int main(){
    srand(time(NULL));
int ndSkaicius = 0;
int kiekStudentu;
std::string arZinoKiek; // ar yra zinomas namu darbu skaicius
std::cout << "Kiek yra studentu? ";
KiekyraStudentu (kiekStudentu, arZinoKiek, ndSkaicius);
std::cout << "\n Programa baigta vykdyti \n";
}
