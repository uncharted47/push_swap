/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:10:15 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/02 22:53:54 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	struct s_stack	*target_node;
	struct s_stack	*next;
}					t_stack;

char				**ft_split(char *str, char sep);
t_stack				*parse(t_stack *stack_A, char **str);
void				ft_exit(char *message);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
char				**failsafe(char **str);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);
long long			ft_atoi(char *num);
t_stack				*ft_lstnew(int content);
void				ft_lstdelone(t_stack *lst);
void				sa(t_stack **stack_A);
void				sb(t_stack **stack_B);
void				ra(t_stack **stack_A);
void				rb(t_stack **stack_B);
void				ss(t_stack **stack_A, t_stack **stack_B);
void				pa(t_stack **stack_A, t_stack **stack_B);
void				pb(t_stack **stack_A, t_stack **stack_B);
void				rr(t_stack **stack_A, t_stack **stack_B);
void				rra(t_stack **stack_A);
void				rrb(t_stack **stack_B);
int					checkvalidnumber(char *number);
void				ft_lstclear(t_stack **lst);
void				rrr(t_stack **stack_A, t_stack **stack_B);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_isdigit(int car);
int					ft_checkdup(t_stack *stack, int number);
int					ft_morethantwo(t_stack *lst);
t_stack				*ft_lstfirst(t_stack *stack);
int					ft_sorted(t_stack *a);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
