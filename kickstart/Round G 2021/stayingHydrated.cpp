#include <string>
#include <climits>
#include <iostream>

using namespace std;

//INCOMPLETE

long long mod(long long val)
{
	if (val >= 0)
		return val;
	else
		return (-1 * val);
}



long long calcMinDistToObject(long long *object, long long x, long long y)
{
	long long dist = 0;

	long long xdiff;
	long long ydiff;

	
	if (mod(object[0] - x) <= mod(object[2] - x))
		xdiff = mod(object[0] - x);
	else
		xdiff = mod(object[2] - x);


	if (mod(object[1] - y) >= mod(object[3] - y))
		ydiff = mod(object[1] - y);
	else
		ydiff = mod(object[3] - y);

	cout << xdiff <<" " << ydiff << endl;

	dist = xdiff + ydiff;

	return dist;
}



long long solve(long long k, long long** objects, long long x1min, long long y1min, long long x2max, long long y2max)
{
	long long minDistSum = LLONG_MAX;

	for (int i = x1min; i <= x2max; i++)
	{
		for (int j = y1min; j <= y2max; j++)
		{
			long long curMinDistSum = 0;

			for(int c = 0; c < k; c++)
			{

				long long* curObject = objects[c];
				curMinDistSum += calcMinDistToObject(curObject, i, j);
				cout << curMinDistSum << endl;
			}

			if (curMinDistSum < minDistSum)
				minDistSum = curMinDistSum;

			cout << "NEXT SUM" <<  endl;
			

		}
	}

	return minDistSum;

}

int main()
{
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int k = 0;
		cin >> k;

		long long** objects = new long long * [k];

		long long x1 = 0;
		long long x2 = 0;
		long long y1 = 0;
		long long y2 = 0;

		long long x1min = LLONG_MAX;
		long long y1min = LLONG_MAX;
		long long x2max = LLONG_MIN;
		long long y2max = LLONG_MIN;

		for (int j = 0; j < k; j++)
		{
			cin >> x1 >> y1 >> x2 >> y2;

			if (x1 < x1min)
				x1min = x1;
			if (y1 < y1min)
				y1min = y1;
			if (x2 > x2max)
				x2max = x2;
			if (y2 > y2max)
				y2max = y2;


			long long* object = new long long[4];
			object[0] = x1;
			object[1] = y1;
			object[2] = x2;
			object[3] = y2;

			objects[j] = object;
		}

		cout << "Case #" << i + 1 << ": " << endl; 
		cout << endl << solve(k, objects, x1min, y1min, x2max, y2max);
		cout << endl;
	}

	return 0;
}
