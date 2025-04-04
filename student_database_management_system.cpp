#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct student
{
    int id;
    string name;
    int age;
    string grade;
};
void addstudent();
void displaystudent();
void deletestudent();
void searchstudent();
void updatestudent();
int main()
{
    int choice;
    while(true)
    {
        cout<<"\n___STUDENT MANAGEMENT SYSTEM___";
        cout<<"\n\n1. Add Student";
        cout<<"\n2. Display Student";
        cout<<"\n3. Search Student";
        cout<<"\n4. Update Student";
        cout<<"\n5. Delete Student";
        cout<<"\n6. Exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                addstudent();
                break;
            }
            case 2:
            {
                displaystudent();
                break;
            }
            case 3:
            {
                searchstudent();
                break;
            }
            case 4:
            {
                updatestudent();
                break;
            }
            case 5:
            {
                deletestudent();
                break;
            }
            case 6:
            {
                return 0;
            }
            default:
            {
                cout<<"Invalid choice!";
                break;
            }
        }
    }
}
void addstudent()
{
    student s;
    ofstream file("students.txt",ios::app);
    cout<<"Enter ID : ";
    cin>>s.id;
    cout<<"Enter Name : ";
    cin>>ws;
    getline(cin,s.name);
    cout<<"Enter age : ";
    cin>>s.age;
    cout<<"Enter Grade : ";
    cin>>s.grade;
    file<<s.id<<"  "<<s.name<<"  "<<s.age<<"  "<<s.grade<<endl;
    file.close();
    cout<<"Student added successfully !";
}
void displaystudent()
{
    ifstream file("students.txt");
    student s;
    cout<<"\nID  Name  Age  Grade\n-------------";
    while(file>>s.id>>ws && getline(file,s.name,' ') && file>>s.age>>s.grade)
    {
        cout<<"\n"<<s.id<<"   "<<s.name<<"    "<<s.age<<"     "<<s.grade;
    }
    file.close();
}
void searchstudent()
{
    ifstream file("students.txt");
    student s;
    int searchid;
    bool found=false;
    cout<<"Enter student id to search : ";
    cin>>searchid;
    while(file>>s.id>>ws && getline(file,s.name,' ') && file>>s.age>>s.grade)
    {
        if(s.id==searchid)
        {
            cout<<"\nID : "<<s.id<<"\nName : "<<s.name<<"\nAge : "<<s.age<<"\nGrade : "<<s.grade;
            found=true;
            break;
        }
    }
    file.close();
    if(found==false)
    {
        cout<<"Student not found ! ";
    }
}
void updatestudent()
{
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    student s;
    int searchid;
    bool found=false;
    cout<<"Enter student id to update : ";
    cin>>searchid;
    while(file>>s.id>>ws && getline(file,s.name,' ') && file>>s.age>>s.grade)
    {
        if(s.id==searchid)
        {
            cout<<"Enter New Name : ";
            cin>>ws;
            getline(cin,s.name);
            cout<<"Enter New Age : ";
            cin>>s.age;
            cout<<"Enter New Grade : ";
            cin>>s.grade;
            found=true;
        }
        temp<<s.id<<" "<<s.name<<" "<<s.age<<" "<<s.grade<<endl;
    }
    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt","students.txt");
    if(found)
    {
        cout<<"Student update successfully !";
    }
    else
    {
        cout<<"Student not found! ";
    }
}
void deletestudent()
{
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    student s;
    int searchid;
    bool found=false;
    cout<<"Enter student ID to delete : ";
    cin>>searchid;
    while(file>>s.id>>ws && getline(file,s.name,' ') && file>>s.age>>s.grade)
    {
        if(s.id==searchid)
        {
            found=true;
            continue;
        }
        temp<<s.id<<" "<<s.name<<" "<<s.age<<" "<<s.grade<<endl;
    }
    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt","students.txt");
    if(found)
    {
        cout<<"Student deleted successfully ! ";
    }
    else{
        cout<<"Student not found !";
    }
}