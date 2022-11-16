#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{TRUE,FALSE} boolean;
#define SIZE 20

struct personal
{
    char first_name[SIZE];
    char last_name[SIZE];
    char email[50];
    int number;
    struct personal* next;
};

struct professional
{
    char first_name[SIZE];
    char last_name[SIZE];
    char email[20];
    char office_name[20];
    char office_address[20];
    char office_type[20];
   int  office_number;
    struct professional* next;
};
struct call
{
    char name[SIZE];
    
    int number;
    char address[20];
    int calls,total,duration;
    struct call* next;
    struct personal* pers_lptr;
    struct professional* prof_lptr;
  
};

struct personal* createlist_personal( struct personal* list_ptr)// creation of personal
{
    struct personal* nptr;
    char first_name[10], last_name[10], email[20];
    int number;
    nptr= NULL;
    
    printf("Enter the personal contact deails : \n");

    {
        nptr = (struct personal*) malloc(sizeof(struct personal));// creating dynamic memory allocation using malloc
        printf("first name : ");
        scanf("%s",first_name);
        printf("last name : ");
        scanf("%s",last_name);
        printf("email : ");
        scanf("%s",email);
        printf("number : ");
        scanf("%d",&number);
        strcpy( nptr->first_name , first_name);// copies from string to node
        strcpy ( nptr->last_name , last_name);
        strcpy ( nptr->email ,email);
        nptr->number = number;
        nptr->next = list_ptr;
        list_ptr = nptr;//changes and runs the loop for saving new details in node
    }

    return list_ptr;// return back to main
   
}

struct professional* createlist_professional( struct professional* list_ptr)// creation of professional list
{
    struct professional* nptr;
    char first_name[10], last_name[10], email[20], office_name[20], office_address[20],office_type[20];
    int office_number;
    nptr= NULL;
    
    printf("Enter the professional contact deails : \n");
   
    
        nptr = (struct professional*) malloc(sizeof(struct professional));
        printf("first name : ");
        scanf("%s",first_name);
        printf("last name : ");
        scanf("%s",last_name);
        printf("email : ");
        scanf("%s",email);
        printf("office name : ");
        scanf("%s",office_name);
        printf("office address : ");
        scanf("%s",office_address);
        printf("office number : ");
        scanf("%d",&office_number);
        printf("office Type :");
        scanf("%s",office_type);
        strcpy(nptr->first_name , first_name);
        strcpy(nptr->last_name , last_name);
        strcpy(nptr->email , email);
        strcpy(nptr->office_name , office_name);
        strcpy(nptr->office_address , office_address);
        strcpy(nptr->office_type, office_type);
        nptr->office_number = office_number;
        nptr->next = list_ptr;
        list_ptr = nptr;
    
    return list_ptr;
}

void displaypersonal(struct personal* list_ptr)// display function to show the current node of personal
{
    printf("First name : %s\n",list_ptr->first_name);
    printf("Last name : %s\n",list_ptr->last_name);
    printf("Email id : %s\n",list_ptr->email);
    printf("personal number : %d\n",list_ptr->number);
}
void displayprofessional(struct professional* list_ptr) // // display function to show the current node of professional
{
    printf("First name : %s\n",list_ptr->first_name);
    printf("Last name : %s\n",list_ptr->last_name);
    printf("Email id : %s\n",list_ptr->email);
    printf("Office name : %s\n",list_ptr->office_name);
    printf("Office address : %s\n",list_ptr->office_address);
    printf("Office number : %d\n",list_ptr->office_number);
    printf("Oficce Type : %s \n",list_ptr->office_type);
}
void printReverse_personal(struct personal* list_ptr)   //personal reverse printing
{
    if (list_ptr == NULL)     // Base case
           return;
 
    printReverse_personal(list_ptr->next);
    displaypersonal(list_ptr);
    
}
void printReverse_professional(struct professional* list_ptr)   //professional reverse function
{
    if (list_ptr == NULL)     // Base case
           return;
 
    printReverse_professional(list_ptr->next);
    displayprofessional(list_ptr);
    
}

