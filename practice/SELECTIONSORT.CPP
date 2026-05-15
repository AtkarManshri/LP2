#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr={10,2,9,1,3,20,30,23,100};
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {  int mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mini])
            {
                mini=j;
            
            }
          

        }
           
         swap(arr[i],arr[mini]);//i loop 
    }

    for(auto it:arr)
    {
        cout<<it<<"\n";
    }
} 
    
    