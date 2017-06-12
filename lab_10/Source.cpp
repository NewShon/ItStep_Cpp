#include <iostream>


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

template<typename T>
auto solve(T a, T b)->decltype(a+b) {
	T arr[3];
	if (a == 0 || b == 0) {
		arr[0] = 0;
		return *arr;
	}
	arr[0] = 1;
	arr[1] = -b / a;
	return *arr;
}

template<typename T>
auto solve(T a, T b, T c)->decltype(a + b + c) {
	T arr[3];
	//êîëè÷åñòâî êîðíåé
	//çíà÷åíèå
	//çíà÷åíèå
	if (a == 0 || b == 0) {
		arr[0] = 0;
		return *arr;
	}
	arr[0] = 1;
	arr[1] = -b / a;
	return *arr;
}

int main() {

	std::cout << "getMin:\t" << getMin(4.2, 5) << std::endl;
	std::cout << "getMin:\t" << getMin(5, 4.2) << std::endl;

	int arr[5] = {1,5,8,3,6};
	std::cout << "getMax:\t" << getMax(arr, 5) << std::endl;
	std::cout << "getMax:\t" << getMax<5>(arr) << std::endl;

	sort(arr, 5);
	std::cout << "sort:\t";
	for (int i = 0; i < 5; i++)
		std::cout<< arr[i] << " ";
	
	std::cout << "\n" << "find:\t" << find(arr, 5, 6) << std::endl;

	std::cout << "solve:\t" << solve(1, 5) << std::endl;

	return 0;
}
