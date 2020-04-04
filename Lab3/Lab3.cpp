#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include<string>
#include <algorithm>
#include <vector>

using namespace std;

// Задача 19 среднего уровня
void task1() {


	char ch[15]; // Hello Wordl Oh
	cout << "Enter 14 symbols:";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(ch, 15);

	int lengthArray = 0;
	char** separateWords = 0;
	char* tokens = strtok(ch, " ");
	while (tokens)
	{
		separateWords = (char**)realloc(separateWords, sizeof(char*) * ++lengthArray);
		separateWords[lengthArray - 1] = (char*)malloc(strlen(tokens) + 1);
		strcpy(separateWords[lengthArray - 1], tokens);
		tokens = strtok(0, " ");
	}
	for (int i = lengthArray - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(separateWords[j], separateWords[i]) > 0)
			{
				char* t = separateWords[j];
				separateWords[j] = separateWords[i];
				separateWords[i] = t;
			}
		}
	}

	for (int i = 0; i < lengthArray; i++) {
		cout << separateWords[i] << " ";
	}

}

// Задача 11 среднего уровня
void task2()
{

	char chA[100]; // bbb aaa aaaabba baba
	cout << "Enter 20 symbols with a:", cin >> chA;
	int countNew = 0, countOld = 0;

	for (int i = 0; i < strlen(chA); i++) {
		if (chA[i] == 'a') {
			countNew++;
		}
		else if (countNew > countOld) {
			countOld = countNew;
			countNew = 0;
		}
		else {
			countNew = 0;
		}
	}

	cout << "Count of A: " << countOld;
}

// Задача 19 выского уровня
void task3() {
	//char str[200] = "Function strtok searches for tokens in a row string. The sequence of calls to this function, a line break string into tokens, which represent a sequence of symbols, separated by comma";
	char str[200] = "noitcnuF kotrts sehcraes rof snekot ni a wor gnirts. ehT ecneuqes fo sllac ot siht noitcnuf, a enil kaerb gnirts otni snekot, hcihw tneserper a ecneuqes fo slobmys, detarapes yb ammoc";
	cout << "Each word of this string need to be reversed:\n" << str;

	int ArrayLength = 0;
	char** ReverseWords = 0;
	char* token = strtok(str, " ");

	while (token) {
		ReverseWords = (char**)realloc(ReverseWords, sizeof(char*) * ++ArrayLength);
		ReverseWords[ArrayLength - 1] = (char*)malloc(strlen(token) + 1);
		strcpy(ReverseWords[ArrayLength - 1], token);
		token = strtok(0, " ");
	}

	cout << "\n\nReversed string:\n";

	for (int i = 0; i < ArrayLength; i++) {
		string str(ReverseWords[i]);
		if (str.back() == '.' || str.back() == ',') {
			reverse(str.begin(), str.end() - 1);
		}
		else {
			reverse(str.begin(), str.end());
		}

		cout << str << " ";
	}

}


void chooseTask() {
	int taskNumber;
	cout << "Choose task number(1 - medium, 2 - medium, 3 - hard:";
	cin >> taskNumber;
	switch (taskNumber) {
	case 1:
		task1();
		break;

	case 2:
		task2();
		break;

	case 3:
		task3();
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