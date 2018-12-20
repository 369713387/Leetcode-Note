#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
   stack<int> s1;  
    for(int i = 0; i< tokens.size();i++){
    	if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
    		s1.push(stoi(tokens[i]));
		}else{
            int res = 0;
			int b = s1.top();
			s1.pop();
			int a = s1.top();
			s1.pop();
			if(tokens[i]=="+"){
				res = a+b;
				s1.push(res);
            }
            else if(tokens[i]=="-")
            {
                res = a-b;
				s1.push(res);
            }
            else if(tokens[i]=="*")
            {
                res = a*b;
				s1.push(res);
            }
            else if(tokens[i]=="/")
            {
                res = a/b;
				s1.push(res);
            }
								
			}
		}
	    return s1.top();
}

int main(){
	vector<string> tokens;
	tokens.push_back("0");
	tokens.push_back("3");
	tokens.push_back("/");
	int res = evalRPN(tokens);
	cout<<res;
	return 0;
}
