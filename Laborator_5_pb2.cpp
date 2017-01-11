#include <iostream>

using namespace std;
class graf
{
    int noduri,**a;
public:
    Graph(int x)
    {
        noduri = x;
        a = new int*[noduri];
        for(int i = 0; i < noduri; ++i)
            a[i] = new int[noduri];
        for(int i = 0 ; i < noduri ; i++)
            for(int j = 0 ; j < noduri ; j++)
                *(*(a+i)+j) = 0;
    }
    ~graf()
    {
        delete [] a;
    }
    int size ( )
    {
        return noduri;
    }
    void addArc ( int v, int w )
    {
        *(*(a+v)+w) = 1;
    }
    bool isArc ( int v, int w )
    {
        if (*(*(a+v)+w) == 1 )
            return true;
        else
            return false;
    }
    void print ( )
    {
        for(int i = 0 ; i < noduri ; i++)
        {
            for(int j = 0 ; j < noduri ; j++)
            {
                cout << *(*(a+i)+j) << " ";
            }
            cout << endl;
        }
    }
    void dfs ( int v , bool vazut[])
    {
        int w;
        vazut[v] = true;
        for ( w = 1 ; w <= noduri; w++)
            if( isArc(v,w) && !vazut[w])
            {
                cout << "Arcul intre: " << v << " - " << w;
                dfs ( w,vazut );
            }
    }

};
int main ( )
{
    graf x(3);
    x.addArc(0,0);
    x.addArc(1,1);
    x.addArc(1,2);
    x.addArc(2,2);
    x.addArc(2,0);
    x.print();

    int size = x.size();
    bool *v;
    v = new bool[size];
    for ( int i = 0 ; i < size ; i++)
        *(v+i) = false;

    cout << "\n";
    x.dfs(1,v);

    delete [] v;
    return 0;
}
