#include "computer.h"

computer::computer()
{
    srand(time(NULL));      
    index=0;
}

computer::~computer()
{
    nuke();
}

computer& computer::operator=(computer &other)
{
   if(this != &other)
   {
      nuke();
      copy(other);
   }
   return *this;      
}

string computer::solver()
{
    if(size<=4 && size>0)
    {
        multiset<int>::iterator it;
        it=list.begin();
        unconvert(*it);
    }
    return Result;   
}

string computer::testOutput()
{
    return Result;      
}

void computer::currentInput(string current)
{
    Result=current;
    convert();
}

void computer::set(int sizes, int colors)
{
     size=sizes;
     color=colors;
     
}

void computer::result(int Black, int White, int order)
{
     black=Black;
     white=White;
     
     if(size>0 && size<=4)
     {
         if(black!=size)
         {
             if(order==1)
                thinking();
             else
                remove();
         }
         else
             nuke();
     }
     else
         suicide();
}           

void computer::nuke()
{
     list.clear();
}

void computer::initialize()
{}

void computer::thinking()
{
     int tempBlack=black, tempWhite=white;
     for(int a=1; a<=color; a++)
        for(int b=1; b<=color; b++)
           for(int c=1; c<=color; c++)
               for(int d=1; d<=color; d++)
               {
                    int testing=1331*a + 121*b + 11*c + d; 
                    compare(testing, validate, white, black); 
                    if (black == tempBlack && white == tempWhite)
                      list.insert(testing);
               }
     black=tempBlack; white=tempWhite;
}

void computer::remove()
{
     int tempBlack=black, tempWhite=white;
     multiset<int>::iterator it=list.begin(), data;
     while(it != list.end())
     {
         compare(*it, validate, white, black);
         if (tempBlack != black || tempWhite != white)
         {
            data=it;
            list.erase(data);
            it=list.begin();
         }
         else
            it++;
     }
     black=tempBlack; white=tempWhite;
}

void computer::compare(int test, int actual, int& White, int& Black)
{
     int guess[4], real[4]; 
     for (int i = 0; i < 4; i++)
     { 
         guess[i] = test % 11;
         test /= 11;
         real[i] = actual % 11;
         actual /= 11;
     }
     Black=0;
     for (int i = 0; i < 4; i++)
     {
       if (guess[i] == real[i])
       { 
             Black++;
             guess[i] = 54;      
             real[i] = 17;
       }
     }
     White = 0;
     for (int i = 0; i < 4; i++)
     {
       for (int j = 0; j < 4; j++)
          if (guess[i] == real[j])
          { 
                White++;
                guess[i] = 19;
                real[j]  = 33;
          }
     }
}

void computer::convert()
{
     validate=0;
     for(int i=0; i<size; i++)
        validate+=((pow(11,i))*(Result[i]-'0'+1));
}

int computer::convert(string item)
{
     int random=0;
     for(int i=0; i<size; i++)
        random+=((pow(11,i))*(item[i]-'0'+1));
     return random; 
}

void computer::unconvert(int item)
{
    Result="";
    value[0]='\0';
    for(int i=0; i<size; i++)
    {
        value[i]=(char)(((int)'0')+((item%11)-1)); //convert 0 to ascii value and add it and convert it to char
        item=item/11;                        //this convert and int value into char value
    }
    value[size]='\0';
    Result=value;
}

int computer::random()
{
   return rand()%(color-1);  
} 

void computer::suicide()
{
    Result="";
    value[0]='\0';
    for(int i=0; i<size; i++)
        value[i]=(char)(((int)'0')+random());
    value[size]='\0';
    Result=value;
}

void computer::copy(computer &other)
{
    Input=other.Input;
    Result=other.Result;
    validate=other.validate;
    color=other.color; 
    size=other.size;
    index=other.index;
    black=other.black; 
    white=other.white;
    list=other.list; 
} 

int computer::random(int lo, int hi)
{
    int i=rand()%hi;
    return (i<lo) ?  i+lo : i;
}
