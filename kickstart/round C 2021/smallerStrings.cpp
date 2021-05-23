/******************************************************************************

TEST

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string str)
{

    long long int l = 0;
    long long int h = str.length() - 1;
    
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    
    return true;
}

void generateAllLexiSmallerStrings(string s, string * arr, string test)
{
    static int cur = 0;
    static int flag = 0;
    static int arrC = 0;
    
    char c;
    
    if(s.length() == 0)
    {
        arr[arrC] = test;
        
        //cout << endl << test;
        arrC++;
        return;
    }
    
    string next = s.substr(1, s.length()-1);
    
    for(int i = 97; i <= s[cur]; i++)
    {
        if(flag == 0)
        {
            c = i;
            test.assign(1, c);
            //cout << endl << s[i] << test;
            generateAllLexiSmallerStrings(next, arr, test);
            flag++;
        }
        else
        {
            c = i;
            test += c;
            generateAllLexiSmallerStrings(next, arr, test);
        }
    }
    
    cur++;
}

int generateAns(long long int n, long long int k, string s)
{
    int count = 0;
    int x = 1;
    string test;
    
    for(int i = 0; i < s.length(); i++)
    {
        x = x * (s[i] - 97 + 1) ;
        //cout << endl << x;
    }
    
    string * arr = new string[x];
    generateAllLexiSmallerStrings(s, arr, test);
    
    for(int i = 0; i < x; i++)
    {
        if(isPalindrome(arr[i]))
        {
            //cout << endl << "Palindrome";
            count++;
        }
    }
    
    
    return count;
}

int main()
{
    int t;
    long long int n,k;
    string s;
    int i = 1;
    
    cin >> t;
    
    while(t--)
    {
        cin >> n >> k;
        cin >> s;
        
        cout << "Case #" << i << ": " << generateAns(n, k, s);
        i++;
    }
    
    return 0;
}
