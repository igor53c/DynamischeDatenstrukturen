// DynamischeDatenstrukturen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

void demoVector();
void ausgabe(vector<string>);

void demoList();
void ausgabe(list<int>);

void demoStack();

void demoQueue();

int main()
{
	locale::global(locale("German_germany"));

	//demoVector();

	//demoList();

	//demoStack();

	demoQueue();

	return EXIT_SUCCESS;
}

void demoVector()
{
	vector<string> v, v2;

	v.push_back("Franz");
	v.push_back("jagt");

	v2.push_back("im");
	v2.push_back("verwahrlosten");
	v2.push_back("Taxi");

	v.insert(v.end(), v2.begin(), v2.end());

	v.push_back("quer");
	v.push_back("durch");
	v.push_back("Bayern");

	ausgabe(v);

	v.insert(v.begin() + 3, "komplett");

	ausgabe(v);

	v.erase(v.begin() + 6);

	ausgabe(v);

	/*for (int i = 0; i < 4 ; i++)
	{
		v.erase(v.begin() + 2);
	}

	ausgabe(v);*/

	// oder
	v.erase(v.begin() + 2, v.begin() + 6);

	ausgabe(v);
}

void ausgabe(vector<string> v)
{
	/*for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;*/

	for (const auto wert : v)
	{
		cout << wert << " ";
	}

	cout << endl;

}

void demoList()
{
	list<int> list1, list2;

	int i;

	for (i = 1; i <= 10; i++)
	{
		list1.push_back(i);
	}

	ausgabe(list1);

	for (int i = 1; i <= 10; i++)
	{
		list2.push_front(i);
	}

	ausgabe(list2);

	list2.sort();

	ausgabe(list2);

	int anzahl = 5;

	while (anzahl--)
	{
		list1.pop_front();
	}

	ausgabe(list1);

	anzahl = 5;

	while (anzahl--)
	{
		list2.pop_back();
	}

	ausgabe(list2);

	cout << list1.front() << endl;
	cout << list2.back() << endl;

	list1.insert(list1.begin(), 5, 10);

	ausgabe(list1);

	list1.remove(10);

	ausgabe(list1);

	cout << list1.size() << endl;

	list2.reverse();

	ausgabe(list2);

	list1.clear();

	cout << list1.empty() << endl;

	list2.clear();

	for (int i = 0; i <= 10; i++)
	{
		if (i % 2 == 1)
			list1.push_back(i);
	}

	for (int i = 0; i <= 10; i++)
	{
		if (i % 2 == 0)
			list2.push_back(i);
	}

	ausgabe(list1);
	ausgabe(list2);

	list1.merge(list2);

	ausgabe(list1);
	ausgabe(list2);
}

void ausgabe(list<int> liste)
{
	/*list<int>::iterator it;

	for (it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;*/

	for (const auto wert : liste)
	{
		cout << wert << " ";
	}

	cout << endl;
}

void demoStack()
{
	stack<string> stapel;

	stapel.push("BMW");
	stapel.push("Audi");
	stapel.push("Mercedes");
	stapel.push("Honda");
	stapel.push("VW");
	stapel.push("Toyota");
	stapel.push("Porsche");

	while (!stapel.empty())
	{
		cout << stapel.top() << endl;

		stapel.pop();
	}
}

void demoQueue()
{
	queue<string> schlange;

	schlange.push("Fiat");
	schlange.push("LKW");
	schlange.push("Opel");
	schlange.push("Audi");
	schlange.push("Bus");
	schlange.push("Motorrad");
	schlange.push("Toyota");

	for (int i = 1; i <= 4; i++)
	{
		cout << schlange.front() << endl;

		schlange.pop();
	}

	cout << endl;

	schlange.push("Ford");
	schlange.push("Honda");

	while (!schlange.empty())
	{
		cout << schlange.front() << endl;

		schlange.pop();
	}
}
