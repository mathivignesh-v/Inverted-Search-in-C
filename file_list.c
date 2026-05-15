#include "inverted.h"

void insert_file(flist **head, char *fname)
{
    flist *new = malloc(sizeof(flist));
    strcpy(new->fname, fname);
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        flist *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }

    printf("Successful: inserting file name : %s\n", fname);
}