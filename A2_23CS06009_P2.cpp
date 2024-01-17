#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    vector<int>v(5,1);

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<5;j++)
        {
            v[j]=v[j]+v[j-1];
        }
    }
    cout<<v[4]<<endl;
}