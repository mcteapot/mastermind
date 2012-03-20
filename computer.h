#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <set>
#include <math.h>

using namespace std;

class computer
{
     public:
         computer();
         ~computer();
         computer& operator=(computer &other);
         int random();
         int random(int lo, int hi);  
         string solver(); //return new input
         void set(int sizes, int colors); //set the sizes and amount of colors
         void currentInput(string current); //get string
         void result(int Black, int White, int order);  //current result         
         string testOutput();
            
     private: 
         string Input, Result;
         int validate;
         int color, size, index; //figure it out
         int black, white;
         char value[10];
         multiset<int> list;

         
         void nuke(); //algorithm
         void initialize(); //algorithm
         void thinking(); //algorithm
         void copy(computer &other); //need algorthm to figure out what else to copy
         void remove();
         void suicide();
         void convert();
         int convert(string item);
         void unconvert(int item);
         void compare(int test, int actual, int& White, int& Black);
};
