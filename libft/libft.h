/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:34 by hdeniz            #+#    #+#             */
/*   Updated: 2023/11/12 18:00:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 20240106

# define END_OF_NUMBER_INDEX 47 /* 48 - 1 */

/* **************************** [v] INCLUDES [v] **************************** */
# include <stdbool.h> /*
# typedef bool;
# */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] FUNCTIONS [v] **************************** */
extern void				ft_putchar_fd(char character, int fd);
extern void				ft_putnbr_fd(int number, int fd);
extern void				*ft_calloc(unsigned int type_size, unsigned int size);
extern int				ft_atoi(const char *const string);
extern int				ft_strlen(const char *const string);
extern bool				ft_safe_free(char **variable);
extern bool				ft_free_matrix(char ***matrix);
extern unsigned short	ft_numlen(register long long number);
extern char				*ft_strjoin(char const *s1, char const *s2);
extern char				*ft_strjoinfree(char *s1, const char *s2);
extern char				*ft_strdup(const char *const string);
extern bool				ft_strcasecmp(const char *const string, \
const char *const compare);
extern bool				ft_strboolcmp(const char *string, \
const char *compare);
extern char				ft_strcmp(const char *string, const char *compare);
extern char				ft_numindex(long long number, \
register unsigned short index);
extern void				ft_bzero(char *const buffer, register int size);
extern char const		*ft_strchr(char const *string, \
register int character);
extern char				*ft_substr(char const *string, \
unsigned int start, unsigned int len);
extern char				**ft_split(char const *string, register char character);
/* *************************** [^] FUNCTIONS [^] **************************** */

#endif /* LIBFT_H */
