#include<iostream>
using namespace std;
int main(){
  int total = 0;
  if(1==1) for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) for(int k = 0; k < 10; k++){
        total += 1;
      }
  cout << (total == 1000)<< endl;
  cout << (total == 100) << endl;
}
