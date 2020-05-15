#include "v2.0.h"


#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("pavarde1 < pavarde2") {
	Studentas a, b, c;
	a.setPavarde("Pavardyte");
	b.setPavarde("Adomaitis");
	c.setPavarde("Zigmantauskas");

		REQUIRE(SortByPavarde(a, b) == false);
		REQUIRE(SortByPavarde(a, c) == true);
		REQUIRE(SortByPavarde(b, c) == true);
}

TEST_CASE("vidurkis1 < vidurkis2") {
	Studentas a, b, c;
	a.galutinisVid = 8,5;
	b.galutinisVid = 9;
	c.galutinisVid = 7.45;

	REQUIRE(SortByVid(a, b) == true);
	REQUIRE(SortByVid(a, c) == false);
	REQUIRE(SortByVid(b, c) == false);
}

TEST_CASE("Vidurkis") {
	Studentas a, b, c;
	for (int i = 0; i < 5; i++)
	{
		a.namuDarbai.push_back(10);
		b.namuDarbai.push_back(5);
		c.namuDarbai.push_back(12);
	}

	REQUIRE(vidurkis(a.namuDarbai) == 10);
	REQUIRE(vidurkis(b.namuDarbai) == 5);
	REQUIRE(vidurkis(c.namuDarbai) == 12);
}