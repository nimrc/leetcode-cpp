#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;

        int left = 0, ans = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (map[s[i]])
                left = left > map[s[i]] ? left : map[s[i]];

            ans = ans > (i - left + 1) ? ans : (i - left + 1);
            map[s[i]] = i + 1;
        }

        return ans;
    }
};

int main(int argc, char **argv)
{
    string input = "abcabcbb";

    int res = (new Solution)->lengthOfLongestSubstring(input);

    cout << res << endl;
    assert(res == 3);

    return 0;
}
