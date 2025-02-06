#include<stdio.h>
struct student{
 char name[50];
 int id;
 float math;
 float english;
 float spl;
 float spl_lab;
};

int main(){

struct student student1,student2,student3;

printf("enter the number student1\n:");

printf("student name:");
scanf("%s",&student1.name);

printf("student id:");
scanf("%d",&student1.id);

printf("enter the student gread input grad:\n");

printf("math gread=");
scanf("%f",&student1.math);

printf("english gread=");
scanf("%f",&student1.english);

printf("spl gread=");
scanf("%f",&student1.spl);

printf("spl lab gread=");
scanf("%f",&student1.spl_lab);




printf("the number of studen1 :\n");
printf("student name:%s\n",student1.name);
printf("student id:%d\n",student1.id);

printf("student math :%f\n",student1.math);
printf("student english :%f\n",student1.english);
printf("student spl :%f\n",student1.spl);
printf("student spl lab:%f\n",student1.spl_lab);



printf("enter the number student2\n:");

printf("student name:");
scanf("%s",&student2.name);

printf("student id:");
scanf("%d",&student2.id);

printf("enter the student gread input grad:\n");

printf("math gread=");
scanf("%f",&student2.math);

printf("english gread=");
scanf("%f",&student2.english);

printf("spl gread=");
scanf("%f",&student2.spl);

printf("spl lab gread=");
scanf("%f",&student2.spl_lab);




printf("the number of studen2 :\n");
printf("student name:%s\n",student2.name);
printf("student id:%d\n",student2.id);

printf("student math :%f\n",student2.math);
printf("student english :%f\n",student2.english);
printf("student spl :%f\n",student2.spl);
printf("student spl lab:%f\n",student2.spl_lab);


printf("enter the number student3\n:");

printf("student name:");
scanf("%s",&student3.name);

printf("student id:");
scanf("%d",&student3.id);

printf("enter the faculty input grad:\n");

printf("math gread=");
scanf("%f",&student3.math);

printf("english gread=");
scanf("%f",&student3.english);

printf("spl gread=");
scanf("%f",&student3.spl);

printf("spl lab gread=");
scanf("%f",&student3.spl_lab);




printf("the number of studen3 :\n");
printf("student name:%s\n",student3.name);
printf("student id:%d\n",student3.id);

printf("student math :%f\n",student3.math);
printf("student english :%f\n",student3.english);
printf("student spl :%f\n",student3.spl);
printf("student spl lab:%f\n",student3.spl_lab);



getch();


}
