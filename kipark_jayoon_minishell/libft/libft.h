/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:25:50 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/24 15:23:14 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef enum e_is_delimeter
{
	DEL_FIRST_CALL,
	DEL_YES,
	DEL_NO,
}	t_delimeter;

typedef struct s_utils_substr
{
	char	*dst;
	char	*src;
}	t_str;

/* ft_check_error	*/
typedef enum e_error
{
	E_LIBFT,
	E_SYSTEM_CALL,
	E_MALLOC
}	t_error;

/*	gnl	*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_util
{
	int				fd;
	char			buf[BUFFER_SIZE];
	ssize_t			index;
	ssize_t			ret_read;
	struct s_util	*next;
}	t_util;

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	malloc_size;
}	t_string;

typedef enum e_util_of_status
{
	SUCCESS = 0,
	FAIL,
	EXIST,
	NOT_EXIST,
	MALLOC_ERROR
}	t_cond;

//gnl
char		*get_next_line(int fd);
t_cond		copy_buffer_to_string(t_util *curr, t_string *ps);
char		*make_return(int fd, t_util *head, t_util **phead, t_string *ps);
t_cond		read_and_copy_to_str(int fd, t_util *curr, t_string *ps);
t_cond		find_node(int fd, t_util **phead, t_util **pcurr);
t_cond		init_string(t_string *ps);
char		*delete_current_node(int fd, t_util *head, t_util **phead);
char		*free_string(t_string *ps);
t_cond		stretch_string(t_string *ps);

// libft
int			ft_atoi(const char *str);
ssize_t		ft_atol(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_issign(int c);
int			ft_isint(ssize_t num);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *set, size_t n);
void		*ft_calloc(size_t cnt, size_t n);
char		*ft_strdup(const char *s);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
ssize_t		ft_putchar_fd(char c, int fd);
ssize_t		ft_putstr_fd(char *s, int fd);
ssize_t		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

void		ft_safe_free(void *ret);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));

// additional func
void		*ft_safe_malloc(size_t size);
void		ft_check_error(t_error e, ssize_t data);
int			ft_strchr_index(char *str, char word);

#endif
