#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <string>

using std::string;
class MyString
{
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend MyString operator-(const MyString &obj);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);

private:
    char *str;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);     // Copy constructor
    MyString(MyString &&source) noexcept; // Move constructor
    ~MyString();

    MyString &operator=(const MyString &source); // Overloading the assignment operator for copying
    MyString &operator=(MyString &&source);      // Overloading the assignment operator for moving

    void changeString(const char *str);
    const char *display() const;
    int getLengthOfString() const;
};

#endif // _MYSTRING_H_