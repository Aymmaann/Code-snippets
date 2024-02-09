#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the matrix : ";
    cin>>n;
    int matrix[101][101];
    int row=0, col=0;
    
    // 0:right, 1:down, 2:left; 3:up
    int direction = 0;
    int count = 1;

    while(count <= n*n) {
        matrix[row][col] = count;

        if (direction==0) {
            if (col==n-1 || matrix[row][col+1] > 0){
                direction = 1; row++;
            }
            else
                col++;
        }

        else if(direction==1){
            if(row==n-1 || matrix[row+1][col] > 0){
                direction=2; col--;
            }
            else
                row++;
        }

        else if(direction==2){
            if(col==0 || matrix[row][col-1] > 0){
                direction=3; row--;
            }
            else
                col--;
        }

        else{
            if(matrix[row-1][col] > 0){
                direction=0; col++;
            }
            else
                row--;
        }
        
        count++;
    }

    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0)
                cout << matrix[i][j] << "   ";
            else
                cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
