#include <iostream>
#include <string>

using namespace std;

bool is_oct(const string& octal) {
    for (char c : octal) {
        if (c > '7') return 0;
    }
    return 1;
}

int oct_to_dec(const string& octal) {
    int decimal = 0;
    for (size_t i = 0; i < octal.size(); i++) {
        decimal = decimal * 8 + (octal[i] - '0');
    }
    return decimal;
}

int main() {
    string arr_oct_n[2];

    for (int i = 0; i < 2; i++) {
        cout << "Введите " << (i + 1) << "-е восьмеричное число: ";
        cin >> arr_oct_n[i];
    }

    for (int i = 0; i < 2; i++) {
        if (!is_oct(arr_oct_n[i])) {
            cout << "Ошибка: " << (i + 1) << "-е введенное число не является восьмеричным!" << endl;
            return 1;
        }
    }

    int dec_sum = oct_to_dec(arr_oct_n[0]) + oct_to_dec(arr_oct_n[1]);
    cout << "Сумма в десятичной системе: " << dec_sum << endl;

    return 0;
}

