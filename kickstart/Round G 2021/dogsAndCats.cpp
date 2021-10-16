#include<iostream>
#include<string>
using namespace std;


void solve(string s, long long n, long long d, long long c, long long m)
{
	int dct = 0;
	int dins = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'D')
			dins++;
	}

	if (dins > d)
	{
		cout << "NO";
		return;
	}
	else
	{
		//bool flag = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (dct == dins)
			{
				cout << "YES";
				return;
			}

			if (s[i] == 'C')
			{
				if (c > 0)
				{
					c--;
				}
				else
				{
					cout << "NO";
					return;
				}
			}
			else if (s[i] == 'D')
			{
				d--;
				dct++;
				c += m;
			}
			else
				continue;
		}

		if (dct == dins)
		{
			cout << "YES";
			return;
		}
		else
		{
			cout << "NO";
			return;
		}
	}
}

int main()
{
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long n, d, c, m = 0;
		cin >> n >> d >> c >> m;
		string s;
		cin >> s;
		cout << "Case #" << i + 1 << ": ";
		solve(s, n, d, c, m);
		cout << endl;
	}

	return 0;
}
