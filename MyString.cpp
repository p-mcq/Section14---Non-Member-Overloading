#include "MyString.h"
#include <cstring>
#include <istream>

MyString::MyString() : str(nullptr)
{
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *s)
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

MyString::MyString(const MyString &source)
    : str(nullptr)
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

MyString &MyString::operator=(const MyString &source)
{
    if (this == &source)
    {
        return *this;
    }
    delete[] this->str;
    str = new char[strlen(source.str) + 1];
    strcpy(this->str, source.str);
    return *this;
}

MyString &MyString::operator=(MyString &&source)
{
    if (this == &source)
    {
        return *this;
    }
    delete[] this->str;
    this->str = source.str;
    source.str = nullptr;
    return *this;
}

MyString::MyString(MyString &&source) noexcept
{
    str = source.str;
    source.str = nullptr;
}

MyString::~MyString()
{
    delete[] str;
}

void MyString::changeString(const char *s)
{
    delete[] str;
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

const char *MyString::display() const
{
    return str;
}

int MyString::getLengthOfString() const
{
    return strlen(str);
}

std::ostream &operator<<(std::ostream &out, const MyString &rhs)
{
    out << "The String is: " << rhs.str;
    return out;
}

std::istream &operator>>(std::istream &in, MyString &rhs)
{
    char *stringToInsert = new char[1000];
    in >> stringToInsert;
    rhs = MyString{stringToInsert};
    delete[] stringToInsert;
    return in;
}
