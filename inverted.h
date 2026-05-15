#ifndef INVERTED_H
#define INVERTED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* File node */
typedef struct file_node
{
    char fname[50];
    int count;
    struct file_node *next;
} fnode;

/* Word node */
typedef struct word_node
{
    char word[50];
    int file_count;
    fnode *fhead;
    struct word_node *next;
} wnode;

/* File list */
typedef struct file_list
{
    char fname[50];
    struct file_list *next;
} flist;

/* Function declarations */
void insert_file(flist **head, char *fname);
void create_db(wnode **head, flist *fhead);
void process_file(wnode **head, char *fname);
void display_db(wnode *head);
void search_db(wnode *head, char *word);
void save_db(wnode *head, char *fname);

#endif