#include<bits/stdc++.h>
using namespace std;

void deleteFromMaxHeap(priority_queue<int>& maxHeap, int elementToDelete) {
    priority_queue<int> tempHeap;  // Create a temporary max heap to store elements

    // Pop elements from the original max heap and push them to the temporary heap
    while (!maxHeap.empty()) {
        int current = maxHeap.top();
        maxHeap.pop();
        if (current != elementToDelete) {
            tempHeap.push(current);
        }
    }
    // Copy elements back to the original max heap
    while (!tempHeap.empty()) {
        maxHeap.push(tempHeap.top());
        tempHeap.pop();
    }
}

int main()
{
     int n;
     cin>>n; // for the number of points
     cout<<"Enter the points in the form of x1,x1,h:"<<endl;
    vector<pair<pair<int,int>,pair<int,char>>>v;
    for(int i=0;i<n;i++)
    {
        int x,y,h;
        cin>>x>>y>>h;
        v.push_back({{x,h},{i+1,'s'}});
        v.push_back({{y,h},{i+1,'e'}});
    }
     
    cout<<endl; 
    sort(v.begin(),v.end());
    
    //set<int>s;
    /*for(auto x:v)
     {
        cout<<x.first.first<<endl;
     }*/

     vector<pair<int,int>>result; //to store thr result
     priority_queue<int>maxi;    // for maxheap for storing the height
     
     //int height=log(maxi);
     //int height1;
     //int max_height=0;

     for(auto x:v)
     {
        if(maxi.empty())
        {
            result.push_back({x.first.first,x.first.second});
            maxi.push(x.first.second);
        }
        else
        {
            if(maxi.top()<x.first.second)
            {
                maxi.push(x.first.second);
                result.push_back({x.first.first,x.first.second});
            }
            else if(maxi.top() > x.first.second)
            {
                deleteFromMaxHeap(maxi,x.first.second);
            }
            else
            {
                int down=x.first.first;
                maxi.pop();

                if(maxi.empty())
                {
                    result.push_back({down,0});
                }
                else
                {
                    result.push_back({down,maxi.top()});
                }
            }
        }
     }

     cout<<"Result are given below :"<<endl;
     for(auto temp:result)
     {
        cout<<temp.first<<" "<<temp.second<<" "<<endl; 
     } 
     
}
