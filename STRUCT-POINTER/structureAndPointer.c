#include<stdio.h>
#include<string.h>

int main(){
  
    struct student
    {
        char name[50];
        int age;
    };

    struct student student,student2;
    struct student *s1 = &student;
    struct student *s2 = &student2;
    

    strcpy(s1->name, "zakir mustafa");
    s1->age = 20;
    
    printf("The name is %s and age is %d : \n",s1->name,s1->age);
   
    printf("Enter the name : ");
    gets(s2->name);
    printf("Enter the age : ");
    scanf("%d",&s2->age);

    printf("The entered name is %s and entered age is %d : \n",s2->name,s2->age);


    return 0;

}