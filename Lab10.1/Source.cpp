#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool Include(string s, const char c)
{
	for (int i = 0; s[i + 2] != '\0'; i++)
		if (c == s[i] && c == s[i + 1] && c == s[i + 2])
			return true;
	return false;
}


void CreateTXT(char* fname) 
{
	ofstream fout(fname); 
	char ch; 
	string s; 
	do
	{
		cin.get(); 
		cin.sync();
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl; 
		if (Include(s, '*'))
			cout << "String has 3 * in a row" << endl;
		else
			cout << "String hasn`t 3 * in a row" << endl;
		cout << endl;
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	
}
void PrintTXT(char* fname) 
{
	ifstream fin(fname); 
	string s; 
	while (getline(fin, s)) // поки можна зчитувати рядок
	{
		cout << s << endl; 
	}
	cout << endl;
}


int main()
{
	char t[100]; 
	char c = '*';
	cout << "enter file name 1: "; cin >> t;
	CreateTXT(t); 
	PrintTXT(t); 
	return 0;
}