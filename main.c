#include "inverted.h"

int main()
{
    wnode *db = NULL;
    flist *files = NULL;

    int choice;
    char fname[50], word[50];

    while (1)
    {
        printf("\n1.Create DATABASE\n2.Display Database\n3.Update DATABASE\n4.Search\n5.Save Database\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter file name: ");
            scanf("%s", fname);
            insert_file(&files, fname);
            create_db(&db, files);
            break;

        case 2:
            display_db(db);
            break;

        case 3:
            printf("Enter file name to update: ");
            scanf("%s", fname);
            insert_file(&files, fname);
            process_file(&db, fname);
            break;

        case 4:
            printf("Enter word: ");
            scanf("%s", word);
            search_db(db, word);
            break;

        case 5:
            printf("Enter backup file name: ");
            scanf("%s", fname);
            save_db(db, fname);
            break;

        default:
            exit(0);
        }
    }
}