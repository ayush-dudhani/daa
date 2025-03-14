#include <bits/stdc++.h>
using namespace std;
#define N 4

struct Node{
    Node* parent;
    int cost;
    int costpath;
    int studentID;
    int clubID;
    bool assigned[N];   // for clubs whether they are assigned or not
};

struct comp
{
    bool operator()(Node *a, Node *b){
        return a->cost > b->cost;
    }
};

Node* newNode (int stdid, int clubid, bool assigned[], Node *parent){
    Node* temp = new Node;
    for (int i = 0; i <N; i++){
        temp->assigned[i] = assigned[i];
    }
    temp->assigned[clubid] = true;
    temp->parent = parent;
    temp->studentID = stdid;
    temp->clubID = clubid;
}

int calculateCost(int costMat[N][N], int cur_studid, int cur_clubid, bool assigned[]){
    int cost = 0;
    bool available[N] ={true};

    for( int i= cur_studid+1; i<N ; i++){
        int min= INT_MAX; 
        int minIndex = -1;
        for(int j=0; j<N; j++){
            if(!assigned[j] && costMat[i][j] < min && available[j]){
                minIndex = j;
                min = costMat[i][j];
            }
        }
        cost = cost + min;
        available[minIndex] = false;
    }
    return cost;


}

void printStudents(Node *print){
    if(print->parent == NULL){
        return;
    }
    printStudents(print->parent);
    cout << "Student : " << char(print->studentID + 'A') << " was assigned to club : " << print->clubID << endl; 
}
int findCost(int costMat[N][N]){
    priority_queue<Node *, vector<Node*>, comp> pq;
    bool assigned[N] = {false};
    Node *root = newNode(-1, -1, assigned, NULL);  // dummmy root node
    root->cost = root->costpath = 0;
    pq.push(root);

    while (!pq.empty()) {
    {
        Node *min = pq.top();
        pq.pop();
        int cur_studid = min->studentID + 1;   // -1 tha ab 0 ho jaayega

    if (cur_studid == N){
        printStudents(min);
        return min->cost;   
    }

        for(int j=0; j<N; j++){
            if (!min->assigned[j])   // if not assigned to a student 
            {
                Node *child = newNode(cur_studid, j, min->assigned, min);
                child->costpath = min->costpath + costMat[cur_studid][j];

                child->cost = child->costpath + calculateCost(costMat, cur_studid, j, child->assigned);
                pq.push(child);
            }
            
        }
    }
    
    }
}

int main(){
      int costMat[N][N] =
        {
            {9, 2, 7, 8},
            {6, 4, 3, 7},
            {5, 8, 1, 8},
            {7, 6, 9, 4}};

    cout << " Optimal Cost: " << findCost(costMat) << endl;
}