/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sermini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 18:20:23 by jbert             #+#    #+#             */
/*   Updated: 2014/03/22 13:50:54 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "42sh.h"

int		tb_realloc(char ***tb)
{
	char	**tmp;
	int		i;

	i = 0;
	while (*tb[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (*tb[i])
	{
		tmp[i] = *tb[i];
		free(*tb[i]);
		i++;
	}
	tmp[i++] = NULL;
	tmp[i] = NULL;
	free(*tb[i]);
	*tb = tmp;
	return (i);
}

char	*find_login(char *b)
{
	char			login[11];
	char			*tmp;
	unsigned int	i;

	ft_bzero(login, 11);
	i = 0;
	while (b[i] && b[i] != '\n')
	{
		login[i] = b[i];
		i++;
	}
	tmp = (char *)malloc(sizeof(char) * 11);
	tmp = ft_strcpy(tmp, login);
	return (tmp);
}

int		*filedes(int *fd)
{
	static int	*file;
	int			*tmp;

	tmp = file;
	file = fd;
	return (tmp);
}

int		ft_chat(char *b, int *fd)
{
	char	*login;

	login = find_login(b);
	write(fd[1], b, ft_strlen(b));
	write(fd[1], "\0", 1);
	write(fd[1], (char *)4, 1);
	return (0);
}

void	ft_start(char *t, t_chat *chat)
{
	char	*login;
	t_conv	*tmp;

	login = find_login(t);
	tmp = NULL;
	while (chat->conv != NULL)
	{
		tmp = chat->conv;
		if (ft_strcmp(login, chat->conv->login))
			chat->conv = chat->conv->next;
		else
			break ;
	}
	if (chat->conv == NULL)
	{
		chat->conv = (t_conv *)malloc(sizeof(t_conv) * 1);
		chat->conv->login = (char *)malloc(sizeof(char) * 12);
		ft_bzero(chat->conv->login, 12);
		chat->conv->login = ft_strncpy(chat->conv->login, login, 11);
		ft_putendl(chat->conv->login);
		chat->conv->conv = (char **)malloc(sizeof(char *) * 2);
		chat->conv->conv[0] = ft_strdup(&t[ft_strlen(login) + 1]);
		chat->conv->conv[1] = NULL;
		chat->conv->prev = tmp;
		if (tmp)
			chat->conv->prev->next = chat->conv;
		chat->conv->next = NULL;
	}
	else
		chat->conv->conv[tb_realloc(&(chat->conv->conv))] = ft_strdup(&t[ft_strlen(login)]);
	while (chat->conv->prev != NULL)
		chat->conv = chat->conv->prev;
}

void	put_login(t_conv *conv, char *now)
{
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	ft_putendl("Amis :");
	while (conv->next != NULL)
	{
		if (!ft_strcmp(now, conv->login))
			tputs(tgetstr("uc", NULL), 1, tputs_putchar);
		ft_putendl(conv->login);
		if (!ft_strcmp(now, conv->login))
			tputs(tgetstr("ue", NULL), 1, tputs_putchar);
		conv = conv->next;
	}
	if (conv)
	{
		if (!ft_strcmp(now, conv->login))
			tputs(tgetstr("us", NULL), 1, tputs_putchar);
		ft_putendl(conv->login);
		if (!ft_strcmp(now, conv->login))
			tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	}
	while (conv->prev != NULL)
		conv = conv->prev;
}

void	sjgr(t_conv *conv, struct termios *term)
{
	t_coor	coor;
	char	car[5];
	char	*now;

	coor.xpos = coor.ypos = coor.lm = coor.sl = 0;
	ft_init_term(&coor, term);
	ft_bzero(car, 5);
	now = conv->login;
	while (*(unsigned int *)car != ESC)
	{
		ft_bzero(car, 5);
		read(0, car, 4);
		if (*(unsigned int *)car == UP)
		{
			while (conv->next && ft_strcmp(conv->login, now))
				conv = conv->next;
			if (conv->prev)
				conv = conv->prev;
			now = conv->login;
			while (conv->prev != NULL)
				conv = conv->prev;
		}
		if (*(unsigned int *)car == DOWN)
		{
			while (conv->next && ft_strcmp(conv->login, now))
				conv = conv->next;
			if (conv->next)
				conv = conv->next;
			now = conv->login;
			while (conv->prev != NULL)
				conv = conv->prev;
		}
		put_login(conv, now);
		if (*(unsigned int *)car == RETURN)
		{
			if (!ft_strcmp(now, "New message"))
				new_mess(term);
			else
			{
				while (conv->next && ft_strcmp(conv->login, now))
					conv = conv->next;
				if (conv->conv)
					ft_put_tb(conv->conv);
				else
					ft_putendl("Empty conv");
				while (conv->prev != NULL)
					conv = conv->prev;
			}
		}
	}
	ft_restor_term(term);
}

void	new_mess(struct termios *term)
{
	char	*now;
	int		i;
	char	car[5];

    term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	ft_putstr("\nMessage to : ");
	now = (char *)malloc(sizeof(char) * 13);
	ft_bzero(now, 13);
	ft_bzero(car, 5);
	i = 0;
	while ((i <= 12) && *(unsigned int *)car != RETURN)
	{
		ft_bzero(car, 5);
		read(0, car, 4);
		now[i] = *(unsigned int *)car;
		i++;
	}
	if (i == 13 && *(unsigned int *)car != RETURN)
		ft_putstr("Name too long");
	else
	{
		ft_putstr("\nMessage to : ");
		ft_putstr(now);
		ft_putstr(" : ");
	}
	free(now);
    term->c_lflag &= ~(ECHO);
	tcsetattr(0, 0, term);
}
			/*if (!ft_strcmp(now, "New message"))
			{

			}
			else*/
void	init_chat(t_chat *chat)
{
	pipe(chat->fd);
	chat->conv = (t_conv *)malloc(sizeof(t_conv) * 1);
	chat->conv->login = ft_strdup("New message\0");
	chat->conv->prev = NULL;
	chat->conv->next = NULL;
}

void	ft_sleep(int time)
{
	int				start;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	start = tv.tv_sec;
	while (tv.tv_sec <= (start + time))
		gettimeofday(&tv, NULL);
}

int		ft_speak(t_chat *chat)
{
	int		i;
	char	buf[1025];
	char	*tmp;

	ft_putstr("Verification, nouveaux messages");
	ft_bzero(buf, 1025);
	tmp = NULL;
	write(chat->fd[1], "\0", 1);
	while ((i = read(chat->fd[0], buf, 1024))) 
	{
		if (i == -1)
		{
			ft_putendl_fd("Error while reading", 2);
			return (-1);
		}
		ft_putchar('.');
		if (tmp)
			tmp = ft_strjoin(tmp, buf);
		else
			tmp = ft_strdup(buf);
		ft_putchar('.');
		ft_bzero(buf, 1025);
		if (buf[i - 1] == '\0')
			break ;
	}
	ft_putstr("\nChecked\n");
	ft_sleep(1);
	if (tmp && tmp[0])
		ft_start(tmp, chat);
	else
		ft_putendl("No friends ...");
	ft_sleep(1);
	sjgr(chat->conv, &(chat->term));
	free(tmp);
	return (1);
}
