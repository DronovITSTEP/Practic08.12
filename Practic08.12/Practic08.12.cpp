#include <iostream>

using namespace std;

/*double mult(double x, double y) {
	return x * y;
}
double mult(double x, double y, double z) {
	return x * y * z;
}
int mult(int x, int y){
	return x * y;
}*/

/*template <typename T >
T max_element(int n, T array[]) {
	T value = array[0];
	for (int i = 1; i < n; i++) {
		value = value > array[i] ? value : array[i];
	}
	cout << "\nFor : ";
	return value;
}*/

/*long max_element(int n, long array[]) {
	long value = array[0];
	for (int i = 1; i < n; i++) {
		value = value > array[i] ? value : array[i];
	}
	cout << "\nFor (long): ";
	return value;
}

double max_element(int n, float array[]) {
	float value = array[0];
	for (int i = 1; i < n; i++) {
		value = value > array[i] ? value : array[i];
	}
	cout << "\nFor (float): ";
	return double(value);
}

double max_element(int n, double array[]) {
	double value = array[0];
	for (int i = 1; i < n; i++) {
		value = value > array[i] ? value : array[i];
	}
	cout << "\nFor (double): ";
	return value;
}*/

/*template <typename T1, typename T2>
T1 Max(T1 A, T2 B) {
	return A > B ? A : B;
}*/

/*
	В функцию передаётся массив случайных
	чисел в диапазоне от -20 до +20. Необходимо найти 
	позиции крайних отрицательных элементов 
	(самого левого отрицательного элемента и
	самого правого отрицательного элемента) и отсортировать 
	элементы, находящиеся между ними.
*/
void f1(int arr[], int s) {
	int start_index, end_index;
	int temp;
	// поиск первого отрицательного элемента
	for (int i = 0; i < s; i++) {
		if (arr[i] < 0) {
			start_index = i;
			break;
		}
	}
	// поиск последнего отрицательного элемента
	for (int i = s - 1; i >= 0; i--) {
		if (arr[i] < 0) {
			end_index = i;
			break;
		}
	}

	for (int i = start_index + 1; i < end_index ;i++) {
		for (int j = start_index + 1; j < end_index - 1 ; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

long fact(int N) {
	long F = 1;
	for (int i = 2; i <= N; i++) {
		F *= i;
	}
	return F;
}

long fact2(int N) {
	if (N < 1) return 0;
	else if (N == 1) return 1;
	else return N * fact2(N - 1);
}


//ф-я быстрой сортировки массива
template <typename T>
void quickSort(T arr[], int N) {
	int i = 0, j = N;
	T temp, p;
	p = arr[N / 2];

	do {
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) quickSort(arr, j);
	if (N > i) quickSort(arr + i, N - i);
}

// ф-я двойного поиска элемента в массиве
int BinarySearch(int arr[], int Lb, int Ub, int key) {
	int M;
	while (1) {
		M = (Lb + Ub) / 2;
		if (key < arr[M]) {
			Ub = M - 1;
		}
		else if (key > arr[M])
			Lb = M + 1;
		else
			return M;
		if (Lb > Ub)
			return -1;
	}
}

/*
Написать рекурсивную функцию нахождения
степени числа.
*/
int Pow(int a, int b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else return a * Pow(a, b - 1);
}
int main()
{
	/*int x[] = {5,9,4,3,7,6,4,6};
	long f[] = { 151,787,148,8787,2651,784 };
	float y[] = { 0.5, 0.6, 1, 0.15 };
	double z[] = { 0.005, 6.154, 9.044 };
	cout << "max_element(8, x) = " << max_element(8, x);
	cout << "max_element(6, f) = " << max_element(6, f);
	cout << "max_element(4, y) = " << max_element(4, y);
	cout << "max_element(3, z) = " << max_element(3, z);*/

	/*cout << Max(5, 6) << endl;
	cout << Max('A', 'B') << endl;
	cout << Max(10, 56.55);*/

	/*const int size = 20;
	int arr[20];

	srand(time(0));

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 20 - rand()%20;
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	f1(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}*/

	/*cout << fact(5) << endl;
	cout << fact2(5);*/

	srand(time(0));
	const int size = 10;
	int arr[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	quickSort(arr, size - 1);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	int k;
	cin >> k;
	cout << BinarySearch(arr, 0, size, k);


}