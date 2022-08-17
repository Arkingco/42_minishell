/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/17 14:39:33 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <stdio.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define GET 0
# define SET 1

typedef struct s_envlst
{
	char			*key;
	char			*value;
	struct s_envlst	*next;
}	t_envlst;

typedef struct s_global
{
	char		**envp;
	t_envlst	*lst_env;
}	t_global;

// main.c

//main_loop.c
void	loop_get_commandline(void);

// init.c
void	init(int argc, char *envp[]);
void	init_env_lst(char *envp[]);
void	update_shlvl(void);

// signal_action.c
void	set_signal_action(void);

// env_list_adt_1.c
void		ft_env_lstadd_back(t_envlst **lst, t_envlst *new);
int			ft_env_lstsize(t_envlst *lst);
t_envlst	*ft_addenv(char *key, char *value);
t_envlst	*ft_env_lstlast(t_envlst *lst);
void		ft_free_envlst(t_envlst *lst);

// env_list_adt_2.c
// t_envlst	*ft_env_lstdup(t_envlst *lst);
t_envlst	*ft_getenv_lst(char *key);
char		*ft_getenv(char *key);
int			ft_delenv(char *key);
void		ft_addenv_str(char *str_envp);

// env_list_adt_3.c
int		ft_has_env(char *key);
void	ft_setenv(char *key, char *value);
char	**ft_envlst_to_envp(void);

// util_1.c
void	ft_error(int exit_status, char *message);
void	ft_free_envp(char **envp);

// env.c
void	env(void);
#endif
