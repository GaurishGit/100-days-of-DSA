int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int* result = (int*)malloc(1000 * sizeof(int));
    int index = 0;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            if (i == size - 1) {
                result[index++] = node->val;
            }

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }
    }

    *returnSize = index;
    return result;
}