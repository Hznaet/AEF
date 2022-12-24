#include <iostream>
#include <fstream>
#include <iomanip>
#include <clocale>
#include <Windows.h>
#include <string>
using namespace std;

class student {
private:
    string file;
    string line;
    string name;
    string surname;
    string patronymic;
    string name_gr;
    int numb_gr;
    int ahah;
public:
    void vvod_nazvania()
    {
        cout << "Введите название файла:" << '\n';
        cin >> file;
    }
    void razdelenie_zapisi_i_chtenia() {
        cout << "Если вы хотите открыть файл для записи, то введите 1, если для чтения, то любое иное значение." << '\n';
        cin >> ahah;
        cout << '\n';
        cout << '\n';
        if (ahah == 1) {
            cout << "Запись начата в файл:" << file << '\n';

            cout << "Введите фамилию:" << '\n';
            cin >> surname;

            cout << "Введите имя:" << '\n';
            cin >> name;

            cout << "Введите отчество:" << '\n';
            cin >> patronymic;

            cout << "Введите название группы:" << '\n';
            cin >> name_gr;

            cout << "Введите номер курса:" << '\n';
            cin >> numb_gr;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << " Ошибка: вы ввели неправильное значение. Введённое вами значение заменяется на 0. " << '\n';
            }

            fstream fs;
            fs.open(file, ios::app);
            if (fs.is_open()) {
                fs << surname << " ";
                fs << name << " ";
                fs << patronymic << " ";
                fs << name_gr << " ";
                fs << numb_gr << " курс\n";
            }
            fs.close();

            cout << '\n';
            cout << "Результат записи:\n";
            ifstream in(file);
            if (in.is_open())
            {
                while (getline(in, line))
                {
                    cout << line << endl;
                }
            }
            in.close();
        }
        else
        {
            ifstream gh(file);
            if (gh.is_open())
            {
                while (getline(gh, line))
                {
                    cout << line << endl;
                }
            }
            gh.close();
        }
    }
    void conec_progi() {
        cout << "Программа завершена!" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    student bob;
    bob.vvod_nazvania();
    cout << '\n';
    bob.razdelenie_zapisi_i_chtenia();
    cout << '\n';
    bob.conec_progi();
    cout << '\n';
}