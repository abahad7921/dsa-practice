#include <bits/stdc++.h>
using namespace std;

void firstNegativeNumber(vector<int> arr,int k)
{
    int n = arr.size();

    if(n < k || k < 1)
        return;

    queue<int>q; //this queue will store the negative numbers

    int i=0,j=0;

    while(j < n)
    {
        if(arr[j] < 0)
            q.push(arr[j]);

        if((j - i + 1) > k)
        {
            if(q.size() == 0)
                cout<<0<<endl;
            else
            {
                cout<<q.front()<<endl;

                if(arr[i] == q.front())
                    q.pop();
            }

            i++;
        }

        j++;
    }

    if(q.size() == 0)
        cout<<0<<endl;
    else
        cout<<q.front()<<endl;
}


int main() {

    #ifndef ONLINE JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif 

    vector<int> arr = {1,-1,-3,0,-5,6,-7,-8};
    vector<int> arr1 = {1,1,1,1,1,1,1,1};
	
    // maxSubarraySum(arr,3);
    firstNegativeNumber(arr1,3);

	return 0;
}
