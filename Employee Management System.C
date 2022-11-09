/* Pogram using File handling to create a payroll system for n no. of employees
   of an organization with the following information read from keyboard:
            Employee Code
            Employee Name
            Designation
            Account number
            Date of joining
            Basic Pay
            DA
            HRA
            Deduction like EPF, LIC
        Your program should create a file to store inputted information and have the facilities as
            i. Create a Master File
            ii. List employee
            iii. Insert a new entry
            iv. Search record by employee code.

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct emp
{
    int id; // Employee Code

    char f_name[10];      // Employee first Name
    char l_name[10];      // Employee last Name
    char Desigantion[10]; // Designation
    char Ac[16];          // Account number
    char Doj[10];         // Date of joining

    float Base_pay; // Basic Pay
    float DA;       // Dearness allowance
    float HRA;      // House Rent Allowance
    float EPF;      // Deduction
    float salary;   // Total salary
} e, t;

int found = 0;
char c;

FILE *fp, *ft;

void add();
void display();
void search(int id);

void main()
{
    int choice;
    int id;

    while (1)
    {
        clrscr();
        printf("\n===============================================================================\n");
        printf("                       Welcome to Employee Management System");
        printf("\n===============================================================================\n\n");
        printf("\t\t\t\t\t\t\t- Developed by Sumit\n");

        printf("\t1. Add Records : \n");
        printf("\t2. Display Records : \n");
        printf("\t3. Search Records : \n");
        printf("\t4. Exit: \n");
        printf("\n\n");
        printf(" Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\n Enter Id : ");
            scanf("%d", &id);
            search(id);
            break;
        case 4:
            exit(0);
            break;

        default:
            printf(" ! Invalid Choice !\n");
        }
    }
}

void add()
{
    clrscr();
    fp = fopen("sumit.raj", "a");

    printf("\n===============================================================================\n");
    printf("                                  Input Data ");
    printf("\n===============================================================================\n");

    printf(" Enter Id : ");
    scanf("%d", &e.id);

    printf(" Enter First Name : ");
    scanf("%s", e.f_name);
    printf(" Enter Last Name : ");
    scanf("%s", e.l_name);
    printf(" Enter Designation : ");
    scanf("%s", e.Desigantion);
    printf(" Enter A/c No. : ");
    scanf("%s", e.Ac);
    printf(" Enter Date of Joining (DD/MM/YYYY) : ");
    scanf("%s", e.Doj);

    printf(" Enter Base Pay amount : ");
    scanf("%f", &e.Base_pay);
    printf(" Enter DA Percentage : ");
    scanf("%f", &e.DA);
    printf(" Enter HRA Percentage : ");
    scanf("%f", &e.HRA);
    printf(" Enter  EPF and Lic amount : ");
    scanf("%f", &e.EPF);

    e.salary = e.Base_pay + (e.Base_pay * (e.DA / 100));
    e.salary += e.Base_pay * (e.HRA / 100);
    e.salary -= e.EPF;

    fprintf(fp, "\n%d %s %s %s %s %s %.1f %.1f %.1f %.1f %.1f", e.id, e.f_name, e.l_name, e.Desigantion, e.Ac, e.Doj, e.Base_pay, e.DA, e.HRA, e.EPF, e.salary);
    printf("\n  - Record Added - \n");

    printf("\n\n");
    fclose(fp);
    getch();
}

void display()
{
    clrscr();
    ft = fopen("sumit.raj", "r");
    printf("\n=============================================================================\n");
    printf("  ID             Name           Desigantion             Salary");
    printf("\n=============================================================================\n\n");
    while ((c = getc(ft)) != EOF)
    {
        fscanf(ft, "\n%d %s %s %s %s %s %f %f %f %f %f", &t.id, t.f_name, t.l_name, t.Desigantion, t.Ac, t.Doj, &t.Base_pay, &t.DA, &t.HRA, &t.EPF, &t.salary);
        printf("  %-5d \t %s %-10s \t %-20s \t %.1f Rs \n\n", t.id, t.f_name, t.l_name, t.Desigantion, t.salary);
        found = 1;
    }
    if (!found)
        printf("\n !! No Record Found !!");

    printf("\n\n");
    fclose(ft);
    getch();
}
//---------------------

void search(int id)
{
    clrscr();

    ft = fopen("sumit.raj", "r");

    printf("\n=============================================================================\n");
    printf("                              Searched Records");
    printf("\n=============================================================================\n\n");

    while ((c = getc(ft)) != EOF)
    {
        fscanf(ft, "\n%d %s %s %s %s %s %f %f %f %f %f", &t.id, t.f_name, t.l_name, t.Desigantion, t.Ac, t.Doj, &t.Base_pay, &t.DA, &t.HRA, &t.EPF, &t.salary);

        if (t.id == id)
        {
            printf(" ID = %d \n\tName            = %s %s\n\tDesignation     = %s \n\tA/c no.         = %s \n\tDate of Joining = %s \n\tBase pay        = %.1f Rs\n\tDA              = %.1f %%\n\tHRA             = %.1f %%\n\tEPF             = %.1f Rs\n\tSalary          = %.1f Rs\n\n", t.id, t.f_name, t.l_name, t.Desigantion, t.Ac, t.Doj, t.Base_pay, t.DA, t.HRA, t.EPF, t.salary);

            found = 1;
        }
    }
    if (!found)
        printf("\n!! Id Not Found !!");

    printf("\n\n");
    fclose(ft);
    getch();
}
