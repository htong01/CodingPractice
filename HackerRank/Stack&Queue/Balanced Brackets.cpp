最基础的stack使用方式，push，pop，top

string isBalanced(string s) {
    stack<char> st;
    // st.push('@');
    for(auto c:s){
        if(c=='(' || c=='[' || c=='{') st.push(c);
        else{
            while(!st.empty() && (c==')'&&st.top()=='(') || (c==']'&&st.top()=='[') || (c=='}'&&st.top()=='{'))
                st.pop();
        }
    }
    // if(st.top()=='@') return "YES";
    // else return "NO";
    if(!st.empty()) return "YES";
    else return "NO";
}

输出结果没有return东西？？？为什么？？且如果判断最上面的是不是我自己加进去的话，test case中())这个情况不过

-------------------------------------------------------------------------------------------------
最后分开来写了，更直观一点，已经开始不带脑子做题了
string isBalanced(string s) {
    stack<char> st;
    for(auto c:s){
        if(c=='(' || c=='[' || c=='{') st.push(c);
        else{
            if(c==')' && (st.empty()||st.top()!='(')) return "NO";
            else if(c==']' && (st.empty()||st.top()!='[')) return "NO";
            else if(c=='}' && (st.empty()||st.top()!='{')) return "NO";
            else st.pop();
        }
    }

    if(st.empty()) return "YES";
    else return "NO";
}
