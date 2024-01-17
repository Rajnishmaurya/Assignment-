#include<bits/stdc++.h>
using namespace std;

vector<int> minimumheight(list<int>adj[],vector<int>&degree,int n)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(degree[i]==1)
        q.push(i);
    }
    
    while(n>2)
    {
        int s=q.size();
        n=n-s;
        for(int i=0;i<s;i++)
        {
            int temp=q.front();
            q.pop();

            for(auto x:adj[temp])
            {
                degree[x]--;
                if(degree[x]==1)
                {
                    q.push(x);
                }
            }

        }
    }
    vector<int>result;
    while(!q.empty())
    {
        result.push_back(q.front());
        q.pop();
    }
    return result;

}

void adjaceny_list(list<int>adj[],int x,int y,vector<int>&degree)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
    degree[x]++;
    degree[y]++;
}

int main()
{
    int n;
    cout<<"Enter the number of node: ";
    cin>>n;
    list<int>adj[n];
    vector<int>degree(n,0);

    cout<<"Enter the edge: "<<endl;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adjaceny_list(adj,x,y,degree);
    }
    
    vector<int>result=minimumheight(adj,degree,n);
    cout<<"Result :";
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
}