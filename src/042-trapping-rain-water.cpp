//
// https://leetcode.com/problems/trapping-rain-water/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> leftMax(height.size()), rightMax(height.size());
        int m = 0, v = 0;

        for (int i = 0; i < height.size(); ++i) {
            m = max(m, height[i]);
            leftMax[i] = m;
        }

        m = 0;

        for (int i = height.size() - 1; i >= 0; --i) {
            m = max(m, height[i]);
            rightMax[i] = m;
        }

        for (int i = 0; i < height.size(); ++i) {
            v += (min(leftMax[i], rightMax[i]) - height[i]);
        }

        return v;
    }
};

int main(int argc, char **argv)
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int res = (new Solution)->trap(height);

    cout << res << endl;
    assert(res == 6);

    return 0;
}


