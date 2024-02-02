/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:36:26 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/02 22:55:45 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_lis
{
	int				*length;
	int				*sub;
	int				i;
	int				j;
}					t_lis;

typedef struct s_stack
{
	struct s_stack	*prev;
	int				nb;
	int				index;
	int				posa;
	int				posb;
	long			lastnb;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rr;
	unsigned int	rra;
	unsigned int	rrb;
	unsigned int	rrr;
	int				above_mediun;
	struct s_stack	*next;
}					t_stack;

int					ft_isdigit(int car);
void				ft_sortthree(t_stack **stack_A);
void				ft_sort(t_stack **stack_A, t_stack **stack_B);
void				*ft_calloc(size_t elementCount, size_t elementSize);
int					ft_lstindex(t_stack *lst);
void				ft_pushtob_intialisation(t_stack **stack_A, int **arr,
						int **sorted);
void				ft_free(t_lis *lis, int *arr);
void				movethesmallest(t_stack **stack_A);
void				*ft_memset(void *mem, int c, size_t n);
int					ft_save(int length, int flag);
int					*ft_allocatnumber(int num);
int					abs(int x);
int					ft_isinthesub(int number, int *arr, int length);
int					ft_validlisstack(t_stack *a, int *arr);
int					ft_sorted(t_stack *a);
void				ft_reset(t_stack *head);
int					ft_strlen(const char *str);
int					ft_findlargest(t_stack *stack_A);
void				ft_exit(char *message);
void				ft_setpositions(t_stack **stack_A, t_stack **stack_B);
void				*ft_bzero(void *mem, size_t n);
t_stack				*findthelargest(t_stack *stack_A);
void				ft_setpos(t_stack *current_B, t_stack *head_A,
						t_stack *smallest, int largest);
void				ft_setcost(t_stack *stack_A, t_stack *stack_B);
void				ft_setpositions(t_stack **stack_A, t_stack **stack_B);
void				setrrr(t_stack *stack);
void				setrr(t_stack *stack);
int					*ft_fromstacktoarr(t_stack *stack_A);
int					ft_check(t_stack *stack);
void				ft_pushnonlistob(t_stack **stack_A, t_stack **stack_B);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);
void				ft_lstiter(t_stack *lst, void (*f)(int));
t_stack				*ft_lstmap(t_stack *lst, int (*f)(int),
						void (*del)(void *));
t_stack				*findthesmallest(t_stack *stack_A);
long long			ft_atoi(char *num);
char				**failsafe(char **split);
void				ft_pushnonlistob(t_stack **stack_A, t_stack **stack_B);
t_stack				*ft_lstnew(int content);
int					ft_fillstack(t_stack **stack, char *str, char **numbers);
char				**ft_split(char *str, char sep);
int					ft_checkdup(t_stack *list, int number);
int					ft_checksign(char *number);
int					checkvalidnumber(char *number);
int					ft_strlen(const char *str);
int					ft_printf(const char *str, ...);
t_stack				*parse(t_stack *stack, char **str);
void				ft_lstdelone(t_stack *lst);
void				ft_lstclear(t_stack **lst);
t_stack				*ft_lstfirst(t_stack *stack);
void				ft_sortfive(t_stack **stack_A, t_stack **stack_B);
void				ft_sortfour(t_stack **stack_A, t_stack **stack_B);
void				sa(t_stack **stack_A, int flag);
void				sb(t_stack **stack_B, int flag);
void				ra(t_stack **stack_A, int flag);
void				rb(t_stack **stack_B, int flag);
void				ss(t_stack **stack_A, t_stack **stack_B);
void				pa(t_stack **stack_A, t_stack **stack_B, int flag);
void				pb(t_stack **stack_A, t_stack **stack_B, int flag);
void				rr(t_stack **stack_A, t_stack **stack_B);
void				rra(t_stack **stack_A, int flag);
void				rrb(t_stack **stack_B, int flag);
void				bubblesort(int *arr, int length);
int					ft_morethantwo(t_stack *lst);
void				rrr(t_stack **stack_A, t_stack **stack_B);
int					*ft_lis(int *arr, int len);
int					ft_save(int length, int flag);
int					ft_isinthesub(int number, int *arr, int length);
void				ft_setmoves(t_stack *stack_B);
int					ft_validlisstack(t_stack *a, int *arr);
int					*ft_fromstacktoarr(t_stack *stack_A);
void				print_stack(const char *label, t_stack *stack);
t_lis				*ft_lengthsub(int len, int *arr);
void				ft_9lebche9leb(t_stack **stack_A, t_stack **stack_B);
// t_stack				*ft_find_the_cheapest(t_stack **stack_A,
// t_stack **stack_B);
#endif
