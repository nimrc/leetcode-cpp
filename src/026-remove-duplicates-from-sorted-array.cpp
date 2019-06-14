//
// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        int k = 0, i = 1, tmp = nums[0];

        for (; i < nums.size(); ++i) {
            if (nums[i] != tmp) {
                tmp = nums[i];
                nums[i - k] = tmp;
            } else {
                k++;
            }
        }
        return i - k;
    }
};

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    dump(nums);

    int res = (new Solution)->removeDuplicates(nums);

    assert_equal(res, 5);

    dump(nums);

    return 0;
}

