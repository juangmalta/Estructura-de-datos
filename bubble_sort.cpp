#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> bubble_sort_algorithm(vector<int> A){
    int n=A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(A[j]>A[j+1]){
                int tmp_value=A[j];
                A[j]=A[j+1];
                A[j+1]=tmp_value;
            }
        }
        
    }
    return A;
}

int main(){
    int num_items =10;
    vector<int> x(num_items,0);
    srand(time(0));
    generate(x.begin(),x.end(),[](){
        return rand() % 100;
        });
    cout<<"vector before sorting"<<endl;
    for(int i =0;i<num_items;i++){
        cout<<x[i]<<" ";
    }
    vector<int>x_order=bubble_sort_algorithm(x);
    cout<<endl<<"Vector after sorting"<<endl;
    for(int i = 0;i<num_items;i++){
        cout<<x_order[i]<<" ";
    }
    return 0;
}