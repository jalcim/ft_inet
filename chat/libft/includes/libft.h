/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:34:31 by nbahri            #+#    #+#             */
/*   Updated: 2014/03/26 05:42:38 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H__
# define __LIBFT_H__
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 1

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

int		ft_printf(const char *fmt, ...);
int		ft_quicksort(int *intab, int beg, int end);
void	put_int_t(int *int_tab, int size);
void	sort_int(int *t, int size);
void	ft_put_tb(char **tb);
void	ft_sort_t(int i, int size, char **t);
char	*ft_strjoin_free(char *a, char *b, int nb);
int		get_next_line(int const fd, char **line);
char	**ft_strsplit(const char *s, char c);
char	**ft_get_tab(const char *s);
size_t	ft_strlen(char const *str);
int		ft_int_len(int nb);
void	ft_put_int_tab(int *int_tab, int size);
char	*ft_strrev(char *str);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putnbr(int nb);
void	ft_putnbr_fd(int n, int fd);
int		ft_power(int nb, int power);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_strdup(char const *s1);
char	*ft_strcat(char *dest, char const *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strstr(char const *str1, char const *str2);
char	*ft_strnstr(char const *str1, char const *str2, size_t n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strtrim(char const *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strnew(size_t size);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strmap(char const *s, char (*f) (char));
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
size_t	ft_strlcat(char *dest, const char *src, size_t dest_size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f) (char *));
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_memdel(void **ap);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memalloc(size_t size);

#endif
