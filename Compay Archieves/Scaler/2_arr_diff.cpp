#include<bits/stdc++.h>
using namespace std;

int findLengthOfShortestSubarray(int arr[], int N , int k)
{
	int minlength = INT_MAX;

	int left = 0;
	int right = N - 1;

	while (left < right && abs(arr[left + 1] - arr[left]) <= k)
	{
		left++;
	}

	if (left == N - 1)
		return 0;

	while (right > left && abs(arr[right - 1] - arr[right]) <= k)
	{
		right--;
	}

	minlength = min(N - left - 1, right);

	int j = right;
	for(int i = 0; i < left + 1; i++)
	{
		if (abs(arr[i] - arr[j]) <= k)
		{
			minlength = min(minlength, j - i - 1);
		}
		else if (j < N - 1)
		{
			j++;
		}
		else
		{
			break;
		}
	}

	return minlength;
}

int main()
{
	int arr[] = {1,2};
	int N = sizeof(arr) / sizeof(arr[0]);
	
	cout << (findLengthOfShortestSubarray(arr, N , 0));
}
