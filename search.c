#include "inverted.h"

void search_db(wnode *head, char *word)
{
    while (head)
    {
        if (strcmp(head->word, word) == 0)
        {
            printf("Word %s is present in %d file(s)\n", word, head->file_count);

            fnode *f = head->fhead;
            while (f)
            {
                printf("In file: %s %d time(s)\n", f->fname, f->count);
                f = f->next;
            }
            return;
        }
        head = head->next;
    }

    printf("Word not found\n");
}