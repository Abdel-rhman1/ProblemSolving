#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
int Seqential(int arr[], int element, int left, int right) {
	if (right < 1) return -1;
	if (arr[left] == element) return left;
	if (arr[right] == element) return right;
	return Seqential(arr, element, left + 1, right - 1);
}
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {

		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}
time_t Time() {
	time_t begin_time;
	begin_time = time(NULL);
	return begin_time;
}
int* GenerateRandom(int size) {
	srand(time(NULL));
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size + 0;
	}
	return array;
}
void swap(int *x,int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int Partiation(int arr[],int left,int right) {
	int pi = arr[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; j++) {
		if (arr[j] < pi) {
			i++;
			swap(&arr[i], &arr[j]);
		}	
	}
	swap(&arr[i + 1], &arr[right]);
	return (i + 1);
}
void Quicksort(int arr[], int left, int right) {
	if (left < right) {
		int pi = Partiation(arr, left, right);
		Quicksort(arr, left, pi-1);
		Quicksort(arr, pi + 1, right);
	}
}
int main() {
	int* array;
	cout<<"Enter the size of the set"<<endl;
	int size;
	cin>>size;
	array = GenerateRandom(size);
	time_t begin_time = Time();
	cout << Seqential(array, 290, 0,size) << endl;
	time_t end_time = Time();
	cout << "Sequential Search Take " << end_time - begin_time << " Time Unit " << endl;
	begin_time = Time();
	Quicksort(array, 0, size-1);
	cout << binarySearch(array, 0, size-1, 290) << endl;
	end_time = Time();
	cout << "Binary Search Take " << end_time - begin_time << " Time Unit " << endl;
	delete[]array;
	return 0;
}
