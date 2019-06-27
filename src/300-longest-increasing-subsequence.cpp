//
// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();

        if (size == 0)
            return 0;

        int res = 0;

        for (int i = 0; i < size; ++i) {
            auto it = lower_bound(nums.begin(), nums.begin() + res + 1, nums[i]);

            *it = nums[i];

            res = max(res, (int) (it - nums.begin()));
        }

        return res + 1;
    }
};

int main(int argc, char **argv)
{
    vector<int> input = {10, 9, 2, 5, 3, 7, 101, 18};

    int res = (new Solution)->lengthOfLIS(input);

    assert_equal(res, 4);

    return 0;
}