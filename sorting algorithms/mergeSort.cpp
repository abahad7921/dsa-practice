#include <bits/stdc++.h>
using namespace std;
//Merge Sort Implementation
//time : O(log(n))

void mergeSort(int arr[],int start,int middle,int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;

	int a1[n1],a2[n2];


	for(int i=0;i<n1;i++)
		a1[i] = arr[start + i];

	for(int i=0;i<n2;i++)
		a2[i] = arr[middle+1+i];

	int i=0,j=0,k=start;

	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			arr[k] = a1[i];
			i++;
		}
		else
		{
			arr[k] = a2[j];
			j++;
		}

		k++;
	}


	while(i<n1)
	{
		arr[k] = a1[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k] = a2[j];
		j++;
		k++;
	}
}



void partition(int arr[],int start,int end)
{
	if(start<end)
	{
		int middle = start + (end - start)/2;

		partition(arr,start,middle);
		partition(arr,middle+1,end);

		mergeSort(arr,start,middle,end);
	}
}

int main()
{

	int arr[] = {1,9,69,44,23,5};

	partition(arr,0,5);

	for(int x:arr)
		cout<<x<<" ";


}
