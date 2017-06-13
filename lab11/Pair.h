#pragma once
template<typename T, typename U>
class Pair
{
	T first;
	U second;
public:
	Pair() = delete;
	Pair(const T, const U);
	~Pair() = default;


	T getFirst() const;
	U getSecond() const;
};


template<typename T, typename U>
Pair<T,U>::Pair(const T f, const U s) : first(f), second(s) {}

template<typename T, typename U>
T Pair<T,U>::getFirst() const { return first; }

template<typename T, typename U>
U Pair<T,U>::getSecond() const { return second; }