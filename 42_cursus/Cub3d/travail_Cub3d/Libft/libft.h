/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:13:54 by brhajji-          #+#    #+#             */
/*   Updated: 2022/10/07 17:12:10 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Chars */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
char	ft_toupper(int c);
char	ft_tolower(int c);

/* Strings */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* Memoire */
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

int		ft_atoi(const char *nptr);

/* Malloc */
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_char(char const *s1, char const *s2, char s3);
char	*ft_strjoin_cr(char const *s1, char s2);
char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s, char c);
char	**ft_split_solong_bonus(const char *s, char c);
void	ligne_sup(char **str_arr, int *i);

char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* fd */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* PRINTF */
void	ft_putnbr_base_p(unsigned long long int nbr, int *ret_value);
void	ft_put_p(unsigned long long int nbr, int *ret_value);
void	ft_putnbr_base(unsigned int nbr, char type, int *ret_value);
void	ft_put_u(unsigned int nb, int *ret_value);
void	ft_putnbr(int nb, int *ret_value);
void	ft_putchar(char c, int *ret_value);
void	ft_putstr(char *s, int *ret_value);
int		val_print_hexa(const char *str, va_list *ap, int *i, int *ret_value);
int		val_print(const char *str, va_list *ap, int *i, int *ret_value);
int		ft_printf(const char *str, ...);

/* GET_NEXT_LINE */
int		gnl_strchr(char *buf);
int		gnl_strlen(char *s);
char	*gnl_strdup(char *line);
char	*gnl_strjoin(char *line, char *to_add);
char	*save_until_cr(char *line);
void	save_after_cr(char *buf);
char	*check_line(char **line, int fin);
char	*get_next_line(int fd);

/* Bonus */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **clear, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
