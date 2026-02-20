#include<iostream>
#include<fstream>
using namespace std;

class Book{
  private:
    char title[20];
    int price;
    int id;
  public:
    void inputBook(){
      cout<<"Enter the Book Id : ";
      cin>>id;
      cout<<"Enter the title of the Book : ";
      cin.ignore();
      cin.getline(title,20);
      cout<<"Enter the price of the book : ";
      cin>>price;

    }
    void displayBook(){
      cout<<id<<" "<<title<<" "<<price<<endl;
    }
    void store();
    void ViewAllBooks();
};
void Book::store(){
  ofstream fout;
  fout.open("Book.dat",ios::app|ios::binary);
  fout.write((char*)this,sizeof(*this));
  fout.close();
}
void Book::ViewAllBooks()
{
  ifstream fin;
  fin.open("Book.dat",ios::in|ios::binary);
  if(!fin)
  {
    cout<<"File not Found";
  }
  else{
  fin.read((char*)this,sizeof(*this));
  while(!fin.eof())
  {
    displayBook();
    fin.read((char*)this,sizeof(*this));

  }
}
fin.close();
}
int menu(){
  int choice;
  cout<<"\n1 : Store new Book records";
  cout<<"\n2 : View all Book records";
  cout<<"\n3 : Exit";
  cout<<"\nEnter your choice : ";
  cin>>choice;
  return choice;
}
int main(){
  Book b1;
  while(true)
  {
  switch(menu())
  {
    case 1: b1.inputBook();
            b1.store();
            break;
    case 2: b1.ViewAllBooks();
            break;
    case 3: exit(0);
    default: cout<<"Invalid Choice";
  }
}
}