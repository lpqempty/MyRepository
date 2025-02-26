/* Задание: создать класс "транспортное средство" в котором хранится информация о нескольких ТС:
название ТС, тип двигателя и номер двигателя. Создать вектор от класса ТС, вывести его содержимое на экран, 
все ТС с названием "Man" переписать в новый вектор*/
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class TS
{
private:
    string name;
    string engine_name;
    int engine_num;
public:
    TS(string name1, string engine_name1, int engine_num1) {
        name = name1;
        engine_name = engine_name1;
        engine_num = engine_num1;
    }

    string get_name() const {
        return name;
    }
    string get_engine_name() const {
        return engine_name;
    }
    int get_engine_num() const {
        return engine_num;
    }
};

void display(vector<TS> sredstvo) {
    cout << "----------------------------------------------\n";
    for (const TS& machine : sredstvo) {
        cout << "тип тс: " << machine.get_name() << "\nтип двигателя: " << machine.get_engine_name() << "\nномер двигателя: " << machine.get_engine_num() << endl;
    }
}

bool sorting(const TS& name1, const TS& name2) {
    return name1.get_name() < name2.get_name();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите размерность вектора c ТС " << endl;
    int a;
    cin >> a;
    vector<TS> sredstvo;
    string x, y;
    int z;
    for (int i = 0; i < a; i++) {
        cout << "Введите название тс, ведите тип двигателя и номер двигателя" << endl;
        cin >> x >> y >> z;
        sredstvo.push_back(TS(x, y, z));
    }
    sort(sredstvo.begin(), sredstvo.end(), sorting);
    if (sredstvo.empty()) {
        cout << "Данных в векторе нет\n";
        return 0;
    }
    display(sredstvo);
    vector<TS> sredstvo_man;
    copy_if(sredstvo.begin(), sredstvo.end(), back_inserter(sredstvo_man), [](const TS& otbor) {
        return otbor.get_name() == "Man";
        });
    if (!sredstvo_man.empty()) {
        cout << "Новый вектор с ТС <man>\n";
        display(sredstvo_man);
    }
    else {
        cout << "----------------------------------------------\n";
        cout << "Новый вектор с ТС <man> пуст" << endl;
    }
    return 0;
}