void full_display_personal(struct personal* list_ptr)    //personal full display until end
{
    while(list_ptr != NULL) // until the last node points null
    {
        displaypersonal(list_ptr);
        list_ptr = list_ptr->next;
    }
}

void full_display_professional(struct professional* list_ptr)       //professional full display
{
    while(list_ptr != NULL)
    {
        displayprofessional(list_ptr);
        list_ptr = list_ptr->next;
    }
}

//delete list by name

struct personal* deletelist_personal(struct personal* list_ptr, char del_byname[20])    //personal delete function
{
    struct personal *ptr, *temp = list_ptr->next;
    struct personal *prev , *rptr;
    struct personal* nochange_ptr = list_ptr;
    
    if(strcmp(list_ptr->first_name,del_byname) == 0)
    {    ptr = list_ptr;
        rptr = list_ptr->next;
        free(ptr);
        return rptr;
    }
    else
    {
        while(temp != NULL )
        {
            if(strcmp(temp->first_name,del_byname) == 0 )
            {    prev = list_ptr;
                prev->next = temp->next;
                ptr = temp;
                temp = temp->next;
                list_ptr = list_ptr->next;
                free(ptr);
            }
            else
            {    prev = list_ptr;
                temp = temp->next;
                list_ptr = list_ptr->next;
            }
        }
        return nochange_ptr;
    }
}

struct professional* deletelist_professional(struct professional* list_ptr, char del_byname[20])  //professional
{
    struct professional *ptr, *temp = list_ptr->next;
    struct professional *prev , *rptr;
    struct professional* nochange_ptr = list_ptr;
    
    if(strcmp(list_ptr->first_name,del_byname) == 0)
    {
        ptr = list_ptr;
        rptr = list_ptr->next;
        free(ptr);
        return rptr;
    }
    else
    {
        while(temp != NULL )
        {
            if(strcmp(temp->first_name,del_byname) == 0 )
            {
                prev = list_ptr;
                prev->next = temp->next;
                ptr = temp;
                temp = temp->next;
                list_ptr = list_ptr->next;
                free(ptr);
            }
            else
            {
                prev = list_ptr;
                temp = temp->next;
                list_ptr = list_ptr->next;
            }
        }
        return nochange_ptr;
    }
}

// delete list by number

struct personal* deletelist_personal_bynum(struct personal* list_ptr, int num)
{
    struct personal *ptr, *temp = list_ptr->next;
    struct personal *prev ;
    struct personal* nochange_ptr = list_ptr;
    
    if(list_ptr->number == num)
    {
        temp = list_ptr;
        list_ptr = list_ptr->next;
        free(temp);
        return list_ptr;
    }
    else
    {
        while(temp != NULL )
        {
            if(temp->number == num)
            {
                prev = list_ptr;
                prev->next = temp->next;
                ptr = temp;
                temp = temp->next;
                list_ptr = list_ptr->next;
                free(ptr);
            }
            else
            {
                prev = list_ptr;
                temp = temp->next;
                list_ptr = list_ptr->next;
            }
        }
        return nochange_ptr;
    }
}

struct professional* deletelist_professional_bynum(struct professional* list_ptr, int num)  //professional delete list by number
{
    struct professional *ptr, *temp = list_ptr->next;
    struct professional *prev , *rptr;
    struct professional* nochange_ptr = list_ptr;
    
    if(list_ptr->office_number == num)
    {
        ptr = list_ptr;
        rptr = list_ptr->next;
        free(ptr);
        return rptr;
    }
    else
    {
        while(temp != NULL )
        {
            if(temp->office_number == num)
            {
                prev = list_ptr;
                prev->next = temp->next;
                ptr = temp;
                temp = temp->next;
                list_ptr = list_ptr->next;
                free(ptr);
            }
            else
            {
                prev = list_ptr;
                temp = temp->next;
                list_ptr = list_ptr->next;
            }
        }
        return nochange_ptr;
    }
}



