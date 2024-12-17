#include "push_swap.h"
#include "../libft/libft.h"

bool ft_is_all_digits(char *str)
{
  while (*str)
    if (!ft_is_digit(*str))
      return (0);
  return (1);
}


t_list ft_create_stack(int ac, char **av)
{
  int num;
  char **str_nums;

  while (ac--)
  {
    str_nums = ft_split(av[ac]);
    if (!str_nums)
      return NULL;
    while (*str_nums)
    {
      if (!ft_is_all_digits(*str_nums))
        return (ft_free_list_of_strs(str_nums));





    
  }

}

int main(int ac, char **av)
{
  t_list stack_a;

  if (ac == 1)
    ft_printf("Error\nNo numbers passed!:[\nto pass argument use for example %s 1 2 3 4 5", av[0]);
  stack_a = ft_create_stack(--ac, &av[1]);



}
