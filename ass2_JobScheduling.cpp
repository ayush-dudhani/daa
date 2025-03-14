#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int taskid;
    int deadline;
    int profit;
};

int myfunction(Job a, Job b)
{
    return a.profit > b.profit;
}

void JobScheduling(vector<Job> v)
{
    int p = 0;
    int T=15;
    vector<int> l(T,-1);

    // 
    sort(v.begin(), v.end(), myfunction);
    for(Job x : v){
        cout << x.profit <<" "<< x.taskid <<" " <<x.deadline<<endl;
    }
    for(Job j : v){
        for(int i=j.deadline-1; i>=0;i--){
            if(i<T && l[i]==-1){
                l[i] = j.taskid;
                p+=j.profit;
                break;
            }
        }
    }
    cout<< "Scheduled Jobs are :";
    for (int i = 0; i < T; i++)
    {
        if(l[i]!=-1){
            cout << l[i] << " ";
        }
    }

    cout<<"The total profit : "<< p<<endl;
    
    return;
}

int main(int argc, char const *argv[])
{
    vector <Job> jobs =
{
{1, 9, 15}, {2, 2, 2}, {3, 5, 18}, {4, 7, 1}, {5, 4, 25},
{6, 2, 20}, {7, 5, 8}, {8, 7, 10}, {9, 4, 12}, {10, 3, 5}
};
    JobScheduling(jobs);
    return 0;
}
