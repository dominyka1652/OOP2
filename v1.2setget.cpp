#include "v1.2.h"

void Studentas::setVardas(std::string vardas_) {
	vardas = vardas_;
}

void Studentas::setPavarde(std::string pavarde_) {
	pavarde = pavarde_;
}
void Studentas::setEgzaminas(int egzaminas_) {
	egzaminas = egzaminas_;
}



Studentas::Studentas(const Studentas& s)
{
	ndSkaicius = s.ndSkaicius;
	if (s.galutinisVid) galutinisVid = s.galutinisVid;
	if (s.galutinisMed) galutinisMed = s.galutinisMed;
	namuDarbai = s.namuDarbai;
	vardas = s.vardas;
	pavarde = s.pavarde;
	egzaminas = s.egzaminas;
}



Studentas& Studentas::operator=(const Studentas& s) {
	if (&s == this) return *this;
	ndSkaicius = s.ndSkaicius;
	if (s.galutinisVid) galutinisVid = s.galutinisVid;
	if (s.galutinisMed) galutinisMed = s.galutinisMed;
	namuDarbai = s.namuDarbai;
	vardas = s.vardas;
	pavarde = s.pavarde;
	egzaminas = s.egzaminas;
	return *this;
}

int Studentas::operator+(const Studentas& s) {

	return int{ egzaminas + s.egzaminas };
}

int Studentas::operator-(const Studentas& s) {

	return int(egzaminas - s.egzaminas);
}

int Studentas::operator*(const Studentas& s) {
	return int(egzaminas * s.egzaminas);
}

int Studentas::operator/(const Studentas& s) {
	return int(egzaminas / s.egzaminas);
}