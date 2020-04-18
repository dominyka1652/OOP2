#include <iostream>
#include <iomanip>
#include <algorithm>
#include <new>

struct Studentas{
    std::string vardas;
    std::string pavarde;
    int namuDarbai[200];
    int egzaminas;
    double galutinisVid;
    double galutinisMed;
};

ifFail()
{
    std::cin.clear();
    std::cout << "Ivesta neteisingai, bandykite is naujo: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
///Funkcija iskvieciama, jei nezinomas namu darbu skaicius
///Funkcija tikrina, ar pazymiu ivedimas parasytas tinkamai ir pagal pasirinkima, ar sugeneruoja pazymius, arba leidzia juos ivesti
void pazymiuIvedimas (std::string kaipIvestiPazymius, int i, int sk, int ndSkaicius, Studentas* rezultatai, int kiekStudentu)
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
                 rezultatai[i].namuDarbai[k] = input;
                }

                rezultatai[i].egzaminas = 1 + (double)rand()/RAND_MAX * 10;
                std::cout << "\nEgzamino pazymys: " << rezultatai[i].egzaminas << "\n";
             }

        }
//---------------------------------------------------------------------------------------------------------------------------------

        else if (kaipIvestiPazymius == "Ivesti" || kaipIvestiPazymius == "ivesti")
    {
        std::cout << "Namu darbu pazymiai (ivedus paskutini pazymi turi but parasomas 0):" ;
        for(int k=0; k<sk; k++){ //sk paaiskinimas 200 eilutej
            std::cin >> input;
           while (input <0 || input > 10 || std::cin.fail())
            {    ifFail();
                 std::cin >> input;
            }
               if (input != 0)
               {rezultatai[i].namuDarbai[k] = input;
            sk++;}
        }

        ndSkaicius = --sk;
        std::cout << "Egzamino pazimys ";
        std::cin >> rezultatai[i].egzaminas;
         while (rezultatai[i].egzaminas <= 0 || rezultatai[i].egzaminas > 10 || std::cin.fail())
            {   ifFail();
                std::cin >> rezultatai[i].egzaminas;}
    }

     else {
            ifFail();
            pazymiuIvedimas (kaipIvestiPazymius, i, sk, ndSkaicius, rezultatai, kiekStudentu);
        }
}

///Funkcija iskvieciama, kai zinomas namu darbu skaicius
///Funkcija tikrina, ar pazymiu ivedimas parasytas tinkamai ir pagal pasirinkima, ar sugeneruoja pazymius, arba leidzia juos ivesti
void pazymiuIvedimas2(std::string kaipIvestiPazymius,int i,Studentas* rezultatai,int kiekStudentu,int ndSkaicius){
int input; //ivestas arba sugeneruotas skaicius
      if (kaipIvestiPazymius == "sugeneruoti" || kaipIvestiPazymius == "Sugeneruoti")
        {   std:: cout << "Namu darbu pazymiai: ";
                 for(int k=0; k<ndSkaicius; k++)
                {
                 input = 1 + (double)rand()/RAND_MAX * 10;
                 std:: cout << input << " ";
                 rezultatai[i].namuDarbai[k] = input;
                }

                rezultatai[i].egzaminas = 1 + (double)rand()/RAND_MAX * 10;
                std::cout << "\nEgzamino pazymys: " << rezultatai[i].egzaminas << "\n";
        }



    else if (kaipIvestiPazymius == "Ivesti" || kaipIvestiPazymius == "ivesti"){
        std::cout << "Namu darbu pazymiai: ";
        for(int k=0; k<ndSkaicius; k++){
            std::cin >> input;
            while (input <= 0 || input > 10 || std::cin.fail())
            {   ifFail();
                std::cin >> input;
            }
            rezultatai[i].namuDarbai[k] = input;
        }

        std::cout << "Egzamino pazymys ";
        std::cin >> rezultatai[i].egzaminas;

        while (rezultatai[i].egzaminas <= 0 || rezultatai[i].egzaminas > 10 || std::cin.fail())
            {   ifFail();
                std::cin >> rezultatai[i].egzaminas;
            }
    }

     else {     ifFail();
                std::cin >> kaipIvestiPazymius;
                pazymiuIvedimas2(kaipIvestiPazymius, i, rezultatai, kiekStudentu, ndSkaicius);
        }
}

