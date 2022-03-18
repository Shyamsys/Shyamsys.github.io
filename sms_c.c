#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>
struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    char dept[100];
    float percentage;
    struct Student *next;
    int x;
    int y;
    
}* head;
int nodecount;
void gotoxy(short x, short y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void insert(int rollnumber, char* name, char* phone, char* dept, float percentage)
{
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    strcpy(student->dept,dept);
    student->percentage = percentage;
    student->next = NULL;
    
    if(head==NULL){
        head = student;
    }
    else{
        student->next = head;
        head = student;
    }
    nodecount++;
    
}
void search(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
        	gotoxy(60,15);
        	printf("Details found! :)");
        	system("cls");
        	gotoxy(75,5);
        	printf("The Details of the entered Register Number is :");
        	gotoxy(70,9);
            printf("Roll Number: %d\n", temp->rollnumber);
            gotoxy(70,13);
            printf("Name: %s\n", temp->name);
            gotoxy(70,17);
            printf("Phone: %s\n", temp->phone);
            gotoxy(70,21);
            printf("Percentage: %0.4f\n", temp->percentage);
            gotoxy(70,25);
            printf("Department: %s\n", temp->dept);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void update(int rollnumber)
{
    
    struct Student * temp = head;
    while(temp!=NULL){
        
        if(temp->rollnumber==rollnumber){
        	system("cls");
        	gotoxy(75,5);
            printf("Record with roll number %d Found !!!\n", rollnumber);
            gotoxy(70,9);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            gotoxy(70,13);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            gotoxy(70,17);
            printf("Enter new percentage: ");
            scanf("%f",&temp->percentage);
            printf("%s", temp->dept);
            system("cls");
            gotoxy(75,25);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
        
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
    
}
void Delete(int rollnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->rollnumber==rollnumber){
            
            printf("Record with roll number %d Found !!!\n", rollnumber);
            
            if(temp1==temp2){
                head = head->next;
                free(temp1);
                nodecount--;
            }
            else{
                temp2->next = temp1->next;
                free(temp1);
				nodecount--; 
            }
            
            system("cls");
                gotoxy(75,25);
                printf("The Student's detail is deleted successfully");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    system("cls");
    gotoxy(75,25);
    printf("Student with roll number %d is not found !!!\n", rollnumber);
    
}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
	printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t");
		printf("Roll Number: %d\n\n", temp->rollnumber);
	
    printf("\t\t\t\t\t\t\t\t\t");
		printf("Name: %s\n\n", temp->name);    
	
    printf("\t\t\t\t\t\t\t\t\t");
		printf("Phone: %s\n\n", temp->phone);   
  	
  	printf("\t\t\t\t\t\t\t\t\t");
		printf("Department: %s\n\n", temp->dept);
    
    printf("\t\t\t\t\t\t\t\t\t");
		printf("Percentage: %0.4f\n\n\n", temp->percentage);
        temp = temp->next;
    
    }
    }
void intro(){
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t #####   ###  ### #######  #####              ##  ##    ###    ######    #####    #####   ##   ##  \n");
	printf("\t\t\t\t##   ##   ##  ##   ##   #   ## ##             ##  ##   ## ##    ##  ##  ### ###  ### ###  ###  ##  \n");
	printf("\t\t\t\t##         ####    ##       ##  ##            ##  ##  ##   ##   ##  ##  ##   ##  ##   ##  #### ##  \n");
	printf("\t\t\t\t #####      ##     ####     ##  ##            ######  ##   ##   #####   ##   ##  ##   ##  #######  \n");
	printf("\t\t\t\t     ##     ##     ##       ##  ##            ##  ##  #######   ## ##   ##   ##  ##   ##  ## ####  \n");
	printf("\t\t\t\t##   ##     ##     ##   #   ## ##             ##  ##  ##   ##   ## ##   ### ###  ### ###  ##  ###  \n");
	printf("\t\t\t\t #####     ####   #######  #####              ##  ##  ##   ##  #### ##   #####    #####   ##   ##  \n");
	Sleep(2000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t##   ##   ## ##   ###  ##    ##     ##   ##  ##   ##  ### ###  ### ##            ### ###   ## ##     ##     \n");
	printf("\t\t\t\t ## ##   ##   ##   ##  ##     ##     ## ##    ## ##    ##  ##   ##  ##            ##  ##  ##   ##     ##    \n");
	printf("\t\t\t\t# ### #  ##   ##   ##  ##   ## ##   # ### #  # ### #   ##       ##  ##            ##      ####      ## ##   \n");
	printf("\t\t\t\t## # ##  ##   ##   ## ###   ##  ##  ## # ##  ## # ##   ## ##    ##  ##            ## ##    #####    ##  ##  \n");
	printf("\t\t\t\t##   ##  ##   ##   ##  ##   ## ###  ##   ##  ##   ##   ##       ##  ##            ##          ###   ## ###  \n");
	printf("\t\t\t\t##   ##  ##   ##   ##  ##   ##  ##  ##   ##  ##   ##   ##  ##   ##  ##            ##  ##  ##   ##   ##  ##  \n");
	printf("\t\t\t\t##   ##   ## ##   ###  ##  ###  ##  ##   ##  ##   ##  ### ###  ### ##            ### ###   ## ##   ###  ##  \n");
	Sleep(2000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t ## ##   ###  ##  ##  ##     ##     ##   ##  \n");
	printf("\t\t\t\t\t\t\t##   ##   ##  ##  ##  ##      ##     ## ##   \n");
	printf("\t\t\t\t\t\t\t####      ##  ##  ##  ##    ## ##   # ### #  \n");
	printf("\t\t\t\t\t\t\t #####    ## ###   ## ##    ##  ##  ## # ##  \n");
	printf("\t\t\t\t\t\t\t    ###   ##  ##    ##      ## ###  ##   ##  \n");
	printf("\t\t\t\t\t\t\t##   ##   ##  ##    ##      ##  ##  ##   ##  \n");
	printf("\t\t\t\t\t\t\t ## ##   ###  ##    ##     ###  ##  ##   ##  \n");
	Sleep(2000);
	system("cls");
}

int main()
{
	system("COLOR BF");
	intro();
    head = NULL;
    main_menu();
}

int main_menu(){
	int choice;
    char name[100];
    char phone[100];
    char dept[100];
    int rollnumber;
    float percentage;
    system("COLOR 5F");
    system("cls");
    gotoxy(75,5);
    printf("WELCOME TO SMS SCHOOL");
    gotoxy(60,9);
    printf("1:  New Student's Details");
    gotoxy(60,13);
    printf("2:  Search Student's Details");
    gotoxy(60,17);
    printf("3:  Delete Student's Details");
    gotoxy(60,21);
    printf("4:  Update Student's Details");
    gotoxy(60,25);
    printf("5:  Display Students Details");
    gotoxy(60,29);
    printf("6:  Queires? Contact US :)");
    
    do
    {
    	gotoxy(120,17);
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            	system("cls");
            	gotoxy(75,5);
            	printf("SMS SCHOOL");
            	gotoxy(70,7);
            	printf("NEW STUDENT ENTRY");
            	gotoxy(60,11);
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                gotoxy(60,15);
                printf("Enter name: ");
                scanf("%s", name);
                gotoxy(60,19);
                printf("Enter phone number: ");
                scanf("%s", phone);
                gotoxy(60,23);
                printf("Enter percentage: ");
                scanf("%f", &percentage);
                gotoxy(60,27);
                printf("Enter Department: ");
                scanf("%s", dept);
                
                system("cls");
                gotoxy(75,25);
                printf("SUCCESSFULLY ADDED NEW STUDENT DETAILS");
                Sleep(1000);
                insert(rollnumber, name, phone, dept, percentage);
                main_menu();
                break;
            case 2:
            	system("cls");
            	gotoxy(75,5);
            	printf("SEARCH THE STUDENT'S DETAILS");
            	gotoxy(70,9);
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                Sleep(2000);
                main_menu();
                break;
            case 3:
            	system("cls");
            	gotoxy(75,5);
            	printf("DELETE THE STUDENT'S DETAILS");
            	gotoxy(70,9);
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                Sleep(1000);
                main_menu();
                break;
            case 4:
            	system("cls");
            	gotoxy(75,5);
            	printf("Update Student's Details");
            	gotoxy(70,9);
                printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(rollnumber);
                Sleep(1000);
                main_menu();
                break;
            case 5:
            	system("cls");
                display();
                Sleep(5000);
                main_menu();
                break;
            case 6:
            	system("cls");
            	gotoxy(75,5);
            	printf("DEVELOPERS <>");
            	gotoxy(70,9);
            	printf("M. SYED HAROON");
            	gotoxy(70,11);
            	printf("B Tech ECE II - Year");
            	gotoxy(70,13);
            	printf("Contact no :- 8610670128");
            	gotoxy(70,15);
            	printf("<------------------------------------>");
            	gotoxy(70,17);
            	printf("M. MOHAMMED ESA");
            	gotoxy(70,19);
            	printf("B Tech ECE II - Year");
            	gotoxy(70,21);
            	printf("Contact no :- 9629587974");
            	gotoxy(70,23);
            	printf("<------------------------------------>");
            	gotoxy(70,25);
            	printf("S. N. SHYAM");
            	gotoxy(70,27);
            	printf("B Tech ECE II - Year");
            	gotoxy(70,29);
            	printf("Contact no :- 8190949031");
            	gotoxy(70,31);
            	printf("<------------------------------------>");
            	Sleep(5000);
            	main_menu();
        }
        
    } while (choice != 0);
}
