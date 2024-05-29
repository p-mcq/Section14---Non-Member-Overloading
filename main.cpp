#include <iostream>
#include "MyString.h"

using std::cout, std::endl, std::boolalpha;

int main()
{
    cout << boolalpha << endl;
    MyString a{"Hello"};
    MyString b{"World"};
    MyString c{a};
    cout << "------------------" << endl;
    cout << (a == c) << endl; // true
    cout << (a == b) << endl; // false
    cout << "------------------" << endl;

    MyString concat = a + b;
    cout << concat.display() << endl; // HelloWorld
    cout << "------------------" << endl;

    MyString lower = -concat;
    cout << lower.display() << endl; // helloworld
    cout << "------------------" << endl;
    return 0;
}