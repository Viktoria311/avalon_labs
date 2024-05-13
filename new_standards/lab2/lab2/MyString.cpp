#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <cstring>
#include <cctype>
#include "MyString.h"
#include <iostream>


MyString::MyString()
{
	m_pStr = nullptr;
}

MyString::MyString(const char* ptr)
{
	if (ptr != nullptr)
	{
		size_t size = strlen(ptr);
		m_pStr = new char[size + 1];
		strcpy_s(m_pStr, size + 1, ptr);
	}
	else
		m_pStr = nullptr;
}

MyString::MyString(MyString&& str) noexcept// move конструктор копирования
{
	m_pStr = str.m_pStr;
	str.m_pStr = nullptr;
}

// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
	m_pStr = nullptr;
}

const char* MyString::GetString() const
{
	return m_pStr;
}

MyString& MyString::operator=(const MyString& str)
{
	if (this != &str)
	{
		if (this->m_pStr != nullptr && str.m_pStr != nullptr) // если это две разные строки
		{
			if ( strlen(str.m_pStr) > strlen(m_pStr)) // при this->m_pStr == nullptr  второе условие не выполнится
			{// и прога не упадет
				delete[] m_pStr; // при this->m_pStr == nullptr  delete[]  ничего не сделает
				m_pStr = new char[strlen(str.m_pStr) + 1];
			}
			strcpy_s(m_pStr, strlen(str.m_pStr) + 1, str.m_pStr);
			m_pStr[strlen(str.m_pStr)] = '\0';
		}
		else if (this->m_pStr == nullptr && str.m_pStr != nullptr) // если была пустая,  выделяем память
		{
			m_pStr = new char[strlen(str.m_pStr) + 1];
			strcpy_s(m_pStr, strlen(str.m_pStr) + 1, str.m_pStr);
			m_pStr[strlen(str.m_pStr)] = '\0';
		} 
		else if (this->m_pStr != nullptr && str.m_pStr == nullptr) // если непустой присваиваем пустую
		{
			delete[] m_pStr;
			m_pStr = nullptr;
		}
	}
	return *this;
}

MyString::MyString(const MyString& str)
{
	if (str.m_pStr != nullptr)
	{
		m_pStr = new char[strlen(str.m_pStr) + 1];
		strcpy_s(m_pStr, strlen(str.m_pStr) + 1, str.m_pStr);
		m_pStr[strlen(str.m_pStr)] = '\0';
	}
	else
		m_pStr = nullptr;
}

void MyString::SetNewString(const char* ptr)
{
	if (strcmp(this->m_pStr, ptr) != 0) //  строки не одинаковы
	{
		if (strlen(ptr) > strlen(m_pStr)) // и длины строк разные
		{
			delete[] m_pStr;
			m_pStr = new char[strlen(ptr) + 1];
		}
		strcpy_s(m_pStr, strlen(ptr) + 1, ptr);
		m_pStr[strlen(ptr)] = '\0';
	}
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	os << "\"" << str.m_pStr << "\"";
	return os;
}

////////////////////////////////////////////////////////////////

MyString& MyString::operator=(MyString&& str) noexcept
{
	if (this != &str)
	{
		delete[] m_pStr;
		m_pStr = str.m_pStr;
		str.m_pStr = nullptr;
	}

	return *this;
}

MyString& MyString::operator=(const char* p_char) // строка в статической защищенной памяти. ее указатель нельзя присваивать
{                                                // при вызове деструктора будет попытка освобождения защищенной памяти
	if (m_pStr != nullptr)
	{
		if (strcmp(this->m_pStr, p_char) != 0) //  строки не одинаковы
		{
			if (strlen(p_char) > strlen(m_pStr)) // длина строки объекта меньше
			{
				delete[] m_pStr;
				m_pStr = new char[strlen(p_char) + 1];
			}
			strcpy_s(m_pStr, strlen(p_char) + 1, p_char);
			m_pStr[strlen(p_char)] = '\0';
		}

	}
	else
	{
		m_pStr = new char[strlen(p_char) + 1];
		strcpy_s(m_pStr, strlen(p_char) + 1, p_char);
	}
	
	return *this;
}

