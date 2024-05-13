#pragma once
#include <vector>
#include <iostream>
#include <algorithm>


template<typename T>
class Vec1
{
private:
	T from;
	T to;
	std::vector<T> vec;
public:
	typedef typename std::vector<T>::iterator iter;
	typedef typename std::vector<T>::const_iterator const_iter;
	typedef typename std::vector<T>::reverse_iterator reverse_iter;
	typedef typename std::vector<T>::const_reverse_iterator const_reverse_iter;

	// �������� �������� ������� ������ ��� �������� ���������
	Vec1() = delete;
	Vec1(const T& range_x, const T& range_y); // ����������� � ���������� ���������
	Vec1(const T& range_x, const T& range_y, const std::initializer_list<T>& i_list); // �����������: �������� � ��������
	Vec1(const Vec1& vec) = default;
	Vec1(Vec1&& vec) = default;
	Vec1& operator=(const Vec1& vec) = default;
	Vec1& operator=(Vec1&& vec) = default;
	~Vec1() = default;

	// ��������� ��� ����� ���������
	void set_range(const T& x, const T& y);

	// const - �� ����� ������ ��������: ������ ������� ����� � ��� ���������
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
		std::sort(vec.begin(), vec.end(), comp);
	}

	bool find(const T& elem) const;

	// �������
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
			// ���� � ������� ������ �������� ���
			if (find(*it) == false)
			{
				insert_it = vec.insert(insert_it, *it);

				// ��������� �������� �� �����������
				if (bool_first_insert == false)
				{
					bool_first_insert = true;
					return_val = *it;
				}

				++insert_it;
			}
		}
		
		// ���� ������� ����
		if (bool_first_insert == true)
		{
			for (auto it = begin(); it != end(); ++it)
			{
				if (*it == return_val)
					return it;
			}
		}
		else // ���� ������� �� ����, ���� ������� pos., �� ����  iter
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
			// ���� � ������� ������ �������� ���
			if (find(*it) == false)
			{
				insert_it = vec.insert(insert_it, *it);

				// ��������� �������� �� �����������
				if (bool_first_insert == false)
				{
					bool_first_insert = true;
					return_val = *it;
				}

				++insert_it;
			}
		}

		// ���� ������� ����
		if (bool_first_insert == true)
		{
			for (auto it = begin(); it != end(); ++it)
			{
				if (*it == return_val)
					return it;
			}
		}
		else // ���� ������� �� ����, ���� ������� pos., �� ����  iter
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
	
	// ��������
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
	friend std::ostream& operator<<(std::ostream& os, const Vec1<T>& vec);
};

#include <algorithm>
#include <iterator>


template<typename T>
std::ostream& operator<<(std::ostream& os, Vec1<T>& vec)
{
	for (const auto& elem : vec)
		os << elem << ' ';

	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		os << *it << ' ';

	return os;
}

template<typename T>
Vec1<T>::Vec1(const T& range_x, const T& range_y) : from(range_x), to(range_y)
{
	vec.reserve(range_y - range_x + 1);
}

template<typename T>
Vec1<T>::Vec1(const T& range_x, const T& range_y, const std::initializer_list<T>& i_list) 
		: from(range_x), to(range_y)
{
	vec.reserve(range_y - range_x + 1);


	std::copy_if(i_list.begin(), i_list.end(), std::back_inserter(vec),
		[*this] (const auto& elem) 
		{ 
			// ���� ������� ������ � �������� 
			if (elem >= from && elem <= to)
			{
				auto find_it = vec.end();
				auto end_it = vec.end();

				// ��������: ���� �� ������� � �������
				for (auto it = vec.begin(); it != end_it; ++it)
					if (*it == elem)
						find_it = it;

				// ���� ������� ������ � �������� � ���� �������� ���� ��� � �������
				return find_it == end_it;
			}
			else // ���� ������� �� ������ � ��������
			{
				return false;
			}
			
		});
}

