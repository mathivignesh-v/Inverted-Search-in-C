#include "inverted.h"

void save_db(wnode *head, char *fname)
{
    FILE *fp = fopen(fname, "w");
    if (!fp)
    {
        printf("Cannot save\n");
        return;
    }

    while (head)
    {
        fprintf(fp, "%s:%d:", head->word, head->file_count);

        fnode *f = head->fhead;
        while (f)
        {
            fprintf(fp, "%s:%d:", f->fname, f->count);
            f = f->next;
        }
        fprintf(fp, "#\n");

        head = head->next;
    }

    fclose(fp);
    printf("Database saved successfully\n");
}