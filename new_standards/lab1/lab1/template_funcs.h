#pragma once

#include <algorithm>
#include <iterator>

// for Exercise 2
#include <cctype>
#include <vector>
#include <string>

// for Exercise 3
#include <map>
#include <iostream>
#include <set>

// for Exercise 5
#include <list>

// for Exercise 7
#include <deque>

//Exercise 2.
class Lamb
{
public:
	void operator()(std::string& str) const
	{
		for (auto& ch : str)
		{
			if (isalpha(ch))
				std::toupper(ch);
		}
	}
};
//Exercise 4.
template<typename Cont>
void PrintAnyCont(const Cont& cont)
{
	auto it = std::begin(cont);
	auto it_end = std::end(cont);

	for (; it != it_end; ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

}

///Exercise 5. 
std::string operator-(const std::string& str)
{
	std::string s(str);
	for (auto& ch : s)
	{
		std::isupper(ch) ? std::tolower(ch) : std::toupper(ch);
	}

	//std::transform(str.begin(), str.end(), str.begin(),
	//	[](char& ch) { std::isupper(ch) ? std::tolower(ch) : std::toupper(ch); });

	return str;
}
template<typename Cont>
void NegateAll(Cont& cont)
{
	auto it = std::begin(cont);
	auto it_end = std::end(cont);

	{
		for (; it != it_end; ++it)
		{
			(*it) = -(*it);
		}
	}
}

//Exercise 6.
template<typename T>
class AbsLessForSort
{
public:
	bool operator()(const T& elem1, const T& elem2) const
	{
		return std::abs(elem1) < std::abs(elem2);
	}
};

//Exercise 6.
template<typename Cont>
void absSort(Cont& cont)
{
	auto it = std::begin(cont);
	auto it_end = std::end(cont);

	//std::sort(it, it_end, AbsLessForSort<decltype(*it + *it)>());
	//std::sort(it, it_end, [](decltype(*it + *it) elem1, decltype(*it + *it) elem2) -> bool
	//	{ return std::abs(elem1) < std::abs(elem2); });
	std::sort(it, it_end, [](auto elem1, auto elem2) -> bool
		{ return std::abs(elem1) < std::abs(elem2); });
}

//Exercise 7.
template<typename Container1, typename Container2>
auto SumCont(const Container1& c1, const Container2& c2)//  -> std::vector<decltype(*std::begin(c1) + *std::begin(c2))>
{
	auto max_size = std::max(std::size(c1), std::size(c2));
	std::vector<decltype(*std::begin(c1) + *std::begin(c2))> vec(max_size);
	//auto min_size = std::min(std::size(c1), std::size(c2));
	
	std::copy(std::begin(c1), std::end(c1), vec.begin());
	std::transform(std::begin(c2), std::end(c2), vec.begin(), vec.begin(), 
		[](const auto& X, const auto& Y) { return X + Y; });
	//vec.reserve(max_size);

	//std::transform(std::begin(c1), std::end(c1), std::begin(c2), std::back_inserter(vec),
	//	[](decltype(*(std::begin(c1)) + *(std::begin(c1))) X, decltype(*(std::begin(c2)) + *(std::begin(c2))) Y) { return X + Y; });



	return vec;
}
//Exercise 8.
template<typename Container1, typename Cont2, typename Cont3, typename PRED>
void Separate(const Container1& c1, Cont2& c2, Cont3& c3, PRED Pred)
{
	for_each(std::begin(c1), std::end(c1),
		[&](decltype(*std::begin(c1) + *std::begin(c1)) X)
		{
			if (Pred(X))
				c2.insert(std::end(c2), X);
			else
				c3.insert(std::end(c3), X);
		});
}

//Exercise 10
template<typename T> std::map<std::string, T> my_map;

enum class COLORS : char { RED, GREEN, BLUE, WHITE, PING, ORANGE, BLACK, YELLOW };

// specialization of a template variable
template<> std::map<std::string, COLORS> my_map<COLORS>
{
	{"red", COLORS::RED }, {"green", COLORS::GREEN }, {"blue", COLORS::BLUE },
	{"white", COLORS::WHITE }, {"ping", COLORS::PING }, {"orange", COLORS::ORANGE },
	{"black", COLORS::BLACK }, {"yellow", COLORS::YELLOW }
};

template<typename T>
T stringToEnum(const std::string& str)
{
	/*
	auto it = my_map<T>.find(str);
	
	if (it != my_map<T>.end())
		return my_map<T>.find(str)->second;
	
	throw  std::out_of_range("no element");
	*/
	return my_map<T>.at(str);
}

template<typename T>
std::string enumToString(const T& t)
{
	
	for (const auto& [f, s] : my_map<T>)
	{
		if (s == t)
			return f;
	}

	throw std::out_of_range("no element");
}
