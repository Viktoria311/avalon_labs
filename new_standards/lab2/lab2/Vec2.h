#pragma once

#include <vector>
#include <iostream>
#include <algorithm>


template<typename T>
class Vec2 : private std::vector<T>
{
private:
	T from;
	T to;
public:
	typedef typename std::vector<T>::iterator iter;
	typedef typename std::vector<T>::const_iterator const_iter;
	typedef typename std::vector<T>::reverse_iterator reverse_iter;
	typedef typename std::vector<T>::const_reverse_iterator const_reverse_iter;

	// разрешаю создание вектора только при заданном диапазоне
	Vec2() = delete;
	Vec2(const T& range_x, const T& range_y); // конструктор с установкой диапазона
	Vec2(const T& range_x, const T& range_y, const std::initializer_list<T>& i_list); // конструктор: диапазон и элементы
	Vec2(const Vec2& vec) = default;
	Vec2(Vec2&& vec) = default;
	Vec2& operator=(const Vec2& vec) = default;
	Vec2& operator=(Vec2&& vec) = default;
	~Vec2() = default;

	// установка или смена диапазона
	void set_range(const T& x, const T& y);

	// const - не можем менять элементы: нельзя хранить копии и вне диапазона
	const T& at(size_t i) const;
	const T& operator[](int i) const;
	size_t size() const;
	const T& front() const;
	const T& back() const;
	size_t capacity() const;
	bool empty() const;
	void clear();

	template<typename COMP>
	void sort(COMP comp)
	{
		std::sort(begin(), end(), comp);
	}

	bool find(const T& elem) const;

	// вставка
	void push_back(const T& elem);
	iter insert(const_iter pos, const T& value);
	iter insert(const_iter pos, T&& value);


	template<typename Container>
	iter insert_range(const_iter pos, const Container& c)
	{
		bool is_pos_end_iter = pos == cend();
		T pos_value;
		if (is_pos_end_iter == false)
			pos_value = *pos;

		T return_val;
		bool bool_first_insert = false;
		iter return_it = end();
		const_iter insert_it = pos;

		for (auto it = std::begin(c); it != std::end(c); ++it)
		{
			// если в векторе такого элемента нет
			if (find(*it) == false)
			{
				insert_it = insert(insert_it, *it);

				// запомнить итератор на возврааемое
				if (bool_first_insert == false)
				{
					bool_first_insert = true;
					return_val = *it;
				}

				++insert_it;
			}
		}

		// если вставка была
		if (bool_first_insert == true)
		{
			for (auto it = begin(); it != end(); ++it)
			{
				if (*it == return_val)
					return it;
			}
		}
		else // если вставки не было, надо вернуть pos., но типа  iter
		{
			if (is_pos_end_iter)
			{
				return end();
			}
			else
			{
				for (auto it = begin(); it != end(); ++it)
				{
					if (*it == pos_value)
						return it;
				}
			}
		}
	}

	template<typename Container>
	iter insert_range(const_iter pos, Container&& c)
	{
		bool is_pos_end_iter = pos == cend();
		T pos_value;
		if (is_pos_end_iter == false)
			pos_value = *pos;

		T return_val;
		bool bool_first_insert = false;
		iter return_it = end();
		const_iter insert_it = pos;

		for (auto it = std::begin(c); it != std::end(c); ++it)
		{
			// если в векторе такого элемента нет
			if (find(*it) == false)
			{
				insert_it = insert(insert_it, *it);

				// запомнить итератор на возврааемое
				if (bool_first_insert == false)
				{
					bool_first_insert = true;
					return_val = *it;
				}

				++insert_it;
			}
		}

		// если вставка была
		if (bool_first_insert == true)
		{
			for (auto it = begin(); it != end(); ++it)
			{
				if (*it == return_val)
					return it;
			}
		}
		else // если вставки не было, надо вернуть pos., но типа  iter
		{
			if (is_pos_end_iter)
			{
				return end();
			}
			else
			{
				for (auto it = begin(); it != end(); ++it)
				{
					if (*it == pos_value)
						return it;
				}
			}
		}
	}

	// удаление
	iter erase(iter pos);
	iter erase(const_iter pos);
	iter erase(iter first, iter last);
	iter erase(const_iter first, const_iter last);


	iter begin();
	iter end();
	const_iter cbegin() const;
	const_iter cend() const;
	reverse_iter rbegin();
	reverse_iter rend();
	const_reverse_iter crbegin() const;
	const_reverse_iter crend() const;

	template<typename T>
	friend std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec);
};

#include <algorithm>
#include <iterator>


template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec)
{
	//for (const auto& elem : vec)
	//	os << elem << ' ';

	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		os << *it << ' ';

	return os;
}

template<typename T>
Vec2<T>::Vec2(const T& range_x, const T& range_y) : std::vector<T>(), from(range_x), to(range_y)
{
	std::vector<T>::reserve(range_y - range_x + 1);
}

