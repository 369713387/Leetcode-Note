#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<queue>
#include <algorithm>
using namespace std;

/*
这道题说有一种可滑动的四位数的锁，貌似行李箱上比较常见这种锁。
给了我们一个目标值，还有一些死锁的情况，就是说如果到达这些死锁的位置，就不能再动了，相当于迷宫中的障碍物。
然后问我们最少多少步可以从初始的0000位置滑动到给定的target位置。
如果各位足够老辣的话，应该能发现其实本质就是个迷宫遍历的问题，只不过相邻位置不再是上下左右四个位置，而是四位数字每个都加一减一，总共有八个相邻的位置。
遍历迷宫问题中求最短路径要用BFS来做，那么这道题也就是用BFS来解啦，和经典BFS遍历迷宫解法唯一不同的就是找下一个位置的地方，这里我们要遍历四位数字的每一位，然后分别加1减1，我们用j从-1遍历到1，遇到0跳过，也就是实现了加1减1的过程。
然后我们要计算要更新位上的数字，为了处理9加1变0，和0减1变9的情况，我们统一给该位数字加上个10，然后再加或减1，最后再对10取余即可，注意字符和整型数之间通过加或减'0'来转换。
我们用结果res来记录BFS遍历的层数，如果此时新生成的字符串等于target了，直接返回结果res，否则我们看如果该字符串不在死锁集合里，且之前没有遍历过，那么加入队列queue中，之后将该字符串加入visited集合中即可。
注意这里在while循环中，由于要一层一层的往外扩展，一般的做法是会用一个变量len来记录当前的q.size()，博主为了简洁，使用了一个trick，就是从q.size()往0遍历，千万不能反回来，因为在计算的过程中q的大小会变化，如果让k < q.size() 为终止条件，绝b会出错，而我们初始化为q.size()就没事
*/
int openLock(vector<string>& deadends, string target) {
	/*
        unordered_set<string> deadlock(deadends.begin(), deadends.end());
        if (deadlock.count("0000")) return -1;
        int res = 0;
        unordered_set<string> visited{{"0000"}};
        queue<string> q{{"0000"}};
        while (!q.empty()) {
            ++res;
            for (int k = q.size(); k > 0; --k) {
                auto t = q.front(); 
				q.pop();
                for (int i = 0; i < t.size(); ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (j == 0) continue;
                        string str = t;
                        str[i] = ((t[i] - '0') + 10 + j) % 10 + '0';
                        if (str == target) return res;
                        //count(n)计算下标为n的位置有无数据，有返回1，无返回0。
                        if (!visited.count(str) && !deadlock.count(str)){
                        	q.push(str);                        	
						}						       
                        visited.insert(str);
                    }
                }
            }
            cout<<" "<<q.size();
        }        
        return -1;
        */
        //超时解 
        /*
        vector<string>::iterator iterd = find(deadends.begin(),deadends.end(),"0000");
        
        //find()！=end()找到指定元素 
        if(iterd!=deadends.end()){
        
            //死锁情况中有0000直接返回-1
            cout<<"死锁情况中有0000直接返回-1"<<endl;
            return -1;
        }
        
        int step = 0;
        vector<string> visited{{"0000"}};
        
        queue<string> q {{"0000"}};
        
        while(!q.empty()){
            step++;
            for(int k = q.size();k>0;--k){
                auto t = q.front();
                q.pop();
                for(int i = 0;i<t.size();i++){
                    for(int j = -1;j<=1;j++){
                        if(j==0){
                            continue;
                        }
                        string str = t;
                        str[i] = ((t[i]-'0') + 10 + j)%10 + '0';
                        if(str == target){
                            return step;
                        }
                        vector<string>::iterator iter_v = find(visited.begin(),visited.end(),str);
                        vector<string>::iterator iter_d = find(deadends.begin(),deadends.end(),str);
                        //find()==end()找不到指定元素 
                        if(iter_v==visited.end() && iter_d==deadends.end()){                        
                            q.push(str);
                        }
                        visited.push_back(str);
                    }                        
                }
            }
            cout<<" "<<q.size();
        }
        return -1;
        */
        //最优解 
        /*
        int res = 0, trg = stoi(target);
        vector<bool> visited_s(10000, false), visited_e(10000, false);
        for (auto &s : deadends) {
            int n = stoi(s);
            visited_s[n] = visited_e[n] = true;            
        }
        if (visited_s[0]) return -1;
        if (trg == 0) return res;
        queue<int> q_s({0}), q_e({trg});
        visited_s[0] = true; visited_e[trg] = true;
        
        while (!q_s.empty() && !q_e.empty()) {
            if (q_e.size() < q_s.size()) {
                swap(q_s, q_e);
                swap(visited_s, visited_e);
            }
            int fringe = q_s.size();   
            res++;
            while(fringe--) {
                int pass = q_s.front();
                q_s.pop();
                int n = pass;
                for (int i = 0; i < 4; i++) {
                    int diff = pow(10, i);
                    int d = n % 10;
                    n /= 10;
                    int inc = pass + (d == 9 ? -9 * diff : diff);
                    if (!visited_s[inc]) {
                        if (visited_e[inc]) return res;
                        visited_s[inc] = true;
                        q_s.push(inc);
                    }
                    int dec = pass + (d == 0 ? 9 * diff : -diff);
                    if (!visited_s[dec]) {
                        if (visited_e[dec]) return res;
                        visited_s[dec] = true;
                        q_s.push(dec);
                    }
                }
            }
        }
        return -1;
        */
}

int main(){
	vector<string> deadEnds{{"8887"},{"8889"},{"8878"},{"8898"},{"8788"},{"8988"},{"7888"},{"9888"}};
		
	int res = openLock(deadEnds,"8888");
	
	cout<<res<<endl;
	
	return 0;
}
 
