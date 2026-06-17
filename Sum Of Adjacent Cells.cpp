#include <iostream>
using namespace std;
int main() {
    int dif[8][2] ={{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
    int r,c;
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cin>>a[i][j];
    }
    int sum=0,row,col;
    cin>>row>>col;
    for(int i=0;i<8;i++){
        int x = row-1+dif[i][0];
        int y = col-1+dif[i][1];
        if((x>=0 && x<r) && (y>=0 && y<c)){
            cout<<a[x][y]<<" ";
        sum+=a[x][y];
        }
    }
    cout<<sum;
    return 0;
}
