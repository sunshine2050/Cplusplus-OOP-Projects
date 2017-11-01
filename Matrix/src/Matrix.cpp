#include <math.h>
#include <assert.h>
#include "Matrix.h"

Matrix::Matrix(int r,int c){ setUp(r,c); }

void Matrix::setUp(int r,int c)
{
    if(r>0 && c>0){
        nr = r; nc = c;
        mat = new double[r*c];
    }
    else { mat = NULL; nr = nc = 0; }
}

Matrix::Matrix(double* m, int r, int c){
    setUp(r,c);
    if( mat != NULL){
        for(int i=0;i<r*c;i++) mat[i] = m[i];
    }
}

double Matrix::getElement(int i, int j) const
{
    if(i>=0 && i<nr && j>=0 && j<nc) return mat[i*nc + j];
    else return HUGE_VAL;
}

void Matrix::setElement(int i, int j, double e){
    if(i>=0 && i<nr && j>=0 && j<nc) mat[i*nc+j] = e;
}

void Matrix::times(const Matrix& b, Matrix& ans) const
{
    assert( nc == b.nr);
    for(int i=0;i<nr;i++){
        for(int j=0;j<b.nc;j++){
            ans.setElement(i,j,rowTimesCols(i,b.mat,j,b.nc));
        }
    }
}

double Matrix::rowTimesCols(int i, double* b, int j, int bc) const
{
    double sum = 0.0;
    for(int k=0;k<nc;k++) sum += mat[i*nc+k] * b[k*bc + j];
    return sum;
}

void Matrix::display() const {
    for(int i=0;i<nr;i++){
        std::cout<<std::endl<<"( ";
        for(int j=0;j<nc-1;j++){
            std::cout<<mat[i*nc+j]<<" ";
        }
        std::cout<<mat[i*nc + nc-1]<<" )"<<std::endl;
    }
}
