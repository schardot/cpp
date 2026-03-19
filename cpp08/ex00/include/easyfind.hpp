#include <algorithm>
#include <stdexcept>


template <typename T>
typename T::iterator easyfind(T &value, int num) {
	typename T::iterator it = std::find(value.begin(), value.end(), num);
	if (it != value.end())
		return it;
	throw std::out_of_range("not found");
}

template <typename T>
typename T::const_iterator easyfind(const T &value, int num) {
	typename T::const_iterator it = std::find(value.begin(), value.end(), num);
	if (it != value.end())
		return it;
	throw std::out_of_range("not found");
}
