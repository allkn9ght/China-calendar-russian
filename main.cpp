#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

const char *YearsAnimals[12] = {
"Крыса", "Бык", "Тигр", "Кролик",
"Дракон", "Змея", "Лошадь", "Коза",
"Обезьяна", "Петух", "Собака", "Кабан"
};
const char *YearsElement[5] = {
"Дерево", "Огонь", "Земля", "Металл", "Вода"
};
const int KNOWN_60YARR_CYCLE_BEGIN = 1984;

int get_year_animal_index(int);
int get_year_element_index(int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Программа определяет каким является год по китайскому календарю, \n"
            "по его значению в летоисчислении нашей эры. \n\n";

char ch = 0;
int Year;
do {
    bool AllCorrect = false;
    do {
        cout << "Введите год нашей эры: ";
        AllCorrect = (cin >> Year && Year > 0 );
        if(AllCorrect) {
            break;
        } else{
            cout << "(i) Год должен быть положительным целым числом.. \n";
            cin.clear();
            while (cin.get()!='\n') continue;
        }

    } while(true);
    int animal_index = get_year_animal_index(Year);
    int element_index = get_year_element_index(Year);

    cout << "\n -> " << Year << " год нашей эры соответствует в китайском календаре животному "
         << YearsAnimals[animal_index] << " и стихии " << YearsElement[element_index] << ".\n";

    cout << "\nПроверить еще один год(д/н)";
    cin >> ch;

    } while(ch == 'д' || ch == 'Д' || ch == 'y' || ch == 'Y');

    cout << "\nДля выхода нажмите <Enter>.. \n";
    fflush(stdin);
    cin.get();
    return 0;

}

int get_year_animal_index(int y) {
int rest = y - KNOWN_60YARR_CYCLE_BEGIN;
int reply;
if (rest < 0) {
    reply = 11 - abs((rest+1)%12);
} else {
reply = abs(rest %12);
}
return reply;
}
int get_year_element_index(int y) {
int rest = y - KNOWN_60YARR_CYCLE_BEGIN;
int last_digit_of_rest = abs(rest %10);
int index;
if(rest < 0) {
    if(last_digit_of_rest < 1 || last_digit_of_rest > 8) {
        index = 0;
    } else if (last_digit_of_rest <3) {
    index = 4;
    }else if (last_digit_of_rest <5) {
    index = 3;
    }else if (last_digit_of_rest <7) {
    index = 2;
    } else if (last_digit_of_rest <9) {
    index = 1;
    }
} else {
if (last_digit_of_rest <2) {
    index = 0;
} else if (last_digit_of_rest <4) {
index = 1;
}else if (last_digit_of_rest <6) {
index = 2;
}else if (last_digit_of_rest < 8) {
index = 3;
}else if (last_digit_of_rest <10) {
index = 4;
}
}
return index;
}
