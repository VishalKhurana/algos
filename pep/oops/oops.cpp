#include<iostream>
using namespace std;
class parent{
    private:
    int salary;
    int age;
    string address;
    public:
    parent(int salary,int age,string address)
    {
        this->age=age;
        this->salary=salary;
        this->address=address;
    }
    parent()
    {

    }

    void get_age()
    {
        cout<<age<<endl;
    }
     int get_salary()
    {
        return salary;
    }
     void get_address()
    {
        cout<<address<<endl;
    }
    protected:
    int a=500;

};
class child : public parent
{
public:
void disp()
{
    cout<<get_salary()<<endl;
    cout<<a<<endl;
}
protected:
 int a=500;
};

int main()
{
// child obj;
// obj.disp();
parent *l;
child ch;
l=&ch;
 parent g(45,45,"rtgf");
child obj;

obj.disp();


}
// #include <iostream>  
// using namespace std;  
//  class Account {  
//    public:  
//    float salary = 60000;   
//  };  
//    class Programmer: public Account {  
//    public:  
//    float bonus = 5000;    
//    };       
// int main(void) {  
//      Programmer p1;  
//      cout<<"Salary: "<<p1.salary<<endl;    
//      cout<<"Bonus: "<<p1.bonus<<endl;    
//     return 0;  
// }  
