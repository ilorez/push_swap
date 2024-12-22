#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./libft/includes/t_bool.h"

t_bool ft_is_n_between(int n, int a, int b)
{
  if ((a > b && n > b && n < a) || (a < b && n < b && n > a))
    return (true);
  return (false);
}
int ft_get_min_pos(t_list *stack, int min)
{
  int min_i;
  int num;
  int i;

  i = 0;
  min_i = 0;
  while (stack)
  {
    num = *(int *)stack->content;
    if (num < min)
    {
      min_i = i;
      min = num;
    }
    i++;
    stack = stack->next;
  }
  return (min_i);
}
// this function always stack that is have more then two numbers
// min: the first element by default
int ft_get_right_order(t_list *stack, int min)
{
  t_list  *before_n;
  t_list  *after_n;
  int min_pos;

  min_pos = ft_get_min_pos(stack, min);
  before_n = NULL;
  after_n = stack;
  while (min_pos--)
  {
    before_n = stack;
    stack = stack->next;
  }
  if (stack->next)
    after_n = stack->next;
  else if (!before_n)
    before_n = ft_lstlast(stack);
  if (*(int *)before_n->content > *(int *)after_n->content)
      return (1);
  return (-1);
}
// sl: stack size
int ft_get_pos_of(t_list *stack,int size, int n)
{
  int a;
  int b;
  int order;
  int edge;
  int i;
  int first;
  
  if (size == 1)
    return (0);


  a = *(int *)stack->content;
  b = *(int *)stack->next->content;
  if (size == 2)
    return ((int)ft_is_n_between(n, a, b));
  order = ft_get_right_order(stack, a);
  i = 1;
  first = a;
  edge = 0;
  while (stack->next)
  {
    a = *(int *)stack->content;
    b = *(int *)stack->next->content;
    if ((order == 1 && a > b) || (order == -1 && a < b)) 
    {
      edge = i;
      i++;
      stack = stack->next;
      continue;
    }
    if (order == 1 && n > a && n < b)
      return i;
    if (order == -1 && n < a && n > b)
      return i;
    i++;
    stack = stack->next;
  }
  if (b < first && n > b && n < first)
      return 0;
  if (first < b && n < b && n > first)
      return 0;
  return (edge);
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
    int nums[] = {1, 4, 8, 12, -10};
    t_list *current = NULL;
    
    for (int i = 0; i < 5; i++) {
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
    printf("Position for 9 : %d == 3 \n", ft_get_pos_of(stack,5 ,9));  // Should find position
    printf("Position for 2: %d == 1\n", ft_get_pos_of(stack,5, 2));  // Should handle number less than all
    printf("Position for 7: %d == 2\n", ft_get_pos_of(stack,5, 7));  // Should handle number greater than all
    printf("Position for 23: %d == 4\n", ft_get_pos_of(stack,5, 23));  // Should find position
    printf("Position for 0: %d == 0\n", ft_get_pos_of(stack,5, 0));  // Should find position
    
    
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