///Funkcija apskaiciuoja visu pazymiu vidurki ir mediana bei juos isspausdina
void vidurkisMediana (Studentas* rezultatai, int kiekStudentu, int &ndSkaicius){
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
            int arr[isviso] = {};
           for (int z=0; z<ndSkaicius; z++){
            nd += rezultatai[i].namuDarbai[z];
            arr[z] = rezultatai[i].namuDarbai[z];
           }

             vid = (nd/isviso*0.4) + (rezultatai[i].egzaminas*0.6);
             rezultatai[i].galutinisVid = vid;
            std::sort(arr, arr+isviso);

            if (isviso%2==0)
                { int l = 0;
                  double med = 0; //mediana
                    l = (isviso - 2)/2; //pazymiu skaicius iki reikiamu skaitmenu
                    med = std::round (((arr[l]+ arr[l+1])/2)*0.4 + (rezultatai[i].egzaminas*0.6));
                    rezultatai[i].galutinisMed = med;
                }
            else{
                int l = 0;
                double med = 0; //mediana
                l = isviso/2; //pazymiu skaicius iki reikiamu skaitmenu
                med = (arr[l]*0.4) + (rezultatai[i].egzaminas*0.6);
                rezultatai[i].galutinisMed = med;
            }
            std::cout << std::left << std::setw(20) << rezultatai[i].pavarde;
            std::cout << std::left << std::setw(25) << rezultatai[i].vardas;
            if(vidurkisArMediana == "vidurki") std::cout << std::left << std::setw(20) << std::setprecision(3) << rezultatai[i].galutinisVid;
            else if(vidurkisArMediana == "mediana") std::cout << std::left << std::setw(20) << std::setprecision(3) << rezultatai[i].galutinisMed;
            std::cout << std::endl;
        }
        delete [] rezultatai;
    }
    else {
        ifFail();
        vidurkisMediana(rezultatai,kiekStudentu,ndSkaicius);
    }
}

///I funkcija kreipiamasi jei yra nezinomas namu darbu skaicius ir ivedama, ar norima pazymius suvesti ranka, ar generuoti
void Skaitymas(Studentas* rezultatai, int kiekStudentu, int ndSkaicius){
std::string kaipIvestiPazymius; //ivedimo budas ranka arba generuojant
    for (int i = 0; i<kiekStudentu; i++)
    {   int sk = 1; //namu darbu skaicius, kuris didinamas ivedus nauja pazymi
         std::cout << "Vardas ";
        std::cin >> rezultatai[i].vardas;
        std::cout << "Pavarde ";
        std::cin >> rezultatai[i].pavarde;
        std::cout << "Ar norite pazymius irasyti ranka, ar atsitiktinai sugeneruoti?\n";
        std::cout << "Jei irasyti ranka, iveskite zodi 'ivesti'\n";
        std::cout << "Jei norite sugeneruoti atsitiktinai, iveskite zodi 'sugeneruoti': ";
        std::cin >> kaipIvestiPazymius;
        pazymiuIvedimas(kaipIvestiPazymius, i, sk, ndSkaicius, rezultatai, kiekStudentu);

    }
vidurkisMediana (rezultatai,kiekStudentu,ndSkaicius);

}

///Funkcija iskvieciama kai zinomas namu darbu skaicius ir ivedama, ar norima pazymius suvesti ranka, ar generuoti
void Skaitymas2(Studentas* rezultatai, int kiekStudentu, int ndSkaicius){

std::string kaipIvestiPazymius; //ivedimo budas ranka arba generuojant
    for (int i = 0; i<kiekStudentu; i++)
    {   std::cout << "Vardas ";
        std::cin >> rezultatai[i].vardas;
        std::cout << "Pavarde ";
        std::cin >> rezultatai[i].pavarde;
        std::cout << "Ar norite pazymius irasyti ranka, ar atsitiktinai sugeneruoti?\n";
        std::cout << "Jei irasyti ranka, iveskite zodi 'ivesti'\n";
        std::cout << "Jei norite sugeneruoti atsitiktinai, iveskite zodi 'sugeneruoti': ";
        std::cin >> kaipIvestiPazymius;
        pazymiuIvedimas2(kaipIvestiPazymius, i, rezultatai, kiekStudentu, ndSkaicius);

    }
    vidurkisMediana (rezultatai,kiekStudentu,ndSkaicius);
}

///Funkcijoje ivedama ar zinomas namu darbu skaicius ir tikrinama, ar ivestas atsakymas teisingas
///bei kreipiasi i kitas funkcijas ivykdzius salygas
void Ivedimas (std:: string arZinoKiek, int ndSkaicius, Studentas* rezultatai, int kiekStudentu){

     std::cin >> arZinoKiek; // ar yra zinomas namu darbu skaicius
    if (arZinoKiek == "Taip" || arZinoKiek == "taip")
        {   std::cout << "Iveskite namu darbu skaiciu: ";
            std::cin >> ndSkaicius;
            if (ndSkaicius >= 1)
            Skaitymas2(rezultatai, kiekStudentu, ndSkaicius);
            else if(ndSkaicius <= 0 || std::cin.fail()) {
                    ifFail();
                    Ivedimas(arZinoKiek, ndSkaicius, rezultatai, kiekStudentu);}
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
    if (kiekStudentu >= 1)
    {   Studentas* rezultatai = new Studentas [kiekStudentu];
        std:: cout << "Ar zinote namu darbu skaiciu? Jei zinote, parasykite 'taip', kitu atveju rasykite 'ne' ";
        Ivedimas(arZinoKiek, ndSkaicius, rezultatai, kiekStudentu);
    }
    else if (kiekStudentu <0 || std::cin.fail() ) {
            ifFail();
            KiekyraStudentu(kiekStudentu, arZinoKiek, ndSkaicius);
    }
}

//--------------------------------------------------------------
int main(){
    srand(time(NULL));
int kiekStudentu;
int ndSkaicius = 0;
std::string arZinoKiek; // ar yra zinomas namu darbu skaicius
std::cout << "Kiek yra studentu? ";
KiekyraStudentu (kiekStudentu, arZinoKiek, ndSkaicius);
std::cout << "\n Programa baigta vykdyti \n";
}
