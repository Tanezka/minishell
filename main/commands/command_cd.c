/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:08:26 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/08 16:08:28 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../main.h" /*
# define PATH_MAX
# define FILE_NAME_LONG
#typedef t_shell;
#    int skip_docs(t_shell);
#   void set_variable(char *, char *, t_shell);
#   char *get_variable_direct_value(char *, t_shell);
#   void werror_shell(t_shell, char *, int, char *);
#   void perror_shell(t_shell, char *, int, char *);
#   char *get_variable(char *, t_shell);
#    int command_pwd(t_shell);
#        */
#include "../../libft/libft.h" /*
#   void ft_bzero(char *, int);
#    int ft_strboolcmp(char *, char *);
#    int ft_strlen(char *);
#        */
#include <unistd.h> /*
# define F_OK
#   char *getcwd(char *, size_t);
#    int access(char *, int);
#    int chdir(char *);
#ssize_t write(int, void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	cd_home(t_shell shell);
extern __inline__ void	set_new_dir(char new_dir[PATH_MAX], char *other_char);
extern __inline__ int	cd_error(t_shell shell, char *file);
extern __inline__ int	check_currenct_dir(t_shell shell);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	command_cd(t_shell shell)
{
	char	new_dir[PATH_MAX];

	shell->errorlevel = (shell->index++, 0U);
	(skip_docs(shell), ft_bzero(new_dir, PATH_MAX));
	if ((shell->arg[shell->index].this == ((void *)0) && cd_home(shell)) || \
		(ft_strboolcmp(shell->arg[shell->index].this, "-") && \
		command_pwd(shell)) || !check_currenct_dir(shell))
		return ;
	if (ft_strlen(shell->arg[shell->index].this) >= PATH_MAX)
	{
		werror_shell(shell, FILE_NAME_LONG, 0, "cd");
		return ;
	}
	if (shell->arg[shell->index].this[0] == '/')
		set_new_dir(new_dir, shell->arg[shell->index].this);
	else
	{
		(getcwd(new_dir, PATH_MAX), set_new_dir(new_dir, "/"));
		set_new_dir(new_dir, shell->arg[shell->index].this);
	}
	if ((access(new_dir, F_OK) < 0 || chdir(new_dir) != 0) && \
		cd_error(shell, shell->arg[shell->index].this))
		return ;
	set_variable("OLDPWD", shell->pwd, shell);
	(getcwd(shell->pwd, PATH_MAX), set_variable("PWD", shell->pwd, shell));
}

extern __inline__ int
	check_currenct_dir(t_shell shell)
{
	char	current_dir[PATH_MAX];

	ft_bzero(current_dir, PATH_MAX);
	if (!getcwd(current_dir, PATH_MAX))
	{
		perror_shell(shell, ((void *)0), 0, HOW_THE_FUCK_CD_FAILED);
		if (chdir("/") != 0)
		{
			cd_error(shell, "/");
			return (0);
		}
		getcwd(shell->pwd, PATH_MAX);
		set_variable("OLDPWD", ((void *)0), shell);
		set_variable("PWD", shell->pwd, shell);
		return (0);
	}
	return (1);
}

extern __inline__ int
	cd_home(t_shell shell)
{
	char	*home;
	char	new_dir[PATH_MAX];

	home = get_variable_direct_value("HOME", shell);
	if (!home)
	{
		shell->errorlevel = (unsigned int)1;
		werror_shell(shell, HOME_NOT_SET, 0, "cd");
		return (1);
	}
	if (access(home, F_OK) != -1)
		chdir(home);
	else
	{
		shell->errorlevel = (unsigned int)1;
		perror_shell(shell, home, 0, "cd");
		return (1);
	}
	getcwd(new_dir, PATH_MAX);
	getcwd(shell->pwd, PATH_MAX);
	set_variable("PWD", shell->pwd, shell);
	return (1);
}

extern __inline__ void
	set_new_dir(char new_dir[PATH_MAX], char *other_char)
{
	register int	len;
	register int	index;

	index = -1;
	len = ft_strlen(new_dir) - 1;
	while (++index, ++len, other_char[index])
		new_dir[len] = other_char[index];
	new_dir[len] = 0;
}

extern __inline__ int
	cd_error(t_shell shell, char *file)
{
	char	*cmd42_name;

	shell->errorlevel = (unsigned int)1;
	cmd42_name = get_variable("CMD42_NAME", shell);
	write(shell->std_out_fd, "-", 1);
	write(shell->std_out_fd, cmd42_name, ft_strlen(cmd42_name));
	write(shell->std_out_fd, ": cd", 4);
	if (!!file)
	{
		write(shell->std_out_fd, ": `", 3);
		write(shell->std_out_fd, file, ft_strlen(file));
		write(shell->std_out_fd, "'", 1);
	}
	perror("");
	return (1);
}
