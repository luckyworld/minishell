/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:03:14 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/16 21:30:57 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "fpf_printf.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isescaped(char c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strequ(const char *s1, const char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_pushchar(char *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_countwords(const char *s1, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(const char *s);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_countwords(char const *s1, char c);
char				*ft_itoa(int n);
char				*ft_pushchar(char *s, char c);
int					ft_power(int nb, int power);
int					ft_decade(int nbr);
int					ft_atoi(const char *str);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstpush(t_list *list, t_list *new);

/*
** LIBPRINTF
*/

int					ft_wcharlen(wchar_t wchar);
size_t				ft_wbytelen(wchar_t *ws);
void				*ft_strlower(char *s);
char				*ft_itoa_base(uintmax_t nbr, int base);
int					ft_wchartostr(char *s, wchar_t wc);
size_t				ft_wstrlen(wchar_t *s);
int					ft_wstrtostr(char *s, wchar_t *wstr, int n);
char				*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char				*ft_strsub_with_free(char const *s, unsigned int start,
					size_t len);
char				*ft_transform_wchar_in_char(wchar_t *ws);
int					ft_putwchar_in_char(wchar_t wchar, char *fresh, int i);

#endif