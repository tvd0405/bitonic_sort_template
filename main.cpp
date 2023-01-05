/*
 * main.cpp
 *
 *  Created on: Jan 4, 2023
 *      Author: user5
 */
/* C++ Program for Bitonic Sort. Note that this program
works only when size of input is a power of 2. */
#include<bits/stdc++.h>
using namespace std;

/*The parameter dir indicates the sorting direction, ASCENDING
or DESCENDING; if (a[i] > a[j]) agrees with the direction,
then a[i] and a[j] are interchanged.*/
void compAndSwap(int a[], int i, int j, int dir)
{
	if (dir==(a[i]>a[j]))
		swap(a[i],a[j]);
}

/*It recursively sorts a bitonic sequence in ascending order,
if dir = 1, and in descending order otherwise (means dir=0).
The sequence to be sorted starts at index position low,
the parameter cnt is the number of elements to be sorted.*/
void bitonicMergeEnd()
{
	return;
}

template <const int cnt>
void bitonicMerge(int a[], int low, int dir)
{
	if (cnt <= 1)
		bitonicMergeEnd();
	else
	{
		for (int i=low; i<low+cnt/2; i++)
			compAndSwap(a, i, i+cnt/2, dir);
		bitonicMerge<cnt/2>(a, low, dir);
		bitonicMerge<cnt/2>(a, low+cnt/2, dir);
	}
}

/* This function first produces a bitonic sequence by recursively
	sorting its two halves in opposite sorting orders, and then
	calls bitonicMerge to make them in the same order */
void bitonicSortEnd()
{
	return;
}

template <int cnt>
void bitonicSort(int a[],int low, int dir)
{
	if (cnt <= 1)
		bitonicSortEnd();
	else
	{
		// sort in ascending order since dir here is 1
		bitonicSort<cnt/2>(a, low, 1);

		// sort in descending order since dir here is 0
		bitonicSort<cnt/2>(a, low+cnt/2, 0);

		// Will merge whole sequence in ascending order
		// since dir=1.
		bitonicMerge<cnt>(a,low, dir);
	}
}

/* Caller of bitonicSort for sorting the entire array of
length N in ASCENDING order */
template <const int N>
void sort(int a[], int up)
{
	bitonicSort<N>(a,0, up);
}

// Driver code
int main()
{
	//int a[]= {3, 7, 4, 8, 6, 2, 11, 10, 1, 5, 9, 12, 16, 14, 13, 15};
	const int N = pow(2,5);
	int a[N];
	for (int i=0; i<N; i++)
		a[i] = rand()%256;
	//const int N = sizeof(a)/sizeof(a[0]);

	int up = 1; // means sort in ascending order
	sort<N>(a, up);

	printf("Sorted array: \n");
	for (int i=0; i<N; i++)
		printf("%d ", a[i]);
	return 0;
}




