#include <iostream>

int binary_search(int *array, unsigned int length, int number) {
  int middle = length / 2;
  return number == array[middle] ?
    middle :
    number < array[middle] ?
      binary_search(array, middle, number) :
      middle + binary_search(&array[middle], middle + (length % 2), number);
}

int main() {
  const int N = 20;
  int mas[N];
  for (int i = 0; i < N; i++) {
    mas[i] = i * 4 + 1;
  }

  for(int i = 0; i < N; i++)
    std::cout << "mas[" << i << "] = " << mas[i]
      << ", index returned from binary_search = " <<
      binary_search(mas, N, i * 4 + 1) << std::endl;


}
