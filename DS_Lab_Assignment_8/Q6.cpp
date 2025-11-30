#include <iostream>
using namespace std;

int heapArr[100], heapSize = 0;

void insertPQ(int x) {
    heapArr[++heapSize] = x;
    int i = heapSize;
    while(i>1 && heapArr[i] > heapArr[i/2]) {
        swap(heapArr[i], heapArr[i/2]);
        i /= 2;
    }
}

int deleteMax() {
    if (heapSize == 0) return -1;
    int x = heapArr[1];
    heapArr[1] = heapArr[heapSize--];
    int i = 1;
    while (true) {
        int l = 2*i, r = 2*i+1, mx = i;
        if (l<=heapSize && heapArr[l]>heapArr[mx]) mx=l;
        if (r<=heapSize && heapArr[r]>heapArr[mx]) mx=r;
        if (mx==i) break;
        swap(heapArr[i], heapArr[mx]);
        i = mx;
    }
    return x;
}

int main() {
    insertPQ(40);
    insertPQ(10);
    insertPQ(60);
    insertPQ(30);

    cout << deleteMax() << endl;
    cout << deleteMax() << endl;
}

