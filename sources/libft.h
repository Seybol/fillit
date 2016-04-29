/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:08:55 by scebula           #+#    #+#             */
/*   Updated: 2016/01/18 19:57:01 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

void				*ft_memset(void *b, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
typedef struct		s_tetri
{
	int				x[4];
	int				y[4];
	unsigned char	letter;
	int				length;
	int				height;
	struct s_tetri	*next;
}					t_tetri;
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	int				max;
	char			**tabmax;
	int				max_found;
}					t_data;
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
int					ft_max(int *tab);
void				ft_print_tab(char **tab);
int					ft_algo(int p, t_tetri *t, char **tab, t_data *d);
char				**ft_copytab(char **src);
int					ft_tab_max_square(char **s);
int					ft_next_position(int p, char **tab, t_data *d, t_tetri *t);
void				ft_cut_tab(char **tab, int max);
int					ft_data_to_list(t_list **begin_list, int fd);
int					ft_check_list(t_list **begin_list);
int					ft_test(char *str);
void				ft_create_t_tetri(t_list **list, t_tetri **t, char letter);
void				ft_coor_init(int *x, int *y, int p, t_data *d);
void				ft_update_tab(char **tab, int x, int y, t_tetri *t);
void				ft_repare_tab(char **tab, int x, int y, t_tetri *t);
void				ft_initnull(int *fd, t_list **l, t_tetri **t, t_data **d);
#endif
