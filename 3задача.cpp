#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool is_hex(const string& hex) {
    for (char c : hex) {
        if (!(c <= '9' or (c >= 'A' and c <= 'F') or (c >= 'a' and c <= 'f'))) return 0;
    }
    return 1;
}

int hex_to_dec(const string& hex) {
    int decimal = 0;
    stringstream ss(hex);
    ss >> std::hex >> decimal;
    return decimal;
}

string dec_to_oct(int decimal) {
    if (decimal == 0) return "0";

    string octal;
    while (decimal > 0) {
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

int main() {
    string arr_hex_n[2];

    for (int i = 0; i < 2; i++) {
        cout << "Введите " << (i + 1) << "-е шестнадцатеричное число: ";
        cin >> arr_hex_n[i];
    }


    for (int i = 0; i < 2; i++) {
        if (!is_hex(arr_hex_n[i])) {
            cout << "Ошибка: " << (i + 1) << "-е введенное число не является шестнадцатеричным!" << endl;
            return 1;
        }
    }


    int dec_diff = hex_to_dec(arr_hex_n[0]) - hex_to_dec(arr_hex_n[1]);


    string oct_res = dec_to_oct(dec_diff);
    cout << "Разность в восьмеричной системе: " << oct_res << endl;

    return 0;
}
