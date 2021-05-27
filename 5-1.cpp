#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct ENode{
    int adjvex;
    int weight;
    ENode* next;
};

struct Triple{
    int src,dest,weight;
};

typedef struct VNode{
    int vertex;
    ENode* firstarc;
}AdjList;

struct Cmp
{
    inline bool operator()(const Triple &x, const Triple &y)
    {
        return x.weight > y.weight;
    }
};

class ALGraph{
private:
    vector<AdjList> adjList;
    int vexNum;
    int edgNum;
    int sum;
    vector<int> parent;
    vector<Triple> edge;
    vector<bool> visited;

public:
    void CreateFromMatrix(vector<vector<int> > &a, int n, int m);
    void CreateGraph();
    void PrintGraph();
    void DFS(int v);
    void BFS();
    int Kruskal();
};

void ALGraph::CreateFromMatrix(vector<vector<int> > &a, int n, int m){
    int cnt=0;
    this->edgNum = m;
    this->vexNum = n;
    this->adjList.resize(this->vexNum);
    this->visited.resize(this->vexNum);
    this->edge.resize(this->edgNum);
    for (int i=0;i<this->vexNum;i++){
        this->adjList[i].vertex = i;
        this->adjList[i].firstarc = NULL;
    }
    cout<<a.size()<<" "<<a[0].size()<<endl;
    for (int i=0;i<a.size();i++){
        for (int j=i+1;j<a[i].size();j++){
            if (a[i][j]>0){
                ENode* temp = new ENode();
                temp->weight = a[i][j];
                temp->adjvex = j;
                temp->next = this->adjList[i].firstarc;
                this->adjList[i].firstarc = temp;
                temp = new ENode();
                temp->weight = a[i][j];
                temp->adjvex = i;
                temp->next = this->adjList[j].firstarc;
                this->adjList[j].firstarc = temp;
                Triple* edg = new Triple();
                edg->weight = a[i][j];
                edg->src = i;
                edg->dest = j;
                this->edge[cnt++]=*edg;
            }
        }
    }
}

void ALGraph::CreateGraph()
{
    cout << "Input the number of vertex:" << endl;
    cin >> this->vexNum;
    this->adjList.resize(this->vexNum);
    this->visited.resize(this->vexNum);
    cout << "Input the number of edgNum:" << endl;
    cin >> this->edgNum;
    this->edge.resize(this->edgNum);
    for (int i = 0; i<this->vexNum; i++){
        this->adjList[i].vertex = i;
        this->adjList[i].firstarc = NULL;
    }
    cout << "Input " << this->edgNum << " edge's info:" << endl;
    int cnt=0;
    for (int i = 0; i<this->edgNum; i++){
        int src, dest, weight;
        cin >> src >> dest >> weight;
        ENode* temp = new ENode();
        temp->weight = weight;
        temp->adjvex = dest;
        temp->next = this->adjList[src].firstarc;
        this->adjList[src].firstarc = temp;
        temp = new ENode();
        temp->weight = weight;
        temp->adjvex = src;
        temp->next = this->adjList[dest].firstarc;
        this->adjList[dest].firstarc = temp;
        Triple* edg = new Triple();
        edg->weight = weight;
        edg->src = src;
        edg->dest = dest;
        this->edge[cnt++]=*edg;
    }
}
void ALGraph::BFS()
{
    for(int i=0;i<this->vexNum;i++)
        this->visited[i] = false;
    queue<int> q;
    cout<<this->adjList[0].vertex<<" ";
    this->visited[this->adjList[0].vertex]=true;
    q.push(this->adjList[0].vertex);
    while(!q.empty()){
        for (ENode *e = this->adjList[q.front()].firstarc;e!=NULL;e=e->next){
            if (!this->visited[e->adjvex]){
                this->visited[e->adjvex] = true;
                cout<<e->adjvex<<" ";
                q.push(e->adjvex);
            }
        }
        q.pop();
    }
    cout<<endl;
    for(int i=0;i<this->vexNum;i++)
        this->visited[i] = false;
}
void ALGraph::DFS(int v)
{
    this->visited[v] = true;
    cout << this->adjList[v].vertex << " ";
    ENode* p = this->adjList[v].firstarc;
    while (p){
        if (!this->visited[p->adjvex])
            DFS(p->adjvex);
        p = p->next;
    }
    return;
}
int ALGraph::Kruskal(){
    this->sum = 0;
    make_heap(edge.begin(),edge.end(),Cmp());
    this->parent.resize(this->vexNum);
    for (int i=0;i < this->vexNum; i++)
        this->parent[i]=i;
    while(!edge.empty()){
        Triple tmp = edge.front();
        if (parent[tmp.src]!=parent[tmp.dest]){
            this->sum += tmp.weight;
            cout << tmp.src << tmp.dest << tmp.weight;
            parent[tmp.src] < parent[tmp.dest] ? parent[tmp.dest] = parent[tmp.src] : parent[tmp.src] = parent[tmp.dest];
        }
        pop_heap(edge.begin(),edge.end(),Cmp());
        edge.pop_back();
    }
    cout<<"Total cost:"<<this->sum;
    return this->sum;
}
void CreateByMatrix(vector<vector<int> > &matrix,int &vexNum,int &edgNum){
    cout<<"Input the info of edge:"<<endl;
    for (int i=0;i<edgNum;i++){
        int src,dest, weight;
        cin >> src >> dest >> weight;
        matrix[src][dest] = weight;
        matrix[dest][src] = weight;
    }
    for (int i=0;i<matrix.size();i++){
        for (int j=0;j<matrix[i].size();j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    int k;
    ALGraph *list = new ALGraph();
    vector<vector<int> > ma;
    while(true){
        cout<<"1.Store by AdjMatrix\n";
        cout<<"2.Store by AdjList(output the result of bfs and dfs)\n";
        cout<<"3.Urban transportation network planning（Kruskal)\n";
        cin>>k;
        switch (k)
        {
            case 1:
                int vexNum,edgNum;
                cout<<"Input the number of vertex and edge:"<<endl;
                cin>>vexNum>>edgNum; 
                ma.resize(vexNum,vector<int>(vexNum, 0));
                CreateByMatrix(ma,vexNum, edgNum);
                list->CreateFromMatrix(ma,vexNum,edgNum);
                break;
            case 2:
                int root;
                list->CreateGraph();
                list->BFS();
                cout<<"Input the number which search begin:\n";
                cin>>root;
                list->DFS(root);
                cout<<endl;
                break;
            case 3:
                list->Kruskal();
                break;
            case 0:
                return 0;
            default:
                break;
        }
    }

}