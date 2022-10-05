/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:24:45 by kipark            #+#    #+#             */
/*   Updated: 2022/10/05 21:07:38 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "parser.h"

typedef struct s_here_doc
{
	int					read_end;
	struct s_here_doc	*next;
}	t_here_doc;

t_here_doc	*init_here_doc(t_parsing_list *l_parsing);
t_here_doc	*new_here_doc(int fd);;
t_here_doc	*free_all_here_doc(t_here_doc *here_doc, int this_here_doc_fd);
void		add_here_doc(t_here_doc *here_doc, int fd);
void		print_here_doc(t_here_doc *here_doc);
void		set_here_doc_sig_handler(void);
void		here_doc_sig_handler(int signum);

#endif