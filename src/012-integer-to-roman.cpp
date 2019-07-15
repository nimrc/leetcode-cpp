//
// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

#include <leetcode.h>

using namespace std;

class Solution
{
public:
    map<int, string> m = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };

    string intToRoman(int num)
    {
        string res = "";

        for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
            while (num >= iter->first) {
                res += iter->second;
                num -= iter->first;
            }
        }

        return res;
    }
};

int main(int argc, char **argv)
{
    assert_equal((new Solution)->intToRoman(1994), "MCMXCIV");
}
