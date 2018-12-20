#include<iostream>
#include<vector>
#include<stack> 
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<int> s;
        for(int i = 0;i<T.size();i++){
            while(!s.empty() && T[i]>T[s.top()]){           	
                res[s.top()] = i - s.top();
                s.pop();                                            
            }            
            s.push(i);
        }
        return res;
}

int main(){
	vector<int> t;
	vector<int> res(8,10);
	t.push_back(73);
	t.push_back(74);
	t.push_back(75);
	t.push_back(71);
	t.push_back(69);
	t.push_back(72);
	t.push_back(76);
	t.push_back(73);
	res = dailyTemperatures(t);
	for(int i = 0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	
	return 0;
}

	

