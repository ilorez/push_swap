#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list {
    void        *content;
    struct s_list   *next;
} t_list;

int ft_get_edge(t_list *stack)
{
  
}


int ft_get_pos_of(t_list *stack, int n)
{
  int i;
  int a;
  int b;
  
  if (!stack)
    return (0);
  i = 1;
  while (stack && stack->next)
  {
    a = *(int *)stack->content;
    b = *(int *)stack->next->content;

    i++;
    stack = stack->next;
  }

  return (0);
}

void print_stack(t_list *stack)
{
    if (!stack)
    {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack: ");
    while (stack)
    {
        printf("%d", *(int *)stack->content);
        if (stack->next)
            printf(" -> ");
        stack = stack->next;
    }
    printf("\n");
}

// Add your corrected ft_get_pos_of function here
int main()
{
    t_list *stack = NULL;
    
    // Create test list: 1 -> 4 -> 2 -> 7 -> 3
    int nums[] = {2, -1, 7, 4};
    t_list *current = NULL;
    
    for (int i = 0; i < 4; i++) {
        int *num = malloc(sizeof(int));
        *num = nums[i];
        t_list *new = malloc(sizeof(t_list));
        new->content = num;
        new->next = NULL;
        
        if (!stack) {
            stack = new;
            current = stack;
        } else {
            current->next = new;
            current = new;
        }
    }
  print_stack(stack);
    
    // Test cases
    printf("Position for 5 : %d == 3 \n", ft_get_pos_of(stack, 5));  // Should find position
    printf("Position for 0: %d == 1\n", ft_get_pos_of(stack, 0));  // Should handle number less than all
    printf("Position for 8: %d == 2\n", ft_get_pos_of(stack, 8));  // Should handle number greater than all
    printf("Position for 3: %d == 0\n", ft_get_pos_of(stack, 3));  // Should find position
    
    // Test with NULL
    printf("Position with NULL stack: %d\n", ft_get_pos_of(NULL, 5));
    
    // Clean up
    while (stack) {
        t_list *temp = stack;
        stack = stack->next;
        free(temp->content);
        free(temp);
    }
    
    return 0;
}

//void my_fun(int *arr1, int *arr2, int *arr3) {
//    int local_arr1[4];
//    int local_arr2[4];
//    int local_arr3[33];
//    
//    // Copy values to create independent arrays
//    memcpy(local_arr1, arr1, 4 * sizeof(int));
//    memcpy(local_arr2, arr2, 4 * sizeof(int));
//    memcpy(local_arr3, arr3, 33 * sizeof(int));
//
//    printf("local c[31]: %d\n", local_arr3[31]);
//}
//int main()
//{
//  int a[4];
//  int b[4];
//  int c[33];
//
//  c[31] = 44443;
//
//  printf("c[31]: %d\n", c[31]);
//  my_fun(a, b, c);
//}


//void ft_get_arr(int **arr) {  // Pass array as pointer
//    *arr[0] = 0;
//    *arr[1] = 1;
//}
//
//int main() {
//    int a[2];
//    int b[2];
//    int c[2];
//    
//    a[0] = 100;
//    a[1] = 200;
//    b[0] = 300;
//    b[1] = 400;
//    
//    ft_get_arr(&c);      
//
//    printf("address:\n"
//           "a: %p\nb: %p\n"
//           "values a:\n"
//           "a[0]: %d\na[1]: %d\n"
//           "values b:\n"
//           "b[0]: %d\nb[1]: %d\n"
//           "values c:\n"
//           "c[0]: %d\nc[1]: %d\n",
//           (void*)a, (void*)b, 
//           a[0], a[1], 
//           b[0], b[1], 
//           c[0], c[1]);
//    
//    return 0;
//}
