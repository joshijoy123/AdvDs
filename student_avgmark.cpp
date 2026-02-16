#include<iostream>
using namespace std;
class student
{
    public:
        string name;
        int mark1;
        int mark2;
        int mark3;
};
int* calculate_avg(string* ptr1,int* ptr2,int* ptr3,int* ptr4)
{
    int *ptr5=new int;
    *ptr5=((*ptr2)+(*ptr3)+(*ptr4))/3;
    return ptr5;
}
int main()
{
    student s1;
    s1.name="Raju";
    s1.mark1=90;
    s1.mark2=95;
    s1.mark3=92;
    string *ptr1=&s1.name;
    int *ptr2=&s1.mark1;
    int *ptr3=&s1.mark2;
    int *ptr4=&s1.mark3;
    int *ptr5=calculate_avg(ptr1,ptr2,ptr3,ptr4);
    cout<<"average mark of"<<s1.name<<"="<<*ptr5;
}
