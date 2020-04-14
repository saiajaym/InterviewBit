#include<bits/stdc++.h>
using namespace std;

/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/


int firstMissingPositive(vector<int> &A) {
     //cout<<A.size()<<endl;
     vector<int> sol(999999, 0);

    for(int i=0;i<A.size();i++){
        if(A[i]>0 && A[i]<=A.size())
        sol[A[i]]=1;
    }

     for(int i=1;i<sol.size();i++){
        if(sol[i]==0)
        return i;
    }
}