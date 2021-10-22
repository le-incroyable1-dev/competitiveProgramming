/*
Get unique characters Problem Code: DSMID003
Add problem to Todo list
Submit
A string of characters including only alphabets (small letters) is provided as an input. Each character appearing in the string has to be inserted in a singly linked list, say SLL, as per the following rules:
If a character, say ch1, is not present in SLL then insert ch1 at the end.
Otherwise, remove ch1 first and then re-insert it in the middle of SLL.
In case some character, say ch2, is already present in the middle of SLL, then ch1 and ch2 have to be arranged as per the chronological order in SLL.

Once all the characters of a string get inserted in SLL, identify characters with minimum and maximum ASCII values. Let these characters be minChar and maxChar, respectively. Update the SLL such that the next pointer of minChar is maxChar. Finally, display the two obtained singly linked lists (unique contents), starting from heads. There should not be any common nodes in between the two linked lists.
Input Format
Line 1 contains the string of characters without spaces.
Output Format
Line 1 will have space separated contents of the finally generated linked list.
Line 2 will have space separated contents of another linked list, if generated due to the last pointer update.
Constraints
Number of characters in the string ranges in between 1 and 1000.
Sample Input 1 
important
Sample Output 1 
i m p o t r a
n
Explanation
Input ‘i’: i-->NULL (Insert at end)
Input ‘m’: i-->m-->NULL (Insert at end)
Input ‘p’: i-->m-->p-->NULL (Insert at end)
Input ‘o’: i-->m-->p-->o-->NULL (Insert at end)
Input ‘r’: i-->m-->p-->o-->r-->NULL (Insert at end)
Input ‘t’: i-->m-->p-->o-->r-->t-->NULL (Insert at end)
Input ‘a’: i-->m-->p-->o-->r-->t-->a-->NULL (Insert at end)
Input ‘n’: i-->m-->p-->o-->r-->t-->a-->n-->NULL (Insert at end)
Input ‘t’: i-->m-->p-->o-->t-->r-->a-->n-->NULL (Remove ‘t’, ‘o’ comes in the middle, chronologically ‘t’ follows ‘o’)

Character with minimum and maximum ASCII values are ‘a’ and ‘t’ respectively. Therefore, node with character ‘a’ has the address of node with character ‘t’ now. The unique contents of the two resultant linked lists starting from respective head nodes are i-->m-->p-->o-->t-->r-->a and n-->NULL.
Author:	shreelekhap
Date Added:	20-10-2021
Time Limit:	1 secs
Source Limit:	50000 Bytes
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char data)
    {
        this->data = data;
        next = NULL;
    }
};


bool isPresent(Node * head,char ch)
{
    while(head!=NULL)
    {
        if(head->data==ch)
        {
            return true;
        }

        head = head->next;
    }

    return false;
}

pair<Node*,Node*> removeNode(Node * head,Node * tail,char ch)
{
    Node * curr = head;
    Node * prev = NULL;

    while(curr->data!=ch)
    {
        prev = curr;
        curr = curr->next;
    }

    if(prev==NULL)
    {
        head = head->next;
        if(head==NULL)
        {
            tail = NULL;
        }
    }
    else
    {
        prev->next = curr->next;
        if(tail==curr)
        {
            tail = prev;
        }
        delete curr;
    }

    return make_pair(head,tail);
}

Node * findMiddle(Node * head)
{
    Node * fast = head;
    Node * slow = head;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

pair<Node*,Node*> insertMiddle(Node * head,Node * tail,Node * node)
{
    if(head==NULL && tail==NULL)
    {
        head = node;
        tail = node;
        return make_pair(head,tail);
    }

    int len = 0;

    Node * curr = head;

    while(curr!=NULL)
    {
        len++;
        curr = curr->next;
    }

    if(len%2==0)
    {
        Node * mid = findMiddle(head);
        node->next = mid->next;
        mid->next = node;
    }
    else
    {

        Node * mid = findMiddle(head);

        if(head->next==NULL)
        {
            if(mid->data<node->data)
            {
                mid->next = node;
                tail = node;
            }
            else
            {
                node->next = mid;
                head = node;
                tail = mid;
            }
        }
        else{

        
        if(mid->data<node->data)
        {
            node->next = mid->next;
            mid->next = node;
        
        }  
        else
        {
            Node * prev = head;
            while(prev->next!=mid)
            {
                prev = prev->next;
            }

            prev->next = node;
            node->next = mid;

        } 

    }

    }

    return make_pair(head,tail);

}

void solve(string s)
{
    Node *head = NULL;
    Node *tail = NULL;
    int n = 0;

    while (n != s.size())
    {
        Node *newNode = new Node(s[n]);
        
        if(head==NULL && tail==NULL)
        {
            head = newNode;
            tail = newNode;
        }
            else
            {
               if(!isPresent(head,s[n]))
               {
                 tail->next = newNode;
                 tail = tail->next;
                }
        else
        {
            pair<Node*,Node*> temp;
            temp = removeNode(head,tail,s[n]);
            head = temp.first;
            tail = temp.second;

            temp = insertMiddle(head,tail,newNode);
            head = temp.first;
            tail = temp.second;
       }

    }

    n++;

    }

    Node * minChar = head;
    Node * curr = head->next;

    while(curr!=NULL)
    {
        if(minChar->data>curr->data)
        {
            minChar = curr;
        }

        curr = curr->next;
    }

    Node * maxChar = head;
    curr = head->next;

    while(curr!=NULL)
    {
        if(maxChar->data<curr->data)
        {
            maxChar = curr;
        }

        curr = curr->next;
    }

    Node * temp = minChar->next;

    minChar->next = maxChar;

    unordered_map<Node*,bool> map;


    while(head!=NULL)
    {
        if(map.find(head)!=map.end())
        {
            break;
        }
        else
        {
            cout << head->data << " ";
            map[head] = true;
            head = head->next;
        }
    }

    cout << endl;

   while(temp!=NULL && temp!=maxChar)
   {
        cout << temp->data << " ";
        temp = temp->next;
   }

}


int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(0);

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    freopen("Error.txt","w",stderr);

    #endif  

   string s;
   cin >> s;

   solve(s);

}
