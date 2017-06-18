#include <iostream>
#include <cmath>
#include <array>

template <typename T, typename U>
auto getMin(const T& a, const U& b) -> decltype(a + b)
{
	if (a < b) return a;
	return b;
}

template <typename T>
T getMax(const T* a, const size_t size) {
	T max = a[0];
	for (int i = 1; i < size; i++)
		if (max < a[i]) max = a[i];
	return max;
}

template<const size_t size, typename T>
T getMax(const T* a) {
	T max = a[0];
	for (int i = 1; i < size; i++)
		if (max < a[i]) max = a[i];
	return max;
}

template<typename T>
void sort(T* A, size_t size) {
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (int i = d, j; i < size; i++)
		{
			T temp = A[i];
			for (j = i; j >= d; j -= d)
			{
				if (temp < A[j - d])
					A[j] = A[j - d];
				else break;
			}
			A[j] = temp;
		}
	}
}

template<typename T>
T find(T* A, size_t size, T el) {
	for (int i = 0; i < size; i++)
		if (el == A[i]) return i;
}

template<typename T, typename U>
std::array<T,2> solve(T a, U b) {
	std::array<T, 2> arr;
	if (a == 0)
	{
		arr[0] = 0;
		return arr;
	}
	if (b == 0)
	{
		arr[0] = 1;
		arr[1] = 0;
		return arr;
	}
	arr[0] = 1;//solve's quantity
	arr[1] = (-b / a);//answer
	return arr;
}

template<typename T, typename U, typename T1>
std::array<T,3> solve(T a, U b, T1 c){

	std::array<T, 3> arr;
	T D = pow(b,2) - (4 * a * c);

	if (D < 0)
	{
		arr[0] = 0;
		return arr;
	}

	if (D == 0)
	{
		arr[0] = 1;
		arr[1] = -b / (2 * a);
		arr[2] = -b / (2 * a);
		return arr;
	}


	arr[0] = 2;
	arr[1] = (-b + pow(D, 0.5)) / (2 * a);
	arr[2] = (-b - pow(D, 0.5)) / (2 * a);
	return arr;
}

template<size_t size, typename T>
std::array<T, size> replace(const T* array, T el, T ch_el)
{
	std::array<T, size> arr;
	int i = 0;
	for (; i < size; ++i)
	{
		if (array[i] == el)
		{
			arr[i] = ch_el;
			++i;
			break;
		}
		else arr[i] = array[i];
	}

	for (; i < size; ++i)
		arr[i] = array[i];

	return arr;
}

template<typename T>
T* replace_all(const T*array, int size, T el, T ch_el)
{
	T *arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == el) arr[i] = ch_el;
		else arr[i] = array[i];
	}

	return arr;
}


int main() {
	int arr[] = { 1, 5, 5, 3, 6 };
	int arr2[] = { 1, 5, 5, 5, 6 };

	std::array<int, 5> ar = replace<5>(arr, 5, 999);
	int* a2 = replace_all(arr2, 5, 5, 999);

	for (int i = 0; i < 5; i++)
		std::cout << ar[i] << " ";

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << a2[i] << " ";


	delete[]a2;

	std::cout << std::endl;
	std::cout << std::endl;


	std::array<double, 2> a1 = solve<double, double>(2, 5);
	std::cout << "2 * x + 5 = 0" << std::endl;
	std::cout << std::endl;
	std::cout << "Solutions:\t" << a1[0] << std::endl;
	std::cout << "x1:\t\t" << a1[1] << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;

	
	std::array<double,3> a = solve<double,double,double>(2, 5, -3);
	std::cout << "2 * x^2 + 5 * x - 3 = 0" << std::endl;
	std::cout << std::endl;
	std::cout << "Solutions:\t" << a[0] << std::endl;
	std::cout << "x1:\t\t" << a[1] << std::endl;
	std::cout << "x2:\t\t" << a[2] << std::endl;

	

	return 0;
}