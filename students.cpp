//Обработка списка студентов с оценками

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Student {
private:
  string group, surname, name, fathersName;
  vector<double> labs;

public:
  Student(string group, string surname, string name, string fathersName, vector<double> labs) {
    this->group = group;
    this->surname = surname;
    this->name = name;
    this->fathersName = fathersName;
    for (int i = 0; i < labs.size(); i++) {
      this->labs.push_back(labs[i]);
    }
  }

  //метод, выводящий строкой одну запись из БД
  void printStudentInString() {
    cout << "\t" << group << "\t";
    cout << setw(36) << left << surname + " " + name + " " + fathersName << "\t";
    for (int i = 0; i < labs.size(); i++) {
      cout << labs[i] << "\t";
    }
    cout << endl;
  }

  string getSurname() { return surname; }
  string getGroup() { return group; }
  vector<double> getScores() { return labs; }
  string getFullName() { return surname + " " + name + " " + fathersName; }

  ~Student() {}
};

vector<Student> createListOfStudents(string fileName) {
  ifstream inputStream(fileName.c_str());
  vector<Student> studentsList;

  if (inputStream.is_open()) {
    while (!inputStream.eof()) {
      string group;
      string surname, name, fathersName;
      vector<double> labs;
      inputStream >> group >> surname >> name >> fathersName;
      for (int i = 0; i < 7; i++) {
        double lab;
        inputStream >> lab;
        labs.push_back(lab);
      }
      Student tmp(group, surname, name, fathersName, labs);

      studentsList.push_back(tmp);
    }
  }
  else {
    cout << endl << "File was not found!" << endl;
  }

  return studentsList;
}

void printList(vector<Student> list) {
  cout << "№ п/п\t№ гр.\t\tФамилия И.О.\t\t\tлб1\tлб2\tлб3\tлб4\tлб5\tлб6\tСумма" << endl;
  cout << "____________________________________________________________________________________________________________";
  cout << endl << endl;

  for (int i = 0; i < list.size(); i++) {
    cout << i + 1;
    list[i].printStudentInString();
  }
}

//сортировка по фамилии
void surnameSort(vector<Student> & list) {
  for (int i = 1, j = i; i < list.size(); j = ++i)
  {
    while (j > 0 && list[j].getSurname().compare(list[j - 1].getSurname()) < 0)
    {
      swap(list[j], list[j - 1]);
      --j;
    }
  }
}

//задание 4
void printDebt(vector<Student> list) {
  cout << endl << endl;
  cout << "Сумма долга на зачет у студентов для группы " << list[0].getGroup() << ":" << endl << endl;
  cout << "№ п/п\t№ гр.\t\tФамилия И.О.\t\t\tДолг" << endl;
  cout << "_________________________________________________________________________";
  cout << endl << endl;

  for (int i = 0; i < list.size(); i++) {
    double debt = 0;
    vector<double> scores = list[i].getScores();
    if(scores[scores.size() - 1] < 100) {
      debt -= (100 - scores[scores.size() - 1]);
    }
    else {
      for (int j = 0; j < scores.size() - 1; j++) {
        if(scores[j] < 0) {
          debt += scores[j];
        }
      }
    }
    cout << i + 1 << "\t" << list[i].getGroup() << "\t";
    cout << setw(36) << left << list[i].getFullName() << "\t";
    cout << abs(debt) << endl;
  }
}

//задание 3
void printWinners(vector<Student> list) {
  vector<Student> newList;

  for (int i = 0; i < list.size(); i++) {
    bool flag = true;
    vector<double> scores = list[i].getScores();

    for(int j = 0; j < scores.size() - 1; j++) {
      if(scores[j] < 0) {
        flag = false;
      }
    }

    if(flag && scores[scores.size() - 1] >= 100) {
      newList.push_back(list[i]);
    }
  }

  surnameSort(newList);

  cout << endl << endl << "Список людей, имеющих право на досрочный зачет группы " << newList[0].getGroup() << ":" << endl << endl;
  printList(newList);
}

//задание 2
void printOneGroup(vector<Student> list) {
  cout << endl << endl;
  cout << "Введите нужную группу: ";
  string neededGroup;
  cin >> neededGroup;

  vector<Student> newList;
  for (int i = 0; i < list.size(); i++) {
    if (list[i].getGroup() == neededGroup) {
      newList.push_back(list[i]);
    }
  }

  surnameSort(newList);

  cout << endl << endl << "Вывод результатов предзачета для группы " << neededGroup << ":" << endl << endl;
  printList(newList);

  printWinners(newList); //вывод задания 3
  printDebt(newList); //вывод задания 4
}

int main() {

  setlocale(0, "");

  vector<Student> listOfStudents = createListOfStudents("spisok.txt");
  printList(listOfStudents);

  while(1) {
    printOneGroup(listOfStudents);

    cout << endl << "Введите 1, чтобы посмотреть другую группу" << endl;
    cout << "Введите другой символ для выхода" << endl;

    int symbol;
    cin >> symbol;
    if (symbol != 1)
      break;
  }
  return 0;
}



