#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int** CreateMatrix(int n){
    int **matrix = new int*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new int[n];
    }
    return matrix;
}
void FillMatrix1(int **matrix, int n)
{
    int k = ((pow(n, 2) - n) / 2) + n;
    cout << "Введите " << k << " чисел через пробел: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
            if (i + j + 1 >= n){
                cin >> matrix[i][j];
            }
			else{
                matrix[i][j] = 0;
            }
		}
	}
}
void FillMatrix0(int **matrix, int n)
{
    srand(time(0));
    int min;
    int max;
    cout << "Введите нижний диапозон значений = ";
    cin >> min;
    cout << "Введите вехний диапозон значений = ";
    cin >> max;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
            if (i + j + 1 >= n){
                matrix[i][j] = rand() % (max - min + 1) + min;
            }
			else{
                matrix[i][j] = 0;
            }
		}
	}
}
void FillMatrix(int **matrix, int n)
{
    cout << "Если хотите заполнить матрицу вручную нажмите 1" << endl << "Если хотите заполнить матрицу рандомом нажмите 0" << endl;
    bool b;
    cin >> b;
    if (b == 1){
        FillMatrix1(matrix, n);
    }
    else{
        FillMatrix0(matrix, n);
    }
}
void PrintMatrix (int **matrix, int n){
    cout << "Полученная матрица выглядит вот так:" << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
int message (int n){
    if ((n <= 10) && (n >= 1)){
        return n;
    }else {
        cout << "Введите число n от [1 до 10]!!! = ";
        cin >> n;
        return message (n);
    }
}
int main(){
    int n;
    cout << "Введите число n от [1 до 10] = ";
    cin >> n;
    n = message (n);
    int **matrix = CreateMatrix(n);
    FillMatrix(matrix, n);
    PrintMatrix (matrix, n);
}