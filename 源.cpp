#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void insertSort(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (vec[j - 1] > vec[j]) swap(vec[j - 1], vec[j]);
        }
    }
    return;
}

void quickSort(vector<int>& vec, int first, int last) {
    if (first >= last) return;
    int left = first;
    int right = last - 1;
    int pivot = vec[left];
    while (left < right) {
        while (left < right && pivot <= vec[right]) right--;
        vec[left] = vec[right];
        while (left < right && pivot >= vec[left]) left++;
        vec[right] = vec[left];
    }
    vec[left] = pivot;
    quickSort(vec, first, left);
    quickSort(vec, left + 1, last);
    return;
}

void Heapify(vector<int>& a, int n, int i) {
    while (1) {
        int maxPos = i;
        if (i * 2 <= n && a[i] < a[i * 2]) { maxPos = i * 2; }
        if (i * 2 + 1 <= n && a[maxPos] < a[i * 2 + 1]) { maxPos = i * 2 + 1; }
        if (maxPos == i) break;
        std::swap(a[i], a[maxPos]);
        i = maxPos;
    }
}
void HeapSort(vector<int>& a, int n) {
    for (int i = n / 2; i >= 1; --i) {
        Heapify(a, n, i);
    }
    int k = n;
    while (k > 1) {
        swap(a[1], a[k]);
        --k;
        Heapify(a, k, 1);
    }
}

void pdqSort(vector<int>& vec, int limit) {
    if (vec.size() < 24) return insertSort(vec);
    if (limit == 0) return HeapSort(vec, vec.size() - 1);
    return quickSort(vec, 0, vec.size());
}

int main() {
    vector<int> n = { 0,6,4,9,8,3,2,5,7,1,6,58,9 };
    //insertSort(n);
    //quickSort(n, 0, n.size());
    //HeapSort(n, n.size()-1);
    int limit = 0;
    pdqSort(n, limit);
    for (int i : n) {
        cout << i << endl;
    }
    return 0;
}