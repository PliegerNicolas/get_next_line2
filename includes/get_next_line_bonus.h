/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:09:46 by nplieger          #+#    #+#             */
/*   Updated: 2023/01/17 12:03:25 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************** */
/* * GET_NEXT_LINE						* */
/* ************************************** */

char		*get_next_line(int fd);

/* ************************************** */
/* * GET_NEXT_LINE_UTILS				* */
/* ************************************** */

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			contains_nl(char *rem, size_t endl);

#endif
