/*
When Chef was born, his parents took him to the famous monk Doctor Strange to know whether he will land himself in heaven after his life or not. According to Strange, Chef will live for L years in total. If he wants to go to heaven, he must spend at least 50% of his life years doing good deeds. He also shows them his future using a string S of length L where Si=0 means the i-th year will be counted as bad as per the rule books of heaven and Si=1 means the i-th year will be counted as good.

Also, Strange can use his special powers to make Chef end his life earlier than that planned by god, i.e, he can choose some L′ (1≤L′≤L) and make him live for only L′ years. Strange wants Chef to succeed, so if there is any choice of L′ that allows Chef to go to heaven, he will do so.

Tell whether Chef can go to heaven.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains a single integer L.
The second line contains a string S of length L, consisting of symbols 0 and 1.
Output
For each test case, output the answer in a single line: "YES" if Chef can go to heaven and "NO" if not (without quotes).

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).
*/


#include <iostream>
using namespace std;


void generateAns(string str, int l)
{
    if(str[0] == '1')
    {
        cout << "YES";
        return;
    }
    
    
    int no = 0;
    int nz = 0;
    int i = 0;
    
    for(i = 0; i < l; i++)
    {
        if(str[i] == '1')
        {
            no++;
        }
    }
    
    nz = l - no;
    i = l-1;
    
    while( i > 0)
    {
        if(no >= nz)
        {
            cout << "YES";
            return;
        }
        
        if(str[i] == '1')
        {
            no--;
        }
        else
        {
            nz--;
        }
        
        i--;
    }
    
    cout << "NO";
    return;
}

int main() {
	// your code goes here
	int t;
	int l;
	string s;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> l;
	    cin >> s;
	    
	    generateAns(s, l);
	    cout << endl;
	    
	}
	
	return 0;
}
