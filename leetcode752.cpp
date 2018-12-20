#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<queue>
#include <algorithm>
using namespace std;

/*
�����˵��һ�ֿɻ�������λ��������ò���������ϱȽϳ�����������
��������һ��Ŀ��ֵ������һЩ���������������˵���������Щ������λ�ã��Ͳ����ٶ��ˣ��൱���Թ��е��ϰ��
Ȼ�����������ٶ��ٲ����Դӳ�ʼ��0000λ�û�����������targetλ�á�
�����λ�㹻�����Ļ���Ӧ���ܷ�����ʵ���ʾ��Ǹ��Թ����������⣬ֻ��������λ�ò��������������ĸ�λ�ã�������λ����ÿ������һ��һ���ܹ��а˸����ڵ�λ�á�
�����Թ������������·��Ҫ��BFS��������ô�����Ҳ������BFS���������;���BFS�����Թ��ⷨΨһ��ͬ�ľ�������һ��λ�õĵط�����������Ҫ������λ���ֵ�ÿһλ��Ȼ��ֱ��1��1��������j��-1������1������0������Ҳ����ʵ���˼�1��1�Ĺ��̡�
Ȼ������Ҫ����Ҫ����λ�ϵ����֣�Ϊ�˴���9��1��0����0��1��9�����������ͳһ����λ���ּ��ϸ�10��Ȼ���ټӻ��1������ٶ�10ȡ�༴�ɣ�ע���ַ���������֮��ͨ���ӻ��'0'��ת����
�����ý��res����¼BFS�����Ĳ����������ʱ�����ɵ��ַ�������target�ˣ�ֱ�ӷ��ؽ��res���������ǿ�������ַ������������������֮ǰû�б���������ô�������queue�У�֮�󽫸��ַ�������visited�����м��ɡ�
ע��������whileѭ���У�����Ҫһ��һ���������չ��һ��������ǻ���һ������len����¼��ǰ��q.size()������Ϊ�˼�࣬ʹ����һ��trick�����Ǵ�q.size()��0������ǧ���ܷ���������Ϊ�ڼ���Ĺ�����q�Ĵ�С��仯�������k < q.size() Ϊ��ֹ��������b����������ǳ�ʼ��Ϊq.size()��û��
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
                        //count(n)�����±�Ϊn��λ���������ݣ��з���1���޷���0��
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
        //��ʱ�� 
        /*
        vector<string>::iterator iterd = find(deadends.begin(),deadends.end(),"0000");
        
        //find()��=end()�ҵ�ָ��Ԫ�� 
        if(iterd!=deadends.end()){
        
            //�����������0000ֱ�ӷ���-1
            cout<<"�����������0000ֱ�ӷ���-1"<<endl;
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
                        //find()==end()�Ҳ���ָ��Ԫ�� 
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
        //���Ž� 
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
 
