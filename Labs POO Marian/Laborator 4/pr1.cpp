#include <iostream>
#include <cmath>

using namespace std;

class matrix
{ 
   int **p, m, n; 
public: 
   matrix(int row, int col) { 
      m = row; 
      n = col; 
      p = new int*[m]; 
      for (int i = 0; i < m; i++) 
	  	p[i] = new int[n]; 
   }
   void citire() { 
      //cout<<"Introdu elementele matricei: "<<endl; 
      for(int i = 0; i < m; i++) { 
	  	for(int j = 0; j < n; j++) { 
	    	cin >> p[i][j]; 
	 	} 
      } 
   } 
   matrix adunare(matrix b) {
      matrix aux(m, n);
      for(int i = 0; i < m; i++) {
	  	for(int j = 0; j < n; j++) {
	    	aux.p[i][j] = p[i][j] + b.p[i][j]; 
	 	} 
      }
      return aux;
   }

	matrix inmultire(matrix b) {
    	matrix aux(1,1);
    	if(this->n == b.m) {
     		matrix T(this->m, b.n);
    		for(int i = 0; i < this->m; i++) {
	  			for(int k = 0; k < b.n; k++) {
	    			T.p[i][k] = 0;
	    			for(int j = 0; j < this->n; j++) {
	       				T.p[i][k]+= this->p[i][j] * b.p[j][k];
	    			}
	 			}	
      		}
      	aux = T;
   		}
   		return aux;
	}
	matrix putere(int putere) {
		matrix out(this->m, this->n);
		for( int i = 0 ; i < this->m ; ++ i )
        	for( int j = 0 ; j < this->n ; ++ j )
            	out.p[i][j] = ( i == j ) ;    

	    matrix temp(this->m, this->n);
	
	    for(int i=0; i < putere; i++)
	    {
	        for(int i=0;i<this->m;i++)
	        {
	            for(int j=0;j<this->m;j++)
	            {
	                temp.p[i][j]=0;   
	                for(int k=0;k<this->m;k++)
	                {
	                    temp.p[i][j]+=out.p[i][k]*this->p[k][j];
	                }
	            }
	        }
	
	        for(int i=0;i<this->m;i++){
	            for(int j=0;j<this->m;j++)
	            {   
	                out.p[i][j]=temp.p[i][j];
	            }
	        }
	    }
	    return out;
	}
	void toString() { 
      for(int i = 0; i < m; i++) { 
	  	for(int j = 0; j < n; j++) { 
	    	cout << p[i][j] <<" "; 
	 	}
		 cout << endl; 
      } 
   }
};
int main() {
	matrix a(3,3), b(3,3), c(3,3), d(3,3), e(3,3), f(3,3);
	cout << "Introdu elementele matricei patratice A[3,3]" << endl;
	a.citire();
	cout << "Introdu elementele matricei patratice B[3,3]" << endl;
	b.citire();
	c = a.adunare(b);
	cout << "A + B = " << endl;
	c.toString();
	d = a.inmultire(b);
	cout << "A * B = " << endl;
	d.toString();
	cout << "A la puterea 4 = " << endl;
	f = a.putere(4);
	f.toString();
	e = b.putere(3);
	cout << "B la puterea 3 = " << endl;
	e.toString();
	return 0;
}
