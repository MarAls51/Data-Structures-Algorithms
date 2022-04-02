#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <list>

using namespace std;

// creating stack using linked list
// ---------------------------------------------------------------------------------
class Node {
public:
    int data;
    Node* nextPtr = NULL;
};


Node* head = NULL;

void insert(int num) {
    if (head == NULL)
    {
        Node* ptr = new Node();
        head = ptr;
        ptr->data = num;
    }
    else
    {
        Node* ptr = new Node();
        ptr->data = num;
        ptr->nextPtr = head;
        head = ptr;
    }
}
void deleteTop()
{
    Node* temp = new Node;
    temp = head;
    head = head->nextPtr;
    delete(temp);
}

void prints() {
    Node* temp = new Node;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->nextPtr;
    }
    delete(temp);
}

// creating stack using array
// ---------------------------------------------------------------------------------
class stack {

public:
    int array[5];
    int top = -1;
    void push(int num) {
        top++;
        array[top] = num;
        cout << num << " pushed onto the stack" << endl;
    }
    void pop()
    {
        if (top == 0) {
            cout << "The stack is empty";
        }
        else
        {
            array[top] = 0;
            top--;
        }
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << endl;
        }
    }
};

// create queue using linked list
// ---------------------------------------------------------------------------------
class QNode {
public:
    int data;
    QNode* next;
};

QNode* front = NULL;
QNode* back = NULL;

void enQueue(int number)
{
    if (front == NULL && back == NULL)
    {
        QNode* ptr = new QNode;
        ptr->data = number;
        front = ptr;
        back = ptr;
    }
    else
    {
        QNode* ptr = new QNode;
        ptr->data = number;
        back->next = ptr;
        back = ptr;
    }
}

void deQueue() {
    if (front->next != NULL)
    {
        QNode* temp = new QNode;
        temp = front;
        front = front->next;
        delete(temp);

    }
    else {
        cout << "the queue is empty" << endl;
    }



}

void printQueue() {
    QNode* temp = new QNode;
    temp = front;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    delete(temp);

}



// create queue using array
// ---------------------------------------------------------------------------------
class arrayQueue {
public:
    int array[5];
    int front = -1;
    int rear = -1;
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int num) {
        // insert int the rear
        if (isEmpty() == true)
        {
            front = 0;
            rear = 0;
            array[rear] = num;
        }
        else if (rear == 4)
        {
            cout << "the queue is full" << endl;
        }
        else
        {
            rear++;
            array[rear] = num;
        }
    }
    void dequeue() {
        // pop from the front
        if (front != 4)
        {
            front += 1;
        }
    }

    void printQueue() {
        int temp = front;
        for (temp; temp <= rear; temp++) {
            cout << array[temp] << endl;
        }
    }
};



// create bst using linked list
// ---------------------------------------------------------------------------------
class treeNode {
public:
    int data;
    treeNode* left;
    treeNode* right;
};

