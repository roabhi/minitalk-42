/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:02:43 by rabril-h          #+#    #+#             */
/*   Updated: 2022/03/07 18:22:59 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int args, char **argv)
{
	int _args;
	char	*params;

	_args = args;
	params = *argv;

	printf("El numero de argumentos es %d", _args);

	return (0);
}
