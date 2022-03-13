/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:14:45 by tmatias           #+#    #+#             */
/*   Updated: 2022/02/17 14:05:58 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

# ifndef HEXA_LOWER
#  define HEXA_LOWER "0123456789abcdef"
# endif

# ifndef HEXA_UPPER
#  define HEXA_UPPER "0123456789ABCDF"
# endif

# ifndef DECIMAL
#  define DECIMAL "0123456789"
# endif

# ifndef BINARY
#  define BINARY "01"
# endif

# ifndef OCTAL
#  define OCTAL "01234567"
# endif

# ifndef FD_SIZE
#  define FD_SIZE 10240
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *));

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

int					ft_lstsize(t_list *lst);
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *c1, const char *c2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_memdel(void **ptr);
int					ft_string_is_positive_number(char *str);
int					ft_charmatrixlen(char **matrix);
int					ft_char_count(char *str, char c);
int					ft_charmatrixlen(char **matrix);

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_exit(char *error);
void				ft_freecharmatrix(char **matrix);
void				ft_free_matrix(char ***m);

char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(long long int n, char *base);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa_base_unsigned(unsigned long long int n,
						char *base);

#endif
