


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


void login_doc()
{   system("clear");
    title();
    int input;
    int uid,flag =0;
    char cpass[20];
    FILE *ptr;

    ptr = fopen("datadoc.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    data_doc  d1;
    
    printf("\n\n\n\t\t\t\tENTER YOUR CREDENTIALS");
    printf("\n\n\n\t\t\t\tPlease Enter User Id ");
    scanf("%d",&uid);
    printf("\n\t\t\t\tPassword: ");
    scanf("%s",cpass);

    while(fread(&d1,sizeof(d1),1,ptr))
        {
        
        if(d1.id == uid)
		{
			if(strcmp(d1.pass,cpass)==0)
			{
				flag = 1;
				strcpy(cpass,d1.name);
				user1_doc(cpass); 
				break;
			}
		}
   
    
         }
         
           if(flag != 1){
		printf("\nCheck UID/Password\n");
		}
		
       fclose(ptr);
     
}


void registration_doc()
{
    system("clear");
    title();
    FILE *ptr;

    ptr = fopen("datadoc.dat","ab");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);void read_doc()
{
    FILE *ptr;

    ptr = fopen("datadoc.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    struct data_doc  d1;
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
    printf("Name : %s\n",d1.name);
    printf("Uid : %d\n",d1.id);
    printf("Password : %s\n",d1.pass);
    printf("Specilization in : %s \n",d1.spec);
    }
     
     	
       
    fclose(ptr);
}
    }

    data_doc d1;
    printf("\n\n\n\t\t\t\tCREATING AN ACCOUNT");
    printf("\n\n\n\t\t\t\tEnter Name: ");
    scanf("%s",d1.name);
    fflush(stdin);   
    printf("\n\t\t\t\tEnter User Id: ");
    scanf("%d",&d1.id);
    printf("\n\t\t\t\tEnter Password: ");
    scanf("%s",d1.pass);
    printf("\n\t\t\t\tEnter your designation: ");
    scanf("%s",d1.spec);
    d1.pre = 1;


    fwrite(&d1,sizeof(d1),1,ptr);
    
    fclose(ptr);
    
 
    log_page2();
}

void read_doc()
{
    FILE *ptr;

    ptr = fopen("datadoc.dat","rb");
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }

    data_doc  d1;
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
    printf("Name : %s\n",d1.name);
    printf("Uid : %d\n",d1.id);
    printf("Password : %s\n",d1.pass);
    printf("Specilization in : %s \n",d1.spec);
    }
     
     	
       
    fclose(ptr);
}


void log_page2()
{   
    title();
    int input;
    printf("\n\n\n\t\t\t\tDOCTOR PORTAL");
    printf("\n\n\t\t\t\tPress '1' for New User\n\t\t\t\tPress '2' for Existing User\n\n");
    printf("\n\n\t\t\tPress here to continue... ");
    scanf("%d",&input);


    if(input == 1)
        {
            registration_doc();
        }

    else if(input == 2)
        {   
            
            login_doc();
        }
    else if(input == 3)
        {
            read_doc();
        } 
}

void user1_doc(char c[])
{   
    system("clear");
    title();
    int input;
    printf("\n\n\n\t\t\t\tWELCOME: %s",c);
    printf("\n\n\t\t\t\tPress '1' to See the Schedule\n\t\t\t\tPress '2' Edit your profile\n\t\t\t\tPress '3' to exit ");
    printf("\n\n\n\t\t\tPress here to continue... ");
    scanf("%d",&input);
      if(input == 1)
        {    
            schedule(c);
        }

    else if(input == 2)
        {
            update_rec(c);
        }
    else if(input == 3)
        {
            exit(EXIT_SUCCESS);
        }

}



void schedule(char c[])
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
    
    printf("\n\n\n\tYOUR SCHEDULE: \n\n");
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
            if(strcmp(d1.doc,c)==0)
            {
                printf("\n\n Reg No.  | First Name  | Last Name  | Age | Contact No.  | Date of Appointment | Doctor");
                printf("\n\n %d      %s         %s          %d   %d         %s              %s",d1.reg,d1.fname,d1.lname,d1.age,d1.phone,d1.date,c);
                printf("\n\n-------------------------------------------------------------------------------------------------------------------------\n\n");
    
        }

}     
      fclose(ptr); 
      
    printf("\n\nPress enter key to continue....");                              
    getchar();
    getchar();
    user1_doc(c);

}

void update_rec(char c[])
{
    system("clear");
    title();
    FILE *ptr;
    FILE *ptr1;
    
    int id;
    
  
    ptr = fopen("datadoc.dat","rb+");
    
    if (ptr == NULL)
    {
       printf("\nUnable to open the file\n");
       exit(EXIT_FAILURE);
    }
    
    
    data_doc d1;
    
    again:
    
    
    
    
    while(fread(&d1,sizeof(d1),1,ptr))
        {
        
        if(strcmp(d1.name,c)==0)
		{
    
    system("clear");
    title();
    printf("\n\n\n\t\t\t\tEDIT YOUR PROFILE");
    printf("\n\n\n\t\t\t\tID No. %d: ",d1.id);
    printf("\n\n\t\t\t\tYour New Name: ");
    scanf("%s",d1.name);
    
    
    fseek(ptr, -sizeof(d1),1);
    fwrite(&d1,sizeof(d1),1,ptr);
    
    
    fclose(ptr);
    
    
    
    printf("\n\nYour profile is updated...."); 
    printf("\n\nPress enter key to continue....");                              
    getchar();
    getchar();
    user1_doc(d1.name);
    }
    
    
  
    
    }
    
    system("clear");
    title();
    fseek(ptr, 0, SEEK_SET );
    goto again; 
    
       
}



