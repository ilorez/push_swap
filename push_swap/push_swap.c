#include "push_swap.h"
#include "../libft/libft.h"
#include "../includes/bool.h"

bool ft_is_all_digits(char *str)
{
  while (*str)
    if (!ft_is_digit(*str))
      return (false);
  return (true);
}

bool ft_create_stack(int ac, char **av, t_list *stack_a)
{
  long long num;
  char **str_nums;
  char *tmp;

  while (ac--)
  {
    str_nums = ft_split(av[ac]);
    if (!str_nums)
      return (false);
    while (*str_nums)
    {
      if (!ft_is_all_digits(*str_nums))
        return (ft_free_list_of_strs(str_nums));
      num = ft_atol(*str_nums);
      if (num > INT_MAX || num < INT_MIN)
      {
        ft_printf("Error\nnot valid number\nfound a number out of INT range\n");
        return (ft_free_list_of_strs(str_nums));
      }
      ft_lst_add_front((int)num, stack_a);
      tmp = *str_nums;
      ++str_nums;
      free(tmp);
    }
    ft_free_list_of_strs(str_nums);
  }
  return (true);
}

int main(int ac, char **av)
{
  t_list stack_a;

  stack_a = NULL;
  if (ac == 1)
    ft_printf("Error\nNo numbers passed!:[\nto pass argument use for example %s 1 2 3 4 5", av[0]);
  if (!ft_create_stack(--ac, &av[1], &stack_a))
    ft_lst_clear(stack_a);
  ft_print_stack(stack_a);

}
