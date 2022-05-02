// Assoziativspeicher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

void demoMap();

map<string, string> PLZMap;

void postleitzahlenDateiEinlesen();

bool leseDatei(const string);

vector<string> stringSplit(const string, const char);

string toLower(const string);

void postleitzahlenSuchen();

void ausgabeAllerPLZ();

int main()
{
	locale::global(locale("German_germany"));

	// demoMap();

	postleitzahlenDateiEinlesen();

	return EXIT_SUCCESS;
}

void demoMap()
{
	map<string, string> PLZMap;

	PLZMap["76689"] = "Karlsruhe";
	PLZMap["20097"] = "Hamburg";
	PLZMap["63069"] = "Offenbach/Main";
	PLZMap["10178"] = "Berlin";

	cout << PLZMap["76689"] << endl;

	PLZMap["76689"] = "Karlsruhe - Stadtmitte";

	cout << PLZMap["76689"] << endl;

	if (PLZMap.find("12345") != PLZMap.end())
	{
		cout << PLZMap["12345"] << endl;
	}
	else
	{
		cout << "nicht gefunden" << endl;
	}
}

void postleitzahlenDateiEinlesen()
{
	string eingabe;

	cout << "\nName der Postleitzahlendatei: " << endl;

	getline(cin, eingabe);

	if (!leseDatei(eingabe))
		return;

	cout << "j/n?" << endl;

	getline(cin, eingabe);

	if (toLower(eingabe) == "j")
		postleitzahlenSuchen();

	cout << "Liste j/n?" << endl;

	getline(cin, eingabe);

	if (toLower(eingabe) == "j")
		ausgabeAllerPLZ();
}

bool leseDatei(const string dateiname)
{
	string zeile, sOrt;

	int recordCount = 0;
	int addCount = 0;

	cout << "Die PLZDatei '" << dateiname << "' wird eingelesen..." << endl;

	ifstream datei(dateiname);

	if (datei.fail())
	{
		cerr << "Fehler" << endl;

		return false;
	}

	while (!datei.eof())
	{
		getline(datei, zeile);

		recordCount++;

		//cout << zeile << endl;

		if(recordCount % 50 == 0)
			cout << "[" << recordCount << "]\r";

		vector<string> v = stringSplit(zeile, ';');

		if (v.size() >= 2)
		{
			sOrt = v[1];

			for (int i = 2; i < v.size(); i++)
			{
				sOrt += ", " + v[i];
			}

			PLZMap[v[0]] = sOrt;

			addCount++;
		}
	}

	cout << "[" << recordCount << "]" << endl;
	cout << "addCount: [" << addCount << "]" << endl;
	cout << "PLZMap.size(): [" << PLZMap.size() << "]" << endl;

	datei.close();

	printf("\n\nErfolgreich\n");

	return true;
}

vector<string> stringSplit(const string s, const char delim)
{
	vector<string> v;

	stringstream sstream(s);

	string element;

	while (getline(sstream, element, delim))
	{
		v.push_back(element);
	}

	return v;
}

string toLower(const string s)
{
	string retValue;

	for (int i = 0; i < s.length(); i++)
	{
		retValue += tolower(s.at(i));
	}

	return retValue;
}

void postleitzahlenSuchen()
{
	string eingabe;

	system("cls");

	while (true)
	{
		cout << "\nPLZ eingeben oder 'exit' um die Suche beenden" << endl;

		getline(cin, eingabe);

		if(toLower(eingabe) == "exit")
			break;

		if (PLZMap.find(eingabe) != PLZMap.end())
		{
			cout << eingabe << " - " << PLZMap[eingabe] << endl;
		}
		else
		{
			cout << "niht gefunden" << endl;
		}
	}
}

void ausgabeAllerPLZ()
{
	int entryCount = 0;

	system("cls");

	for (const auto eintrag : PLZMap)
	{
		cout << eintrag.first << " - " << eintrag.second << endl;
		entryCount++;
	}

	cout << "entryCount: " << entryCount << endl;
}






