/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:01:29 by ybarbier          #+#    #+#             */
/*   Updated: 2015/05/05 14:01:30 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void		ft_bzero(void *s, size_t n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int	    	ft_puts(char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);
void		*ft_memalloc(size_t size);
void		ft_cat(int fd);
size_t		ft_strlen(char *s);
char		*ft_strdup(const char *src);
char		*ft_strcat(char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strequ(char const *s1, char const *s2);
int	    	ft_putchar(char c);
int	    	ft_putchar_fd(char c, int fd);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strnew(size_t size);

#endif
