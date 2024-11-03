#include<stdio.h>
#include<string.h>

// in c structure is a custom/user-defined data type that allows us to group different data types together under a single name.
// structure is useful when you want to store and manage related data as one unit.

int main(){

    // define the structure
    struct student
    {
        char name[50];
        int age;
        float marks;
    };

    //Declare Variables of the Structure
    struct student s1;

    // Assign values
    strcpy(s1.name,"zakir");
    s1.age = 20;
    s1.marks = 8.6;

    // Accessing values
    printf("Name is : %s \n",s1.name);
    printf("Age is : %d \n",s1.age);
    printf("Marks is : %f  \n",s1.marks);
    
    return 0;
}

