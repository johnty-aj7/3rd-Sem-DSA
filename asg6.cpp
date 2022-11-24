/*
NAME - Aaryan Abbot 
SID - 21105034
BRANCH - ECE
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
// CREATING A BINARY TREE CLASS
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

// sorted array to binary search tree
BinaryTreeNode<int> *createBST(int arr[], int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);

    root->left = createBST(arr, si, mid - 1);
    root->right = createBST(arr, mid + 1, ei);
    return root;
}

// CHECK BST

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL) // EMPTY SET
    {
        return INT32_MAX; // agar koi set khali hai to sbse chota number int max hi ho skta.
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT32_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}


BinaryTreeNode<int>* minValueNode(BinaryTreeNode<int>* node)
{
    BinaryTreeNode<int>* current = node;
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}

BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            BinaryTreeNode<int> *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BinaryTreeNode<int> *temp = root->left;
            free(root);
            return temp;
        }
        BinaryTreeNode<int> *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

    int main()
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n); // sort the array.
        BinaryTreeNode<int> *root = createBST(arr, 0, n - 1);
        cout << isBST(root) << endl;

        int data;
        cin >> data;
        root = deleteNode(root,data);//new node after deletion;
    }
