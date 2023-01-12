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
template <const int cnt> struct merge_i {
	static void bitonicMerge(int a[], int low, int dir)
	{
		//for (int i=low; i<low+cnt/2; i++)
		for (int i=0; i<32; i++)
		{
			if (i>=cnt/2) break;
			compAndSwap(a, i+low, i+low+(cnt/2), dir);
		}
		merge_i<cnt/2>::bitonicMerge(a, low, dir);
		merge_i<cnt/2>::bitonicMerge(a, low+cnt/2, dir);
	}
};

template <> struct merge_i<1> {
	static void bitonicMerge(int a[], int low, int dir)
	{
		return;
	}
};

/* This function first produces a bitonic sequence by recursively
	sorting its two halves in opposite sorting orders, and then
	calls bitonicMerge to make them in the same order */
template <int cnt> struct sort_i {
	static void bitonicSort(int a[],int low, int dir)
	{
		// sort in ascending order since dir here is 1
		sort_i<cnt/2>::bitonicSort(a, low, 1);

		// sort in descending order since dir here is 0
		sort_i<cnt/2>::bitonicSort(a, low+cnt/2, 0);

		// Will merge whole sequence in ascending order
		// since dir=1.
		merge_i<cnt>::bitonicMerge(a,low, dir);
	}
};

template <> struct sort_i<1> {
	static void bitonicSort(int a[],int low, int dir)
	{
		return;
	}
};

/* Caller of bitonicSort for sorting the entire array of
length N in ASCENDING order */
void sort32(int a[], int up)
{
	sort_i<32>::bitonicSort(a, 0, up);
}
