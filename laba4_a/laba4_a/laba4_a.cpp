//Вам принесли файл со сторонней информацией.В этом файле следующий построчный текст(ФИО, год рождения, должность, структурная единица) :
//    Иванов Н.М. 1998, инженер, группа 1
//    Петров П.И. 1999, инженер, группа 2
//    Плетнев И.С. 2001, лаборант, группа 4
//    Гаврилов Т.Г. 1976, техник, группа 1
//    Бойко А.Л. 1969, председатель, группа 1
//    Загрузить файл, наполняя созданную БД(в стиле ООП) элементами из файла.
//    Вывести на консоль данные о всех инженерах, а затем в порядке возрастания года рождения данные о всех не председателях.Использовать лямбду.
//    Не забывать освобождать ресурсы.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class data_base {
private:
    vector <vector<string>> base;
public:
    void append(vector <string> vec){
        base.push_back(vec);
    }
    void print() {
        for (vector <string> element : base) {
            for (string el : element) {
                cout << el << endl;
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    string information;
    vector<string> data;
    ifstream fin;
    data_base base;

    fin.open("myFile.txt");
    while (getline(fin, information)) {
        string token;
        stringstream ss(information);
        while (getline(ss, token, ',')) {
            data.push_back(token);
        }
        base.append(data);
        data.clear();
    }
    fin.close();
    base.print();
}
