/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:41:01 by rerayyad          #+#    #+#             */
/*   Updated: 2023/03/29 17:53:56 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_fill(char *stock, int fd);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_line(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_saver(char *stock);

#endif
