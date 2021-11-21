/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:35:44 by hyospark          #+#    #+#             */
/*   Updated: 2021/11/22 00:02:45 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_cmd(t_bundle *bundle)
{
	int	result;

	result = is_builtin(bundle);
	// if (!result)
	// 	result = is_bin(bundle, bundle->token);
	return (result);
}

int	execute_cmd(t_bundle *bundle)
{
	int result;
	int	child_ps;

	while (bundle->token)
	{
		if (bundle->token->pipe == PIPE)
			child_ps = pipe_cmd(bundle);
		result = check_cmd(bundle);
		// if (child_ps)
		// 	child_exit(bundle, result);
		bundle->token = bundle->token->next;
	}
	return (result);
}
