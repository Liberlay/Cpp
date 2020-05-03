#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Задача 19 среднего уровня.
// Записать в файл g все чётные числа файла f, а в файл h все нечётные.Порядок следования чисел сохраняется.

void task19() {
    
    ifstream in;
    in.open("files/f.txt");
    ofstream outG, outH;
    outG.open("files/g.txt", ios::app);
    outH.open("files/h.txt", ios::app);

    if (in.is_open()) {
        int token;
        outG << "All even numbers:\n";
        outH << "All odd numbers:\n";

        while (in >> token) {
            if (token % 2 == 0) {
                outG << token << ' ';
            }
            else {
                outH << token << ' ';
            }
        }
    }
    in.close();
    outG.close();
    outH.close();
}

// Задача 11 среднего уровня.
// Дан файл F, компоненты которого являются действительными числами.Найти сумму компонент файла.

void task11() {
    int sum = 0;
    ifstream in;
    in.open("files/numbers.txt");

    if (in.is_open()) {
        int token;

        while (in >> token) {
            sum += token;
        }
    }
    in.close();

    ofstream out;
    out.open("files/output.txt");

    out << "Summary of all components is: " << sum;
    out.close();

}

// Задача 19 высокого уровня.
// В первом файле хранится k матриц размерности m x n, во втором - l матриц размерности m x n.
// Поменять местами всес четные (по порядковому номеру в файле) матрицы из первого и второго файлов (до конца меньшего из файлов).
// Вывести на экран содержимое первого и второго файлов.

void task19hard() {
    int k = 0, m = 0, n = 0, l = 0;
    cout << "Enter amount of matrix for first file: ", cin >> k;
    cout << "Enter amount of matrix for second file: ", cin >> l;
    cout << "Enter size of matrix (m x n): "; cin >> m; cin >> n;

    ofstream outK, outL;
    outK.open("files/k.txt");
    outL.open("files/l.txt");
    ifstream inK, inL;
    inK.open("files/k.txt");
    inL.open("files/l.txt");
    int matrixId1 = 1;
    do {
        outK << "Matrix " << matrixId1 << endl;
        int number;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                number = rand() % 10;
                outK << number << " ";
            }
            outK << endl;
        }
        outK << endl;
        matrixId1++;
    } while (matrixId1 <= k);


    int matrixId2 = 1;
    do {
        outL << "Matrix " << matrixId2 << endl;
        int number;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                number = rand() % 10;
                outL << number << " ";
            }
            outL << endl;
        }
        outL << endl;
        matrixId2++;
    } while (matrixId2 <= l);

    cout << endl << endl;

    string str;
    int i = 2;
    bool replacing = false;
    string searchK, searchL;
    vector<string> vL, vK;

    if (inK.is_open() && inL.is_open()) {
        while (!inK.eof() || !inL.eof()) {
            getline(inK, searchK);
            getline(inL, searchL);

            str = "Matrix " + to_string(i);
            if (searchK == str && searchL == str) {
                replacing = true;
                i += 2;
            }
            else {
                if (searchK.find("Matrix") != string::npos && searchL.find("Matrix") != string::npos) {
                    replacing = false;
                }
            }

            if (replacing) {
                vL.push_back(searchK);
                vK.push_back(searchL);
            }
            else {
                vL.push_back(searchL);
                vK.push_back(searchK);
            }
          
        }
    }

    ofstream outNewL, outNewK;
    outNewL.open("files/lNew.txt");
    outNewK.open("files/kNew.txt");

    for (auto it1 = vL.begin(); it1 != vL.end(); it1++)
    {
        outNewL << (*it1) << endl;
    }
    for (auto it2 = vK.begin(); it2 != vK.end(); it2++)
    {
        outNewK << (*it2) << endl;
    }

    inK.close();
    inL.close();
    outK.close();
    outL.close();
    outNewL.close();
    outNewK.close();

    
}

void chooseTask() {
    int taskNumber;
    cout << "Choose task number( 1, 2, 3) :";
    cin >> taskNumber;
    switch (taskNumber) {
    case 1:
        task19();
        break;

    case 2:
        task11();
        break;

    case 3:
        task19hard();
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