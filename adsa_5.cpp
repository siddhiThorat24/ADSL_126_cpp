#include<iostream>
using namespace std;

struct people{
    int start,end;
};

int main(){
    people p[100];
    int n,k,i,j;
    cout<<"Enter no. of shop:";
    cin>>n;
    cout<<"Enter no. of people:";
    cin>>k;

    for(i=0;i<n;i++){
        cin>>p[i].start;
    }
    for(i=0;i<n;i++){
        cin>>p[i].end;
    }

    int personEnd[100]={0};
    int count=0;

    for(i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(p[i].start>=personEnd[j]){
                personEnd[j]=p[i].end;
                count++;
                break;
            }
        }
    }

    cout<<count;

    return 0;
}