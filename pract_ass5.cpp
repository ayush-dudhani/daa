#include <bits/stdc++.h>
using namespace std;
#define n 8

void printsol(int sol[n][n]){
    for (int i = 0; i <n; i++){
        for (int j = 0; j < n; j++)
        {
            cout<< sol[i][j]<< " ";
        }
    }
    cout<<endl;
}

void solve (int sol[n][n], int x, int y, int mov){
    if(x<0 || y<0 || x>=n || y>=n || sol[x][y]!=-1){
        return;
    }

    if(mov == n*n){
        sol[x][y] = mov;
        printsol(sol);
        return;
    }
    sol[x][y] =mov;
    solve(sol, x+2, y-1, mov+1);
    solve(sol, x+2, y+1, mov+1);
    solve(sol, x-2, y-1, mov+1);
    solve(sol, x-2, y+1, mov+1);
    solve(sol, x+1, y+2, mov+1);
    solve(sol, x+1, y-2, mov+1);
    solve(sol, x-1, y+2, mov+1);
    solve(sol, x-1, y-2, mov+1);

    sol[x][y] = -1;
}

int main(){
    int sol[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) 
            sol[i][j] =-1;
    }

    solve(sol, 0,0,1);
}