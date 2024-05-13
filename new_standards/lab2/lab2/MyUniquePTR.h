#pragma once

template<typename T>
class MyUniquePTR
{
private:
	T* ptr{};
public:
	MyUniquePTR() = default;
	MyUniquePTR(T* p);
	~MyUniquePTR();
	MyUniquePTR(const MyUniquePTR& other) = delete;
	MyUniquePTR(MyUniquePTR&& other);
	MyUniquePTR& operator=(const MyUniquePTR& other) = delete;
	MyUniquePTR& operator=(MyUniquePTR&& other);

	T* operator->();
	T& operator*();
	const T* operator->() const;
	const T& operator*() const;
	operator bool() const;
	
};


template<typename T>
MyUniquePTR<T>::MyUniquePTR(T* p) : ptr(p)
{

}

template<typename T>
MyUniquePTR<T>::MyUniquePTR(MyUniquePTR&& other) : ptr(other.ptr)
{
	other.ptr = nullptr;
}

template<typename T>
MyUniquePTR<T>& MyUniquePTR<T>::operator=(MyUniquePTR&& other)
{
	delete ptr;
	ptr = other.ptr;
	other.ptr = nullptr;

	return *this;
}

template<typename T>
MyUniquePTR<T>::~MyUniquePTR()
{
	delete ptr;
	ptr = nullptr;
}

template<typename T>
T* MyUniquePTR<T>::operator->()
{
	return ptr;
}

template<typename T>
T& MyUniquePTR<T>::operator*()
{
	return *ptr;
}


template<typename T>
const T* MyUniquePTR<T>::operator->() const
{
	return ptr;
}

template<typename T>
const T& MyUniquePTR<T>::operator*() const
{
	return *ptr;
}

template<typename T>
MyUniquePTR<T>::operator bool() const
{
	return ptr != nullptr;
}