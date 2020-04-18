#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <windows.h>


using namespace std;

// Задача 19 среднего уровня
void task19() {

	string s, sspace;
	cout << "Enter string without spaces :";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		sspace.insert(sspace.end(), s.at(i));
		sspace.insert(sspace.end(), ' ');
	}
	cout << sspace;

}

// Задача 11 среднего уровня
void task11() {

	string s;
	cout << "Enter any string :";
	cin.ignore(std::cin.rdbuf()->in_avail());
	getline(cin, s);

	sort(s.begin(), s.end());

	cout << s;

}
// Задача 9 высокго уровня.
// Не стал использовать русский язык для корректного отображения в консоли
void task9() {

	string s;
	string token;
	int count = 0;
	cout << "Enter any string :";
	cin.ignore(std::cin.rdbuf()->in_avail());
	getline(cin, s);
	stringstream ss(s);


	while (getline(ss, token, ' ')) {
		const int n = token.length();
		char* ch = new char[n];
		token.copy(ch, n);

		for (int i = 0; i < n; i++) {
			if (!islower(ch[i])) {
				break;
			} else if (i == n - 1) count++;
		}
	}

	cout << "Amount of words in lower case :" << count;

}

void chooseTask() {
	int taskNumber;
	cout << "Choose task number( 19, 11, 9) :";
	cin >> taskNumber;
	switch (taskNumber) {
	case 19:
		task19();
		break;

	case 11:
		task11();
		break;

	case 9:
		task9();
		break;

	default:
		cout << "Enter task number from list!\n";
		chooseTask();
	}
}

int main()
{
	chooseTask();
}
   
