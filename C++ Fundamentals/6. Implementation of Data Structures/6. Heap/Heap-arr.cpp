#include<bits/stdc++.h>
using namespace std;

class Heap {
    public:
        int index;
        int size;
        vector<int> heap;
        Heap() {
            this->index = 0;
            this->size = 0;
        }
        void push(int val) {
            heap.push_back(val);
            int index = heap.size() - 1;
            int size = heap.size();
            while(index > 0 && heap[(index - 1) / 2] < heap[index]) {
                swap(heap[(index - 1) / 2], heap[index]);
                index = (index - 1) / 2;
            }
        }
        void pop() {
            heap.pop_back();
            size--;
        }
        void heapify(vector<int> &heap, int i, bool(*comaparator) (int, int)) {
            int parent = i;
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            if(leftChild < size && comaparator(heap[leftChild], heap[parent])) {
                parent = leftChild;
            }
            if(rightChild < size && comaparator(heap[rightChild], heap[parent])) {
                parent = rightChild;
            }
            if(parent != i) {
                swap(heap[i], heap[parent]);
                heapify(heap, parent, comaparator);
            }
        }
        static bool maxHeapComparator(int a, int b) {
            return a > b;
        }
        static bool minHeapComaprator(int a, int b) {
            return a < b;
        }
        void remove(int val) {
            int indx;
            for(indx = 0; indx < size ; indx++) {
                if(heap[indx] == val) {
                    break;
                }
            }
            heap[indx] = heap[size - 1];
            heap.pop_back();
            size--;
            heapify(heap, indx, maxHeapComparator);
        }
        void print() {
            for(auto i : heap) {
                cout << i << " ";
            }
            cout << endl;
        }
};

int main() {
    Heap *h = new Heap();
    h->push(10);
    h->push(15);
    h->push(20);
    h->push(25);
    h->push(30);
    h->print();
    h->pop();
    h->print();
}