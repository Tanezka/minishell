/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:44:36 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/09 17:44:37 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../main.h" /*
# define MALLOC_ERROR;
# define UNEX_TOKEN;
# struct s_operator;
#typedef t_shell;
#   void here_doc_just_one_char(t_shell, char);
#   void reset_here_doc_operator(char *, t_operator);
#   void prompt_preparer(t_shell, char *);
#   void cancel_here_doc(t_shell, struct s_operator);
#   bool dollar_is_valid(char *);
#   void replace_dollar_with_value(char **, t_shell);
#   void set_here_doc_operator(char *, t_operator);
#   void handle_sigint(int);
#   void error_shell(t_shell, char *, int, char *);
#   bool char_whitespace(char);
#   void werror_shell(t_shell, char *, int, char *);
#*/
#include <stdio.h> /*
#typedef FILE;
^------> <readline/readline.h>
#*/
#include <readline/readline.h> /*
@ <----- <stdio.h> REQUIRED
@ +----+ +------------+
@ |FLAG| | -lreadline |
@ +----+ +------------+
#typedef rl_getc_function();
#   char *readline(char *);
#*/
#include "../../../libft/libft.h" /*
#   bool ft_safe_free(char **);
#   char *ft_strdup(char *);
#   void *ft_calloc(Uint, Uint);
#    int ft_strlen(char *);
#   char *ft_strjoinfree(char *, char *);
#*/
#include <signal.h> /*
# define SIGINT;
#sigh... signal(int, sighandler_t); ((sighandler_t))
#*/
#include <stdbool.h> /*
# define true;
#typedef bool;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	join_here_doc(t_shell shell, struct s_operator operator);
static bool	input_err(t_shell shell, struct s_operator operator);
static bool	if_loop(struct s_operator operator);
static char	next_doc(struct s_operator operator);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	quote_here_doc(t_shell shell)
{
	struct s_operator	o;

	reset_here_doc_operator(shell->input, &o);
	here_doc_just_one_char(shell, next_doc(o));
	while (if_loop(o))
	{
		prompt_preparer(shell, prepare_here_doc(shell, &o));
		shell->quote_here_doc = readline(shell->prompt);
		if (!shell->quote_here_doc || g_signal == SIGINT || input_err(shell, o))
		{
			ft_safe_free(&shell->quote_here_doc);
			cancel_here_doc(shell, o);
			return ;
		}
		if (!o.single_quote && dollar_is_valid(shell->quote_here_doc))
			replace_dollar_with_value(&shell->quote_here_doc, shell);
		set_here_doc_operator(shell->quote_here_doc, &o);
		if (*shell->quote_here_doc == 0)
			here_doc_just_one_char(shell, next_doc(o));
		else
			shell->org_input = (join_here_doc(shell, o), shell->input);
		ft_safe_free(&shell->quote_here_doc);
	}
	rl_getc_function = shell->original_rl_getc_function;
	signal(SIGINT, handle_sigint);
}

static void
	join_here_doc(t_shell shell, struct s_operator operator)
{
	bool			any_operator;
	char			*temp;
	register int	index;
	register int	input_index;

	any_operator = operator.single_quote || operator.double_quote;
	temp = ft_strdup(shell->input);
	if (!temp)
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_strdup()");
	ft_safe_free(&shell->input);
	shell->input = (char *) ft_calloc(sizeof(char), ft_strlen(temp) + \
		ft_strlen(shell->quote_here_doc) + 1 + any_operator);
	if (!shell->input && ft_safe_free(&temp))
		error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), "ft_calloc()");
	index = -1;
	input_index = -1;
	while (++index, ++input_index, !!temp[index])
		shell->input[input_index] = temp[index];
	index = (ft_safe_free(&temp), --input_index, -1);
	while (++input_index, ++index, !!shell->quote_here_doc[index])
		shell->input[input_index] = shell->quote_here_doc[index];
	shell->input[input_index] = '\n';
	shell->input[input_index + any_operator] = 0;
	shell->org_input = shell->input;
}

static bool
	input_err(t_shell shell, struct s_operator operator)
{
	register int	index;

	if (!shell->quote_here_doc)
		return (false);
	index = -1;
	while (++index, !!shell->quote_here_doc[index])
	{
		if (shell->quote_here_doc[index] == '|' || \
			shell->quote_here_doc[index] == ';')
		{
			shell->input = ft_strjoinfree(shell->input, " ");
			if (!shell->input && ft_safe_free(&shell->quote_here_doc))
				error_shell(shell, MALLOC_ERROR, (__LINE__ - 2), \
					"ft_strfreejoin()");
			shell->org_input = (join_here_doc(shell, operator), shell->input);
			return (true);
		}
		if (!char_whitespace(shell->quote_here_doc[index]))
			return (false);
	}
	return (false);
}

static bool
	if_loop(struct s_operator operator)
{
	if (operator.pipe || operator.single_quote || operator.double_quote)
		return (true);
	return (false);
}

static char
	next_doc(struct s_operator operator)
{
	if (o.pipe)
		return (0);
	if (o.double_quote || o.single_quote)
		return ('\n');
	return (0);
}
