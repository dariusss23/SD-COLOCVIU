#include <iostream>

using namespace std;

int n,m,k,a[2005][2005];
int x,y;
int Max=-1;

static inline bool inside(int i, int j){
    return i>=1 && i<=n  && j<=m && j>=1;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>a[i][j];
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int nr=0;
            x=i;
            y=j;
            int suprafata=1; 
            while (nr<k && a[x][--y] <= a[i][j] && inside(x,y) == true) suprafata++, nr++;
            x=i;
            y=j;
            nr=0;
            while (nr<k && a[x][++y] <= a[i][j] && inside(x,y) == true) suprafata++, nr++;
            x=i;
            y=j;
            nr=0;
            while (nr<k && a[++x][y] <= a[i][j] && inside(x,y) == true) suprafata++, nr++;
            x=i;
            y=j;
            nr=0;
            while (nr<k && a[--x][y] <= a[i][j] && inside(x,y) == true) suprafata++, nr++;
            if (suprafata > Max) Max=suprafata;
        }
    }
    cout << Max;
}
