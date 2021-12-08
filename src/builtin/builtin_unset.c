/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:36:08 by hyospark          #+#    #+#             */
/*   Updated: 2021/12/08 16:41:14 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **arr_cpy(t_bundle *bundle, t_token *token, int len)
{
	int i;
	int k;
	char **key;
	char **env_copy;

	i = 0;
	k = 0;
	env_copy = (char **)malloc(sizeof(char *) * len);
	if (env_copy == NULL)
		return (NULL);
	env_copy[len - 1] = NULL;
	while (bundle->env[i])
	{
		key = ft_split(bundle->env[i], '=');
		if (key == NULL)
			return (NULL);
		if (ft_strcmp(key[0], token->content) != 0)
		{
			env_copy[k] = ft_strdup(bundle->env[i]);
			k++;
		}
		i++;
		all_free(key);
	}
	return (env_copy);
}

int	builtin_unset(t_bundle *bundle)
{
	char	**env_copy;
	char	*env_current;
	int		len;

	while (bundle->token->next && bundle->token->next->token_type != PIPE)
	{
		bundle->token = bundle->token->next;
		len = ft_arrlen(bundle->env);
		if (len == 0)
			return (FAIL);
			env_current = builtin_getenv(bundle, bundle->token->content);
		if (env_current != NULL)
		{
			env_copy = arr_cpy(bundle, bundle->token, len);
			if (env_copy == NULL)
				return (FAIL);
			all_free(bundle->env);
			bundle->env = env_copy;
		}
	}
	return (SUCCESS);
}