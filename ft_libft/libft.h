/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:32:29 by ahaidour          #+#    #+#             */
/*   Updated: 2023/05/06 16:44:00 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_lst
{
	int				content;
	int				index;
	struct t_lst	*next;
}					t_lst;

long int			ft_atoi(char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t n, size_t size);

char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, int start, int len);
void				ft_putendl_fd(char *s, int fd);

void				ft_lstadd_back(t_lst **lst, t_lst *new);
void				ft_lstadd_front(t_lst **lst, t_lst *new);
void				ft_lstclear(t_lst **lst, void (*del)(void *));
void				ft_lstdelone(t_lst *lst, void (*del)(void *));
void				ft_lstiter(t_lst *lst, void (*f)(void *));
t_lst				*ft_lstlast(t_lst *lst);
t_lst				*ft_lstnew(int content);
int					ft_lstsize(t_lst *lst);

#endif
