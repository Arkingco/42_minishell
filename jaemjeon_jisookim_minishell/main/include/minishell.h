/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/19 16:42:18 by jisookim         ###   ########.fr       */
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

# define INPUT 0
# define OUTPUT 1

enum	e_token
{
	E_WORD = 0,
	E_REDIRECT,
	E_PIPE,
	E_NULL
};

enum	e_redirect
{
	E_REDI_R = 0,
	E_REDI_L,
	E_REDI_RR,
	E_REDI_LL
};

typedef struct s_token
{
	int				type;
	int				redirect_type;
	char			*word_value;
	struct s_token	*next;
}	t_token;

typedef struct s_simple_command
{
	t_token						cur;
	struct	s_simple_command	*next;
}	t_simple_command;

typedef struct s_redirect
{
	t_token		*redirect_io[2];
}	t_redirect;

typedef struct s_cmd
{
	t_simple_command	simple_command;
	t_redirect			redirect;
	struct s_cmd		*next;
}	t_cmd;

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
	t_token		*lst_token;
	t_cmd		*lst_cmd;
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

// pwd.c
void	pwd(void);

// paring.c
void	parsing(char *line);
void	make_token_list(char *line);
void	make_cmd_list(void);

// parse_token.c
void	parse_add_redirect_token(t_token *token_addr, int io);

// token_list_adt_1.c
void	ft_token_lstadd_back(t_token **lst, t_token *new);
int		ft_token_lstsize(t_token *lst);
t_token	*ft_addtoken(int type, int redirect_type, char *word_value);
t_token	*ft_token_lstlast(t_token *lst);
void	ft_free_token(t_token *lst);
t_token	*ft_tokendup(t_token *token);
#endif
