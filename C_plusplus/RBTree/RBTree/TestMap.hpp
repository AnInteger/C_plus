#pragma once
#include <map>
#include <iostream>
#include <string>
using namespace std;


void TestMap()
{
	map<string, string> m1;
	map<string, string> m2{ {"apple","ƻ��"},{"orange","����"},{"peach","����"} };
	auto it = m2.begin();
	while (it != m2.end())
	{
		cout << it->first << "----->" << (*it).second<< endl;
		it++;
	}
}