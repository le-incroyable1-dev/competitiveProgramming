/*
Stacks and a Queue Problem Code: DSEND001SolvedSubmit
There is a queue (Q) and two stacks (S1 and S2). An integer x can be pushed either in S1 or S2 provided the insertion criteria is satisfied. x can be pushed in S1 if and only if x < S1.top. On the other hand, if x > S2.top then x can be pushed in S2.

For a set of n integers, execute the following steps in sequence for each integer, say x. Also, print the contents of Q, S1, and S2 at the moment x successfully gets inserted in either of the stacks.

If S1 is empty or if x satisfies the insertion criteria for S1, push x in S1.
Else if S2 is empty or if x satisfies the insertion criteria for S2, push x in S2.
Else
Choose a stack whose top element is closer to x, assuming conflict will never appear.
Pop integers from the chosen stack and enqueue them in Q till the successful insertion of x.
Dequeue integers from Q and push them back into the earlier chosen stack by repeating the following sequence of operations till Q is not empty:
Dequeue and enqueue Q.size – 1 integers.
Dequeue an integer from Q and push it into the earlier chosen stack.
Now integers are present in S1 and S2 where as Q is empty. Reverse the contents of S2. Now, pop smaller out of the two top (S1.top and S2.top) integers and enqueue it in Q, assuming conflict will never appear. At the end, only Q will have n integers in non-decreasing order. Also, print the contents of Q, S1, and S2 after every successful insertion in Q.
Input Format
Line 1 contains an integer N.
Line 2 contains space separated N integers.
Output Format
Show the contents of Q, S1, and S2 (in separate lines) after each insertion. Nothing will be displayed if Q, S1, or S2 is empty.

Constraints
All integers range in between 1 and 1000.
*/

#include <bits/stdc++.h>
using namespace std;

//s1 s2 and q
stack<int> s1;
stack<int> s2;
queue<int> q;
    
    
void printStack(stack<int> s)
{
    if(s.empty())
    {
        return;
    }
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    cout << endl;
}

void printQueue(queue<int> q)
{
    if(q.empty())
    {
        return;
    }
    
    while(!q.empty())
    {
        cout << q.front()<< " ";
        q.pop();
    }
    
    cout << endl;
}


//Reverse stack

void insert_at_bottom(int x)
{
    if(s2.size() == 0)
    {
        s2.push(x);
    } 
    else
    {
        int a = s2.top();
        s2.pop();
        insert_at_bottom(x);
        s2.push(a);
    }
}
 
void reverses2()
{
    if(s2.size()>0)
    {
        int x = s2.top();
        s2.pop();
        reverses2();
        insert_at_bottom(x);
    }
}
//

void solve2()
{
    //temporary duplicates to print at each stage
    stack<int> ts1;
    stack<int> ts2;
    queue<int> tq;
    
    reverses2();
    
    while(!s1.empty() || !s2.empty())
    {
        if(s1.empty())
        {
            while(!s2.empty())
            {
                int el = s2.top();
                s2.pop();
                q.push(el);
                
                ts1 = s1;
                ts2 = s2;
                tq = q;
        
                printQueue(tq);
                printStack(ts1);
                printStack(ts2);
            }
        }
        else if(s2.empty())
        {
            while(!s1.empty())
            {
                int el = s1.top();
                s1.pop();
                q.push(el);
                
                ts1 = s1;
                ts2 = s2;
                tq = q;
        
                printQueue(tq);
                printStack(ts1);
                printStack(ts2);
            }
        }
        else
        {
            int el1 = s1.top();
            int el2 = s2.top();
            
            //pop the smaller top and enqueue
            if(el1 > el2)
            {
                s2.pop();
                q.push(el2);
            }
            else
            {
                s1.pop();
                q.push(el1);
            }
            
            ts1 = s1;
            ts2 = s2;
            tq = q;
        
            printQueue(tq);
            printStack(ts1);
            printStack(ts2);
        }
        
    }
    
    return;
}

void solve1(int x)
{
    //temporary duplicates to print at each stage
    stack<int> ts1;
    stack<int> ts2;
    queue<int> tq;
    
    if(s1.empty() || x < s1.top())
    {
        s1.push(x);
        
        ts1 = s1;
        ts2 = s2;
        tq = q;
        
        printQueue(tq);
        printStack(ts1);
        printStack(ts2);
    }
    else if(s2.empty() || x > s2.top())
    {
        s2.push(x);
        
        ts1 = s1;
        ts2 = s2;
        tq = q;
        
        printQueue(tq);
        printStack(ts1);
        printStack(ts2);
    }
    else
    {
        if((abs(s1.top() - x) < (abs(s2.top() - x))))
        {
            while(!s1.empty() && x >= s1.top())
            {
                int el = s1.top();
                s1.pop();
                q.push(el);
            }
            
            s1.push(x);
            
            ts1 = s1;
            ts2 = s2;
            tq = q;
        
            printQueue(tq);
            printStack(ts1);
            printStack(ts2);
            
            while(!q.empty())
            {
                for(int i = 0 ; i < q.size() - 1; i++)
                {
                    int el = q.front();
                    q.pop();
                    q.push(el);
                }
                
                int el = q.front();
                q.pop();
                s1.push(el);
            }
            
        }
        else if((abs(s1.top() - x) > (abs(s2.top() - x))))
        {
            while(!s2.empty() && x <= s2.top())
            {
                int el = s2.top();
                s2.pop();
                q.push(el);
            }
            
            s2.push(x);
            
            ts1 = s1;
            ts2 = s2;
            tq = q;
        
            printQueue(tq);
            printStack(ts1);
            printStack(ts2);
            
            while(!q.empty())
            {
                for(int i = 0 ; i < q.size() - 1; i++)
                {
                    int el = q.front();
                    q.pop();
                    q.push(el);
                }
                
                int el = q.front();
                q.pop();
                s2.push(el);
            }
            
        }
        
        
    }
    
    return;
    
    
}


int main() {
    
	int t = 0;
	cin >> t;
	int x;
	
	while(t--)
	{
	    cin >> x;
	    solve1(x);
	}
	
	solve2();
	
	return 0;
}
