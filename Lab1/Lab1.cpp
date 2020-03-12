#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <string> 
#include <string.h>
using namespace std;

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}


struct Player {
	string name;
	Date birthday;
	string club;
	string position;
	short games;
	string birthplace;
};

const tm currentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

	return tstruct;
}

struct Product {
	string name;
	Date dateofproduction;
	int shelflife;
	short price;
	string serialnumber;
};

struct Note {
	string name;
	string phonenumber;
	Date birthday;
};

string DatePlusDays(struct tm* date, int days)
{
	const time_t ONE_DAY = 24 * 60 * 60;

	time_t date_seconds = mktime(date) + (days * ONE_DAY);

	*date = *localtime(&date_seconds); ;

	char buf[80];

	strftime(buf, sizeof(buf), "%d-%m-%Y", date);

	return buf;
}

// Задача среднего уровня
void task19()
{
	const int count = 2;
	Player players[count];

	for (int i = 0; i < count; i++) {
		cout << "\nEnter player " << i << " info:" << endl;
		cout << "Name:", cin >> players[i].name;

		do
		{
			cout << "Birthday: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> players[i].birthday.day >> players[i].birthday.month >> players[i].birthday.year;
		} while (!players[i].birthday.isCorrect());

		cout << "Club:", cin >> players[i].club;
		cout << "Position:", cin >> players[i].position;
		cout << "Count of games:", cin >> players[i].games;
		cout << "Birthplace:", cin >> players[i].birthplace;

	}

	cout << "Players who played more than 40 games and younger 20 years:" << endl;

	tm tstruct = currentDateTime();
	short date[3];
	date[0] = tstruct.tm_mday;
	date[1] = tstruct.tm_mon + 1;
	date[2] = tstruct.tm_year + 1900;

	for (int k = 0; k < count; k++) {

		if (players[k].games > 40 && players[k].position.compare("Deffender") == 0 &&
			((date[2] - players[k].birthday.year < 20) ||
			(date[2] - players[k].birthday.year == 20 && date[1] < players[k].birthday.month) ||
				(date[2] - players[k].birthday.year == 20 && date[1] == players[k].birthday.month && date[0] < players[k].birthday.day))) {
			cout << players[k].name << ":  " << players[k].birthday.day << "." << players[k].birthday.month << "." << players[k].birthday.year << "  " << players[k].club << "  " << players[k].position << "  " << players[k].games << "  " << players[k].birthplace << endl;
		}
	}


}

// Задача среднего уровня
void task11() {

	const int count = 2;
	Product products[count];

	for (int i = 0; i < count; i++) {
		cout << "\nEnter Product " << i << " info:" << endl;
		cout << "Name:", cin >> products[i].name;

		do
		{
			cout << "Date of production: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> products[i].dateofproduction.day >> products[i].dateofproduction.month >> products[i].dateofproduction.year;
		} while (!products[i].dateofproduction.isCorrect());

		cout << "Shelf life:", cin >> products[i].shelflife;
		cout << "Price:", cin >> products[i].price;
		cout << "Serial number:", cin >> products[i].serialnumber;

	}

	cout << "Product list:" << endl;
	for (int i = 0; i < count; i++) {
		struct tm date = { 0, 0, 12 };
		date.tm_year = products[i].dateofproduction.year - 1900;
		date.tm_mon = products[i].dateofproduction.month - 1;
		date.tm_mday = products[i].dateofproduction.day;

		cout << "Name: " << products[i].name << " Date expired: " << DatePlusDays(&date, products[i].shelflife) << endl;
	}
}

string getInitials (string name) {
	string st;
	char ch[80];
	strcpy(ch, name.c_str());
	for (int j = 0; j < 80; j++) {
		if (ch[j] == '.') {
			st += ch[j-1];
		}
	}

	return st;
}

int enterMonth () {
	short inputmonth;
	cout << "Enter month:",cin >> inputmonth;

	if(inputmonth < 0 && inputmonth > 12) {
		enterMonth();
	}
	return inputmonth;
}

// Задача высокого уровня
void task5() {
	
	const int count = 2;
	Note people[count];
	tm tstruct = currentDateTime();
	short date[3];
	date[0] = tstruct.tm_mday;
	date[1] = tstruct.tm_mon + 1;
	date[2] = tstruct.tm_year + 1900;
	for (int i = 0; i < count; i++) {
		cout << "\nEnter people " << i << " info:" << endl;
		cout << "Name:", cin >> people[i].name;
		cout << "\nPhone number:", cin >> people[i].phonenumber;

		do
		{
			cout << "Birthday: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> people[i].birthday.day >> people[i].birthday.month >> people[i].birthday.year;
		} while (!people[i].birthday.isCorrect());
	}

	for (int i = 0; i < count - 1; i++) {
		string st1 = getInitials(people[i].name);
		for (int k = i + 1; k < count; k++) {
			string st2 = getInitials(people[k].name);
			if ( strcmp(st1.c_str(), st2.c_str()) > 0) {
				swap(people[i], people[k]);
			}
		}
	}

	for (int k = 0; k < count; k++) {
		cout << "Name: " << people[k].name << "  Phone number: " << people[k].phonenumber << "  Birhtday: " << people[k].birthday.day << "." << people[k].birthday.month << "." << people[k].birthday.year << endl;
	}

	int inputmonth = enterMonth();

	int c = 0;
	for (int k = 0; k < count; k++) {

		if (people[k].birthday.month == inputmonth) {
			cout << "\nName:" << people[k].name;
			cout << "\nPhone number:" << people[k].phonenumber;
			cout << "\nBirthday:" << people[k].birthday.day << "." << people[k].birthday.month << "." << people[k].birthday.year << endl;
			c++;
		}
	}
	if ( c == 0 ) {
		cout << "There is no person which birthday month match with today's month";
	}
		
}


void chooseTask() {
	int taskNumber;
	cout << "Choose task number(19, 11, 5):";
	cin >> taskNumber;
	switch (taskNumber) {
	case 19:
		task19();
		break;

	case 11:
		task11();
		break;

	case 5:
		task5();
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