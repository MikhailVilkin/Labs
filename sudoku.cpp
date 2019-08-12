#include <iostream>
using namespace std;
bool checkArray(unsigned int* array) {
  bool check[9] = {};
  for(int i = 0; i < 9; i++)
    if(check[array[i]-1])
      return false;
    else
      check[array[i]-1] = 1;
  for(int i = 0; i < 9; i++)
    if(!check[i])
      return false;
  return true;
}
int main() {
  bool validation = true, flag = true; //Если функция проверки хотя бы раз вернет false - судоку не верен
  unsigned int sudoku[9][9] = {
    {1,6,9, 2,8,4, 5,7,3},
    {2,3,4, 1,5,7, 8,6,9},
    {5,7,8, 3,9,6, 1,2,4},

    {9,5,3, 4,1,2, 6,8,7},
    {4,2,6, 5,7,8, 9,3,1},
    {8,1,7, 6,3,9, 4,5,2},

    {7,8,5, 9,2,1, 3,4,6},
    {3,4,1, 7,6,5, 2,9,8},
    {6,9,2, 8,4,3, 7,1,5}
    };
    for(int i = 0; i<9; i++){
      for(int j =0; j<9;j++){
        cout << sudoku[i][j] << "  ";
      }
      cout << endl;
    }
//Проверка строк и столбцов
  unsigned int arrayForCheck[9];
  for (int i = 0; i < 9; i++) {
    if (!(validation = checkArray(sudoku[i]))) { //проход по строкам
      cout << "string " << i+1 << endl;
      if(!validation)
        flag = false;
    }
    for(int j=0; j < 9; j++)
      arrayForCheck[j] = sudoku[j][i]; // в этот массив записывается столбец
    if (!(validation = checkArray(arrayForCheck))) { //проход по столбцам
      cout << "column " << i+1 << endl;
      if(!validation)
        flag = false;
    }
  }
//Проверка квадратов
  for(int i = 0; i < 9; i+=3) //цикл проверяет каждый отдельный квадрат
    for(int j = 0; j < 9; j+=3) {
        for(int p = i, s = 0; p < i+3; p++)
          for(int k = j; k < j+3; k++, s++)
            arrayForCheck[s] = sudoku[p][k]; // в массив записываются значения одного квадрата
    if (!(validation = checkArray(arrayForCheck))) {
      cout << "Square " << (i+1)/3+1 << " " << (j+1)/3+1 << endl;
      if(!validation)
        flag = false;
    }
    }
  if(flag)
    cout << "Sudoku is correct!" << endl << endl;
  else
    cout << "Errors in the above" << endl << "Sudoku is incorrect" << endl << "Try again"<< endl << endl;
  return 0;
}

