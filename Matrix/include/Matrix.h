#include <iostream>

class Matrix
{
    public:
        Matrix(){ mat = NULL; }
        Matrix(int r, int c);
        Matrix(double* m , int r, int c);
        ~Matrix(){ delete mat; }
        double getElement(int i, int j) const;
        void setElement(int i, int j, double e);
        int rows() const { return nr; }
        int cols() const { return nc; }
        void times(const Matrix& b, Matrix& ans) const;
        void display() const;

    private:
        double rowTimesCols(int i, double* b, int j, int bc) const;
        void setUp(int r, int c);
        double* mat;
        int nr,nc;
};

