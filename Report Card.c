#include<conio.h>
#include<stdio.h>
#include<process.h>

struct student
{
 int rollno;
 char name[50];
 int p_marks,c_marks,m_marks,e_marks,cs_marks;
 float per;
 char grade;
 int std;
}st;

 FILE *fptr;



void write_student()
   {
    fptr=fopen("student.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%d",&st.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(st.name);
    printf("\nEnter The marks in physics out of 100 : ");
    scanf("%d",&st.p_marks);
    printf("\nEnter The marks in chemistry out of 100 : ");
    scanf("%d",&st.c_marks);
    printf("\nEnter The marks in maths out of 100 : ");
    scanf("%d",&st.m_marks);
    printf("\nEnter The marks in english out of 100 : ");
    scanf("%d",&st.e_marks);
    printf("\nEnter The marks in computer science out of 100 : ");
    scanf("%d",&st.cs_marks);
    st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
    if(st.per>=60)
       st.grade='A';
    else if(st.per>=50 &&st.per<60)
      st.grade='B';
    else if(st.per>=33 &&st.per<50)
      st.grade='C';
    else
     st.grade='F';
    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}


void display_all()
{
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("\nRoll Number of Student : %d",st.rollno);
      printf("\nName of student : %s",st.name);
      printf("\nMarks in Physics : %d",st.p_marks);
      printf("\nMarks in Chemistry : %d",st.c_marks);
      printf("\nMarks in Maths : %d",st.m_marks);
      printf("\nMarks in English : %d",st.e_marks);
      printf("\nMarks in Computer Science : %d",st.cs_marks);
      printf("\nPercentage of student is  : %.2f",st.per);
      printf("\nGrade of student is : %c",st.grade);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}




void display_sp(int n)
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.rollno==n)
        {
         system("cls");
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in Physics : %d",st.p_marks);
            printf("\nMarks in Chemistry : %d",st.c_marks);
            printf("\nMarks in Maths : %d",st.m_marks);
            printf("\nMarks in English : %d",st.e_marks);
            printf("\nMarks in Computer Science : %d",st.cs_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nrecord not exist");
    getch();
}



void modify_student()
{
    int no,found=0;
    system("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The roll number of student");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.rollno==no)
           {
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in Physics : %d",st.p_marks);
            printf("\nMarks in Chemistry : %d",st.c_marks);
            printf("\nMarks in Maths : %d",st.m_marks);
            printf("\nMarks in English : %d",st.e_marks);
            printf("\nMarks in Computer Science : %d",st.cs_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The roll number of student ");
            scanf("%d",&st.rollno);
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            gets(st.name);
            printf("\nEnter The marks in physics out of 100 : ");
            scanf("%d",&st.p_marks);
            printf("\nEnter The marks in chemistry out of 100 : ");
            scanf("%d",&st.c_marks);
            printf("\nEnter The marks in maths out of 100 : ");
            scanf("%d",&st.m_marks);
            printf("\nEnter The marks in english out of 100 : ");
            scanf("%d",&st.e_marks);
            printf("\nEnter The marks in computer science out of 100 : ");
            scanf("%d",&st.cs_marks);
            st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
            if(st.per>=60)
               st.grade='A';
            else if(st.per>=50 && st.per<60)
               st.grade='B';
            else if(st.per>=33 && st.per<50)
               st.grade='C';
            else
               st.grade='F';
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}




void delete_student()
   {
    int no;
    FILE *fptr2;
    system("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb");

    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.rollno!=no)
       {
      fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.dat");
    rename("Temp.dat","student.dat");
    printf("\n\n\tRecord Deleted ..");
    getch();
}

void main()
{
    char ch2;
   system("cls");
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': system("cls");
          write_student();
          break;
    case '2': display_all();break;
    case '3':  {
           int num;
           system("cls");
           printf("\n\n\tPlease Enter The roll number ");
           scanf("%d",&num);
           display_sp(num);
           }
           break;
      case '4': modify_student();break;
      case '5': delete_student();break;
      case '6': break;
      default:printf("\a");entry_menu();
}
