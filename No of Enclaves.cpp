#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
class Solution {
   public:
   void dfs(int x, int y, vector < vector <int>>& A){
      if(x < 0 || y < 0 || x >= A.size() || y >= A[0].size() ||
      A[x][y] == 0) return;
      A[x][y] = 0;
      for(int k = 0; k < 4; k++){
         int nx = dir[k][0] + x;
         int ny = dir[k][1] + y;
         dfs(nx, ny, A);
      }
   }
   int numEnclaves(vector<vector<int>>& A) {
      int ret = 0;
      int n = A.size();
      int m = n ? A[0].size() : 0;
      for(int i = 0; i < n; i++){
         if(A[i][0] == 1){
            dfs(i, 0, A);
         }
         if(A[i][m - 1] == 1){
            dfs(i, m - 1, A);
         }
      }
      for(int i = 0; i < m; i++){
         if(A[0][i] == 1){
            dfs(0, i, A);
         }
         if(A[n - 1][i] == 1){
            dfs(n - 1, i, A);
         }
      }
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            ret += A[i][j];
         }
      }
      return ret;
   }
};
main(){
   vector<vector<int>> v1 = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
   Solution ob;
   cout << (ob.numEnclaves(v1));
}
