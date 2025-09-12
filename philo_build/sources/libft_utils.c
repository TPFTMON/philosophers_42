/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 08:45:02 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/12 21:47:35 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*merge;
	size_t	index;

	len = ft_strlen(s1) + ft_strlen(s2);
	merge = (char *)malloc(sizeof(char) * (len + 1));
	if (!merge)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
	{
		merge[index] = *s1;
		if (*s1 != '\0')
			index++;
		s1++;
	}
	while (*s2 != '\0')
	{
		merge[index] = *s2;
		index++;
		s2++;
	}
	merge[index] = '\0';
	return (merge);
}

/*
 * Prints an error message to STDERR.
 * If msg is NULL,
 * uses perror to print the system error associated with 'object'.
 * If object is NULL, prints only msg.
 * Otherwise, prints "object: msg".
 * And returns an error code given.
 */
int	print_error_with_code(char *object, char *msg, int error_code)
{
	char	*msg_with_colon;
	char	*full_msg;

	if (!object && !msg)
		return (0);
	if (object == NULL)
		write(STDERR_FD, msg, ft_strlen(msg));
	else if (msg == NULL)
		perror(object);
	else
	{
		msg_with_colon = ft_strjoin(object, ": ");
		if (!msg_with_colon)
			return (perror("ft_strjoin in print_error"), error_code);
		full_msg = ft_strjoin(msg_with_colon, msg);
		free(msg_with_colon);
		if (!full_msg)
			return (perror("ft_strjoin in print_error"), error_code);
		write(STDERR_FD, full_msg, ft_strlen(full_msg));
		free(full_msg);
	}
	return (error_code);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;
	int	result;

	index = 0;
	while ((str[index] == 32) || (str[index] > 8 && str[index] < 14))
		index++;
	sign = 1;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -sign;
		(index)++;
	}
	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
		result = result * 10 + (str[index++] - '0');
	return (result * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
