#pragma once


#include <vector>
#include <iostream>
#include <algorithm>


template<typename T, size_t X, size_t Y>
class VEC2 : private std::vector<T>
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
	VEC2();
	VEC2(const std::initializer_list<T>& i_list);
	VEC2(std::initializer_list<T>&& i_list);
	VEC2(const VEC2& vec) = default;
	VEC2(VEC2 && vec) = default;
	VEC2& operator=(const VEC2 & vec) = default;
	VEC2& operator=(VEC2 && vec) = default;
	~VEC2() = default;


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

	template<typename T, size_t X, size_t Y>
	friend std::ostream& operator<<(std::ostream& os, const VEC2<T, X, Y>& vec);
};

#include <algorithm>
#include <iterator>


template<typename T, size_t X, size_t Y>
std::ostream& operator<<(std::ostream& os, const VEC2<T, X, Y>& vec)
{
	//for (const auto& elem : vec)
	//	os << elem << ' ';

	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
	{
		os << *it << ' ';
	}

	return os;
}

template<typename T, size_t X, size_t Y>
VEC2<T, X, Y>::VEC2() : std::vector<T>(), from(X), to(Y)
{
	std::vector<T>::reserve(Y - X + 1);
}

template<typename T, size_t X, size_t Y>
VEC2<T, X, Y>::VEC2(const std::initializer_list<T>& i_list) : std::vector<T>(i_list), from(X), to(Y)
{
	reserve(Y - X + 1);

	for (const auto& elem : i_list)
	{
		auto it_of_elem = end();

		// проверка: есть ли такой элемент в векторе
		for (auto it = begin(); it != end(); ++it)
		{
			if (*it == elem)
			{
				it_of_elem = it;
				break;
			}
		}
		// вставляем только те элементы из i_list, которых нет в векторе. и без дублей
		if (it_of_elem == end())
		{
			push_back(elem);
		}
	}
}

template<typename T, size_t X, size_t Y>
VEC2<T, X, Y>::VEC2(std::initializer_list<T>&& i_list) : std::vector<T>(i_list), from(X), to(Y)
{
	reserve(Y - X + 1);

	for (const auto& elem : i_list)
	{
		auto it_of_elem = end();

		// проверка: есть ли такой элемент в векторе
		for (auto it = begin(); it != end(); ++it)
		{
			if (*it == elem)
			{
				it_of_elem = it;
				break;
			}
		}
		// вставляем только те элементы из i_list, которых нет в векторе. и без дублей
		if (it_of_elem == end())
		{
			push_back(elem);
		}
	}
}


// не можем менять элементы: нельзя хранить копии и вне диапазона
template<typename T, size_t X, size_t Y>
const T& VEC2<T, X, Y>::at(size_t i) const
{
	/*
	if (i >= std::vector<T>::size())
	{
		throw std::out_of_range;
	}
	*/
	return std::vector<T>::operator[](i);
}

template<typename T, size_t X, size_t Y>
const T& VEC2<T, X, Y>::operator[](int i) const
{
	return std::vector<T>::operator[](i);
}

template<typename T, size_t X, size_t Y>
size_t VEC2<T, X, Y>::size() const
{
	return std::vector<T>::size();
}

template<typename T, size_t X, size_t Y>
const T& VEC2<T, X, Y>::front() const
{
	return std::vector<T>::operator[](0);
}

template<typename T, size_t X, size_t Y>
const T& VEC2<T, X, Y>::back() const
{
	return operator[](size() - 1);
}

template<typename T, size_t X, size_t Y>
size_t VEC2<T, X, Y>::capacity() const
{
	return std::vector<T>::capacity();
}

template<typename T, size_t X, size_t Y>
bool VEC2<T, X, Y>::empty() const
{
	return std::vector<T>::empty();
}

template<typename T, size_t X, size_t Y>
void VEC2<T, X, Y>::clear()
{
	std::vector<T>::clear();
}

template<typename T, size_t X, size_t Y>
bool VEC2<T, X, Y>::find(const T& elem) const
{
	for (auto it = cbegin(); it != cend(); ++it)
	{
		if (*it == elem)
			return true;
	}

	return false;
}

template<typename T, size_t X, size_t Y>
void VEC2<T, X, Y>::push_back(const T& elem)
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

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::iter VEC2<T, X, Y>::insert(const_iter pos, const T& value)
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

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::iter VEC2<T, X, Y>::insert(const_iter pos, T&& value)
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

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::iter VEC2<T, X, Y>::erase(iter pos)
{
	return std::vector<T>::erase(pos);
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::iter VEC2<T, X, Y>::erase(const_iter pos)
{
	return std::vector<T>::erase(pos);
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::iter VEC2<T, X, Y>::erase(iter first, iter last)
{
	return std::vector<T>::erase(first, last);
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::iter VEC2<T, X, Y>::erase(const_iter first, const_iter last)
{
	return std::vector<T>::erase(first, last);
}

//////////////////////////////////////////////////////////////////////////

///*
template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::iter VEC2<T, X, Y>::begin()
{
	return std::vector<T>::begin();
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::iter VEC2<T, X, Y>::end()
{
	return std::vector<T>::end();
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::const_iter VEC2<T, X, Y>::cbegin() const
{
	return std::vector<T>::cbegin();
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::const_iter VEC2<T, X, Y>::cend() const
{
	return std::vector<T>::cend();
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::reverse_iter VEC2<T, X, Y>::rbegin()
{
	return std::vector<T>::rbegin();
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::reverse_iter VEC2<T, X, Y>::rend()
{
	return std::vector<T>::rend();
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::const_reverse_iter VEC2<T, X, Y>::crbegin() const
{
	return std::vector<T>::crbegin();
}

template<typename T, size_t X, size_t Y>
typename VEC2<T, X, Y>::const_reverse_iter VEC2<T, X, Y>::crend() const
{
	return std::vector<T>::crend();
}
//*/