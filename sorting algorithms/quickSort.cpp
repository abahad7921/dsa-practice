 #include <bits/stdc++.h>
using namespace std;

//Quick Sort Implementation
//time: O(log(n))

int quickSort(int arr[],int start,int end)
{
	int pIndex = start;
	int pivot = arr[end];

	for(int i= start;i<end;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr[i],arr[pIndex]);
			pIndex++;
		}
	}

	swap(arr[pIndex],arr[end]);

	return pIndex;
}




void partition(int arr[],int start,int end)
{
	if(start<end)
	{
		int pIndex = quickSort(arr,start,end);
		partition(arr,start,pIndex-1);
		partition(arr,pIndex+1,end);
	}
}



int main()
{
	int arr[6] = {1,9,4,7,6,2};


	partition(arr,0,5);
	for(int x: arr)
	{
		cout<<x<<" ";
	}
		
}
