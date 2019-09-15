#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Matrix2D{
    private:
        T** mat_data;
        int row;
        int col;
    public:
        Matrix2D(int row_sz, int col_sz){
            row = row_sz;
            col = col_sz;
            mat_data = new T*[row];
            for(int i = 0; i < row; i++)
                mat_data[i] = new T[col];
        }
        ~Matrix2D(){
            for(int i = 0; i < row; i++)
                delete[] mat_data[i];
            delete[] mat_data;
        }
        void initRandom(){
            for (int i=0; i < row; i++){
                 for (int j=0; j < col; j++){
                    mat_data[i][j] = (T)rand();
                }
            }
        }
        void initVal(T value){
            for (int i=0; i < row; i++){
                 for (int j=0; j < col; j++){
                    mat_data[i][j] = value;
                }
            }
        }
        T getElement(int i, int j){
            return mat_data[i][j];
        }
        T setElement(int i, int j, T value){
            mat_data[i][j] = value;
        }
        T addToElement(int i, int j, T value){
            mat_data[i][j] += value;
        }
        int getRowSz(){
            return row;
        }
        int getColSz(){
            return col;
        }
        void print(){
            for (int i=0; i < row; i++){
                 for (int j=0; j < col; j++){                    
                    cout << +mat_data[i][j] << "  " ;
                }
                cout <<endl;
            }
        }
};

template <typename T>
Matrix2D<T> multiply2DMatrix(Matrix2D<T>& A, Matrix2D<T>& B){
    if(A.getColSz() != B.getRowSz()){
        perror("matrix A column and B row mismatch for multiplication.");
        exit(-1);
    }
    Matrix2D<T> mat_data(A.getRowSz(), B.getColSz());
    mat_data.initVal(0);
    for(int i=0; i<A.getRowSz(); ++i){
         for(int j=0; j<B.getColSz(); ++j){
            for(int k=0; k<A.getColSz(); ++k) {
                mat_data.addToElement(i,j,A.getElement(i,k)*B.getElement(k,j));
            }
        }
    }

    return mat_data;
}

int main(int argc, char *argv[]){
    Matrix2D<int> A(2,3);
    Matrix2D<int> B(3,5);
    A.initVal(1);
    B.initVal(3);
    Matrix2D<int> product = multiply2DMatrix(A,B);
    A.print();
    B.print();
    product.print();
    return 0;      
}