void search_byname_personal(struct personal* list_ptr , char byname[20])    //personal
{
    int count=0;
    while(list_ptr!=NULL)
    {
        if(strcmp(list_ptr->first_name,byname) == 0 || strcmp(list_ptr->last_name,byname) == 0)
        {
            displaypersonal(list_ptr);
            list_ptr = list_ptr->next;
            count++;
        }
        else
        {    list_ptr = list_ptr->next;
        }
    }
    
    if(count>0)
    {    printf("%d times found\n",count);
    }
    else
    {    printf("not found\n");
    }
}

void search_byname_professional(struct professional* list_ptr , char byname[20])  //professional
{
    int count=0;
    while(list_ptr!=NULL)
    {
        if(strcmp(list_ptr->first_name,byname) == 0 || strcmp(list_ptr->last_name,byname) == 0)
        {    displayprofessional(list_ptr);
            
            list_ptr = list_ptr->next;
            count++;
        }
        else
        {    list_ptr = list_ptr->next;
        }
    }
    
    if(count>0)
    {    printf("%d times found\n",count);
    }
    else
    {    printf("not found\n");
    }
}
 
//display by number
 
void search_bynum_personal(struct personal* list_ptr, int num)      //searching personal list using number
{
    int count =0;
    while(list_ptr!= NULL)
    {
        if(list_ptr->number == num)
        {
            displaypersonal(list_ptr);
            list_ptr = list_ptr->next;
            count++;
        }
        else
        {    list_ptr = list_ptr->next;
        }
    }
    
    if(count>0)
    {    printf("%d times found\n",count);
    }
    else
    {    printf("not found\n");
    }
}

void search_bynum_professional(struct professional* list_ptr, int num)      //professional list using number
{
    int count =0;
    while(list_ptr!= NULL)
    {
        if(list_ptr->office_number == num)
        {  displayprofessional(list_ptr);
           list_ptr = list_ptr->next;
            count++;
        }
        else
        {    list_ptr = list_ptr->next;
        }
    }
    
    if(count>0)
    {    printf("%d times found\n",count);
    }
    else
    {    printf("not found\n");
    }
}

void search_to_edit_personal_byname(struct personal* list_ptr, char byname[20])   //personal edit by name
{
    int count=0;
    while(list_ptr!=NULL)
    {
        if(strcmp(list_ptr->first_name,byname) == 0)
        { int key;
            printf("1.First name, 2.Last Name , 3. Email,4.personal Number");
            scanf("%d",&key);
            switch(key)
            { case 1:
            printf("Enter First name to edit : \n");
            scanf("%s",list_ptr->first_name);
                    break;
                case 2:
            printf("Enter Last name to edit : \n");
            scanf("%s",list_ptr->last_name);
                    break;
                case 3:
            printf("Enter Email id to edit : \n");
            scanf("%s",list_ptr->email);
                    break;
                case 4:
            printf("Enter personal number to edit: \n");
            scanf("%d",&list_ptr->number);
                    break;
                default:
                    printf("Enter valid operation");
            }
            list_ptr = list_ptr->next;
            count++;
        }
        else
        {
            list_ptr = list_ptr->next;
        }
    }
    if(count>0)
    {    printf("%d edited\n",count);
    }
    else
    {    printf("not found\n");
    }
}
void search_to_edit_professional_byname(struct professional* list_ptr, char byname[20])    //professional edit by name
{
    int count=0;
    while(list_ptr!=NULL)
    {
        if(strcmp(list_ptr->first_name,byname) == 0)
        {int key;
            printf("1.First name, 2.Last Name , 3. Email,4.Office Name,5.Office Address,6.Office Number,7 Office Type");
            scanf("%d",&key);
            switch(key)
            { case 1:
            printf("Enter First name to edit : \n");
            scanf("%s",list_ptr->first_name);
                    break;
                case 2:
            printf("Enter Last name to edit : \n");
            scanf("%s",list_ptr->last_name);
                    break;
                case 3:
            printf("Enter Email id to edit : \n");
            scanf("%s",list_ptr->email);
                    break;
                case 4:
            printf("Enter Office Name to edit: \n");
            scanf("%s",list_ptr->office_name);
                    break;
                case 5:
            printf("Enter Office Address to edit: \n");
            scanf("%s",list_ptr->office_address);
                    break;
                case 6:
            printf("Enter Office Number to edit: \n");
            scanf("%d",&list_ptr->office_number);
                    break;
                case 7:
                    printf("Enter office type\n");
                    scanf("%s",list_ptr->office_type);
                default:
                    printf("Enter valid operation");
            }
            list_ptr = list_ptr->next;
            count++;
        }
        else
        {
            list_ptr = list_ptr->next;
        }
    }
    if(count>0)
    {    printf("%d edited\n",count);
    }
    else
    {    printf("not found\n");
    }
}
boolean comparePersonal(struct personal*first,struct personal* second) // used for comparing
{
  if(strcmp(first->first_name,second->first_name)<0)
  {
    return TRUE;
  }
  else if(strcmp(first->first_name,second->first_name)==0)
{ if(strcmp(first->last_name, second->last_name)<0)
    {
        return TRUE;
    }
    else if (strcmp(first->last_name, second->last_name)==0)
        
        if(first->number<second->number)
        {
          return TRUE;
        }
  }
    return FALSE;
}
boolean compareProessional(struct professional*first,struct professional* second)
    {
      if(strcmp(first->first_name,second->first_name)<0)
      {
        return TRUE;
      }
      else if(strcmp(first->first_name,second->first_name)==0)
    { if(strcmp(first->last_name, second->last_name)<0)
        {
            return TRUE;
        }
        else if (strcmp(first->last_name, second->last_name)==0)
            
            if(first->office_number<second->office_number)
            {
              return TRUE;
            }
      }

  return FALSE;
}

