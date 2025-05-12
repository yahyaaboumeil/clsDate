#include <charconv>
#include <iostream>
#include <ctime>  // or #include <time.h>
#include <string>
#include <vector>
#include "clsDate.h"
#include "help.cpp"

using namespace std;


int main() {
	//clsDate D(50,202);
	vector<string> v = clsString::Split(GetDay(50, 2025), "/");
	for (string &s : v)
		cout << s << endl;
	//D.Print();
}
