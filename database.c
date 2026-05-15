#include "inverted.h"

/* Create word node */
wnode *create_word(char *word, char *fname)
{
    wnode *new = malloc(sizeof(wnode));
    strcpy(new->word, word);
    new->file_count = 1;
    new->next = NULL;

    fnode *f = malloc(sizeof(fnode));
    strcpy(f->fname, fname);
    f->count = 1;
    f->next = NULL;

    new->fhead = f;
    return new;
}

/* Add file */
void add_file(wnode *w, char *fname)
{
    fnode *temp = w->fhead;

    while (temp)
    {
        if (strcmp(temp->fname, fname) == 0)
        {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    fnode *new = malloc(sizeof(fnode));
    strcpy(new->fname, fname);
    new->count = 1;
    new->next = w->fhead;
    w->fhead = new;
    w->file_count++;
}

/* Insert word */
void insert_word(wnode **head, char *word, char *fname)
{
    wnode *temp = *head, *prev = NULL;

    while (temp && strcmp(temp->word, word) < 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp && strcmp(temp->word, word) == 0)
    {
        add_file(temp, fname);
        return;
    }

    wnode *new = create_word(word, fname);

    if (prev == NULL)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        new->next = prev->next;
        prev->next = new;
    }
}

/* Process file */
void process_file(wnode **head, char *fname)
{
    FILE *fp = fopen(fname, "r");
    if (!fp)
    {
        printf("Cannot open %s\n", fname);
        return;
    }

    char word[50];
    int i = 0, ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch))
            word[i++] = tolower(ch);
        else if (i > 0)
        {
            word[i] = '\0';
            insert_word(head, word, fname);
            i = 0;
        }
    }

    if (i > 0)
    {
        word[i] = '\0';
        insert_word(head, word, fname);
    }

    fclose(fp);
}

/* Create DB */
void create_db(wnode **head, flist *fhead)
{
    flist *temp = fhead;
    while (temp)
    {
        process_file(head, temp->fname);
        temp = temp->next;
    }

    printf("Database created successfully\n");
}

/* Display DB */
void display_db(wnode *head)
{
    while (head)
    {
        printf("%s -> %d file(s): ", head->word, head->file_count);

        fnode *f = head->fhead;
        while (f)
        {
            printf("%s (%d) ", f->fname, f->count);
            f = f->next;
        }
        printf("\n");

        head = head->next;
    }
}