struct personal* sortedMerge_personal(struct personal* a, struct personal* b)
{
    // base cases
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    struct personal* result = NULL;
 
    
    if (comparePersonal(a, b))
    {
        result = a;
        result->next = sortedMerge_personal(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge_personal(a, b->next);
    }
 
    return result;
}
struct professional* sortedMerge_proffesional(struct professional* a, struct professional* b)
{
    // base cases
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    struct professional* result = NULL;
 
    // pick either `a` or `b`, and recur
    if (compareProessional(a, b))
    {
        result = a;
        result->next = sortedMerge_proffesional(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge_proffesional(a, b->next);
    }
 
    return result;
}
 
void frontBackSplit_personal(struct personal* source, struct personal** frontRef,
                    struct personal** backRef)
{
    // if the length is less than 2, handle it separately
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    struct personal* slow = source;
    struct personal* fast = source->next;
 
    // advance `fast` two nodes, and advance `slow` one node
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    // `slow` is before the midpoint in the list, so split it in two
    // at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void frontBackSplit_proffesional(struct professional* source, struct professional** frontRef,
                    struct professional** backRef)
{
    // if the length is less than 2, handle it separately
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    struct professional* slow = source;
    struct professional* fast = source->next;
 
    // advance `fast` two nodes, and advance `slow` one node
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    // `slow` is before the midpoint in the list, so split it in two
    // at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
struct personal* mergesort_personal(struct personal* head)
{
    // base case — length 0 or 1
    if (head == NULL || (head)->next == NULL) {
        return head;
    }
 
    struct personal* a;
    struct personal* b;
 
    // split `head` into `a` and `b` sublists
    frontBackSplit_personal(head, &a, &b);
 
    // recursively sort the sublists
    mergesort_personal(a);
    mergesort_personal(b);
 
    // answer = merge the two sorted lists
    return sortedMerge_personal(a, b);
     }
struct professional* mergesort_professional(struct professional* head)
{
    // base case — length 0 or 1
    if (head == NULL || (head)->next == NULL) {
        return head;
    }
 
    struct professional* a;
    struct professional* b;
 
