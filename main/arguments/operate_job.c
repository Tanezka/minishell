/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:54:54 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 23:54:54 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
#typedef t_shell;
#typedef t_operator;
#    int tilda_valid(t_shell, t_operator, int);
#   char *get_variable(char *, t_shell);
#    int dollar_valid(t_shell, int);
#   char *get_varaible_by_name(char *, t_shell, int);
#    int variable_name_len(char *, int);
#*/
#include "../../libft/libft.h" /*
# define END_OF_NUMBER_INDEX;
#   char ft_numindex(long , ushort);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	overwrite_this(t_shell shell, char *this, char *copy, \
int *string_index);
extern __inline__ int	put_dollar(t_shell shell, char **this, \
int *string_index);
extern __inline__ int	put_exit_status(t_shell shell, char **this, \
int *string_index);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	operate_job(t_shell shell, int arg_index, int *string_index, t_operator op)
{
	char	*this;

	if (op->single_quote)
		return (0);
	this = shell->arg[arg_index].this;
	if (*shell->input == '~' && tilda_valid(shell, op, 0))
		return (overwrite_this(shell, this, get_variable("HOME", shell), \
			string_index));
	if (*shell->input == '$' && *(shell->input + 1) == '?')
		return (put_exit_status(shell, &this, string_index));
	else if (*shell->input == '$' && dollar_valid(shell, 0))
		return (put_dollar(shell, &this, string_index));
	return (0);
}

extern __inline__ int
	overwrite_this(t_shell shell, char *this, char *copy, int *string_index)
{
	register int	index;

	shell->input++;
	if (!copy)
		return (1);
	index = -1;
	while (++index, !!copy[index])
	{
		this[*string_index] = copy[index];
		++(*string_index);
	}
	return (1);
}

extern __inline__ int
	put_dollar(t_shell shell, char **this, int *string_index)
{
	char			*variable;
	register int	variable_index;

	variable_index = 0;
	variable = get_varaible_by_name(shell->input, shell, 0);
	while (variable[variable_index])
	{
		(*this)[*string_index] = variable[variable_index];
		++variable_index;
		*string_index += 1;
	}
	shell->input += variable_name_len(shell->input + 1, 0);
	return (1);
}

extern __inline__ int
	put_exit_status(t_shell shell, char **this, int *string_index)
{
	register char	value;
	register int	variable_index;

	variable_index = 0;
	value = 0;
	while (1)
	{
		value = 48 + ft_numindex(shell->errorlevel, variable_index);
		if (value == END_OF_NUMBER_INDEX)
		{
			shell->input += 2;
			return (1);
		}
		(*this)[*string_index] = value;
		++variable_index;
		*string_index += 1;
	}
	return (0);
}
