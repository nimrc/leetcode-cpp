//
// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int size = nums.size();

        if (size < 2)
            return 0;

        for (int i = 1; i < size; ++i) {
            if (nums[i] < nums[i - 1])
                return i - 1;
        }

        return size - 1;
    }

    int findPeakElement2(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = mid1 + 1;

            if (nums[mid1] > nums[mid2])
                high = mid1;
            else
                low = mid2;
        }
        return low;
    }
};

int main(int argc, char **argv)
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    int res = (new Solution)->findPeakElement(nums);
    assert_equal(res, 1);

    int res2 = (new Solution)->findPeakElement2(nums);
    assert_equal(res2, 5);

    return 0;
}
