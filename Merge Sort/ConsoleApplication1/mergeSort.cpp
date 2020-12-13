// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
	int i, j, k,t;
	j = low;
	for (i=mid+1;i<=high;i++)
	{
		while (arr[j]<=arr[i] && j<i)
		{
			j++;
		}
		if (j == i) {
			break;
		}
		t = arr[i];
		for (k = i; k > j; k--)
		{
			arr[k] = arr[k - 1];
		}
		arr[j] = t;
	}
}


void merge_sort(int arr[], int low, int high) {
	if (low >= high)
	{
		return;
	}
	int mid = (low + high) / 2;
	merge_sort(arr,low,mid);
	merge_sort(arr,mid+1,high);
	merge(arr, low, mid, high);

}

int main()
{
	clock_t start_s = clock();
	int arr[10] = { 2, 4, 10, 12, 11, 5, 15, 18,1,22 };
	cout << "arrary : ";
	for (int i = 0;i < 10; i++) {
		cout << "\t" << arr[i];
	}
	cout << "\n";
	
	merge_sort(arr,0,9);
	cout << "sorted array : ";
	for (int i = 0; i < 10; i++) {
		cout << "\t" << arr[i];
	}
	clock_t stop_s = clock();
	cout << "\ntime: " << (stop_s - start_s) / (double)CLOCKS_PER_SEC << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
