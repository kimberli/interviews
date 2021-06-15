/*Given a string A containing just the characters ’(‘ and ’)’.

Find the length of the longest valid (well-formed) parentheses substring.*/
int Solution::longestValidParentheses(string A) {
    stack<int>s;
    int maxlen=0;
    s.push(-1);
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')
        {
            s.push(i);
        }
        else
        {
            s.pop();
            if(s.empty()) s.push(i);
            else 
            {
                maxlen=max(maxlen,i-s.top());
            }
        }

    }
    return maxlen;
}
