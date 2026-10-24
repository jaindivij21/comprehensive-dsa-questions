// Leetcode: Number of Ways to Assign Edge Weights I
// https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *buildTree(unordered_map<int, vector<int>> &edgeMap) {
        int rootVal = edgeMap.begin()->first;

        TreeNode *root = new TreeNode(rootVal);

        unordered_set<int> visited;
        visited.insert(rootVal);

        queue<pair<TreeNode *, int>> q;
        q.push({root, rootVal});

        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();

            int childCount = 0;

            for (int nei : edgeMap[val]) {
                if (visited.count(nei)) continue;

                visited.insert(nei);

                TreeNode *child = new TreeNode(nei);

                if (childCount == 0)
                    node->left = child;
                else if (childCount == 1)
                    node->right = child;

                childCount++;

                q.push({child, nei});
            }
        }

        return root;
    }

    int calDepthOfTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(calDepthOfTree(root->left), calDepthOfTree(root->right));
    }

    int assignEdgeWeights(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> edgeMap;
        for (auto edge : edges) {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }

        TreeNode *root = buildTree(edgeMap);
        int depth = calDepthOfTree(root);
        return pow(2, depth - 2);
    }
};

int main() {
    Solution solution;
    int n = 7;
    vector<vector<int>> edges = {{1, 2}};

    cout << solution.assignEdgeWeights(edges) << endl;

    return 0;
}