class tree {

public:
    // insert O(h) worst time complexity, h being the height of the subtree
    treeNode* insert(int number, treeNode* root) {
        if (root == NULL)
        {
            cout << number << " :Created root val" << endl;
            treeNode* root1 = new treeNode;
            root1->data = number;
            root1->left = root1->right = NULL;
            return root1;
        }
        else if (number <= root->data)
        {
            cout << "Called Left" << endl;
            root->left = insert(number, root->left); // <- understand this recursion 
        }
        else {
            cout << "Called Right" << endl;
            root->right = insert(number, root->right);
        }
        return root;
    }
    // search
    treeNode* search(int number, treeNode* root) {
        if (root == NULL)
        {
            cout << "There is no such number in the tree";
        }
        else if (root->data == number)
        {
            cout << root->data << " : item found" << endl;
        }
        else if (number < root->data)
        {
            cout << "left amigo" << endl;
            root->left = search(number, root->left);
        }
        else {
            cout << "right amigo" << endl;
            root->right = search(number, root->right);
        }
        return root;
    }
    // find min
    treeNode* min(treeNode* root)
    {
        treeNode* temp = new treeNode;
        temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;



    }
    // remove
    // four cases: null node, node is a leaf, node has a right subtree, node has a left subtree, both a left and right subtree
    // largest value in the left tree or the smallest value in the right tree, right leftmost, left rightmost.
    treeNode* remove(int num, treeNode* root) {
        if (root == NULL)
        {
            return root;
        }
        else if (num < root->data)
        {
            root->left = remove(num, root->left);
        }
        else if (num > root->data)
        {
            root->right = remove(num, root->right);
        }
        else {
            if (root->left == NULL && root->right == NULL)
            {
                delete(root);
                root = NULL;
                return root;
            }
            else if (root->left == NULL)
            {
                treeNode* temp = new treeNode;
                temp = root;
                root = root->right;
                delete(temp);
                return root;
            }
            else if (root->right == NULL)
            {
                treeNode* temp = new treeNode;
                temp = root;
                root = root->left;
                delete(temp);
                return root;
            }
            else {
                treeNode* temp = new treeNode;
                temp = min(root->right);
                root->data = temp->data;
                root->right = remove(temp->data, root->right);
                return root;
            }
        }
    }

    // dfs
    void dfs(treeNode* root) // stack implementation 3/19/22
    {

    }

    // bfs
    void bfs() { // queue implementation 3/19/22

    }

    // preorder
    void preorder(treeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }

    // postorder
    void postorder(treeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
    }

    // inorder
    void inorder(treeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
    // root node;
};


// ---------------------------------------------------------------------------------

// creating binary tree 3/19/22

class binaryNode {
public:
    int data;
    binaryNode* left;
    binaryNode* right;
};

/*
class binaryTree {
public:
    // insert
    // inserting into a binary search tree
        // delete
    /*
    void insert(binaryNode* root) {
        queue <binaryNode*> myQ;
        myQ.push(root);
        while (!myQ.empty())
        {
            binaryNode* node = myQ.front();
            myQ.pop();
           if (node->left == NULL)
           {
               binaryNode* j = new binaryNode;
                   j->data = 5;
                   j->left = NULL;
                   j->right = NULL;
                   node->left = j;
                   break;
           }
           if (node->right == NULL)
           {
               binaryNode* j = new binaryNode;
               j->data = 5;
               j->left = NULL;
               j->right = NULL;
               node->right = j;
               break;
           }
           myQ.push(node->left);
           myQ.push(node->right);
    }
    */


    /* function to delete the given deepest node
(d_node) in binary tree */
/*void deletDeepest(struct Node* root,
    struct Node* d_node)
{
    queue<struct Node*> q;
    q.push(root);
    // Do level order traversal until last node
    struct Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
/* function to delete element in binary tree */
/*
Node* deletion(struct Node* root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->key == key)
            return NULL;
        else
            return root;
    }
    queue<struct Node*> q;
    q.push(root);
    struct Node* temp;
    struct Node* key_node = NULL;
    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->key == key)
            key_node = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    if (key_node != NULL) {
        int x = temp->key;
        deletDeepest(root, temp);
        key_node->key = x;
    }
    return root;
}
}
// search BFS OR DFS
};
*/
// createing heap using linked list max-heapify,min-heapify 3/19/22

// creating graph using c++ 3/19/22
class graph {
public:
    map<int, list<int>> l;

