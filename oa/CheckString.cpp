//和当时Niantic第三轮类似题，list of string，每个string前半部分是字符串后面是数字的，都是用stack对应数字系列

int check_log_history(vecotr<string> events){
    if(events.size() == 0) return 0;
    
    int step = 0;
    int n = event.size();
    unordered_set<int> set;
    stack<int> st;
    
    for(int i=0;i<n;i++){
        step++;
        string str = event[i];
        int num = stoi(event[i].substr(8));
        if(num.at(0) == 'A'){
            if(set.insert(num).second != false)
                st.push(num);
            else
                return step;
        }
        
        else{
            if(set.erase() != false){
                int t = st.top();
                st.pop();
                if(t != num) return step;
            }
            else
                return step;
        }
    }
    
    return st.size() == 0 ? 0:++step;
    
}
