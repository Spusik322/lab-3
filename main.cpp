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
int Message (int n){
    if ((n <= 10) && (n >= 1)){
        return n;
    }else {
        cout << "Введите число n от [1 до 10]!!! = ";
        cin >> n;
        return Message (n);
    }
}
void SumInStroka (int** matrix, int n){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if (matrix[i][j] < 0){
                sum = 0;
                break;
            }
            else{
                sum += matrix[i][j];;
            }
        }
        if (sum != 0){
        cout << "Сумма в "<< i+1 << " строке = " << sum << endl;
        sum = 0;
        }
    }
}
void MinNumber(int** matrix, int n){
    if(n > 1){
        int minimum = matrix[0][1];
        for (int k = 1; k < n; ++k){
            for (int i = 0; i < n - k; ++i){
                if (matrix[i][i + k] < minimum){
                    minimum = matrix[i][i + k];
                }
            }
        }
        for (int k = 1; k < n; ++k){
            for (int i = 0; i < n - k; ++i){
                if (matrix[i + k][i] < minimum){
                    minimum = matrix[i + k][i];
                }
            }
        }
        cout << "Минимальное значение с паралельной диагонали = " << minimum << endl;
    }
    else {
        cout << "В матрице нет диагоналей паралельных главной";
    }
}
void DeleteMatrix(int** matrix,int n){
        for(int i = 0;i < n; ++i){
            delete[]matrix[i];
        }
        delete[]matrix;
    }
int main(){
    int n;
    cout << "Введите число n от [1 до 10] = ";
    cin >> n;
    n = Message (n);
    int **matrix = CreateMatrix(n);
    FillMatrix(matrix, n);
    PrintMatrix (matrix, n);
    SumInStroka(matrix, n);
    MinNumber(matrix, n);
    DeleteMatrix(matrix, n);
    return 0;
}