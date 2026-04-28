/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QueueNode* queue = (struct QueueNode*)malloc(1000 * sizeof(struct QueueNode));
    int front = 0, rear = 0;

    int map[2000][100];
    int count[2000] = {0};

    int offset = 1000;

    queue[rear++] = (struct QueueNode){root, 0};

    while (front < rear) {
        struct QueueNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = node->data;

        if (node->left)
            queue[rear++] = (struct QueueNode){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (struct QueueNode){node->right, hd + 1};
    }

    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }

    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    free(arr);
    return 0;
}