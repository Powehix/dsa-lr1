#include<iostream>
#include <time.h>
using namespace std;

void check(int n, int * arr);
void print(int n, int * arr);
void multiplication(int * arr, int x, int n);
void sort(int n, int * arr);
void approximation(int x, int * arr, int n);

void main() {
	int n, x, c;
	cout << "Enter n > ";
	cin >> n;
	cout << "-------------\nArray:\n-------------\n";
	int * arr = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++)
		arr[i] = rand();
	check(n, arr);
	print(n, arr);
	cout << "-------------\nEnter the number you want to find (multiplicative method) > ";
	cin >> x;
	multiplication(arr, x, n);
	cout << "\n-------------\nSorted array (insertion sort):\n-------------\n";
	sort(n, arr);
	print(n, arr);
	cout << "-------------\nEnter the number you want to find (approximation method) > ";
	cin >> c;
	approximation(c, arr, n);
	system("pause");
}

void print(int n, int * arr) {
	for (int i = 0; i < n; i++)
		cout << i << ". - " << arr[i] << endl;
}

void check(int n, int * arr) {
	int k = 1;
	while (k != 0) {
		k = 0;
		for (int i = 0; i < n; i++)
			for (int j = n; j > i; j--) {
				if (arr[i] == arr[j]) {
					arr[i] = rand();
					k++;
				}
			}
	}
}

void multiplication(int * arr, int x, int n) {
	arr[n] = x;
	int i = 4, count = 0;
	while ((arr[i - 4] - x)*(arr[i - 3] - x)*(arr[i - 2] - x)*(arr[i - 1] - x) != 0) {
		i = i + 4;
		count++;
	}
	if (arr[i - 4] == x) {
		i = i - 4;
		count++;
	}
	else if (arr[i - 3] == x) {
		i = i - 3;
		count += 2;
	}
	else if (arr[i - 2] == x) {
		i = i - 2;
		count += 3;
	}
	else {
		i = i - 1;
		count += 3;
	}
	if (i < n) cout << "Number found! Its serial number in the array: " << i;
	else cout << "Number not found.";
	cout << "\nThe number of comparison operations: " << count;
}

void sort(int n, int * arr) {
	int i, j, x;
	for (i = 1; i < n; i++) {
		x = arr[i];
		j = i - 1;
		while ((x < arr[j]) && j >= 0) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = x;
	}
}

void approximation(int x, int * arr, int n) {
	int i, count = 2;
	if ((x < arr[0]) || (x > arr[n - 1])) cout << "Number not found.";
	else {
		i = abs(round((n / (arr[n - 1] - arr[0] + 1))*(x - arr[0])));
		while (arr[i] < x) {
			i++;
			count++;
		}
		while (arr[i] > x) {
			i--;
			count++;
		}
		count++;
		if (arr[i] == x) cout << "Number found! Its serial number in the array: " << i;
		else cout << "Number not found.";
	}
	cout << "\nThe number of comparison operations: " << count;
	cout << "\n-------------\n";
}