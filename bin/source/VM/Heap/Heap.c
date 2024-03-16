#include "../header/Heap.h"
#include <stdio.h>
#include <stdlib.h>
struct Heap VM_var;
void c_set(char* name, void* value) {
    int i;
    for (i = 0; i < VM_var.count; i++) {
        if (strcmp(VM_var.name[i], name) == 0) {
            VM_var.value[i] = value;
            return;
        }
    }
    if (VM_var.count < MAX_VARS) {
        VM_var.name[VM_var.count] = strdup(name);
        VM_var.value[VM_var.count] = value;
        VM_var.count++;
    } else {
        fprintf(stderr, "Memory Reference Error: Too many variables\n");
        exit(1);
    }
}
void c_del(char* target) {
    int i;
    for (i = 0; i < VM_var.count; i++) {
        if (strcmp(VM_var.name[i], target) == 0) {
            free(VM_var.name[i]);
            for (int j = i; j < VM_var.count - 1; j++) {
                VM_var.name[j] = VM_var.name[j + 1];
                VM_var.value[j] = VM_var.value[j + 1];
            }
            VM_var.count--;
            return;
        }
    }
    fprintf(stderr, "Memory Reference Error: Variable not found\n");
    exit(1);
}
void* c_get(char* target) {
    int i;
    for (i = 0; i < VM_var.count; i++) {
        if (strcmp(VM_var.name[i], target) == 0) {
            return VM_var.value[i];
        }
    }
    return NULL;
}