/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:36:08 by edvicair          #+#    #+#             */
/*   Updated: 2023/01/18 19:24:52 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    ft_free_double(char **s)
{
    int i;

    i = 0;
    if (s == NULL)
        return ;
    while (s[i])
    {
        free(s[i]);
        s[i] = NULL;
        i++;
    }
    free(s);
    s = NULL;
}

void    ft_free_redir(t_redir *redir)
{
    t_redir *tmp;

	printf("ici : %ld\n", sizeof(t_redir));
	printf("caca\n");
    while (redir)
    {
    	if (redir->feldup)
            free(redir->feldup);
        if (redir->next)
        {
    		tmp = redir;
    		redir = redir->next;
    		free(tmp);
        }
		else
			break;
    }
    free(redir);
	redir = NULL;
}

void	ft_free_token(t_msh *msh, t_token *token)
{
	t_token *tmp;
	
	printf("1\n");

	while (token)
	{
		printf("ici\n");
        ft_free_redir(token->redir);
		ft_free_double(token->cmd);
		if (token->next)
		{
			tmp = token;
			token = token->next;
			free(tmp);
		}
		else
			break;
	}
	free(token);
	token = NULL;
    msh->in = 0;
    msh->out = 1;
}