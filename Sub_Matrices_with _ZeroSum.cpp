/*

Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note: elements might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output
2

Explanation
-8 5 7
3 7 -8
5 -8 9

-8 5 7
3 7 -8
5 -8 9

*/


int cnt=0;
void findZ(vector<int> a){
    unordered_map<int,int> mp;
    int sum=0;
    
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        
        if(sum==0) cnt++;
        
        if( mp.find(sum)!=mp.end())
            cnt+=mp[sum];
       
            mp[sum]++;
    }
}
int Solution::solve(vector<vector<int> > &A) {
if(A.size()==0)
return 0;
cnt=0;
for(int l = 0;l<A[0].size();l++){
     vector<int> tmp(A.size(),0);
    for(int r=l;r<A[0].size();r++){
       
       for(int i=0;i<A.size();i++){
           tmp[i]+=A[i][r];
       }
       
       findZ(tmp);
    }
}
   
   return cnt;
   
}
