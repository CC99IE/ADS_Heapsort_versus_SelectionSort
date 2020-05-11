// Created by Catalin Chirita at 03:41:10 - 10-May-2020
// To be honest i have no idea about this it's just a bunch of scap holded together by duct tape
// Please be kind on this poor algorithm for it has suffered enough
// By the rather absurd endless tirade of four letter words that i lashed out in anger upon it
// The shocking, unspeakable things that I said about it

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("data.in");

class Select_sort
{
private:
    int vector[1024];
    int n;
public:
    Select_sort (int x[],int k)
    {
        for(int i = 0; i < k; i++)
            vector[i] = x[i];
        n = k;
    }

    void FindMaxAndSwap(int i)
    {
        int j,max = -999999999;
        max = i;
            for (j = i+1; j < n; j++)
            if (vector[j] < vector[max])
                max = j;
        swap(vector[max], vector[i]);
    }

    void Sort()
    {
        int i;
        for (i = 0; i < n-1; i++)
            FindMaxAndSwap(i);
    }

    void Print()
    {
        for(int i = 0;i < n;i++)
            cout<<vector[i]<<" ";
    }
};

class Heap_sort
{
private:
    vector<int> heap;
public:
    Heap_sort(vector<int> A,int k)
    {
        int i;
        for(i = 0;i < k; i++)
            heap.push_back(A[i]);
    }

    void Mheap(int i, int size)
    {
        int biggest;
        int l = (2*i) + 1;
        int r = l + 1;

        if(l < size && heap[l] > heap[i])
            biggest = l;
        else
            biggest = i;

        if(r < size && heap[r] > heap[biggest])
            biggest = r;

        if(biggest != i)
        {
            swap(heap[i], heap[biggest]);
            Mheap(biggest, size);
        }
}

    void build_Max_Heap()
    {
        for(int i = (heap.size() / 2); i >= 0; i--)
            Mheap(i, heap.size());
    }

    void Sort()
    {
        build_Max_Heap();
        int sz = heap.size();
        for(int i = heap.size() - 1; i > 0; i--)
        {
            swap(heap[0], heap[i]);
            sz--;
            Mheap(0, sz);
        }
    }

void Print()
{
    for (int i=0; i< heap.size(); i++)
        cout << heap[i] << " ";
    cout<<endl;
}

};

void Sort(vector<int> A,int n)
{
    Heap_sort example = Heap_sort(A,n);
    example.Sort();
    example.Print();

}

void Sort(int A[],int n)
{
    Select_sort Example = Select_sort(A,n);
    Example.Sort();
    Example.Print();
}


int main()
{
    int v[100],n;
    in>>n;
    for(int i = 0;i < n;i++)
        in>>v[i];
    vector<int> A(v, v + n);
    Sort(A,n);
    Sort(v,n);
}