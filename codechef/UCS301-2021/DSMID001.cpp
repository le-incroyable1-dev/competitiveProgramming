/*
Generate random integers Problem Code: DSMID001
Add problem to Todo list
Submit
A group of students is trying to generate a random sequence of numbers having only odd positive integers. The group decided to start with a sequence of n single digit integers and apply the following procedure to complete the task. 1. ORGANIZE THE GIVEN DIGITS
Arrange the n digits in an array, say A[0..n-1] such that A[0] = first integer, A[n-1] = second integer, and the third integer gets inserted at the middle index position.
This divides the array into two parts A[0..middle_index] and A[middle_index..n-1]. Next integer in sequence, i.e. the fourth integer gets inserted at the middle index in the first part. Similarly the fifth integer takes the middle index position in the second part.
Now the array has four parts. The next four integers in sequence take the respective middle positions in the obtained four parts.
Repeat this process till all the n integers get inserted in the array A.
Note: The middle index is computed as lower bound((a+b)/2), where `a` and `b` are starting and ending indices respectively. 2. REMOVE EVEN INTEGERS Execute the following steps in sequence till even integers are present in the array A.
Scan the array A from the end of 0th index, i.e. from A[0], and identify the first even and the first odd integers. Let the index of an even integer is e and that of an odd integer is o then A[max(o,e)] = A[e] + A[o]. Also delete the integer A[min(o,e)].
Scan the array A from the end of (n-1)th index, i.e. from A[n-1], and identify the first even and the first odd integers. Let the index of an even integer is e and that of an odd integer is o then A[min(o,e)] = A[e] + A[o]. Also delete the integer A[max(o,e)].
3. REMOVE NEGATIVE INTEGERS Execute the following steps in sequence till negative integers are present in the array A.
Scan the array A from the end of 0th index, i.e. from A[0], and identify the first negative and the first positive integers. Let the index of a positive integer is p and that of a negative integer is n then A[max(p,n)] = A[p] + A[n]. Also delete the integer A[min(p,n)].
Scan the array A from the end of (n-1)th index, i.e. from A[n-1], and identify the first negative and the first positive integers. Let the index of a positive integer is p and that of a negative integer is n then A[min(p,n)] = A[p] + A[n]. Also delete the integer A[max(p,n)].
4. Repeat Step 2 to remove EVEN integers. Follow the same steps as listed in Step 2. 5. REMOVE DUPLICATES Keep only the last occurrence for any repeating integer.

Implement the above algorithm to generate a sequence of odd positive integers.

Input Format
- Line 1 contains an integer N, the number of single digit integers to start with. - Line 2 contains N space separated integers. This is a sequence of n single digit integers.
Output Format
Line 1 is a space separated sequence of odd positive integers obtained at the end.

Constraints
All inputs range in between 1 and 1000.
Sample Input 1 
9
1 9 5 3 7 2 4 6 8
Sample Output 1 
3 5 23 7
Explanation
The contents of array A[0..8] get updated in the following manner:
ORGANIZE THE GIVEN DIGITS
1 2 3 4 5 6 7 8 9
REMOVE EVEN INTEGERS
After 2(a)
3 3 4 5 6 7 8 9
After 2(b)
3 3 4 5 6 7 17
After 2(a)
3 7 5 6 7 17
After 2(b)
3 7 5 23 7
REMOVE NEGATIVE INTEGERS
3 7 5 23 7
Repeat Step 2 to remove EVEN integers.
3 7 5 23 7
REMOVE DUPLICATES
3 5 23 7
Sample Input 2 
10
5 8 -2 -1 2 1 9 6 -3 7
Sample Output 2 
11 21
Explanation
The contents of array A[0..9] get updated in the following manner:
ORGANIZE THE GIVEN DIGITS
5 1 -1 9 -2 6 2 -3 7 8
REMOVE EVEN INTEGERS
After 2(a)
1 -1 9 3 6 2 -3 7 8
After 2(b)
1 -1 9 3 6 2 -3 15
After 2(a)
-1 9 3 7 2 -3 15
After 2(b)
-1 9 3 7 17 -3
REMOVE NEGATIVE INTEGERS
After 3(a)
8 3 7 17 -3
After 3(b)
8 3 7 14
Repeat Step 2 to remove EVEN integers.
After 2(a) executed as part of Step 4
11 7 14
After 2(b) executed as part of Step 4
11 21
REMOVE DUPLICATES
11 21
Author:	shreelekhap
Date Added:	19-10-2021
Time Limit:	1 secs
Source Limit:	50000 Bytes
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int


#include <bits/stdc++.h>
using namespace std;

#define ll long long int


void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2)
	{
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	while (i < n1)
		arr3[k++] = arr1[i++];


	while (j < n2)
		arr3[k++] = arr2[j++];
}


void createHalves(int h1[], int h2[], int s1, int s2, int original[])
{

	for (int i = 0; i < s1; i++)
		h1[i] = original[i];
	for (int j = 0; j < s2; j++)
		h2[j] = original[s1 + j];
}


void mergeSort(int input[], int size) {

	if (size == 0 or size == 1)
		return;
	else
	{
		const int size1 = size / 2;
		const int size2 = size - (size / 2);

		int* half1 = new int[size1];
		int* half2 = new int[size2];
		createHalves(half1, half2, size1, size2, input);

		mergeSort(half1, size1);
		mergeSort(half2, size2);

		mergeArrays(half1, half2, size1, size2, input);
	}
}


void setupIndices(int* ind, int n, int* sind, int size)
{
	if (n >= size)
		return;

	int s1 = (2 * n) - 1;
	int s = s1;

	for (int i = 0; i < n - 1; i++)
	{
		if (sind[i + 1] - sind[i] == 1)
			s--;
	}

	int* nsind = new int[s];
	
	int r = 0;


	for (int i = 0; i < n; i++)
	{
		//ind[i] = sind[i];
		nsind[i] = sind[i];

		if (i < n - 1 && (sind[i + 1] - sind[i]) > 1)
		{
			int mid = (sind[i + 1] + sind[i]) / 2;
			ind[n + i - r] = mid;
			nsind[n + i - r] = mid;
		}
		else
			r++;
	}


	mergeSort(nsind, s);

	setupIndices(ind, s, nsind, size);

	return;

}

void part1(int* ind, int* res, int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		res[ind[i]] = arr[i];
	}
}

int* part2(int* arr, int &n)
{
	bool noEven = true;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			noEven = false;
			break;
		}
	}

	//int r = 0;
	int* res = arr;

	while (!noEven)
	{
		noEven = true;

		int e = -1;
		int o = -1;
		int r = 0;
		//int cr = r;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 2 == 0)
			{
				e = i;
				break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 2 != 0)
			{
				o = i;
				break;
			}
		}

		if (e != -1 && o != -1)
		{
			r++;

			n = n - 1;
			//cout << "n : " << n << endl;

			arr[max(o, e)] = arr[o] + arr[e];

			int m1 = min(o, e);

			int* a1 = new int[n];
			int j = 0;

			for (int i = 0; i < n; i++)
			{
				if (j == m1)
					j++;

				a1[i] = arr[j];

				j++;
			}

			res = a1;

		}
		else
			res = arr;

		e = -1;
		o = -1;

		for (int i = n - 1; i >= 0; i--)
		{
			if (res[i] % 2 == 0)
			{
				e = i;
				break;
			}
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (res[i] % 2 != 0)
			{
				o = i;
				break;
			}
		}


		if (e != -1 && o != -1)
		{
			r++;

			n = n - 1;

			//cout << "n : " << n << endl;

			res[min(o, e)] = res[o] + res[e];

			int m1 = max(o, e);

			int* a1 = new int[n];
			int j = 0;

			for (int i = 0; i < n ;i++)
			{
				if (j == m1)
					j++;

				a1[i] = res[j];

				j++;
			}

			res = a1;

		}

		for (int i = 0; i < n; i++)
		{
			if (res[i] % 2 == 0)
			{
				noEven = false;
				break;
			}
		}

		arr = res;

		if (r == 0)
			break;
	}

	return res;
}

int* part3(int* arr, int &n)
{
	bool noNeg = true;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			noNeg = false;
			break;
		}
	}

	int r = 0;
	int* res = arr;

	while (!noNeg)
	{
		noNeg = true;

		int ne = -1;
		int p = -1;

		int cr = r;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] < 0)
			{
				ne = i;
				break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > 0)
			{
				p = i;
				break;
			}
		}

		if (ne != -1 && p != -1)
		{
			r++;
			n = n - 1;

			arr[max(ne, p)] = arr[ne] + arr[p];

			int m1 = min(ne, p);

			int* a1 = new int[n];
			int j = 0;

			for (int i = 0; i < n; i++)
			{
				if (j == m1)
					j++;

				a1[i] = arr[j];

				j++;
			}

			res = a1;

		}
		else
			res = arr;

		ne = -1;
		p = -1;

		for (int i = n - 1; i >= 0; i--)
		{
			if (res[i] < 0)
			{
				ne = i;
				break;
			}
		}

		for (int i = n - r; i >= 0; i--)
		{
			if (res[i] > 0)
			{
				p = i;
				break;
			}
		}
        
        
		if (ne != -1 && p != -1)
		{
			r++;
			n = n - 1;

			res[min(ne, p)] = res[ne] + res[p];

			int m1 = max(ne, p);

			int* a1 = new int[n];
			int j = 0;

			for (int i = 0; i < n; i++)
			{
				if (j == m1)
					j++;

				a1[i] = res[j];

				j++;
			}

			res = a1;

		}

		for (int i = 0; i < n; i++)
		{
			if (res[i] < 0)
			{
				noNeg = false;
				break;
			}
		}

		arr = res;

		if (r == 0)
			break;
	}

	return res;
}


bool valid(int* arr, int n)
{
	int check = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
			check++;
	}

    if(check == n)
	    return false;
	    
    check = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
			check++;
	}
	
	if(check == n)
	    return false;

	return true;
}



int main() {

	int n = 0;
	cin >> n;

	if (n == 0)
		return 0;

	int* arr = new int[n];
	int* res = new int[n];

	for (int i = 0; i < n; i++)
	{
		//res[i] = -1;
		cin >> arr[i];
	}

     // ------------------------------------ PART 1 -----------------------------------------------   
    
	int* ind = new int[n];
	ind[0] = 0;
	ind[1] = n - 1;

	int* sind = new int[2];
	sind[0] = 0;
	sind[1] = n - 1;

	setupIndices(ind, 2, sind, n);
	
	part1(ind, res, arr, n);
	
	if(!valid(res, n))
	{
	    cout << " ";
	    return 0;
	}
	
	// --------------------------------------------------------------------------------------------
	
	res = part2(res, n);
	
	if(!valid(res, n))
	{
	    cout << " ";
	    return 0;
	}
	
	res = part3(res, n);
	
	if(!valid(res, n))
	{
	    cout << " ";
	    return 0;
	}
	
	res = part2(res, n);
	
	if(!valid(res, n))
	{
	    cout << " ";
	    return 0;
	}
	
	unordered_set <int> myset;
	vector<int> finalResult;

	for (int i = n-1; i >= 0; i--)
	{
		if (myset.find(res[i]) == myset.end())
		{
			myset.insert(res[i]);
			finalResult.push_back(res[i]);
		}
		
	}

	for (int i = finalResult.size() - 1; i >= 0; i--)
	{
		cout << finalResult.at(i) << " ";
	}
	
	//cout << endl;

	return 0;
}
