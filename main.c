//
//  main.c
//  DemoSingleton
//
//  Created by TungDT on 8/27/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "printer.h"
#define COMP1 1
#define COMP2 2

void computer_print(int computer, int pages);

int main(int argc, const char * argv[])
{
    computer_print(COMP1, 500);
    computer_print(COMP2, 1200);
    return 0;
}

void computer_print(int computer, int pages)
{
    printer* spooler = get_printer();
    document doc = {computer, pages};
    add_document(spooler, doc);
    print(spooler);
}
