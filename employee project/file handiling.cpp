#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class employee
{
    private:
    char id[10];
    char name[20];
    char post[20];
    char qualification[20];
    char address[50];
    public:
    employee()
    {
    strcpy(name,"NULL");
    strcpy(post,"NULL");
    strcpy(qualification,"NULL");
    strcpy(address,"NULL");
    }
    void getdata();
    void putdata();
    int storeemployee();
    void seelist();
    void search(char *);
    void delet(char *);
    void update(char *);
};
void employee::getdata()
{
    cout<<"\n enter the id of employee:";
    gets(id);
    cout<<"\n enter the name of employee:";
    gets(name);
    cout<<"\n enter the post of employee:";
    gets(post);
    cout<<"\n enter the qualification of employee:";
    gets(qualification);
    cout<<"\n enter the address of employee:";
    gets(address);
}
void employee::putdata()
{
    cout<<"\n_________________________\n";
    cout<<" id-"<<id;
    cout<<"\n name-"<<name;
    cout<<"\n post-"<<post;
    cout<<"\n qualification-"<<qualification;
    cout<<"\n address -"<<address<<"\n\n";
}
int employee::storeemployee()
{
    ofstream fout;
    getdata();
    fout.open("employee.dat",ios::app|ios::binary);
    fout.write((char *)this,sizeof(*this));
    fout.close();
    return(1);
}
void employee::seelist()
{
    ifstream fin;
    fin.open("employee.dat",ios::in|ios::binary);
    if(!fin)
    cout<<"\nfile not found!\n";
    else
    {
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())           //end of file
    {
    putdata();
    fin.read((char *)this,sizeof(*this));
    }
    fin.close();
    }
}
void employee::search(char *t)
{
    int flag=0;
    ifstream fin;
    fin.open("employee.dat",ios::in|ios::binary);
    if(!fin)
    cout<<"\nfile not found\n";
    else
    {
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
    if(!strcmp(t,id))
    {
    putdata();
    flag=1;
    }
    fin.read((char *)this,sizeof(*this));
    }
    if(flag==0)
    cout<<"\nnot found!\n";
    fin.close();
    }
}
void employee::delet(char *t)
{
    ifstream fin;
    ofstream fout;
    fin.open("employee.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"\nfile not found\n";
    else
    {
    fout.open("tempfile.dat",ios::out|ios::binary);
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
    if(strcmp(id,t))
    fout.write((char*)this,sizeof(*this));
    fin.read((char *)this,sizeof(*this));
    }
    fin.close();
    fout.close();
    remove("employee.dat");
    rename("tempfile.dat","employee.dat");
    }
}
void employee::update(char *t)
{
    fstream file;
    file.open("employee.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
    if(!strcmp(t,id))
    {
    getdata();
    file.seekp(file.tellp()-sizeof(*this));
    file.write((char*)this,sizeof(*this));
    }
    file.read((char*)this,sizeof(*this));
    }
    file.close();
}
int main()
{

    employee e1;
    int choice;
    char a[10];
  cout<<"*******HEY WELCOME TO EMPLOYEE DATA MANAGMENT SYSTEM*******\n\n\n";
  while(1)
  {
  cout<<"ENTER 1 TO ADD NEW PROFILE.\n";
  cout<<"ENTER 2 TO SEE ALL THE PROFILE.\n";
  cout<<"ENTER 3 TO SEARCH A PROFILE.\n";
  cout<<"ENTER 4 TO DELETE A PROFILE.\n";
  cout<<"ENTER 5 TO UPDATE A PROFILE.\n";
  cout<<"ENTER 0 TO EXIT.\n";
   cout<<"\n ENTER YOUR CHOICE:";
   cin>>choice;
   cout<<"\n";
   switch(choice)
   {
   case 1:
    e1.storeemployee();
    cout<<"\n THE PROFILE IS ADDED SUCCESSFULLY\n";
    break;
   case 2:
    e1.seelist();
    break;
   case 3:
    cout<<"\n ENTER THE ID OF EMPLOYEE:";
    cin.ignore();
    gets(a);
    e1.search(a);
    break;
   case 4:
    cout<<"\n ENTER THE ID OF EMPLOYEE:";
    cin.ignore();
    gets(a);
    e1.delet(a);
    break;
   case 5:
    cout<<"\n ENTER THE ID OF EMPLOYEE:";
    cin.ignore();
    gets(a);
    e1.update(a);
    break;
   case 0:
    return 0;
    break;
   default:
    cout<<"PLEASE ENTER A VALLID OPTION";
    break;
   }
    }
    return(0);
}
