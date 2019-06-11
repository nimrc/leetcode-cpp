//
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums3 = {};
        nums3.insert(nums3.end(), nums1.begin(), nums1.end());
        nums3.insert(nums3.end(), nums2.begin(), nums2.end());

        sort(nums3.begin(), nums3.end());

        if (nums3.size() % 2 == 1)
            return nums3[nums3.size() / 2];
        else
            return (nums3[nums3.size() / 2 - 1] + nums3[nums3.size() / 2]) / 2.0;
    }
};

int main(int argc, char **argv)
{
    vector<int> num1 = {1, 2}, num2 = {3, 4};

    double res = (new Solution)->findMedianSortedArrays(num1, num2);

    assert(res == 2.5);

    return 0;
}