template<typename T>
void Vec1<T>::set_range(const T& x, const T& y)
{
	from = x;
	to = y;

	vec.reserve(y - x + 1);

	if (vec.size() != 0) // � ���� ����� �������� � ��� ��������������� ������� ��� ����� ���������
	{
		//
		for (auto it = vec.begin(); it != vec.end(); )
		{
			if (*it < x || *it > y)
				it = vec.erase(it);
			else
				++it;
		}
	}

}

// �� ����� ������ ��������: ������ ������� ����� � ��� ���������
template<typename T>
const T& Vec1<T>::at(size_t i) const
{
	if (i >= vec.size())
	{
		throw std::out_of_range();
	}

	return vec[i];
}

template<typename T>
const T& Vec1<T>::operator[](int i) const
{
	return vec[i];
}

template<typename T>
size_t Vec1<T>::size() const
{
	return vec.size();
}


template<typename T>
const T& Vec1<T>::front() const
{
	return vec[0];
}

template<typename T>
const T& Vec1<T>::back() const
{
	return vec[vec.size() - 1];
}

template<typename T>
size_t Vec1<T>::capacity() const
{
	return vec.capacity();
}

template<typename T>
bool Vec1<T>::empty() const
{
	return vec.empty();
}

template<typename T>
void Vec1<T>::clear()
{
	vec.clear();
}

template<typename T>
bool Vec1<T>::find(const T& elem) const
{
	for (const auto& el : vec)
	{
		if (el == elem)
			return true;
	}

	return false;
}

template<typename T>
void Vec1<T>::push_back(const T& elem)
{
	if (elem >= from && elem <= to)
	{
		for (const auto& item : vec)
		{
			// ���� ����� ����� ������� � �������, ������� �� ������ ��� �������
			if (item == elem)
				return;
		}
		vec.push_back(elem);
	}
}

template<typename T>
typename Vec1<T>::iter Vec1<T>::insert(const_iter pos, const T& value)
{
	if (value >= from && value <= to)
	{
		for (auto it = vec.begin(); it != vec.end(); ++it)
		{
			if (*it == value)
				return it;
		}

		return vec.insert(pos, value);
	}
	
	// ���� ������� �� ����
	///*
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if (it == pos)
			return it;
	}
	//*/
	//return pos;
}

template<typename T>
typename Vec1<T>::iter Vec1<T>::insert(const_iter pos, T&& value)
{
	if (value >= from && value <= to)
	{
		for (auto it = vec.begin(); it != vec.end(); ++it)
		{
			if (*it == value)
				return it;
		}

		return vec.insert(pos, value);
	}

	// ���� ������� �� ����
	///*
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if (it == pos)
			return it;
	}
	//*/
	//return pos;
}


template<typename T>
typename Vec1<T>::iter Vec1<T>::erase(iter pos)
{
	return vec.erase(pos);
}

template<typename T>
typename Vec1<T>::iter Vec1<T>::erase(const_iter pos)
{
	return vec.erase(pos);
}

template<typename T>
typename Vec1<T>::iter Vec1<T>::erase(iter first, iter last)
{
	return vec.erase(first, last);
}

template<typename T>
typename Vec1<T>::iter Vec1<T>::erase(const_iter first, const_iter last)
{
	return vec.erase(first, last);
}


//////////////////////////////////////////////////////////////////////////

///*
template<typename T>
typename Vec1<T>::iter Vec1<T>::begin()
{
	return vec.begin();
}

template<typename T>
typename Vec1<T>::iter Vec1<T>::end()
{
	return vec.end();
}

template<typename T>
typename Vec1<T>::const_iter Vec1<T>::cbegin() const
{
	return vec.cbegin();
}

template<typename T>
typename Vec1<T>::const_iter Vec1<T>::cend() const
{
	return vec.cend();
}

template<typename T>
typename Vec1<T>::reverse_iter Vec1<T>::rbegin()
{
	return vec.rbegin();
}

template<typename T>
typename Vec1<T>::reverse_iter Vec1<T>::rend()
{
	return vec.rend();
}

template<typename T>
typename Vec1<T>::const_reverse_iter Vec1<T>::crbegin() const
{
	return vec.crbegin();
}

template<typename T>
typename Vec1<T>::const_reverse_iter Vec1<T>::crend() const
{
	return vec.crend();
}
//*/