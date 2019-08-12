
/////////////////////////////////////////////////////////////////////
/*
Вилкин М.А.
ИКВТ-83
Лабораторная работа №5, раскодирование сообщения
Вариант 3
*/
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool is_in(char target, string msg) {
	for(int i=0;i<msg.length();i++)
		if(target==msg[i])
			return true;
	return false;
}

int find(char target, string alphabet) { //возвращает индекс элемента
	for(int i=0;i<alphabet.length();i++)
		if(alphabet[i]==target)
			return i;
}

string shift(string alphabet, string msg, int shift) {
	int idx = 0;
	for(int i=0;i<msg.length();i++)
		if(is_in(msg[i], alphabet)) {
			idx = (find(msg[i], alphabet)+shift) % alphabet.length();
			if(idx<0)
				idx = alphabet.length() - idx;
			msg[i] = alphabet[idx];
		}
	return msg;
}

int main() {
  setlocale(0, "");
	ifstream input;
	input.open("Message3.txt");
	int k;
	string alphabet = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	string msg;
	string buffer;

	input >> k;
	input >> msg;
	while(!input.eof()){
		input >> buffer;
		msg += " ";
		msg += buffer;
	}
	cout << msg << '\n' << "Ключ = " << k << "\n\n";

	msg = shift(alphabet, msg, -k);
	reverse(msg.begin(), msg.end());

	cout << msg << endl;
	return 0;
}

