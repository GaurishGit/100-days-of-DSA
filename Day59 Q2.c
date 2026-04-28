/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* build(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postEnd];

    int rootIndex = inStart;
    while (inorder[rootIndex] != root->val) {
        rootIndex++;
    }

    int leftSize = rootIndex - inStart;

    root->left = build(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSize - 1);
    root->right = build(inorder, rootIndex + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return build(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}