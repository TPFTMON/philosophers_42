/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:19:45 by abaryshe          #+#    #+#             */
/*   Updated: 2025/08/11 08:46:31 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// /*
//  * Prints an error message to STDERR.
//  * If msg is NULL,
//  * uses perror to print the system error associated with 'object'.
//  * If object is NULL, prints only msg.
//  * Otherwise, prints "object: msg".
//  * And returns an error code given.
//  */
// int	print_error_with_code(char *object, char *msg, int error_code)
// {
// 	char	*msg_with_colon;
// 	char	*full_msg;

// 	if (!object && !msg)
// 		return (0);
// 	if (object == NULL)
// 		write(STDERR_FD, msg, ft_strlen(msg));
// 	else if (msg == NULL)
// 		perror(object);
// 	else
// 	{
// 		msg_with_colon = ft_strjoin(object, ": ");
// 		if (!msg_with_colon)
// 			return (perror("ft_strjoin in print_error"), error_code);
// 		full_msg = ft_strjoin(msg_with_colon, msg);
// 		free(msg_with_colon);
// 		if (!full_msg)
// 			return (perror("ft_strjoin in print_error"), error_code);
// 		write(STDERR_FD, full_msg, ft_strlen(full_msg));
// 		free(full_msg);
// 	}
// 	return (error_code);
// }
