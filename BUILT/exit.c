/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:12:04 by edvicair          #+#    #+#             */
/*   Updated: 2023/01/18 19:22:22 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_env(t_env *env)
{
	t_env *tmp;

	tmp = NULL;
	while (env)
	{
		if (env->name);
			free(env->name);
		if (env->value);
			free(env->value);
		if (env->next)
		{
			tmp = env;
			env = env->next;
			free(tmp);
		}
		else 
			break;
	}
	free(env);
	env = NULL;
}

void	ft_exit(t_msh *msh)
{
	int res;

	ft_free_env(msh->env);
	if (msh->token->cmd[1])
	{
		free(msh->line);
		res = ft_atoi(msh->token->cmd[1]);
		ft_free_token(msh, msh->token);
		exit(res);
	}
	ft_free_token(msh, msh->token);
	free(msh->line);
	exit(0);
}
