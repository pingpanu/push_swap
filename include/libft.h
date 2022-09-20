/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:02:42 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 22:53:19 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
//# ifndef BUFFER_SIZE
//#  define BUFFER_SIZE 500
//# endif

/*bonus part*/
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_lstnew(int input);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
/*basics function*/
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_abs(int nbr);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif
