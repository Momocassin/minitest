/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:16:14 by edvicair          #+#    #+#             */
/*   Updated: 2023/01/18 20:44:08 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	search_egal(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	ft_export_bis(t_msh *msh, bool egal, char **v_global, int i)
{
	t_env	*cpy;
	bool	o;

	o = 0;
	cpy = msh->env;
	while (cpy->next)
	{
		if (!ft_strncmp(cpy->name, v_global[0], (ft_strlen(v_global[0]) + 1)))
		{
			o = 1;
			if (cpy->value)
			{
				free(cpy->value);
				cpy->value = NULL;

			}
			if (v_global[1])
				cpy->value = ft_strdup(v_global[1]);
			else
				cpy->value = ft_strdup("");
			cpy->egal = egal;
			break ;
		}
		cpy = cpy->next;
	}
	if (!o && !ft_strncmp(cpy->name, v_global[0], (ft_strlen(v_global[0]) + 1)))
	{
		if (cpy->value)
		{
			free(cpy->value);
			cpy->value = NULL;
		}
		if (v_global[1])
			cpy->value = ft_strdup(v_global[1]);
		else
			cpy->value = ft_strdup("");
		cpy->egal = egal;
	}
	else if (!o && cpy->next == NULL)
		ft_env_add_back(&msh->env, ft_env_new(msh, v_global[0], v_global[1], egal));
}

void	ft_export(t_msh *msh, char **cmd)
{
	char	**v_global;
	int		i;
	bool	egal;

	i = 1;
	egal = 0;
	v_global = NULL;
	if (!cmd[1])
	{
		ft_sort_export(msh);
		return ;
	}
	while (cmd[i])
	{
		egal = search_egal(cmd[i]);
		v_global = ft_split(cmd[i], '=');
		if (v_global[1] && (v_global[1][0] == 32 || v_global[1][0] == 9))
		{
			v_global[1] = ft_strdup("");
			break ;
		}
		ft_export_bis(msh, egal, v_global, i);
		ft_free_double(v_global);
		i++;
	}
}
