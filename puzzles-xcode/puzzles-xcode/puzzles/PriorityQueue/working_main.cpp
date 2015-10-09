#include <iostream>
using namespace std;

#if 0
template <class T>
class PrioQueue{
    
private:
    int n, maxsize;
    
    T* x;
    
    // swaps indices i & j
    void swap(int i, int j)
    {
        T temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }
    
public:
    PrioQueue(int m)
    {
        maxsize = m;
        x = new T[maxsize + 1];  // we dont use x[0]
        n = 0;
    }
    
    void insert(T t)
    {
        int i, p;
        x[++n] = t;
        
        for(i=n; i>1 && x[p=i/2] > x[i]; i = p)
            swap(p, i);
    }
    
    T extractMin()
    {
        int i, c;
        T t = x[1];
        x[1] = x[n--];
        
        for(i = 1; (c = 2*i) <= n; i = c)
        {
            if((c+1)<=n && x[c+1]<x[c])
                c++;
            
            if(x[i] <= x[c])
                break;
            
            swap(c, i);
        }
        
        return t;
    }
};
#endif 

void swap(int x[], int i, int j)
{
    int temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

void siftUp(int a[], int n)
{
    int i, p;
    
    for( i = n; i>1 && a[p=i/2] < a[i]; i = p)
        swap(a, p, i);
    
}

void siftDown(int a[], int n)
{
    int i, c;
    
    for(i = 1; (c = 2*i) <= n; i = c)
    {
        if((c+1) <= n && a[c+1] > a[c])
            c++;
        
        if(a[i] >= a[c])
            break;
        
        swap(a, c, i);
    }
    
    
}

void heap_sort(int *s, int n)
{
    int i;
    for (i = 2; i <= n; i++)
        siftUp(s, i);
    for (i = n; i >= 2; i--) {
        swap(s, 1, i);
        siftDown(s, i - 1);
    }
}


int main()
{
    
    int a[] = {0, 10,11,12,9,8,7,6,5,4,3,2,1};
    
    for(int i = 1; i < sizeof(a)/sizeof(a[0]); i++)
        cout << a[i] << " " ;
    
    cout << endl;
    
    heap_sort(a, (sizeof(a)/sizeof(a[0]) - 1));
    
    for(int i = 1; i < sizeof(a)/sizeof(a[0]); i++)
        cout << a[i] << " " ;
    
    cout << endl;
    
    
    
#if 0
    PrioQueue<int> *pq = new PrioQueue<int>(12);
    
    for(int i = 0; i<12; i++)
        pq->insert(11-i);
    
    for(int i = 0; i<12; i++)
        cout << pq->extractMin() << endl;
#endif
    
    return 0;
    
}


