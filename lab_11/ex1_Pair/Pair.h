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
	void make_pair(T, U);
};


template<typename T, typename U>
Pair<T, U>::Pair(const T f, const U s) : first(f), second(s) {}

template<typename T, typename U>
T Pair<T, U>::getFirst() const { return first; }

template<typename T, typename U>
U Pair<T, U>::getSecond() const { return second; }

template<typename T, typename U>
void Pair<T, U>::make_pair(T f, U s){
	first = f;
	second = s;
}

template<>
class Pair<bool,bool>
{
	bool first;
	bool second;
public:
	Pair() = delete;
	Pair(const bool);
	~Pair() = default;


	bool getFirst() const;
	bool getSecond() const;
	void make_pair(const bool);
};


Pair<bool,bool>::Pair(const bool f) : first(f), second(f) {}

bool Pair<bool, bool>::getFirst() const { return first; }

bool Pair<bool, bool>::getSecond() const { return second; }

void Pair<bool, bool>::make_pair(const bool f){
	first = f;
	second = f;
}