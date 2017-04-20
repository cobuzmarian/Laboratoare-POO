#include<iostream>

using namespace std;

class Graph {
    private:
        int n;
        int **A;
    public:
        Graph(int size) {
        	n = size;
        	A = new int*[n];
        	for(int i = 0; i < n; i++)
        		A[i] = new int[n];
        	for(int i = 0; i < n; i++)
        		for(int j = 0; j < n; j++)
        			A[i][j] = 0;
		}
		int size() {
			return n;
		}
        
        void addArc(int v, int w) {
        	A[v-1][w-1] = A[w-1][v-1] = 1;
		}
		
		bool isArc(int v, int w) {
        	return (A[v-1][w-1] == 1);
		}
		
		void print() {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << A[i][j] << " ";
				}
				cout << endl;
			}		
		}
		
        void dfs_lab(int v, bool vazut[]) {
        	int w;
        	vazut[v] = true;
        	for(w = 1; w <= n; w++)
        		if(isArc(v,w) && !vazut[w]) {
        			cout << v << "-" << w <<endl;
        			dfs_lab(w, vazut);
				}
		}	
};

void dfs(Graph g, int v) {
	int n = g.size();
	bool *vazut = new bool[n];
	for(int i = 0; i < n; i++)
		vazut[i] = false;
		
	for(int i = 0; i < n; i++)
		if(vazut[i] == false)
			g.dfs_lab(v, vazut);
}


int main() {
	Graph g(5);  
    g.addArc(2, 1);
    g.addArc(1, 3);
    g.addArc(3, 2);
    g.addArc(1, 4);
    g.addArc(4, 5);
    g.addArc(5, 1);
    dfs(g, 1);
    
    cout<<"Matrice de adiacente: " <<endl;
    g.print();
    return 0;
}