MyString operator+(const MyString& str1, const MyString& str2) // friend
{
	if (str1.m_pStr != nullptr && str2.m_pStr != nullptr)
	{
		auto str1_size = strlen(str1.m_pStr);
		auto str2_size = strlen(str2.m_pStr);

		MyString str;
		str.m_pStr = new char[str1_size + str2_size + 1];
		strcpy_s(str.m_pStr, str1_size + 1, str1.m_pStr);
		strcat_s(str.m_pStr, str1_size + str2_size + 1, str2.m_pStr);
		str.m_pStr[str1_size + str2_size] = '\0';
		// strcpy_s  пишет в конце 0
		return str;
	}
	else if (str1.m_pStr == nullptr)
		return str2;
	else
		return str1;
}

MyString& MyString::operator+=(const MyString& str)
{
	auto this_size = strlen(m_pStr);
	auto str_size = strlen(str.GetString());

	char* buffer = new char[strlen(this->m_pStr) + strlen(str.m_pStr) + 1];
	buffer[0] = '\0';

	strcpy_s(buffer, this_size + 1, m_pStr);
	strcat_s(buffer, this_size + str_size + 1, str.m_pStr);
	
	delete[] m_pStr;
	m_pStr = buffer;

	return *this;
}

MyString& MyString::operator++() // ++str
{
	if (m_pStr != nullptr)
	{
		for(int i = 0; i < static_cast<int>(strlen(m_pStr)); ++i)
			*(m_pStr + i) = std::toupper(*(m_pStr + i));
	}
	return *this;
}
MyString& MyString::operator--() // --str
{
	if (m_pStr != nullptr)
	{
		for (int i = 0; i < static_cast<int>(strlen(m_pStr)); ++i)
			*(m_pStr + i) = std::tolower(*(m_pStr + i));
	}
	return *this;
}
MyString MyString::operator++(int) // str++
{
	MyString return_str{ *this };

	if (m_pStr != nullptr)
	{
		for (int i = 0; i < static_cast<int>(strlen(m_pStr)); ++i)
			*(m_pStr + i) = std::toupper(*(m_pStr + i));
	}

	return return_str;
}
MyString MyString::operator--(int) // str--
{
	MyString return_str{ *this };

	if (m_pStr != nullptr)
	{
		for (int i = 0; i < static_cast<int>(strlen(m_pStr)); ++i)
			*(m_pStr + i) = std::tolower(*(m_pStr + i));
	}

	return return_str;
}
//*/
/*
MyString& MyString::operator+(const MyString& str)
{
	auto str_size = strlen(str.GetString());

	if (m_pStr != nullptr && str.m_pStr != nullptr)
	{
		auto this_size = strlen(m_pStr);

		char* buffer = new char[this_size + str_size + 1];
		strcpy_s(buffer, this_size + str_size + 1, m_pStr);
		strcat_s(buffer + this_size, this_size + str_size + 1, str.m_pStr);

		delete[] m_pStr;
		m_pStr = buffer;
		
	}
	else if (m_pStr == nullptr)
	{
		m_pStr = new char[str_size + 1];
		strcpy_s(m_pStr, str_size + 1, str.GetString());
	}
	
	return *this;
}
*/
///*
bool MyString::operator==(const MyString& str) const
{
	return strcmp(m_pStr, str.m_pStr) == 0;
}
bool MyString::operator==(const char* str) const
{
	return strcmp(m_pStr, str) == 0;
}

bool MyString::operator>(const MyString& str) const
{
	return std::strcmp(m_pStr, str.m_pStr) > 0;
}

bool MyString::operator>(const char* str) const
{
	return std::strcmp(m_pStr, str) > 0;
}
//*/