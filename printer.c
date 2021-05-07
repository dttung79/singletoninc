//
//  printer.c
//  DemoSingleton
//
//  Created by TungDT on 8/27/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "printer.h"

printer* get_printer(void)
{
    static printer* spooler = NULL;
    if (spooler == NULL)
    {
        spooler = (printer*) malloc(sizeof(printer));
        spooler->front = -1;
        spooler->rear = -1;
        spooler->n_pages = INK_PAGES;
    }
    return spooler;
}
void add_document(printer* spooler, document doc)
{
    if (is_full(spooler)) printf("Queue is full!\n");
    else
    {
        if (empty_tray(spooler)) spooler->front = 0;
        spooler->rear = (spooler->rear + 1) % NDOCS;
        spooler->queue[spooler->rear] = doc;
    }
}
void print(printer* spooler)
{
    while (!empty_tray(spooler))
    {
        document doc = get_document(spooler);
        if (doc.n_pages <= spooler->n_pages)
        {
            printf("Print document of comp %d, pages = %d\n", doc.comp_id, doc.n_pages);
            spooler->n_pages -= doc.n_pages;
        }
        else
        {
            printf("Print document of comp %d, pages = %d\n", doc.comp_id, spooler->n_pages);
            spooler->n_pages = 0;
            doc.n_pages -= spooler->n_pages;
            printf("Replace ink tray to continue!\n");
            return;
        }
    }
}
int is_full(printer* spooler)
{
    if (spooler->front == spooler->rear + 1) return TRUE;
    if (spooler->front == 0 && spooler->rear == NDOCS - 1) return TRUE;
    return FALSE;
}
int empty_tray(printer* spooler)
{
    return spooler->front == -1;
}
int get_ndocuments(printer* spooler)
{
    if (spooler->front <= spooler->rear)
        return spooler->rear - spooler->front + 1;
    else
        return NDOCS - (spooler->front - spooler->rear - 1);
}
document get_document(printer* spooler)
{
    if (empty_tray(spooler))
    {
        printf("Printer queue is empty!\n");
        exit(1);
    }
    
    document doc = spooler->queue[spooler->front];
    if (spooler->front == spooler->rear)
    {
        spooler->front = spooler->rear = -1;
    }
    else spooler->front = (spooler->front + 1) % NDOCS;
    
    return doc;
}
