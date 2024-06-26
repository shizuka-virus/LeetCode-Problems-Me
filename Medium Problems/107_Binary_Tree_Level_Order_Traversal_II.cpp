/*
107. Binary Tree Level Order Traversal II
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>>v;
    queue<TreeNode*>q;

    if(root==NULL)
    {
        return v;
    }
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        //inner list to store curr lvl of elements
        vector<int>in;

        //Doing 2 steps
        for(int i=1;i<=n;i++)
        {
            //remove front after storing it
            TreeNode* temp=q.front();
            q.pop();
            in.push_back(temp->val);

            //add next lvl elements
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        v.push_back(in);
    }
    // Reverse the Whole Array
    reverse(v.begin(),v.end());
    return v;
    }
};