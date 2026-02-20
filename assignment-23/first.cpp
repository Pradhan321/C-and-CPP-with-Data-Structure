#include <iostream>
#include<string>
using namespace std;

bool check_palindrome(string s1)
{
  string original = s1;
  int len = s1.length();
  for (int i = 0; i < len / 2; i++)
  {
    char temp = s1[i];
    s1[i] = s1[len - 1 - i];
    s1[len - 1 - i] = temp;
  }
  return (s1 == original);
}

string trim_string(string s)
{
  string newString = "";
  int len = s.length();
  for (int i = 0; i < len; i++)
  {
    if (isalnum(s[i]))
    {
      newString += tolower(s[i]);
    }
  }
  return newString;
}

int count_words(string s)
{
int len=s.length();
int WordCount=0;
bool inword=false;
for(int i=0;i<len;i++)
{
  if(s[i]!=' '&&!inword)
  {
    WordCount++;
    inword=true;
  }
  else if(s[i]==' '){
    inword=false;
  }
}
return WordCount;
}
string reverse_word(string s)
{
  int len=s.length();
  string word="";
  string words[100];
  int wordCount=0;
  for(int i=0;i<len;i++)
  {
    if(s[i]!=' ')
    {
      word+=s[i];
    }
    else if(!word.empty()){
      words[wordCount++]=word;
      word="";
    }
  }
  if(!word.empty()){
    words[wordCount++]=word;
  }
  string result="";
  for(int i=wordCount-1;i>=0;i--)
  {
    result+=words[i];
    if(i>0)
    {
      result+=" ";
    }
  }
  return result;
}
bool check_insensitive_comparison(string first,string second)
{
  int len_first=first.length();
  int len_second=second.length();
  if(len_first!=len_second){
    return false;
  }
  for(int i=0;i<len_first;i++)
  {
   first[i]=tolower(first[i]);
   second[i]=tolower(second[i]);
  }
  return (first==second);
}

void frequency(string s)
{
  int len=s.length();
  char freq[128]={0};
  for(int i=0;i<len;i++)
  {
   freq[s[i]]++;
  }
  for(int i=0;i<128;i++)
  {
    if(freq[i]!=0)
    {
      cout<<"occurance of "<< (char)i<<" is : "<<(int)freq[i]<<endl;
    }
  }
}
bool find_word(string s,string w)
{
   int len=s.length();
  string word="";
  string words[100];
  int wordCount=0;
  for(int i=0;i<len;i++)
  {
    if(s[i]!=' ')
    {
      word+=s[i];
    }
    else if(!word.empty()){
      words[wordCount++]=word;
      word="";
    }
  }
  if(!word.empty()){
    words[wordCount++]=word;
  }
  for(int i=0;i<wordCount;i++)
  {
    if(words[i]==w)
    {
      return true;
    }
  }
  return false;
}
string make_first_capital(string s)
{
  int len=s.length();
  bool newword=true;
  for(int i=0;i<len;i++)
  {
    if(s[i]==' ')
    {
      newword=true;
    }
    else if(newword){
      s[i]=toupper(s[i]);
      newword=false;
    }
  }
  return s;
}
string acronym_name(string s)
{
    int len = s.length();
    string result = "";
    bool newword = true;
    string currentWord = "";

    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            if (!currentWord.empty()) {
                // For non-last words, add only first letter
                result += toupper(currentWord[0]);
                result += ' ';
                currentWord.clear();
            }
            newword = true;
        }
        else
        {
            if (newword) {
                currentWord = ""; // reset for new word
                newword = false;
            }
            currentWord += s[i]; // build the word
        }
    }

    // Handle the last word fully
    if (!currentWord.empty()) {
        currentWord[0] = toupper(currentWord[0]);
        result += currentWord;
    }

    return result;
}

string concatenate(string s,string s1)
{
  
  s+=' ';
    s+=s1;
  
 
  return s;
}
int main()
{
  string s,s1;
  cout << "Enter the string : ";
  getline(cin, s);
  cout << "Enter the word : ";
  getline(cin, s1);
  // if (check_palindrome(s))
  // {
  //   cout << "Your string is palindrome";
  // }
  // else
  // {
  //   cout << "Your string is not palindrome";
  // }
  // cout<<"\nYour Trimed String is : "<<trim_string(s);
  // cout<<"\nTotal words in your string : "<<count_words(s);
  // cout<<"\nYour String in reversed version : "<<reverse_word(s);
//  if(check_insensitive_comparison(s,s1))
//  {
//   cout<<"String are equal (case-insensitive)";
//  }
//  else{
//   cout<<"String are not equal";
//  }
  // frequency(s);
  // if(find_word(s,s1))
  // {
  //   cout<<"word is present in string.";
  // }
  // else{
  // cout<<"word is not present in string.";
  // }
  // cout<<"Your modified string is : "<<make_first_capital(s);
  // cout<<"Your modified string is : "<<acronym_name(s);
  cout<<"Your modified string is : "<<concatenate(s,s1);
}