    // split `head` into `a` and `b` sublists
    frontBackSplit_proffesional(head, &a, &b);
 
    // recursively sort the sublists
    mergesort_professional(a);
    mergesort_professional(b);
 
    // answer = merge the two sorted lists
    return sortedMerge_proffesional(a, b);
     }


void remove_duplicate_personal(struct personal* list_ptr)    //personal list
{
    /* Pointer to traverse the linked list */
    struct personal* current = list_ptr;
    struct personal* next_next;
    int count=0;
    
    if (current == NULL)
       return;

    while (current->next != NULL)
    {
        if((strcmp(current->first_name,current->next->first_name) == 0) && (strcmp(current->last_name,current->next->last_name) == 0)
            && (strcmp(current->email,current->next->email) == 0) && (current->number == current->next->number) ) // if all this statisfies the node gets deleted.
        {
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;
           count++;
        }
        else  //if no deletion
        {
              current = current->next;
           }
    }
    
    if(count == 0)
    {
        printf("No Duplicates are found\n");
    }
    else if(count >0)
    {
        printf("%d duplicates are found And Removed \n",count);
    }
}
void remove_duplicate_professional(struct professional* list_ptr)    //personal
{
    /* Pointer to traverse the linked list */
    struct professional* current = list_ptr;
    struct professional* next_next;
    int count=0;
    
    if (current == NULL)
       return;

    while (current->next != NULL)
    {
        if((strcmp(current->first_name,current->next->first_name) == 0) && (strcmp(current->last_name,current->next->last_name) == 0)
            && (strcmp(current->email,current->next->email) == 0) &&(strcmp(current->office_name,current->next->office_name )==0)&& (strcmp(current->office_address,current->next->office_address )==0)&&(current->office_number == current->next->office_number) )
        {
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;
           count++;
        }
        else  //if no deletion
        {
              current = current->next;
           }
    }
    
    if(count == 0)
    {
        printf("No Duplicates are found\n");
    }
    else if(count >0)
    {
        printf("%d duplicates are found And Removed \n",count);
    }
}
void push_personal(struct personal** resultHead, struct personal* lptr)// used to creat a new node
{
    struct personal* newNode= (struct personal*)malloc(sizeof(struct personal));
 strcpy( newNode->first_name, lptr->first_name);
  strcpy(newNode->last_name , lptr->last_name);
  newNode->number = lptr->number;
 
  newNode->next = (*resultHead);
  (*resultHead) = newNode;
}

struct personal* union_personal(struct personal* p1,struct personal* p2)
{
    struct personal* ptr = p1;
    
    //if(p1)
    
    while(p1->next != NULL)   // p1 one node and p2 null  // p1 and p2 both are not null
    {
        p1 = p1->next;
    }
    p1->next = p2;
    
    return ptr;
}
struct professional* union_professional(struct professional* p1,struct professional* p2)
{
    struct professional* ptr = p1;
    
    //if(p1)
    
    while(p1->next != NULL)   // p1 one node and p2 null  // p1 and p2 both are not null
    {
        p1 = p1->next;
    }
    p1->next = p2;
    
