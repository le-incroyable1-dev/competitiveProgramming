#include <iostream>
using namespace std;

void rowMajorInput(int **arr, int n) {
 
  int i, j;
 
  // input element row wise
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
}

void rowMajorOutput(int **arr, int n) {
 
  int i, j;
 
  // output element row wise
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
  }

  cout << endl;
}


void merge(int **mat, int n)
{
    int nmat = n - (n/2) ;
    
    pair<int, pair<int, int>> ** lists = new pair<int, pair<int, int>> * [nmat];
    
    const int mne = 4*n - 4;
    
    for(int i = 0; i < nmat ; i++)
    {
        lists[i] = new pair<int, pair<int, int>>[mne];
    }

    int it = 1; //counter for iterations of insertion sort
    int lc = 0; //counter for list number
    int st = 0;
    int et = n-1;
    bool printPls = true;

    while(it < (4*n - 4))
    {
        lc = 0;
        st = 0;
        et = n-1;
        int itn = it;

        for(int j = n; j >= 0; j -= 2)
        {
            itn = it;
      
            //printPls = true;
            itn += 2*j - 3 ;
            //cout << "J " << j << " it " << it << " itn " << itn  << endl;
            
            if(j == 0 || j == 1)
            {
                break;
            }
            
            if((itn >= (4*n - 4)))
            {
                printPls = false;
                break;
            }
            
            
            if((itn >= (4*j - 4)))
            {
                //break;
                continue;
            }
            
            /*
            if(it < (2*j - 2))
            {
                printPls = false;
                break;
            }
            */
            int c = 0; //counter for element number of current list
        
            //populate list for current matrix
            
            for(int i = st; i <= et; i++)
            {
                pair<int, int> loc;
                loc.first = i;
                loc.second = st;

                pair<int, pair<int, int>> el;
                el.first = mat[i][st];
                el.second = loc;

                lists[lc][c] = el;
                c++;
            }

            for(int i = st+1; i < et; i++)
            {
                pair<int, int> loc;
                loc.first = et;
                loc.second = i;

                pair<int, pair<int, int>> el;
                el.first = mat[et][i];
                el.second = loc;

                lists[lc][c] = el;
                c++;
            }
            
            /*
            for(int i = it; i > 0; i--)
            {
                if(lists[lc][i].first < lists[lc][i-1].first)
                {
                    int temp = lists[lc][i].first;
                    lists[lc][i].first = lists[lc][i-1].first;
                    lists[lc][i-1].first = temp;
                }
            }
            
            
            //for(int i = 0; i < )
            

            for(int i = 0; i < (2*j - 2); i++)
            {
                mat[lists[lc][i].second.first][lists[lc][i].second.second] = lists[lc][i].first;
            }
            
            
            //increment list count and reset list element number c

            lc++;

            c = 0;
            */

            //populate list for current matrix

            for(int i = et; i >= st; i--)
            {
                pair<int, int> loc;
                loc.first = i;
                loc.second = et;

                pair<int, pair<int, int>> el;
                el.first = mat[i][et];
                el.second = loc;

                lists[lc][c] = el;
                c++;
            }

            for(int i = et-1; i > st; i--)
            {
                pair<int, int> loc;
                loc.first = st;
                loc.second = i;

                pair<int, pair<int, int>> el;
                el.first = mat[st][i];
                el.second = loc;

                lists[lc][c] = el;
                c++;
            }

           
            for(int i = itn; i > 0; i--)
            {
                if(lists[lc][i].first < lists[lc][i-1].first)
                {
                    int temp = lists[lc][i].first;
                    lists[lc][i].first = lists[lc][i-1].first;
                    lists[lc][i-1].first = temp;
                }
            } 
           
            

            for(int i = 0; i < (4*j - 4); i++)
            {
                mat[lists[lc][i].second.first][lists[lc][i].second.second] = lists[lc][i].first;
            }

            //increment the list count for the next matrix
            lc++;


            st++;
            et--;
        }
        
        //cout << "iteration num : " << it << endl;
        if(printPls)
        {
            rowMajorOutput(mat, n);
        }

        it++;
    }
    
    
    
    return;
}



