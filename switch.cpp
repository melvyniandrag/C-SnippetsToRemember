#include <iostream>
using namespace std;

const string f = "first line";
const string s = "second line";
int main(){
	int one = 1;
	switch(one){
		case 10:
			cout << "a" << endl;
			cout << f << endl;
			cout << s << endl;
		case 1:
			cout << "b" << endl;
			cout << f << endl;
			cout << s << endl;
	}
	int ten = 10;
	switch(ten){
		case 0:
			cout << "c" << endl;
			cout << f << endl;
			cout << s << endl;
			break;
		case 10:
			cout << "d" << endl;
			cout << f << endl;
			cout << s << endl;
			break;
		case 20:
			cout << "e" << endl;
			cout << f << endl;
			cout << s << endl;		
	}

}