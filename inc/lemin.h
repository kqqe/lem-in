/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:54 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/11 18:23:49 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_farm	t_farm;
typedef struct s_room	t_room;

/* structure for writing graph edges  */
typedef struct      s_conn
{
	t_room          *room;
	struct s_conn	*next;
}                   t_conn;

/* main room structure  */
struct      s_room
{
	char    *name;
	int     is_start;
	int     is_finish;
	int     blame;
    t_conn  *connections;
	t_room	*next;
};

/* main graph structure */
struct      s_farm
{
	t_room  *room;
    int     rooms_amount;
    int     ant_amount;
};

/* service functions */
int			get_array_len(char **array);
void		free_str_arr(char **array);
t_farm		*allocate_farm_memory();

/* validation, memory allocation, farm filling */
t_farm		*create_farm(char **argv, t_farm *farm);
int			main_validation_fnctn(char *line, t_farm *farm, int operation);
int			get_operation_numbr(char *line, int op);
int			validate_room(char *line, t_farm *farm);
int			validate_edges(char *line, t_farm *farm);
int			get_ants_amount(char *line, t_farm *farm);
int			get_comment_data(char *line, t_farm *farm);


#endif