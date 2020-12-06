#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends





/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class solver
{
private:

public:
void go_down(Node* root,int h,vector<int> &v){
    if(!root)
    return;
    if(h==0){
        v.push_back(root->data);
        return;
    }
    go_down(root->left,h-1,v);
    go_down(root->right,h-1,v);
}
int traverse(Node* root,int x,int k,vector<int> &v){
    if(!root)
    return 0;
    if(root->data==x){
        go_down(root,k,v);
        return 1;
    }
    int l=traverse(root->left,x,k,v);
    if(l&&l<=k){
        if(l==k)
        v.push_back(root->data);
        else
        go_down(root->right,k-l-1,v);
        return l+1;
    }
    int r=traverse(root->right,x,k,v);
    if(r&&r<=k){
        if(r==k)
        v.push_back(root->data);
        else
        go_down(root->left,k-r-1,v);
        return r+1;
    }
    return 0;
}
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
       vector<int> v;
       traverse(root,target,k,v);
       sort(v.begin(),v.end());
       return v;// return the sorted vector of all nodes at k dist
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    solver x = solver();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}