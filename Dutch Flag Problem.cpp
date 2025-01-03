#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(int i, int j, vector<int>& v){
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;

}
void sort(int n, vector<int>& v){
    int lo=0, mid=0, hi=n-1;
    while(mid<=hi){
        if(v[mid]==2){
            swap(mid,hi,v);
            hi--;
        }
        else if(v[mid]==0){
            swap(mid,lo,v);
            mid++;
            lo++;
        }
        else if(v[mid]==1)
            mid++;
    }
}

int main(){
    vector<int> v;
    int n;
    cout<<"enter size : ";
    cin>>n;
    cout<<"enter elements."<<endl;
    for(int i=0;i<n;i++){
        int x;
        cout<<"element at "<<i<<" ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"original array : ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(n,v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
