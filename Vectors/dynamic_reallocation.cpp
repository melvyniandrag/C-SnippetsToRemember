/*
This bit of code show the amount of time taken by a simple vector class to dynamically reallocate mmemory. 

We will have two classes, one which doubles the size of the array, and another which adds a constant amount of elements. 
 
Compilation instructions;

g++ -std=c++11 dynamic_reallocation.cpp -o da.out

View the results with gnuplot.  In a terminal:

gnuplot gnuplot_script. 

Then look at the "slow.png" and "fast.png" images.
*/

#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

class VectorSlow{
  int size;
  int new_size;
  short * items;
  int num_items;

  void resize(){
    new_size = size + 10;
    short * new_vec = new short[new_size];
    for(int i = 0; i < size; ++i){
      new_vec[i] = items[i];
    }
    delete[] items;
    items = new_vec;
    size = new_size;
  }

public:
  VectorSlow(){
    items = new short[2];
    items[0] = 1;
    items[1] = 1;
    num_items = 2;
    size = 2;
  }

  void push_back(short item){
    if((num_items) == size){
      resize();
    }
    items[num_items] = item;
    num_items += 1;
  }

  void print(){
    for(int i = 0; i < num_items; i++){
      cout << items[i] << " " << endl;
      if((i+1) % 10 == 0) { cout << endl;}
    }
  }

  void print_size(string time){
    cout << "My " + time + " size is " << size << endl;
  }

  void clear(){
    delete[] items;
    size = 2;
    num_items = 2;
    items = new short[size];
    items[0] = 1;
    items[1] = 1;
  }


};

class VectorFast{  
  int size;
  int new_size;
  short * items;
  int num_items;

  void resize(){
    new_size = 2*size;
    short * new_vec = new short[new_size];
    for(int i = 0; i < size; ++i){
      new_vec[i] = items[i];
    }
    delete[] items;
    items = new_vec;
    size = new_size;
  }

public:
  VectorFast(){
    items = new short[2];
    items[0] = 1;
    items[1] = 1;
    num_items = 2;
    size = 2;
  }

  void push_back(short item){
    if((num_items) == size){
      resize();
    }
    items[num_items] = item;
    num_items += 1;
  }

  void print(){
    for(int i = 0; i < num_items; i++){
      cout << items[i] << " " << endl;
      if((i+1) % 10 == 0) { cout << endl;}
    }
  }

  void print_size(string time){
    cout << "My " + time + " size is " << size << endl;
  }

  void clear(){
    delete[] items;
    size = 2;
    num_items = 2;
    items = new short[size];
    items[0] = 1;
    items[1] = 1;
  }

};

int main(){
  clock_t t0, t1;

  ofstream fout;

  fout.open("vec_slow.dat");
  VectorSlow a;
  for(auto num_elems : {100, 1000, 5000, 10000, 15000, 30000}){
    t0 = clock();
    for(int i = 0; i < num_elems; i++){
      a.push_back(1);
    }
    t1 = clock();
    fout << num_elems*num_elems << " " << ((float)(t1 - t0))/CLOCKS_PER_SEC << endl;
    a.clear();
  }
  fout.close();

  fout.open("vec_fast.dat");
  VectorFast b;
  for(auto num_elems : {100, 1000, 5000, 10000, 15000, 30000}){
    t0 = clock();
    for(int i = 0; i < num_elems; i++){
      b.push_back(1);
    }
    t1 = clock();
    fout << num_elems << " " << ((float)(t1 - t0))/CLOCKS_PER_SEC << endl;
    b.clear();
  }
  fout.close();
}
