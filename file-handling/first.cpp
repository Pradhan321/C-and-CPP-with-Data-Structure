#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void writing()
{
  ofstream fout;
  fout.open("file.txt",ios::out);
  char str[]="Hello, My name is Avinash Pradhan";
  fout<<str;
  fout.close();
}

void reading()
{
  ifstream fin;
  char ch;
  fin.open("file.txt",ios::in);
  if(!fin)
  {
    cout<<"File not Found";
  }
  else
  {
    ch=fin.get();
    while(!fin.eof())
    {
    cout<<ch;
    ch=fin.get();
    }
  }
  fin.close();
}
void append(char str[])
{
 ofstream fout;
 fout.open("file.txt",ios::app);
 fout<<str;
 fout.close();

}
int main(){
  // writing();
  char str[]="Bhai kaise ho app";
  append(str);
  cout<<endl;
  
  reading();
  cout<<endl;
  return 0;
}