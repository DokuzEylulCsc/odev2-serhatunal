#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// Functions declaration
int menu();

void convertRoman(int *number);

int convertDecimal(string roman);

void additionSubstraction(int operation);

int main() {
    bool flag = true;
    int num = 0;
    string roman = "";

    while (flag) {
        const int choose = menu();
        switch (choose) {
            case 0:
                flag = false;
                break;
            case 1:
                cout << endl << "Please enter number: ";
                cin >> num;

                // Reference http://www.cplusplus.com/forum/beginner/34856/
                while (cin.fail()) {
                    cout << "Please enter integer" << endl;
                    cout << endl << "Please enter number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> num;
                }

                convertRoman(&num);
                break;
            case 2:
                cout << endl << "Please enter roman number: ";
                cin >> roman;
                // Reference https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
                transform(roman.begin(), roman.end(), roman.begin(), ::toupper);
                num = convertDecimal(roman);
                if (num > 0) cout << num << endl;

                break;
            case 3:
                additionSubstraction(3);
                break;
            case 4:
                additionSubstraction(4);
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
                    "3 - addition\n"
                    "4 - substraction" << endl;

    cout << "Please enter your selection: ";
    cin >> choice;

    while (cin.fail()) {
        cout << "Please enter integer" << endl;
        cout << endl << "Please enter your selection: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }

    return choice;
}

// Reference https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
void convertRoman(int *number) {
    if (*number < 1) cout << "None";
    else {
        int count = 12;
        int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        while (*number > 0) {
            int div = *number / nums[count];
            *number %= nums[count];

            while (div--) {
                cout << symbols[count];
            }

            count--;
        }
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

// Reference https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
int convertDecimal(string roman) {
    int num = 0;

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

    if (num < 1) {
        cout << "Please enter roman numeral" << endl;
        return -1;
    }

    return num;
}

void additionSubstraction(int operation) {
    string strNum1 = "";
    string strNum2 = "";

    cout << endl << "Please enter roman number1: ";
    cin >> strNum1;
    transform(strNum1.begin(), strNum1.end(), strNum1.begin(), ::toupper);
    int num1 = convertDecimal(strNum1);

    if (num1 < 0) {
        while (true) {
            cout << "Please enter roman number1: ";
            cin >> strNum1;
            transform(strNum1.begin(), strNum1.end(), strNum1.begin(), ::toupper);
            num1 = convertDecimal(strNum1);
            if (num1 > 0) break;
        }
    }

    cout << endl << "Please enter roman number2: ";
    cin >> strNum2;
    transform(strNum2.begin(), strNum2.end(), strNum2.begin(), ::toupper);
    int num2 = convertDecimal(strNum2);


    if (num2 < 0) {
        while (true) {
            cout << "Please enter roman number2: ";
            cin >> strNum2;
            transform(strNum2.begin(), strNum2.end(), strNum2.begin(), ::toupper);
            num2 = convertDecimal(strNum2);
            if (num2 > 0) break;
        }
    }

    int total = 0;

    if (operation == 3) total = num1 + num2;
    if (operation == 4) total = num1 - num2;
    convertRoman(&total);
}
