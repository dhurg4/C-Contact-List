#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct contact 
{
    char* name; 
    char* phone; 
    char* email; 

};

void addContact(char*** list, int* size) 
{
    (*size)++;
    (*list) = realloc((*list), (*size)*sizeof(char*));
    if (*list == NULL)
    {
        printf("Reallocation failed.\n");  
        return; 
    }

    struct contact person;
        
    person.name = (char*)malloc(50*(sizeof(char)));
    if (person.name == NULL)
    {
        printf("Allocation failed.\n");
        return;
    }
    person.phone = (char*)malloc(15*(sizeof(char)));
    if (person.phone == NULL)
    {
        printf("Allocation failed.\n");
        return;
    }
    person.email = (char*)malloc(50*(sizeof(char)));
    if (person.email == NULL)
    {
        printf("Allocation failed.\n");
        return;
    }

    printf("Enter the person's name: \n");
    scanf("%s", person.name);

    printf("Enter the person's phone numbers: \n");
    scanf("%s", person.phone);

    printf("Enter the person's email address: \n");
    scanf("%s", person.email);

    char* tempContact = (char*)malloc(256*(sizeof(char)));
    strcpy(tempContact, person.name);
    strcat(tempContact, " , ");
    strcat(tempContact, person.phone);
    strcat(tempContact, " , ");
    strcat(tempContact, person.email);

    (*list)[((*size)-1)] = (char*)malloc((strlen(tempContact)+1)*sizeof(char));
    strcpy(((*list)[(*size)-1]), tempContact);

    free(person.name);
    person.name = NULL;
    free(person.phone);
    person.phone = NULL;
    free(person.email);
    person.email = NULL;
}

void displayContacts(char*** list, int* size)
{
    if ((*size) <= 0)
    {
        printf("No contact in the contact list.\n");
    }else
    {
        printf("\n");
        printf("All Contacts: \n");
        for (int i=0; i < (*size); i++)
        {
            printf("%d. %s\n", (i+1) , ((*list)[i]));
        }
        printf("\n");
    }

}

void startingScreen (bool *exitP, char*** list, int* size)
{
    int choiceNum;
    printf("Please select an option\n");
    printf("1. Add a contact\n");
    printf("2. Display all contacts\n");
    printf("3. Delete all contacts and exit\n");

    scanf("%d", &choiceNum);

    switch(choiceNum)
    {
        case 1:
            addContact(list, size);
            return;
        case 2:
            displayContacts(list, size);
            return;
        case 3:
            *exitP = true;
            return;
        default:
            printf("Invalid input. Please try again.");
            return;
    }

}


int main()
{
    bool exitProgram = false;
    char** contactList = NULL;
    int listSize = 0;

    while (exitProgram == false)
    {
        startingScreen(&exitProgram, &contactList, &listSize);
    }

    printf("Deleting contacts...\n");

    for(int i=0; i < listSize; i++)
    {
        free(contactList[i]);
        contactList[i] = NULL;
    }

    free(contactList);
    contactList = NULL;
    
    printf("Program exited.\n");

}