/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:15:48 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:15:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define true;
# define false;
#typedef bool;
#*/
#include "../main.h" /*
# struct s_arg;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	arg_operator(const struct s_arg arg)
{
	if (arg.operator && (\
		arg.this[0] == '<' || \
		arg.this[0] == '>' || \
		arg.this[0] == '|' || \
		arg.this[0] == ';'))
		return (true);
	return (false);
}
