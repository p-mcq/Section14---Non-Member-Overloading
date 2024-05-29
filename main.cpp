#include <iostream>
#include "MyString.h"

using std::cout, std::endl, std::boolalpha, std::cin;

int main()
{
    MyString hello{"Hello"};
    MyString blank;

    cout << hello << endl;
    cout << "Please enter a string:" << endl;
    cin >> blank;
    cout << "You typed: " << blank << endl;

    cout << "Please enter two word separated by a space: ";
    cin >> hello >> blank;

    cout << "The first word is: " << hello << endl;
    cout << "The second word is: " << blank << endl;
    return 0;
}