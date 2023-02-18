#include <iostream>
using namespace std;

void print_matrix(float matrix_[2][5]){
    cout << endl << "MATRIX" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix_[i][j] << " ";
        }
        cout << endl;
    }
}

void input_matrix(float matrix_[2][5]){
    for (int i = 0; i < 2; ++i) {
        cout << "Линия №" << i + 1 << endl;
        for (int j = 0; j < 5; ++j) {
            cout << "=> Столбец №" << j + 1 << endl;
            cin >> matrix_[i][j];
        }
    }
}

void move_min_to_max(float matrix_[2][5]){
    int min_pos_c = 0;  // index (MIN) значения по столбцу (coloumn)
    int min_pos_r = 0;  // index (MIN) значения по строке (row)
    int max_pos_c = 0;  // index (MAX) значения по строке (coloumn)
    int max_pos_r = 0;  // index (MAX) значения по строке (row)
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix_[max_pos_r][max_pos_c] < matrix_[i][j]){
                max_pos_r = i;
                max_pos_c = j;
            }
            if (matrix_[min_pos_r][min_pos_c] > matrix_[i][j]){
                min_pos_r = i;
                min_pos_c = j;
            }
        }
    }
    swap(matrix_[min_pos_r][min_pos_c], matrix_[max_pos_r][max_pos_c]);
}

int main(){
    setlocale(0, "Russian");
    float matrix[2][5];
    input_matrix(matrix);
    print_matrix(matrix);
    move_min_to_max(matrix);
    print_matrix(matrix);
    system("pause");
    return 0;
}