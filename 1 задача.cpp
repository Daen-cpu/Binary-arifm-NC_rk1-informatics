#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isValidOctal(const string& octal) {
    for (char c : octal) {
        if ( c > '7') {
            return 0;
        }
    }
    return 1;
}

string oct_to_hex(const string& octal) {
    int t = 0;
    for (size_t i = 0; i < octal.size(); i++) {
        t = t * 8 + (octal[i] - '0');
    }

    stringstream hexStream;
    hexStream << hex << t;
    return hexStream.str();
}


string oct_to_bin(const string& octal) {
    int decimal = 0;
    string binary = "";

    for (size_t i = 0; i < octal.size(); i++) {
        decimal = decimal * 8 + (octal[i] - '0');
    }

    if (decimal == 0) return "0";

    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }

    return binary;
}

int main() {
    string oct_n;
    cout << "Введите восьмеричное число: ";
    cin >> oct_n;

    if (!isValidOctal(oct_n)) {
            cout << "Ошибка: введено не восьмеричное число!" << endl;
            return 1;
        }

    string hex_n = oct_to_hex(oct_n);
    cout << "Шестнадцатеричное число: " << hex_n << endl;

    string bin_n = oct_to_bin(oct_n);
        cout << "Двоичное число: " << bin_n << endl;

    return 0;
}
