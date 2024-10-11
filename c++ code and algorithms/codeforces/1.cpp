#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
int n;
cin>>n;
vector<vector<int>>vec(n,vector<int>(n,1));
ll moves=0;
int k=(n/2);
vector<vector<int>>visited(n,vector<int>(n,0));
int dx[]={0,0,-1,1,-1,-1,1,1};
int dy[]={-1,1,0,0,-1,1,-1,1};
vector<vector<ll>>distance(n,vector<ll>(n,1000));


priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>>pq;
pq.push({0,{k,k}});
while(!pq.empty())
{
    //cout<<"enter"<<endl;
    auto it=pq.top();
    ll dist=it.first;
    int xco=it.second.first;
    int yco=it.second.second;
    //cout<<dist<<" "<<xco<<" "<<yco<<endl;
    pq.pop();
    visited[xco][yco]=1;
    moves+=dist;
    for(int i=0;i<8;i++)
    {
        if((i==0 && yco==0) ||
           (i==1 && yco==n-1) ||
           (i==2 && xco==0) ||
           (i==3 && xco==n-1)||
           ((i==4 || i==5) && xco==0) ||
           ((i==6 || i==7) && xco==n-1) ||
           ((i==4 ||i==6) && yco==0) ||
           ((i==5 || i==7) && yco==n-1))
            continue;
        int nxco=xco+dx[i];
        int nyco=yco+dy[i];

        if(visited[nxco][nyco]==0 && distance[nxco][nyco]>dist+1)
        {
            distance[nxco][nyco]=dist+1;
            pq.push({dist+1,{nxco,nyco}});

        }



    }

}
cout<<moves<<endl;



}
}
