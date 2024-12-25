#include <stdio.h>
#include <stdlib.h>

void stack_overflow() {
   int arr[5];
   arr[10] = 0;  // Stack buffer overflow
   printf("Stack overflow executed\n"); 
}

void memory_leak() {
   int *ptr = malloc(10);
   ptr = NULL;  // Memory leak
   printf("Memory leak executed\n");
}

void double_free() {
   int *ptr = malloc(10);
   free(ptr);
   free(ptr);  // Double free
   printf("Double free executed\n");
}

int* use_after_return() {
   int x = 5;
   return &x;  // Stack variable invalid after return
}

void use_after_scope() {
   int* ptr;
   {
       int x = 0;
       ptr = &x;
   }
   *ptr = 5;  // Use after scope
}

int main() {
   
   stack_overflow();
  // memory_leak();
   //double_free();
   //int *bad_ptr = use_after_return();
   //printf("%d\n", *bad_ptr);
   //use_after_scope();

   return 0;
}
