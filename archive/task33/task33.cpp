class Solution
{
private:
    void fill(stack<char> &st, const string &s)
    {
        for (const char c : s)
        {
            if (!st.empty() && c == '#')
            {
                st.pop();
            }
            else if (c != '#')
            {
                st.push(c);
            }
        }
    }

public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st1;
        stack<char> st2;

        fill(st1, s);
        fill(st2, t);

        while (!st1.empty() && !st2.empty())
        {
            if (st1.top() != st2.top())
            {
                return false;
            }
            st1.pop();
            st2.pop();
        }

        return st1.size() == st2.size();
    }
};

// Time complexity: O(n + m), n = len(s), m = len(t)
// Space complexity: O(n + m), n = len(s), m = len(t)