#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
int numSquares(int n) {
        //BFSËÑË÷
        queue<pair<int,int>> q;
        q.push(make_pair(n,0));
        vector<bool> visited(n+1, false);
        visited[n] = true;
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            
            q.pop();
            
            for(int i=1; num -i*i >=0; i++){
                if(num-i*i == 0){                	
                
                	return step+1;
				}
                    
                
                if(visited[num-i*i] == false)
                {
                    q.push(make_pair(num-i*i, step+1));
                    
                    visited[num - i*i] = true;
                }
                
            }            
            
        }
        //¶¯Ì¬¹æ»® 
        /*
		vector<int> dp(n + 1, n);
        dp[0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 1; i + j * j <= n; j++) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
		*/
        
    }
    
    int main(){
    	int res = numSquares(12);
    	return 0;
	} 
