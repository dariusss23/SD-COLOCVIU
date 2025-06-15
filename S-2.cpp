#include <iostream>

using namespace std;

int n, h[100005];

int parent(int i){ return i/2; }
int left(int i){ return 2*i; }
int right(int i){ return 2*i+1;}

void HeapUp(int k){
    int dad = parent(k);
    while (dad >=1 && h[dad] > h[k]){
        swap (h[dad], h[k]);
        k = dad;
        dad = parent(k);
    }
}

void HeapDown (int k, int dim){
    while(left(k)  <= dim){
        int smallest = left(k);
        int r = right(k);

        if (r <= dim && h[r] < h[smallest]) smallest =r;

        if (h[k] > h[smallest]){
            swap (h[k], h[smallest]);
            k = smallest;
        }
        else break;
    }
}

int extractMin(int &dim){
    if (dim == 0) return 0;
    int x = h[1];
    h[1] = h[dim--];
    HeapDown (1, dim);
    return x;
}

void add( int &dim, int value){
    h[++dim] = value;
    HeapUp(dim);
}

int main(){
    int dim=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        add(dim, x);
    }

    int sol =0;
    int rez = 0;

    for (int i=1;i<=n-1;i++){
        int a = extractMin(dim);
        int b = extractMin(dim);
        rez = a+b;
        sol = sol+(a+b);
        add(dim, rez);
    }

    cout << sol ;

/*
    for (int i=1;i<=n;i++){
        cout << extractMin(dim) << " ";
    }
*/
}
