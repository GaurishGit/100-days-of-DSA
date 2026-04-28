/*
Problem Statement:
You are given the root of a binary tree. You can place cameras on nodes such that each camera monitors its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Approach:
Use DFS and classify each node into 3 states:
0 -> Not covered
1 -> Has camera
2 -> Covered
*/

int cameras;

int dfs(struct TreeNode* root) {
    if (root == NULL) return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1) {
        return 2;
    }

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 0) cameras++;
    return cameras;
}