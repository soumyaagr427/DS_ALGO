// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    
    //this & SIGN matters alot as because of this only
    //we are able to make changes on variable maxi
    // and then return the value;
       int maxi=INT_MIN;
    int maxpathsum(Node * root)
    {
        if(!root) return 0;
        
        //max of 0 beacuse in case both path gives -ve value
        //its better to discard both thrn take any
        int lh=maxpathsum(root->left);
        int rh=maxpathsum(root->right);
        
        if (!root->left and !root->right)
        return root->data;
        
        if (!root->left)
        return root->data + rh;
        
         if (!root->right)
        return root->data + lh;
     
        //now this will return max height for each node
        maxi=max(maxi,lh+rh+root->data);
        
        
        // this will return max sum path either to consider
        // left or right
        return max(root->data+lh,root->data+rh);
        
    }
    
    int maxPathSum(Node* root)
    {
      
        int ans= maxpathsum(root);
            if(!root->left || !root->right)
                maxi=max(ans,maxi);
         return maxi;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
