void traverse(struct TreeNode* root, int* returnSize, int* result) {
    if (root == NULL) return;
    result[(*returnSize)++] = root->val;
    traverse(root->left, returnSize, result);
    traverse(root->right, returnSize, result);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    traverse(root, returnSize, result);
    return result;
}