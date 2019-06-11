//
// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
//

#include <leetcode.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> stack;
        unordered_map<char, char> tab = {{')', '('}, {']', '['}, {'}', '{'}};
        bool res = true;

        for (char &c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push_back(c);
            } else {
                if (stack.empty()) {
                    res = false;
                } else {
                    res = (stack.back() == tab[c]);
                    stack.pop_back();
                }
            }

            if (!res)
                break;
        }

        if (!stack.empty())
            res = false;

        return res;
    }
};

int main(int argc, char **argv)
{
    string s = "()[]{}";

    bool res = (new Solution)->isValid(s);

    assert_true(res);

    return 0;
}

