#pragma once

template <typename T>
Array<T>::Array() : _data(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}  // () means initializing all elements as 0

template <typename T>
Array<T>::Array(const Array &o)
{
	if (this != &o) {
		_data = new T[o._size];
		for (size_t i = 0; i < o._size; ++i)
			_data[i] = o._data[i];
		_size = o._size;
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &o)
{
	if (this != &o) {
		delete[] _data;
		_data = new T[o._size];
		for (size_t i = 0; i < o._size; ++i)
			_data[i] = o._data[i];
		_size = o._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();
	return _data[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutOfBoundsException();
	return _data[i];
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const noexcept
{
	return "The array index is out of bounds";
}