template<typename T>
Vec2<T>::Vec2(const T& range_x, const T& range_y, const std::initializer_list<T>& i_list) 
	: std::vector<T>(), from(range_x), to(range_y)
{
	reserve(range_y - range_x + 1);


	std::copy_if(i_list.begin(), i_list.end(), std::back_inserter(*this),
		[*this](const auto& elem)
	{
		auto find_it = end();
		auto end_it = end();

		// проверка: есть ли элемент в векторе
		for (auto it = begin(); it != end_it; ++it)
			if (*it == elem)
				find_it = it;

		// если элемент входит в диапазон и если элемента пока нет в векторе
		return (elem >= from && elem <= to && find_it == end_it);
	});
}

template<typename T>
void Vec2<T>::set_range(const T& x, const T& y)
{
	from = x;
	to = y;

	std::vector<T>::reserve(y - x + 1);

	if (size() != 0) // а если метод вызывать у уже использованного вектора для смены диапазона
	{
		for (auto it = begin(); it != end(); )
		{
			if (*it < x || *it > y)
				it = erase(it);
			else
				++it;
		}
	}
}

// не можем менять элементы: нельзя хранить копии и вне диапазона
template<typename T>
const T& Vec2<T>::at(size_t i) const
{
	return std::vector<T>::operator[](i);
}

template<typename T>
const T& Vec2<T>::operator[](int i) const
{
	return std::vector<T>::operator[](i);
}

template<typename T>
size_t Vec2<T>::size() const
{
	return std::vector<T>::size();
}

template<typename T>
const T& Vec2<T>::front() const
{
	return std::vector<T>::operator[](0);
}

template<typename T>
const T& Vec2<T>::back() const
{
	return std::vector<T>::operator[](size() - 1);
}

template<typename T>
size_t Vec2<T>::capacity() const
{
	return std::vector<T>::capacity();
}

template<typename T>
bool Vec2<T>::empty() const
{
	return std::vector<T>::empty();
}

template<typename T>
void Vec2<T>::clear()
{
	std::vector<T>::clear();
}

template<typename T>
bool Vec2<T>::find(const T& elem) const
{
	for (auto it = cbegin(); it != cend(); ++it)
	{
		if (*it == elem)
			return true;
	}

	return false;
}

template<typename T>
void Vec2<T>::push_back(const T& elem)
{
	if (elem >= from && elem <= to)
	{
		for (auto it = begin(); it != end(); ++it)
		{
			// если нашли такой элемент в векторе, выходим из метода без вставки
			if (*it == elem)
				return;
		}
		std::vector<T>::push_back(elem);
	}
}

template<typename T>
typename Vec2<T>::iter Vec2<T>::insert(const_iter pos, const T& value)
{
	if (value >= from && value <= to)
	{
		for (auto it = begin(); it != end(); ++it)
		{
			if (*it == value)
				return it;
		}

		return std::vector<T>::insert(pos, value);
	}

	// если вставки не было
	for (auto it = begin(); it != end(); ++it)
	{
		if (it == pos)
			return it;
	}
}

template<typename T>
typename Vec2<T>::iter Vec2<T>::insert(const_iter pos, T&& value)
{
	if (value >= from && value <= to)
	{
		for (auto it = begin(); it != end(); ++it)
		{
			if (*it == value)
				return it;
		}

		return std::vector<T>::insert(pos, value);
	}

	// если вставки не было
	for (auto it = begin(); it != end(); ++it)
	{
		if (it == pos)
			return it;
	}
}

template<typename T>
typename Vec2<T>::iter Vec2<T>::erase(iter pos)
{
	return std::vector<T>::erase(pos);
}

template<typename T>
typename Vec2<T>::iter Vec2<T>::erase(const_iter pos)
{
	return std::vector<T>::erase(pos);
}

template<typename T>
typename Vec2<T>::iter Vec2<T>::erase(iter first, iter last)
{
	return std::vector<T>::erase(first, last);
}

template<typename T>
typename Vec2<T>::iter Vec2<T>::erase(const_iter first, const_iter last)
{
	return std::vector<T>::erase(first, last);
}

//////////////////////////////////////////////////////////////////////////

///*
template<typename T>
typename Vec2<T>::iter Vec2<T>::begin()
{
	return std::vector<T>::begin();
}

template<typename T>
typename Vec2<T>::iter Vec2<T>::end()
{
	return std::vector<T>::end();
}

template<typename T>
typename Vec2<T>::const_iter Vec2<T>::cbegin() const
{
	return std::vector<T>::cbegin();
}

template<typename T>
typename Vec2<T>::const_iter Vec2<T>::cend() const
{
	return std::vector<T>::cend();
}

template<typename T>
typename Vec2<T>::reverse_iter Vec2<T>::rbegin()
{
	return std::vector<T>::rbegin();
}

template<typename T>
typename Vec2<T>::reverse_iter Vec2<T>::rend()
{
	return std::vector<T>::rend();
}

template<typename T>
typename Vec2<T>::const_reverse_iter Vec2<T>::crbegin() const
{
	return std::vector<T>::crbegin();
}

template<typename T>
typename Vec2<T>::const_reverse_iter Vec2<T>::crend() const
{
	return std::vector<T>::crend();
}
//*/