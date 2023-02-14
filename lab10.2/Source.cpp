#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname) // ��������� ����� � �������� �����
{
	ofstream fout(fname); // ������� ���� ��� ������
	char ch; // ������� ����������� � �� ������������ ��������
	string s; // �������� ������������ �����
	do
	{
		cin.get(); // ������� ����� ��������� � ��� �� ���� �������
		cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
		cout << "enter line: "; getline(cin, s); // ����� �����
		fout << s << endl; // �������� ���� � ����
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname) // ��������� ����� �� �����
{
	ifstream fin(fname); // ������� ���� ��� ����������
	string s; // ���������� �����
	while (getline(fin, s)) // ���� ����� ��������� �����
	{
		cout << s << endl; // �������� ���� �� �����
	}
	cout << endl;
}


string Delete(string& str, const char* cs)
{
	string* d = new string[str.length() + 1];
	string* t = d;
	size_t len = str.length();
	bool b; size_t k = len;
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ' ') { k = i; break; }

	for (int i = 0; i < k; i++)
	{
		b = true;
		for (int j = 0; cs[j] != '\0'; j++)
			if (str[i] == cs[j])
				b = false;
		if (b)
			*t++ = str[i];
	}

	for (int i = k; i < len; i++)
		*t++ = str[i];
	*t = '\0';
	size_t copy(str, len, d) ;
	return *d;
}

void SortTXT(char* fname, char* gname) // ���������� ����� ���������� �����
{
	ofstream g(gname); // ������� ������ ���� ��� ������
	string s, mins, z = ""; // s � ���������� � ����� f �����
	// mins � �����, ���� ���������
	// ���������
	// z - ��������� � ���� g �����
	int k; // - �����, �� � �� �����, �� ���
	// �������� � ���� g
	do // ���� ������ ���������� �����
	{ // � ���, �� �� �� ������� � ���� g
		k = 0; // ��������� �������� �����,
		// �� ��� ��������
		ifstream f(fname); // ������� ������ ���� ��� ����������
		// ����� ������ ������ ���� � �������
		// ���� ������� ������ ���������� �� �� �� ��������� �����
		while (getline(f, s)) // ���� ����� ��������� �����
		{
			if (s <= z) // ���� ��� ����� ��� ��������� � ���� g
				continue; // - ���������� ����
			mins = s; // ������� ������ �� �� ��������� �����
			// - ���������
			k++; // ������� �� �� ��������� �����
			// - �������� ��������
			break; // ������ � ����� ��������� �����
		} // mins ����������� ��������
		// ���� ������ ���������� �� �� �� ��������� �����
		while (getline(f, s)) // ���� ����� ��������� �����
		{
			char cs[] = "1234567890?><,./!'_}{;:!@#$%^\&*()";
			if (s < mins) // ���� ���������� ����� ������
			{ 
				Delete(s, cs);
				
			} // �����
		}
		// ����� ���������� � �� ��������� ����� � ���� g
		z = mins; // ������ ���������� ��������� 
		// ��������� � �� ��������� �����
		if (k > 0) // ���� ���� ������� �� �� �������
			g << z << endl; // ����� - �������� ��������� � ���
		f.close(); // ������� ������ ����
	} // ��� ���� ������ ���� � �������
	while (k > 0); // ����������, ���� � �� ������� �����
}
int main()
{
	// text files
	char fname[100]; // ��'� ������� �����
	cout << "enter file name 1: "; cin >> fname;
	CreateTXT(fname); // ����� ����� ����� � ���������
	PrintTXT(fname); // ������ ���� ������� ����� �� �����
	char gname[100]; // ��'� ������� �����
	cout << "enter file name 2: "; cin >> gname;
	SortTXT(fname, gname); // ����������� ����� ������� �����,
	// ��������� �������� � ������ ����
	PrintTXT(gname); // ������ ���� ������� ����� �� �����
	return 0;
}