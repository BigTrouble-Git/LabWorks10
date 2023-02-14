#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	do
	{
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); // ввели рядок
		fout << s << endl; // записали його у файл
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname) // виведення файлу на екран
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
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

void SortTXT(char* fname, char* gname) // сортування рядків текстового файлу
{
	ofstream g(gname); // відкрили другий файл для запису
	string s, mins, z = ""; // s – прочитаний з файлу f рядок
	// mins – рядок, який вважається
	// найменшим
	// z - записаний у файл g рядок
	int k; // - вказує, чи є ще рядки, які слід
	// записати у файл g
	do // цикл запису мінімального рядка
	{ // з тих, які ще не записані у файл g
		k = 0; // обнуляємо лічильник рядків,
		// які слід записати
		ifstream f(fname); // відкрили перший файл для зчитування
		// тепер будемо читати файл з початку
		// цикл початку пошуку мінімального із ще не записаних рядків
		while (getline(f, s)) // поки можна зчитувати рядки
		{
			if (s <= z) // якщо цей рядок вже записаний у файл g
				continue; // - пропускаємо його
			mins = s; // вважаємо перший ще не записаний рядок
			// - мінімальним
			k++; // знайшли ще не записаний рядок
			// - збільшили лічильник
			break; // вийшли з циклу присвоєння змінній
		} // mins початкового значення
		// цикл пошуку мінімального із ще не записаних рядків
		while (getline(f, s)) // поки можна зчитувати рядки
		{
			char cs[] = "1234567890?><,./!'_}{;:!@#$%^\&*()";
			if (s < mins) // якщо прочитаний рядок менший
			{ 
				Delete(s, cs);
				
			} // рядків
		}
		// запис мінімального з не записаних рядків у файл g
		z = mins; // будемо записувати знайдений 
		// мінімальний з не записаних рядків
		if (k > 0) // якщо були знайдені ще не записані
			g << z << endl; // рядки - записуємо мінімальний з них
		f.close(); // закрили перший файл
	} // щоб потім читати файл з початку
	while (k > 0); // повторюємо, поки є не записані рядки
}
int main()
{
	// text files
	char fname[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> fname;
	CreateTXT(fname); // ввели рядки файлу з клавіатури
	PrintTXT(fname); // вивели вміст першого файлу на екран
	char gname[100]; // ім'я другого файлу
	cout << "enter file name 2: "; cin >> gname;
	SortTXT(fname, gname); // відсортували рядки першого файлу,
	// результат записали у другий файл
	PrintTXT(gname); // вивели вміст другого файлу на екран
	return 0;
}