void solve(int **mat, int n)
{
    if(n == 0)
    {
        return;
    }
    
    int nmat = n - (n/2) ;
    
    pair<int, pair<int, int>> ** lists = new pair<int, pair<int, int>> * [2*nmat];
    
    const int mne = 2*n - 2;
    
    for(int i = 0; i < 2*nmat ; i++)
    {
        lists[i] = new pair<int, pair<int, int>>[mne];
    }

    int it = 1; //counter for iterations of insertion sort
    int lc = 0; //counter for list number
    int st = 0;
    int et = n-1;
    
    

    while(it < (2*n - 2))
    {
        lc = 0;
        st = 0;
        et = n-1;
        int c = 0;

        for(int j = n; j >= 0; j -= 2)
        {
            if(j == 0 || j == 1)
            {
                break;
            }
            
            if((it >= (2*j - 2)))
            {
                break;
            }

            c = 0; //counter for element number of current list
        
            //populate first list for current matrix
            
            for(int i = st; i <= et; i++)
            {
                pair<int, int> loc;
                loc.first = i;
                loc.second = st;

                pair<int, pair<int, int>> el;
                el.first = mat[i][st];
                el.second = loc;

                lists[lc][c] = el;
                c++;
            }

            for(int i = st+1; i < et; i++)
            {
                pair<int, int> loc;
                loc.first = et;
                loc.second = i;

                pair<int, pair<int, int>> el;
                el.first = mat[et][i];
                el.second = loc;

                lists[lc][c] = el;
                c++;
            }
            
        
            for(int i = it; i > 0; i--)
            {
                if(lists[lc][i].first < lists[lc][i-1].first)
                {
                    int temp = lists[lc][i].first;
                    lists[lc][i].first = lists[lc][i-1].first;
                    lists[lc][i-1].first = temp;
                }
            }
            
            
            //for(int i = 0; i < )
            

            for(int i = 0; i < (2*j - 2); i++)
            {
                mat[lists[lc][i].second.first][lists[lc][i].second.second] = lists[lc][i].first;
            }
            
            
            //increment list count and reset list element number c

            lc++;

            c = 0;

            //populate second list for current matrix

            for(int i = et; i >= st; i--)
            {
                pair<int, int> loc;
                loc.first = i;
                loc.second = et;

                pair<int, pair<int, int>> el;
                el.first = mat[i][et];
                el.second = loc;

                lists[lc][c] = el;
                c++;
            }

            for(int i = et-1; i > st; i--)
            {
                pair<int, int> loc;
                loc.first = st;
                loc.second = i;

                pair<int, pair<int, int>> el;
                el.first = mat[st][i];
                el.second = loc;

                lists[lc][c] = el;
                c++;
            }

           
            for(int i = it; i > 0; i--)
            {
                if(lists[lc][i].first < lists[lc][i-1].first)
                {
                    int temp = lists[lc][i].first;
                    lists[lc][i].first = lists[lc][i-1].first;
                    lists[lc][i-1].first = temp;
                }
            } 
           
            
            
            for(int i = 0; i < (2*j - 2); i++)
            {
                mat[lists[lc][i].second.first][lists[lc][i].second.second] = lists[lc][i].first;
            }

            lc++;


            st++;
            et--;
        }
        
        //cout << "iteration num : " << it << endl;
        
        rowMajorOutput(mat, n);

        it++;
    }
    //cout << endl << "merge" << endl;
    merge(mat, n);
    
    return;
}

int main() {
	
	int n = 0;
	cin >> n;
	
	int ** mat = new int*[n];
	for(int i = 0; i < n; i++)
	{
	    mat[i] = new int[n];
	}
	

	rowMajorInput(mat, n);
	//rowMajorOutput(mat, n);
	solve(mat, n);
	
	return 0;
}
