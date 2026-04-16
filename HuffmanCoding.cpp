#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

// Find two minimum nodes
void findTwoMin(Node* arr[], int n, int &min1, int &min2) {
    min1 = -1;
    min2 = -1;

    for (int i = 0; i < n; i++) {
        if (min1 == -1 || arr[i]->freq < arr[min1]->freq) {
            min2 = min1;
            min1 = i;
        }
        else if (min2 == -1 || arr[i]->freq < arr[min2]->freq) {
            min2 = i;
        }
    }
}

// Build Huffman Tree
Node* buildHuffman(Node* arr[], int n) {
    while (n > 1) {
        int min1, min2;
        findTwoMin(arr, n, min1, min2);

        Node* left = arr[min1];
        Node* right = arr[min2];

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        arr[min1] = newNode;

        // remove min2
        for (int i = min2; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;
    }

    return arr[0];
}

// Print Huffman Codes
void printCodes(Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        cout << root->data << " : ";
        for (int i = 0; i < top; i++)
            cout << code[i];
        cout << endl;
    }
}

// Main
int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char ch[50];
    int freq[50];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch[i];
    }

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    Node* arr[50];

    for (int i = 0; i < n; i++) {
        arr[i] = new Node(ch[i], freq[i]);
    }

    Node* root = buildHuffman(arr, n);

    int code[100];
    cout << "\nHuffman Codes:\n";
    printCodes(root, code, 0);

    return 0;
}
