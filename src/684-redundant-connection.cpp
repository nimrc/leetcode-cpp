//
// 684. Redundant Connection
// https://leetcode.com/problems/redundant-connection/
//
#include <leetcode.h>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        ranks = vector<int>(n + 1, 0);
        parents = vector<int>(n + 1, 0);

        for (int i = 0; i < parents.size(); ++i)
            parents[i] = i;
    }

    bool _union(int u, int v)
    {
        int pu = _find(u);
        int pv = _find(v);

        if (pu == pv)
            return false;

        if (ranks[pu] > ranks[pv])
            parents[pv] = pu;
        else if (ranks[pv] > ranks[pu])
            parents[pu] = pv;
        else {
            parents[pv] = pu;
            ranks[pv]++;
        }

        return true;
    }

    int _find(int u)
    {
        if (u != parents[u])
            parents[u] = _find(parents[u]);
        return parents[u];
    }

private:
    vector<int> parents;
    vector<int> ranks;
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        UnionFind uf(edges.size() + 1);

        for (const auto &edge: edges) {
            if (!uf._union(edge[0], edge[1]))
                return edge;
        }

        return vector<int>{};
    }
};

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};

    auto res = (new Solution)->findRedundantConnection(edges);

    assert_equal(res, vector<int>({2, 3}));
}