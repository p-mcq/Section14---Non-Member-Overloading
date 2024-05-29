#include "MyString.h"
#include <cstring>

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

bool operator==(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs.str, rhs.str) == 0;
}

MyString operator-(const MyString &obj)
{
    char *lowercaseStr = new char[strlen(obj.str) + 1];
    strcpy(lowercaseStr, obj.str);
    for (size_t i = 0; i < strlen(lowercaseStr); i++)
    {
        lowercaseStr[i] = tolower(lowercaseStr[i]);
    }
    MyString temp{lowercaseStr};
    delete[] lowercaseStr;
    return temp;
}

MyString operator+(const MyString &lhs, const MyString &rhs)
{
    char *concatenatedStr = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(concatenatedStr, lhs.str);
    strcat(concatenatedStr, rhs.str);
    MyString temp{concatenatedStr};
    delete[] concatenatedStr;
    return temp;
}
