#include <bits/stdc++.h>
using namespace std;
typedef struct BTree{
    char val;
    struct BTree *lchild;
    struct BTree *rchild;
}Node,*Tree;
Tree preBuild(string &s){
    Tree root = new Node;
    if (s[0]=='#') return NULL;
    root->val=s[0];
    s=s.substr(1,s.length()-1);
    root->lchild=preBuild(s);
    s=s.substr(1,s.length()-1);
    root->rchild=preBuild(s);
    return root;
}
void preprint(Tree root){
    if (root == NULL) return;
    cout<<root->val<<" ";
    preprint(root->lchild);
    preprint(root->rchild);
}
void inprint(Tree root){
    if (root == NULL) return;
    inprint(root->lchild);
    cout<<root->val<<" ";
    inprint(root->rchild);
}
void postprint(Tree root){
    if (root == NULL) return;
    postprint(root->lchild);
    postprint(root->rchild);
    cout<<root->val<<" ";
}
void preorder(Tree root){
    stack<Tree> q;
    while(root!=NULL || !q.empty()){
        while (root!=NULL){
            cout<<root->val<<" ";
            q.push(root);
            root=root->lchild;
        }
        if (!q.empty()){
            root=q.top();
            q.pop();
            root=root->rchild;
        }
    }
}
void level(Tree root){
    queue<Tree> q;
    if (root == NULL) return;
    q.push(root);
    while(!q.empty()){
        Tree n=q.front();
        cout<<n->val<<" ";
        (n->lchild!=NULL)&&(q.push(n->lchild),1);
        (n->rchild!=NULL)&&(q.push(n->rchild),1);
        q.pop();
    }
}
int main(){
    string s;
    cin>>s;
    Tree root=preBuild(s);
    
    return 0;
}