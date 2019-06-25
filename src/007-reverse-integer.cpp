//
// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/
//
#include <leetcode.h>

class Solution
{
public:
    int reverse(int x)
    {
        long res = 0;

        while (x != 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }

        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
};

int main(int argc, char **argv)
{
    int res = (new Solution)->reverse(123);

    assert_equal(res, 321);

    return 0;
}