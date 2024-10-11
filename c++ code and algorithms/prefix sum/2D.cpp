#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec(n,vector<int>(m));
    vector<vector<int>>prefix(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
            if(i==0 && j==0) prefix[i][j]=vec[i][j];
            else if(i==0 && j!=0) prefix[i][j]=prefix[i][j-1]+vec[i][j];
            else if(i!=0 && j==0) prefix[i][j]=prefix[i-1][m-1]+vec[i][j];
            else
                prefix[i][j]=prefix[i][j-1]+vec[i][j];

        }
    }
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<prefix[i][j]<<" ";

        }
        cout<<endl;
    }


}
