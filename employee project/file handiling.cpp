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
    cout<<"file not found!";
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
    cout<<"\nfile not found";
    else
    {
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
    if(!strcmp(t,name))
    {
    putdata();
    flag=1;
    }
    fin.read((char *)this,sizeof(*this));
    }
    if(flag==0)
    cout<<"\nnot found!";
    fin.close();
    }
}
void employee::delet(char *t)
{
    ifstream fin;
    ofstream fout;
    fin.open("employee.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"\nfile not found";
    else
    {
    fout.open("tempfile.dat",ios::out|ios::binary);
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
    if(strcmp(name,t))
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
    if(!strcmp(t,name))
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
    //e1.getdata();
    //e1.putdata();
    //e1.storeemployee();
    e1.seelist();
   //e1.search("SHIVAM");
  //e1.delet("NULL");
  //e1.update("SHIVAM");
    return(0);
}
