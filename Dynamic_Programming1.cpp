#include <iostream>
using namespace std;
int r,c;
int* fsmax(int a[][1000],int r,int c){
    int fm=0,sm=0;
    int *b = new int[2];
    for(int i=0;i<c;i++){
        if(a[r][i]>fm){
                sm = fm;
                fm  = a[r][i];
            }else if(a[r][i]>sm)
            sm=a[r][i];
    }
    b[0]=fm;
    b[1]=sm;
    return b;
}
int main() {
    cin>>r>>c;
    int a[r][c],dp[1000][1000];
    int fm=0,sm=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
            if(i==0)
            dp[i][j]=a[i][j];
        }
    }
    for(int i=1;i<r;i++){
        int* y = fsmax(dp,i-1,c);
        for(int j=0;j<c;j++){
           dp[i][j] = a[i][j] +((dp[i-1][j] ==y[0])?y[1]:y[0]);
        }
    }
    cout<<fsmax(dp,r-1,c)[0];

    return 0;
}
