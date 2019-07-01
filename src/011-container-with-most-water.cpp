//
// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0, low = 0, high = height.size() - 1;

        while(low < high) {
            if (height[low] < height[high]) {
                res = max(res, height[low] * (high - low));
                low++;
            } else {
                res = max(res, height[high] * (high - low));
                high--;
            }
        }

        return res;
    }
};

int main(int argc, char **argv)
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int res = (new Solution)->maxArea(height);

    assert_equal(res, 49);
}
