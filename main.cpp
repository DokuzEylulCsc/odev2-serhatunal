#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// Functions declaration
int menu();

void convertRoman();

void convertDecimal();

void increase();

void decrease();

// Main
int main() {
    bool flag = true;
    while (flag) {
        const int choose = menu();
        switch (choose) {
            case 0:
                flag = false;
                break;
            case 1:
                convertRoman();
                break;
            case 2:
                convertDecimal();
                break;
            case 3:
                increase();
                break;
            case 4:
                decrease();
                break;
            default:
                cout << "Invalid Value" << endl;
                break;
        }
    }

    return 0;
}

// Functions
int menu() {
    int choice = 0;

    cout << endl << "0 - Exit\n"
                    "1 - Convert decimal to roman\n"
                    "2 - Convert roman to decimal\n"
                    "3 - Increase\n"
                    "4 - Decrease" << endl;

    cout << "Please enter your selection: ";
    cin >> choice;

    while (cin.fail()) {
        cout << "Please enter integer type" << endl;
        cout << endl << "Please enter your selection: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }

    return choice;
}

void convertRoman() {
    int count = 12;
    int number = 0;
    int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    cout << endl << "Please enter number: ";
    cin >> number;

    while (cin.fail()) {
        cout << "Please enter integer type" << endl;
        cout << endl << "Please enter number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> number;
    }

    cout << endl << "number: " << number << endl;

    while (number > 0) {
        int div = number / nums[count];
        number %= nums[count];

        while (div--) {
            cout << symbols[count];
        }

        count--;
    }

    cout << endl;
}

int findNum(char symbol) {
    if (symbol == 'I') return 1;
    if (symbol == 'V') return 5;
    if (symbol == 'X') return 10;
    if (symbol == 'L') return 50;
    if (symbol == 'C') return 100;
    if (symbol == 'D') return 500;
    if (symbol == 'M') return 1000;
    return -1;
}

void convertDecimal() {
    string roman = "";
    int num = 0;

    cout << endl << "Please enter roman number: ";
    cin >> roman;
    transform(roman.begin(), roman.end(), roman.begin(), ::toupper);


    for (int i = 0; i < roman.length(); i++) {
        int num1 = findNum(roman[i]);

        if (i + 1 < roman.length()) {
            int num2 = findNum(roman[i + 1]);

            if (num1 >= num2) {
                num += num1;
            } else {
                num += (num2 - num1);
                i++;
            }
        } else {
            num += num1;
        }
    }

    if (num > 0) cout << num << endl;
    else cout << "Please enter roman numeric" << endl;
}

void increase() {

}

void decrease() {

}
