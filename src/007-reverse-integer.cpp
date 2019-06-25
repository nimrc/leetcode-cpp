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

        int tmp;
        long res = 0;

        while (x != 0) {
            tmp = x % 10;
            x /= 10;

            res *= 10;
            res += tmp;
        }

        if (res > INT_MAX || res < INT_MIN)
            return 0;

        return res;
    }
};

int main(int argc, char **argv)
{
    int res = (new Solution)->reverse(123);

    assert_equal(res, 321);

    std::cout << (new Solution)->reverse(1534236469) << std::endl;

    return 0;
}