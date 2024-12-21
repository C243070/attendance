#include<stdio.h>

int main()
{
    struct test
    {
        int age;
        char section;
    };
    
    struct test mylist;

    printf("enter the age:");
    scanf("%d",&mylist.age);
    printf("%d",mylist.age);
}