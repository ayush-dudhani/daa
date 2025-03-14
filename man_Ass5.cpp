#include<bits/stdc++.h>
using namespace std;


int solve(int x,int y,vector<vector<int>>a,vector<pair<int,int>>moves,int n,int cnt)
{
	int nx,ny;
			if(cnt==n*n)return 1;
		for(auto v:moves)
			{
				nx=x+v.first;
				ny=y+v.second;
					if(nx>=0 && nx<n && ny <n && ny>=0 && a[nx][ny]==-1)
						{
								a[nx][ny]=cnt+1;
							if(solve(nx,ny,a,moves,n,cnt+1)==1)
								return 1;
							else
							{
								a[nx][ny]=-1;
							}
						}
					
			}

return 0;
}
int main()
{
int n;
cin>>n;
vector<vector<int>>a(n,vector<int>(n,-1));
vector<pair<int,int>>moves={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int cnt=0;
if(solve(0,0,a,moves,n,cnt)==0)
{
	cout<<"Impossible!!\n";
	}
else
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		 	cout<<endl;
	}
}




return 0;
}