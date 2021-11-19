class Solution {
public:
    void find_sub_str(string s, vector<string>& words, int start, vector<int>& ans,unordered_map<string,int> count){
        int word_size = words[0].size();//每個word的size
        int times = words.size();////跑一round幾次
        int end_pos = start + times*word_size - 1;
        if(end_pos > s.size() )//結束位置超過s 就結束
            return;
        //set<string> record;////紀錄每個word是否被用過
        unordered_map<string,int> record;
        for(int i=start;i<=end_pos;){
            while(times){
                string sub_str = s.substr(i,word_size);
                auto it = find(words.begin(),words.end(),sub_str);
                if(it != words.end()){//sub_str有在字典裡
                    record[sub_str]++;
                }else{//沒有就跳出
                    return;
                }
                i+=word_size;
                times--;
            }
        }
        if(record == count)
            ans.push_back(start);
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int word_size = words[0].size(); 
        int times = words.size(); 
        unordered_map<string,int> count;
        for(auto w:words)
            count[w] += 1;

        for(int i=0;i<s.size();i++){
            
            string sub_str = s.substr(i,word_size);
            //cout << sub_str << endl;
            auto it = find(words.begin(),words.end(),sub_str);
            if(it != words.end()){//有在字典裡就查詢
                //cout << i << " " << sub_str << endl;
                find_sub_str(s, words, i,ans,count);
            }
            
            
            
           
        }
        
        return ans;
    }
};
