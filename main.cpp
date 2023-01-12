/*
 * main.cpp
 *
 *  Created on: Jan 4, 2023
 *      Author: user5
 */
#include<bits/stdc++.h>
using namespace std;

extern void sort32(int a[], int up);
// Driver code
int main()
{
	//int a[]= {3, 7, 4, 8, 6, 2, 11, 10, 1, 5, 9, 12, 16, 14, 13, 15};
	const int N = pow(2,5);
	int a[N];
	for (int i=0; i<N; i++)
		a[i] = rand()%512;
	//const int N = sizeof(a)/sizeof(a[0]);

	int up = 1; // means sort in ascending order
	sort32(a, up);

	printf("Sorted array: \n");
	for (int i=0; i<N; i++)
		printf("%d ", a[i]);
	return 0;
}




