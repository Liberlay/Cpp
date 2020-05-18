#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;


/* 
Создать бинарный файл, компонентами которого являются структура содержит следующие поля: 
- фамилия и инициалы работника предприятия 
- год рождения 
- образование 
- должность 
- год поступления на работу 
- заработная плата.
Переписаты бинарный файл так, чтобы перевести сотрудника с посадитехника на должность инженера, 
если сотрудник проработал на пред-ятии более 10 лет
*/

/* Task 19 hard level */
struct Facility {
    string name;
    int birthYear;
    string education, position;
    int positionYear;
    int salary;
};

Facility* fileReaderFacility(char path[], int count) {

    FILE* f_in;
    f_in = fopen(path, "rb");
    Facility* employees = new Facility[count];
    fread(employees, sizeof(Facility), count, f_in);
    fclose(f_in);

    return employees;
}

void fileWriterFacility(char path[], int count, Facility* employees) {
    FILE* f_out;
    f_out = fopen(path, "wb");
    fwrite(employees, sizeof(Facility), count, f_out);
    fclose(f_out);
}

void task19(){
    const int count = 3;
    Facility* employees = new Facility[count];
    char filePath[] = "facility.bin";

    for (int i = 0; i < count; i++) {

        cout << "Enter data for " << i << " employee: " << endl;
        cout << "Name: ", cin >> employees[i].name;
        cout << "Birth year: ", cin >> employees[i].birthYear;
        cout << "Education: ", cin >> employees[i].education;
        cout << "Position: ", cin >> employees[i].position;
        cout << "Year of employment: ", cin >> employees[i].positionYear;
        cout << "Salary: ", cin >> employees[i].salary;

    }
    cout << "\nBefore: " << endl;
    for (int i = 0; i < count; i++) {
        cout << employees[i].name << "  " << employees[i].birthYear << "  " << employees[i].education << "  " << employees[i].position << "  " << employees[i].positionYear << "  " << employees[i].salary << endl;
    }

    fileWriterFacility(filePath, count, employees);

    /* ----- */

    Facility* restoredEmployees = fileReaderFacility(filePath, count);
   
    for (int i = 0; i < count; i++) {
        if (2020 - restoredEmployees[i].positionYear > 10) {
            restoredEmployees[i].position = "Engineer";
        }
    }

    fileWriterFacility(filePath, count, restoredEmployees);

    Facility* restoredEmployees1 = fileReaderFacility(filePath, count);

    cout << "\nAfter: " << endl;
    for (int i = 0; i < count; i++) {
        cout << restoredEmployees1[i].name << "  " << restoredEmployees1[i].birthYear << "  " << restoredEmployees1[i].education << "  " << restoredEmployees1[i].position << "  " << restoredEmployees1[i].positionYear << "  " << restoredEmployees1[i].salary << endl;
    }

}

/* End Task 19 */

/*
Создать бинарный файл, компонентами которого является структура, содержащая следующие поля:
название дисциплины;
семестр, в котором читается данная дисциплина;
курс, на котором читается данная дисциплина;
Переписать бинарный файл  так, чтобы дисциплина «Технология програм-мирования», ранее читаемую во втором семестре второго курса, перенести на первый семестр третьего курса.
*/

/* Task 23 hard level */

struct Discipline {
    string name;
    int semester, grade;
};

Discipline* fileReaderDiscipline(char path[], int count) {

    FILE* f_in;
    f_in = fopen(path, "rb");
    Discipline* disciplines = new Discipline[count];
    fread(disciplines, sizeof(Discipline), count, f_in);
    fclose(f_in);

    return disciplines;
}

void fileWriterDiscipline(char path[], int count, Discipline* disciplines) {
    FILE* f_out;
    f_out = fopen(path, "wb");
    fwrite(disciplines, sizeof(Discipline), count, f_out);
    fclose(f_out);
}


void task23() {
    const int count = 3;
    Discipline* disciplines = new Discipline[count];
    char filePath[] = "discipline.bin";

    disciplines[0].name = "Technology of Programming";
    disciplines[0].semester = 2;
    disciplines[0].grade = 2;

    disciplines[1].name = "Higher Mathematics";
    disciplines[1].semester = 1;
    disciplines[1].grade = 1;

    disciplines[2].name = "History of Ukraine";
    disciplines[2].semester = 2;
    disciplines[2].grade = 3;

    fileWriterDiscipline(filePath, count, disciplines);

    cout << "Before: " << endl;
    for (int i = 0; i < count; i++) {

        cout << disciplines[i].name << ":  grade - " << disciplines[i].grade << ", " << "semester - " << disciplines[i].semester << endl;
    }
    cout << endl;

    /* --- */

    Discipline* disciplinesRestored = fileReaderDiscipline(filePath, count);

    for (int i = 0; i < count; i++) {
        if (disciplinesRestored[i].name == "Technology of Programming") {
            disciplinesRestored[i].semester = 1;
            disciplinesRestored[i].grade = 3;

        }
    }

    fileWriterDiscipline(filePath, count, disciplinesRestored);

    cout << "After: " << endl;
    for (int i = 0; i < count; i++) {

        cout << disciplinesRestored[i].name << ":  grade - " << disciplinesRestored[i].grade << ", " << "semester - " << disciplinesRestored[i].semester << endl;
    }
    cout << endl;

}

/* End Task 23 */

/*
Создать бинарный файл, компонентами которого является структура, содержащая следующие поля:
строка символов;
произвольное целое число.
Переписать бинарный файл так, чтобы целое число соответствовало количеству символов в строке.
*/

/* Task 29 hard level */

struct Line {
    string string;
    int number;
};

Line* fileReaderLine(char path[], int count) {

    FILE* f_in;
    f_in = fopen(path, "rb");
    Line* lines = new Line[count];
    fread(lines, sizeof(Line), count, f_in);
    fclose(f_in);

    return lines;
}

void fileWriterLine(char path[], int count, Line* lines) {
    FILE* f_out;
    f_out = fopen(path, "wb");
    fwrite(lines, sizeof(Line), count, f_out);
    fclose(f_out);
}

void task29() {

    const int count = 3;
    Line* lines = new Line[count];
    char filePath[] = "line.bin";

    for (int i = 0; i < count; i++) {
        cout << "Enter data for " << i+1 << " line: "<< endl;
        cout << "Line:", cin >> lines[i].string;
        cout << "Number:", cin >> lines[i].number;
    }
    cout << endl;

    fileWriterLine(filePath, count, lines);
    
    cout << "Before: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "Number: " << lines[i].number << endl;
        cout << "String: " << lines[i].string << endl << endl;
    }

    /* -- */
    Line* lineRestored = fileReaderLine(filePath, count);
    
    cout << "After: " << endl;
    for (int i = 0; i < count; i++) {
        lineRestored[i].number = lineRestored[i].string.length();
    }

    fileWriterLine(filePath, count, lineRestored);

    for (int i = 0; i < count; i++) {
        cout << "Number: " << lineRestored[i].number << endl;
        cout << "String: " << lineRestored[i].string << endl << endl;
    }
}
/* End Task 29 */

void chooseTask() {
    int taskNumber;
    cout << "Choose task number( 19, 23, 29) :";
    cin >> taskNumber;
    switch (taskNumber) {
    case 19:
        task19();
        break;

    case 23:
        task23();
        break;

    case 29:
        task29();
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