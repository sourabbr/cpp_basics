#include "common.h"

struct tCity {
	String uName;
	Long   uPopulation;
	Double uCost;
};

struct tCountry {
	String uName;
	Vector <tCity> uCities;
};

struct tTours {
	String uTitle;
	Vector <tCountry> uCountries;
};

Void Display (const tTours & pTours);

int main ()
{
	tTours asia {
		"Tour of Asia",	{
			{"India", {
				{"Bangalore", 10000000, 5000},
				{"Hyderabad", 5000000, 7000},
				{"Delhi", 20000000, 10000}
			}},
			{"China", {
				{"Beijing", 12500000, 12000},
				{"Shanghai", 1292383, 23932}
			}}
		}
	};

	Display (asia);

    return 0;
}

Void Display (const tTours & pTours)
{
    cout << "**************************************************" << endl;
    cout << "\t\t" << pTours.uTitle << "\t\t" << endl;
    cout << "**************************************************" << endl << endl;
    cout << std::setw (15) << std::left << "Countries";
    cout << std::setw (10) << std::left << "Cities";
    cout << std::setw (15) << std::right << "Population";
    cout << std::setw (10) << std::right << "Cost" << endl;
    cout << "--------------------------------------------------" << endl;

    for (const auto countries:pTours.uCountries) {

            Int i = 0;
        for (const auto cities:countries.uCities) {

            cout << std::setw (15) << std::left << (i == 0 ? countries.uName : "");
            cout << std::setw (10) << std::left << cities.uName;
            cout << std::setw (15) << std::right << cities.uPopulation;
            cout << std::setw (10) << std::right << cities.uCost << endl;

            i++;
        }

        cout << endl;
    }
}