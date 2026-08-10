#include "Span.hpp"

// ========== ctor / dtor ===========

Span::Span(unsigned int N) : _capacity(N), _size(0) {}

Span::Span(const Span &o)
{
	if (this != &o) {
		_capacity = o._capacity;
		_size = o._size;
		_data = o._data;
	}
}

Span &Span::operator=(const Span &o)
{
	_capacity = o._capacity;
	_size = o._size;
	_data = o._data;
	return *this;
}

Span::~Span() {}

// ======== member functions =========

void Span::addNumber(int value)
{
	if (_size >= _capacity || _size >= _data.max_size())
		throw std::out_of_range("Exceeds the maximum capacity");
	_data.push_back(value);
	++_size;
}

unsigned int Span::longestSpan() const
{
	if (_size < 2)
		throw std::logic_error("No span for less than 2 elements");
	auto min = std::min_element(_data.begin(), _data.end());
	auto max = std::max_element(_data.begin(), _data.end());
	return (static_cast<long>(*max) - static_cast<long>(*min));
}

unsigned int Span::shortestSpan()
{
	unsigned int lspan = longestSpan();
	unsigned int sspan = lspan / (_size - 1);
	std::sort(_data.begin(), _data.end());
	for (size_t i = 0; i < _size - 1; ++i) {
		unsigned int diff = static_cast<long>(_data[i + 1]) - static_cast<long>(_data[i]);
		sspan = diff < sspan ? diff : sspan;
	}
	return sspan;
}
