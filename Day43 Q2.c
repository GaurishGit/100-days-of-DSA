void traverse(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    traverse(root->left, result, index);
    result[(*index)++] = root->val;
    traverse(root->right, result, index);
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int index = 0;
    traverse(root, result, &index);
    return result;
}