
#include <queue>
using namespace std;

/*
Struct TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);

        vector<double> averageForEachLevel;
        averageForEachLevel.push_back(static_cast<double> (root->val));

        while (!queue.empty()) {
            double sumCurrentLevel = 0;

            for (int i = queue.size(); i > 0; --i) {

                TreeNode* current = queue.front();
                queue.front();

                if (current->left != nullptr) {
                    sumCurrentLevel += current->left->val;
                    queue.push(current->left);
                }
                if (current->right != nullptr) {
                    sumCurrentLevel += current->right->val;
                    queue.push(current->right);
                }
            }

            if (queue.size() > 0) {
                averageForEachLevel.push_back(sumCurrentLevel / queue.size());
            }
        }
        return averageForEachLevel;
    }
};
