
/*
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
 NOTE: You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details. 

*/

/*
to speed it up, I used an extra row and column array which maintains if the particular row/column has been set to zero or not
*/



#include <bits/stdc++.h>
using namespace std;
setZeroes(vector<vector<int> > &A) {

    //vector<vector<int>> vis(A.size(), vector(A[0].size(),0));
    queue<pair<int,int>> q;
    int row[A.size()] = {0}, col[A[0].size()] = {0};
    
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(A[i][j]==0)
                q.push({i,j});
        }
    } 

    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();

        if(col[cur.second]==0)
        for(int i = 0;i< A.size();i++){
            A[i][cur.second] = 0;
            col[cur.second] = 1;
        }

        if(row[cur.first]==0)
        for(int i = 0;i< A[0].size();i++){
            A[cur.first][i] = 0;
            row[cur.first] =1;
        }
    }
    
}
