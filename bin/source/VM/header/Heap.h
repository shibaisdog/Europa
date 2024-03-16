#ifndef Heap_H
#define Heap_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100

struct Heap {
    char* name[MAX_VARS];
    void* value[MAX_VARS];
    int count;
};

extern struct Heap VM_var;

#ifdef __cplusplus
extern "C" {
#endif

void c_set(char* name, void* value);
void c_del(char* target);
void* c_get(char* target);

#ifdef __cplusplus
}
#endif

#endif /* Heap_H */