    graph(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(int src)
    {
        map<int, bool> traversed;
        queue<int> myQ;
        myQ.push(src);
        while (!myQ.empty())
        {
            int node = myQ.front();
            myQ.pop();
            for (auto i : l[node])
            {
                if (!traversed[i])
                {
                    myQ.push(i);
                    traversed[i] = true;
                }
            }



        }
    }
    void dfsHelper(int src, map <int, bool> traversed) {

        traversed[src] = true;
        for (int i : l[src])
        {
            if (traversed[i] != true)
            {
                dfsHelper(i, traversed);
            }
        }
    }

    void dfs(int src) {
        map <int, bool> traversed;
        for (auto i : l)
        {
            int node = i.first;
            traversed[node] = false;
        }
        dfsHelper(src, traversed);
    }
};

// ---------------------------------------------------------------------------------

// map, unordered map 3/19/22 map is RBT unordered is hashing

// unordered map is an assoviative container that contains key-value pairs with unique keys.
// search, insertion, and removal have average constant-time complexity
// internally, the elements are organized into buckets.
// it uses hashing to insert elements into buckets.
// this allows fast access to individual elements, because after computing the hash of the value it refers to
// the exact bucket the element is placed into

// maintain a collection of unique {key:value} pairs with fast insertion and removal
//unordered_map<int, char> umap = { {1,'a'},{2,'b'} };

// Use std::unordered_map when 
/*
You need to keep count of some data(Example  strings) and no ordering is required.
You need single element access i.e.no traversal.
*/

// Access
// cout << umap[1] << endl;
// cout << umap[2] << endl;

// Update
// umap[1] = 'C'

// Iterate 
// for(auto& elm:ump)
// {
//  cout << elm.first << " : " << elm.second << endl;
//
//
// }

// Find
// auto result = umap.find(2)
// if(result != umap.end)
//{
// cout << umap.second << endl;
// }           
//else{ cout << "Item not found" << endl; }

// map
// unique value pairs only
// implemented using self-balanced binary search tree, red black tree.

// map.insert(make_pair("Bot",782348818));
// generally used in dictionary type problems

//Use std::map when 
/*
You need ordered data.
You would have to print / access the data(in sorted order).
You need predecessor / successor of elements.
*/

// ---------------------------------------------------------------------------------

// MIN,MAX,FIND() 3/19/22
// sort(someArray)
// int temp = max(val1,val2);
/*
auto it = find(InputIterator first, InputIterator last, const T& val)
{
    while (!array.end()) {
        if (*first == val) return first;
        ++first;
    }
*/


// ---------------------------------------------------------------------------------

// parenthesis, stack works best.

// palindrome
// Function that returns true
// if string is a palindrome
/*
bool isPalindrome(string s)
{
    int length = s.size();
    // Creating a Stack
    stack <char> st;
    // Finding the mid
    int i, mid = length / 2;
    for (i = 0; i < mid; i++) {
        st.push(s[i]);
    }
    // Checking if the length of the string
    // is odd, if odd then neglect the
    // middle character
    if (length % 2 != 0) {
        i++;
    }
    char ele;
    // While not the end of the string
    while (s[i] != '\0')
    {
        ele = st.top();
        st.pop();
        // If the characters differ then the
        // given string is not a palindrome
        if (ele != s[i])
            return false;
        i++;
    }
    return true;
}
*/

// swap(val1, val 2)

// ---------------------------------------------------------------------------------

// build maxheap tree

// priority queue 
class maxheap {
    //insert

    //heapify

    //delete
};

// max-heap cost is O(logn)
// full tree heapify cost O(nlogn)
// removing the root of a tree means replacing it with the right most node.
// heap tree is compelte.

class arrayHeap {
    // parent -> (index-2)/2
    // leftNode -> ( index*2 ) + 1
    // rightNode -> ( index*2 ) + 2

};
// invert a binary search tree

// suffix tree/ tries

/*  // partition algorithms
// quicksort
// mergesort
// bubble sort
// binary search, recursion.
*/

// sliding window

// matrices

// dynamic programming practice, god have mercy on my soul.

int main()
{
    treeNode* root = new treeNode;
    root = NULL;
    tree BST;
    root = BST.insert(5, root);
    BST.insert(10, root);
    BST.insert(12, root);
    BST.insert(18, root);
    BST.insert(3, root);
    BST.insert(2, root);
    cout << "-------------------------------" << endl;
    BST.remove(5, root);
    BST.inorder(root);
    cout << "-------------------------------" << endl;
    BST.preorder(root);
    cout << "-------------------------------" << endl;
    BST.postorder(root);
    return 0;
}
