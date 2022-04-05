

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "structure.h"
#include "launch.h"
#include "emplyoee.h"
#include "doctor.h"
#include "patient.h"
#include "func1.h"


void read_pt(char c[])
{
    system("clear");
    title();
    FILE *ptr;

    ptr = fopen("patient.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    data_pt  d1;
    
    printf("\n\n\n\tPATIENT RECORDS: \n\n");
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
                printf("\n\n Reg No.  | First Name  | Last Name  | Age | Contact No.  | Date of Appointment | Doctor");
                printf("\n\n %d      %s         %s          %d   %d         %s              %s",d1.reg,d1.fname,d1.lname,d1.age,d1.phone,d1.date,d1.doc);
                printf("\n\n-------------------------------------------------------------------------------------------------------------------------\n\n");
    }
    
    printf("\n\nPress enter key to continue....");                              
    getchar();
    getchar();
    user1_emp(c);
}

void add_rec(char c[])
{
    system("clear");
    title();
    FILE *ptr;
  
    ptr = fopen("patient.dat","ab");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
    
    
    data_pt d1;
    
    
    printf("\n\n\n\t\t\t\tADD PATIENT RECORD");
    printf("\n\n\n\t\t\t\tRegistration No.: ");
    scanf("%d",&d1.reg);
    printf("\n\t\t\t\tFirst Name: ");
    scanf("%s",d1.fname);
    fflush(stdin);
    printf("\n\t\t\t\tLast Name: ");
    scanf("%s",d1.lname);
    printf("\n\t\t\t\tAge: ");
    scanf("%d",&d1.age);
    printf("\n\t\t\t\tContact No: ");
    scanf("%d",&d1.phone);
    printf("\n\t\t\t\tSymptoms: ");
    scanf("%s",d1.symptoms);
    printf("\n\t\t\t\tDate of Appointment: ");
    scanf("%s",d1.date);
    printf("\n\t\t\t\tDoctor: ");
    scanf("%s",d1.doc);
    
     fwrite(&d1,sizeof(d1),1,ptr);
    
     fclose(ptr);
     
     display(d1.reg,d1.fname,d1.lname,d1.age,d1.phone,d1.date,d1.doc,c) ;
       
}

void search_rec(char c[])
{
    system("clear");
    title();
    FILE *ptr;
    
    int id;
    
  
    ptr = fopen("patient.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
    
    
    data_pt d1;
    
    again:
    fseek(ptr, 0, SEEK_SET );
    printf("\n\n\n\t\t\t\tSEARCH PATIENT RECORD");
    printf("\n\n\t\t\t\tEnter the Registration No. ");
    scanf("%d",&id);
    
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
        
        if(d1.reg==id)
		{
    system("clear");
    title();
    
    fclose(ptr);
    
    display0(d1.reg,d1.fname,d1.lname,d1.age,d1.phone,d1.date,d1.doc,c) ;
    
    
    
    printf("\n\nPress enter key to continue....");                              
    getchar();
    getchar();
    user1_emp(c);
    }
    
    
       
         
}
      system("clear");
      title();
      
      goto again;
}


void edit_rec(char c[])
{
    system("clear");
    title();
    FILE *ptr;
    FILE *ptr1;
    
    int id;
    
  
    ptr = fopen("patient.dat","rb+");
    
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
    
    
    data_pt d1;
    
    again:
    printf("\n\n\n\t\t\t\tEDIT PATIENT RECORD");
    printf("\n\n\t\t\t\tEnter the Registration No. ");
    scanf("%d",&id);
    
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
        
        if(d1.reg==id)
		{
    
    system("clear");
    title();
    printf("\n\n\n\t\t\t\tEDIT PATIENT RECORD");
    printf("\n\n\n\t\t\t\tRegistration No. %d: ",d1.reg);
    printf("\n\n\t\t\t\tFirst Name: ");
    scanf("%s",d1.fname);
    printf("\n\t\t\t\tLast Name: ");
    scanf("%s",d1.lname);
    printf("\n\t\t\t\tAge: ");
    scanf("%d",&d1.age);
    printf("\n\t\t\t\tContact No: ");
    scanf("%d",&d1.phone);
    printf("\n\t\t\t\tSymptoms: ");
    scanf("%s",d1.symptoms);
    printf("\n\t\t\t\tDate of Appointment: ");
    scanf("%s",d1.date);
    printf("\n\t\t\t\tDoctor: ");
    scanf("%s",d1.doc);
    
    fseek(ptr, -sizeof(d1),1);
    fwrite(&d1,sizeof(d1),1,ptr);
    
    
    fclose(ptr);
    
    
    
    
    printf("\n\nPress enter key to continue....");                              
    getchar();
    getchar();
    user1_emp(c);
    }
    
    
  
    
    }
    
    system("clear");
    title();
    fseek(ptr, 0, SEEK_SET );
    goto again; 
    
       
}

void dis_doc(char c[])
{
    system("clear");
    title();
    FILE *ptr;

    ptr = fopen("datadoc.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    data_doc  d1;
    
    printf("\n\n\n\tDOCTOR RECORDS: \n\n");
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
                printf("\n ID No.  |  Name            |   Specialists in ");
                printf("\n\n %d      %s               %s        ",d1.id,d1.name,d1.spec);
                printf("\n\n-------------------------------------------------------------------------------------------------------------------------\n");
    }
    
    printf("\n\nPress enter key to continue....");                              
    getchar();
    getchar();
    user1_emp(c);
}


