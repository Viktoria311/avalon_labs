#pragma once

#include <iostream>

class MyString
{
    char* m_pStr;	//строка-член класса
public:
    MyString(); // конструктор по умолчанию
    MyString(const char* ptr); // конструктор
    MyString(const MyString& str); // конструктор копирования
    MyString(MyString&& str) noexcept; // move конструктор копирования
    ~MyString();
    const char* GetString() const;
    MyString& operator=(const MyString& str); // оператор присваивания
    void SetNewString(const char* ptr);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

    MyString& operator=(MyString&& str) noexcept;
    MyString& operator=(const char* p_char);
    friend MyString operator+(const MyString& str1, const MyString& str2);
    MyString& operator+=(const MyString& str);
    MyString& operator++(); // ++str
    MyString& operator--(); // --str
    MyString operator++(int); // str++
    MyString operator--(int); // str--

    //MyString& operator+(const MyString& str); 
    bool operator==(const MyString& str) const;
    bool operator==(const char* str) const;
    bool operator>(const MyString& str) const;
    bool operator>(const char* str) const;
};