    return ptr;
}

int Total_Time(struct call* lptr)
{
    struct call *nptr;
    int time=0;
    nptr=lptr;
    while (nptr!=NULL) {
        for (int i=0; i<nptr->calls; i++) {
            nptr->total+=nptr->duration;
                
        }
        time+=nptr->total;
        nptr=nptr->next;
    }
    return time;
}
void Phonebook(struct call* ptr,char*name,int number,char*address,struct personal* pers_lptr,struct professional* prof_lptr,int total_time )
{
    strcpy(ptr->name,name);
    ptr->number=number;
    strcpy(ptr->address,address);
    ptr->duration=total_time;
    ptr->prof_lptr=prof_lptr;
    ptr->pers_lptr=pers_lptr;
}

int main()
{
    struct personal* personal_ptr = NULL;
    int choice;
    
    printf("Press 1 for personal \nPress 2 for professional \n");
    printf("enter the choice to create : ");
    scanf("%d",&choice);
    
    if(choice == 1)// choice for personal or professional
    {
        int option,flag = 1;
        while(flag == 1)// using flag to break the loop in between whenever required
        {
            printf(" 1. To Insert  \n 2. To Edit \n 3. Delete \n 4. Search \n 5. Sort \n 6. To Display \n 7. Union \n 8. Remove Duplicates\n 9. Time\n 0. To exit \n");
            scanf("%d",&option);
            
            if(option == 1 )     //to Add
            {
               personal_ptr = createlist_personal(personal_ptr);
                printf("Contact is created\n");
            }
            else if(option == 2)   // Edit
            {
                    char e_byname[20];
                    printf("enter the  name to edit : ");
                    scanf("%s",e_byname);
                    search_to_edit_personal_byname(personal_ptr, e_byname);// Edit function called
                }
            else if(option == 3)      //Delete
            {
                int delete_key;
                printf("Press 1. Delete by name \nPress 2. Delete by number \n");
                printf("Enter the choice : ");
                scanf("%d",&delete_key);
                if(delete_key == 1)// using key for choosing options wheter to delete by name or number
                {
                    char del_byname[20];
                    printf("enter the name to delete : ");
                    scanf("%s",del_byname);
                    personal_ptr = deletelist_personal(personal_ptr,del_byname);// calling delete by name function
                }
                else if(delete_key == 2)
                {
                    int del_bynum;
                    printf("enter the number to delete : ");
                    scanf("%d",&del_bynum);
                    personal_ptr = deletelist_personal_bynum(personal_ptr,del_bynum);// delete by number function called
                
                }
                
               
            }
            else if (option == 4)      //search
            {
                int search_key;
                printf("Press 1. Search by name \nPress 2. Search by number \n");
                printf("Enter the choice : ");
                scanf("%d",&search_key);
                switch (search_key) {
                 
            case 1:
                    {    char search_byname[20];
                    printf("enter the name to search : ");
                    scanf("%s",search_byname);
                    search_byname_personal(personal_ptr,search_byname);
                        break;
                }
            case 2:
                {    int search_bynum;
                    printf("enter the number to search : ");
                    scanf("%d",&search_bynum);
                    search_bynum_personal(personal_ptr, search_bynum);
                    break;
                }
                    default:
                        printf("Enter valid number");
            }
            }
            else if (option == 5)// Sorting The linked list
            {int key; printf("Enter 1 for Ascending \n 2. For Descending");
                scanf("%d",&key);
                switch (key) {
                    case 1: // 1 for ascending
                        personal_ptr= mergesort_personal(personal_ptr);// calling merge sort
                        printf("sorting done");
                        printReverse_personal(personal_ptr);
                        break;
                    case 2:
                        personal_ptr= mergesort_personal(personal_ptr);
                        printf("sorting done");
                        full_display_personal(personal_ptr);
                    default:
                        printf("Enter Vaild Option");
                        break;
              
            }
            }
           
            else if(option == 6)      //full display function called
            {
                full_display_personal(personal_ptr);
                
                }
          
            else if (option==7) // Union is done
            {
                
                struct personal *p2 = NULL, *uni;
                                int num;
                                printf("Enter the number of contacts to be created : ");
                                scanf("%d",&num);
                                 for(int i=0;i<num;i++){
                                p2 = createlist_personal(p2);
                                   }
                                printf("The Second Linklist is : \n");
                               
                                
                                p2= mergesort_personal(p2);
                                printf("\nThe sorted linked list is : \n");
                                
                                printReverse_personal(p2);
                                
                                uni = union_personal(personal_ptr,p2);// union happens
                                uni = mergesort_personal(uni);
                                printf("The union of two linked lists is : \n");
                                full_display_personal(uni);
                                
                            }
            
            else if (option==8) // Remove Duplicates
            {    remove_duplicate_personal(personal_ptr);
                printf("The list after Deletion");
                full_display_personal(personal_ptr);
            }
            else if (option==9)
            {
               // Total_Time()
            }
            else if(option == 0)
            flag = 0;
            
        }
    }
    
    else if (choice == 2)
    {  int flag = 1;
        struct professional* professional_ptr = NULL;
        
        while(flag == 1)     //to add/insert
        {
           printf(" 1. To Insert  \n 2. To Edit \n 3. Delete \n 4. Search \n 5. Sort \n 6. To Display \n 7. Union \n 8. Remove Duplicates\n 9. Time\n 0. To exit \n");
            int option;
            scanf("%d",&option);
            if(option == 1 )
            {
                
                
                professional_ptr = createlist_professional(professional_ptr);
                printf("Contact is created\n");
                
              
            }
            else if(option == 2)   // edit
            {
               
                printf(" Edit ");
             
                
                    char e_byname[20];
                    printf("enter the feild name to edit : ");
                    scanf("%s",e_byname);
                    search_to_edit_professional_byname(professional_ptr, e_byname);
                
               
                
              
            }
            else if(option == 3)     //delete
            {
                int delete_key;
                printf("Press 1. Delete by name \nPress 2. Delete by number \n");
                printf("Enter the choice : ");
                scanf("%d",&delete_key);
                if(delete_key == 1)
                {
                    char del_byname[20];
                    printf("enter the name to delete : ");
                    scanf("%s",del_byname);
                    professional_ptr = deletelist_professional(professional_ptr,del_byname);
                }
                else if(delete_key == 2)
                {
                    int del_bynum;
                    printf("enter the number to delete : ");
                    scanf("%d",&del_bynum);
                    professional_ptr = deletelist_professional_bynum(professional_ptr, del_bynum);
                }
                
              
            }
            else if (option == 4)      //search
            {
                int search_key;
                printf("Press 1. Search by name \nPress 2. Search by number \n");
                printf("Enter the choice : ");
                scanf("%d",&search_key);
                
                if(search_key == 1)
                {    char search_byname[20];
                    printf("enter the name to search : ");
                    scanf("%s",search_byname);
                    search_byname_professional(professional_ptr,search_byname);
                }
                else if(search_key == 2)
                {    int search_bynum;
                    printf("enter the number to search : ");
                    scanf("%d",&search_bynum);
                    search_bynum_professional(professional_ptr, search_bynum);
                }
                else if (option == 5)// sort
                {  int key; printf("Enter 1 for Ascending \n 2. For Descending");
                    scanf("%d",&key);
                    switch (key) {
                        case 1:
                            professional_ptr= mergesort_professional(professional_ptr);
                            printf("sorting done");
                            printReverse_professional(professional_ptr);
                            break;
                        case 2:
                            professional_ptr= mergesort_professional(professional_ptr);
                            
                           printf("sorting done");
                            full_display_professional(professional_ptr);
                        default:
                            printf("Enter Vaild Option");
                            break;
                    }
                   
                }
              
            }
            else if(option == 6)     //full display
            {
                full_display_professional(professional_ptr);
                
              
            }
            
                else if (option==7)
                {
                    
                    struct professional *p2 = NULL, *uni;
                                    int num;
                                    printf("Enter the number of contacts to be created : ");
                                    scanf("%d",&num);
                                     for(int i=0;i<num;i++){
                                    p2 = createlist_professional(p2);
                                       }
                                    printf("The Second Linklist is : \n");
                                   
                                    
                                    p2= mergesort_professional(p2);
                                    printf("\nThe sorted linked list is : \n");
                                    
                                   
                                    
                                    uni = union_professional(professional_ptr,p2);
                                    uni = mergesort_professional(uni);
                                    printf("The union of two linked lists is : \n");
                                    full_display_professional(uni);
                                    
                                }
            
            else if (option==8)
            {
                remove_duplicate_professional(professional_ptr);
                  printf("The list after Deletion");
                  full_display_professional(professional_ptr);
            }
            else if (option==9)
            {
            //Total_Time

            }
            else if(option == 0)
            {
                flag=0;
            }
        }
    }
    return 0;
    
}





