//
//  printer.h
//  DemoSingleton
//
//  Created by TungDT on 8/27/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef printer_h
#define printer_h

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NDOCS 10
#define INK_PAGES 10000
#define TRUE 1
#define FALSE 0

typedef struct
{
    int comp_id;
    int n_pages;
} document;

typedef struct
{
    int n_pages;
    document queue[NDOCS];
    int front;
    int rear;
} printer;

printer* get_printer(void);

void add_document(printer* spooler, document doc);
void print(printer* spooler);
int is_full(printer* spooler);
int empty_tray(printer* spooler);
int get_ndocuments(printer* spooler);
document get_document(printer* spooler);

#endif /* printer_h */
