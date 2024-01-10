/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_just_newline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:45:40 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:45:41 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../main.h" /*
# define MALLOC_ERROR;
#typedef t_shell;
#   void error_shell(t_shell, char *, int, char *);
#*/
#include "../../../libft/libft.h" /*
#   char *ft_strdup(char *);
#   bool ft_safe_free(char **);
#   void *ft_calloc(Uint, Uint);
#    int ft_strlen(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	here_doc_just_newline(t_shell shell)
{
	char			*temp;
	register int	index;

	temp = ft_strdup(shell->input);
	if (!temp)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
	ft_safe_free(&shell->input);
	shell->input = (char *) ft_calloc(sizeof(char), ft_strlen(temp) + 2);
	if (!shell->input)
		ft_safe_free(&temp);
	if (!shell->input)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 4), "ft_calloc()");
	index = -1;
	while (++index, !!temp[index])
		shell->input[index] = temp[index];
	shell->input[index] = '\n';
	shell->input[index + 1] = 0;
	ft_safe_free(&temp);
	shell->org_input = shell->input;
}
