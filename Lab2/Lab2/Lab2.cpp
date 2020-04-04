#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <string> 
#include <string.h>

using namespace std;

const tm currentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

	return tstruct;
}

struct HomeAdress{
	int PostIndex, HouseNumber, Flat;
	string Country, Region, District, Town, Street;
};

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

struct Pupil {
	char Name[30], SecondName[30], LastName[30];
	string Sex, Nationality, PhoneNumber, School, Group;
	short Height, Weight;
	Date Birthday;
	HomeAdress HomeAdress;
};

Pupil InitPupil();
Pupil* InitArray(int StructSize);
void ShowArray(Pupil* Pupils, int StructSize);
void ShowPupil(Pupil Pupil, int id);
void SortArray(Pupil* Pupils, int StructSize);
void DisplayChoice(Pupil* Pupils, int StructSize, int Sex, int MinAge, int MaxAge);

int main()
{
	int StructSize;
	Pupil* pupils;
	cout << "Enter amount of pupils:", cin >> StructSize;
	int ChooseMinAge, ChooseMaxAge;
	int ChooseSex;
	cout << "\nChoose sex (1 - male, 2 - female):", cin >> ChooseSex;
	cout << "\nEnter min age:", cin >> ChooseMinAge;
	cout << "\nEnter max age:", cin >> ChooseMaxAge;

	pupils = InitArray(StructSize);
	if (pupils == NULL) {
		cout << "Dynamic array doesn't exist!!";
		return 0;
	}

	ShowArray(pupils, StructSize);

	DisplayChoice(pupils, StructSize, ChooseSex, ChooseMinAge, ChooseMaxAge);

	cout << "\nSorted array by name:\n";
	SortArray(pupils, StructSize);
	ShowArray(pupils, StructSize);

	free(pupils);

}

Pupil InitPupil() {

	Pupil pupil;

	cout << "Enter name:", cin >> pupil.Name;
	cout << "Enter secondname:", cin >> pupil.SecondName;
	cout << "Enter lastname:", cin >> pupil.LastName;
	cout << "Enter sex:", cin >> pupil.Sex;
	cout << "Enter nationality:", cin >> pupil.Nationality;
	cout << "Enter phonenumber:", cin >> pupil.PhoneNumber;
	cout << "Enter height:", cin >> pupil.Height;
	cout << "Enter weight:", cin >> pupil.Weight;
	cout << "Enter school:", cin >> pupil.School;
	cout << "Enter group:", cin >> pupil.Group;
		
		do
		{
			cout << "Birthday: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> pupil.Birthday.day >> pupil.Birthday.month >> pupil.Birthday.year;
		} while (!pupil.Birthday.isCorrect());
	
	cout << "Enter post index:", cin >> pupil.HomeAdress.PostIndex;
	cout << "Enter country:", cin >> pupil.HomeAdress.Country;
	cout << "Enter region:", cin >> pupil.HomeAdress.Region;
	cout << "Enter district:", cin >> pupil.HomeAdress.District;
	cout << "Enter town:", cin >> pupil.HomeAdress.Town;
	cout << "Enter street:", cin >> pupil.HomeAdress.Street;
	cout << "Enter house number:", cin >> pupil.HomeAdress.HouseNumber;
	cout << "Enter flat:", cin >> pupil.HomeAdress.Flat;

	return pupil;

}

Pupil* InitArray(int StructSize) {

	Pupil* pupils = (Pupil*)calloc(StructSize, sizeof(Pupil)); // Объявление структуры определенной размерности(длины)

	if (pupils == NULL) return NULL;
	for (int i = 0; i < StructSize; i++) {
		cout << "\nEnter data for pupil  " << (i + 1) << ":" << endl;
		pupils[i] = InitPupil();
	}


	return pupils;

}

void ShowArray(Pupil* Pupils, int StructSize){

	for (int i = 0; i < StructSize; i++) {
		ShowPupil(Pupils[i], i+1);
	}

}

void ShowPupil(Pupil Pupil, int id) {

	cout << "Pupil " << id << ": " << endl
		<< "Name:" << Pupil.Name << endl
		<< "Second name:" << Pupil.SecondName << endl
		<< "Last name: " << Pupil.LastName << endl
		<< "Sex:" << Pupil.Sex << endl
		<< "Nationality: " << Pupil.Nationality << endl
		<< "Height: " << Pupil.Height << endl
		<< "Weight: " << Pupil.Weight << endl
		<< "Birthday: " << Pupil.Birthday.day << " " << Pupil.Birthday.month << " " << Pupil.Birthday.year << endl
		<< "Phone number: " << Pupil.PhoneNumber << endl
		<< "Post index: " << Pupil.HomeAdress.PostIndex << endl
		<< "Country: " << Pupil.HomeAdress.Country << endl
		<< "Region: " << Pupil.HomeAdress.Region << endl
		<< "District: " << Pupil.HomeAdress.District << endl
		<< "Town: " << Pupil.HomeAdress.Town << endl
		<< "Street: " << Pupil.HomeAdress.Street << endl
		<< "House number: " << Pupil.HomeAdress.HouseNumber << endl
		<< "Flat: " << Pupil.HomeAdress.Flat << endl
		<< "School: " << Pupil.School << endl
		<< "Group: " << Pupil.Group << endl << endl;

}

void SortArray(Pupil* Pupils, int StructSize) {
	for (int i = 0; i < StructSize - 1; i++) {
		for (int k = i + 1; k < StructSize; k++) {
			if (strcmp(Pupils[i].Name, Pupils[k].Name) > 0) {
				swap(Pupils[i], Pupils[k]);
			}
		}
	}
}

void DisplayChoice(Pupil* Pupils, int StructSize, int Sex, int MinAge, int MaxAge) {
	string strSex = Sex == 1 ? "Male" : "Female";
	tm tstruct = currentDateTime();
	short date[3];
	date[0] = tstruct.tm_mday;
	date[1] = tstruct.tm_mon + 1;
	date[2] = tstruct.tm_year + 1900;

	cout << endl << endl << strSex << "s whose age more " << MinAge << " and lower " << MaxAge << ": \n\n";

	for (int i = 0; i < StructSize; i++) {
		int age = date[2] - Pupils[i].Birthday.year - 1;
		if (date[1] < Pupils[i].Birthday.month || (date[1] == Pupils[i].Birthday.month && date[0] <= Pupils[i].Birthday.day)) {
			age++;
		}

		if (strcmp(Pupils[i].Sex.c_str(), strSex.c_str()) == 0 && age <= MaxAge && age >= MinAge) {

			ShowPupil(Pupils[i], i+1);

		}
	}

}
