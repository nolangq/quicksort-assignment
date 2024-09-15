#include <iostream>
#include <math.h>
#include <array>
#include <ctime>
#include <time.h>

using namespace std;

int partition(int arr[], int start, int end);
void quicksort(int arr[], int start, int end);
void displayArray(int arr[], int n);
void fillArray(int arr[], int n);

int main()
{
	srand(time(0));
	int nums[] = {10, 80, 3, 19, 14, 7, 5, 12};
	int n = end(nums) - begin(nums);
	cout << "Eight Unsorted:" << endl;
	displayArray(nums, n);
	cout << endl;
	cout << "Eight Sorted:" << endl;
	quicksort(nums, 0, n - 1);
	displayArray(nums, n);
	cout << endl;

	// Array of 100 random numbers
	int oneHundredRandArray[100];
	fillArray(oneHundredRandArray, 100);
	n = end(oneHundredRandArray) - begin(oneHundredRandArray);
	cout << "One Hundred Unsorted:" << endl;
	displayArray(oneHundredRandArray, 100);
	cout << endl;
	cout << "One Hundred Sorted:" << endl;
	quicksort(oneHundredRandArray, 0, n - 1);
	displayArray(oneHundredRandArray, 100);
	cout << endl;
	// Array of 1000 random numbers
	int oneThousandRandArray[1000];
	fillArray(oneThousandRandArray, 1000);
	n = end(oneThousandRandArray) - begin(oneThousandRandArray);
	cout << "One Thousand Unsorted:" << endl;
	displayArray(oneThousandRandArray, 1000);
	cout << endl;
	cout << "One Thousand Sorted:" << endl;
	quicksort(oneThousandRandArray, 0, n - 1);
	displayArray(oneThousandRandArray, 1000);

	return 0;
}

int partition(int arr[], int start, int end)
{
	int temp;
	int pivot = arr[start];
	int i = start;

	for (int j = start + 1; j <= end; j++)
	{
		if (arr[j] < pivot)
		{
			i = i + 1;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//swap start and i
	temp = arr[start];
	arr[start] = arr[i];
	arr[i] = temp;

	return i;
}

void quicksort(int arr[], int start, int end)
{
	if (start < end) // if not empty
	{
		int index = partition(arr, start, end); //index after dividing
		quicksort(arr, start, index - 1); //subarray 1
		quicksort(arr, index + 1, end); //subarray 2
	}
}

void displayArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ", ";
	}

	cout << endl;
}

void fillArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() % 1000);
	}
}