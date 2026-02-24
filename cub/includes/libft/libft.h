/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hreusing <hreusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:46:03 by hreusing          #+#    #+#             */
/*   Updated: 2024/06/27 16:19:32 by hreusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> 
# include <stdlib.h>
# include <string.h>
# include <limits.h>   
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

/* GET NEXT LINE */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_get_line_as_str(t_list *list, char *str);

void	ft_create_list(t_list **list, int fd);
void	ft_dealloc(t_list **list, t_list *clean_node, char *buf);
void	ft_lst_to_str(t_list *src_lst, char *dest);
void	ft_get_unused_chars(t_list **list);
void	ft_copy_str(t_list *src_ls, char *dest);
void	ft_lstappend(t_list **lst, char *buf, int fd);
t_list	*ft_lstlast(t_list *lst);

int		ft_found_newline(t_list *list);
size_t	ft_lenof_line(t_list *list);

/*LIBFT*/

/*LIST FUNTIONS NEED TO BE UPDATED TO NEW STRUCT*/
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

int		ft_isalnum(int argument);
int		ft_isalpha(int argument);
int		ft_isascii(int argument);
int		ft_isdigit(int argument);
int		ft_isprint(int argument);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_bzero(void *str, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);

char	**ft_split(char const *s, char c);
char	*ft_strchr(char const *str, int chr);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, char const *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(char const *str, int chr);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	*ft_calloc(size_t nitems, size_t size);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/*FT_PRINTF*/

int		ft_printf(const char *format, ...);
int		ft_print_str(char *str);
int		ft_print_digit(long n, int base, char specifier);
int		ft_print_char(char c);
int		ft_print_adress(void *format);

#endif