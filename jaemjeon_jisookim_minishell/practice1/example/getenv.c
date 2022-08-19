/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:56:04 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/09 00:54:32 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	char	*env_value;

	env_value = getenv("USER");
	printf("%s\n\n", env_value);
	// jaemjeon 출력

	*env_value = '*';
	printf("%s\n\n", env_value);
	// *eamjeon 출력

	env_value = getenv("KEY");
	printf("%s\n\n", env_value);
	// *eamjeon 출력

	env_value = getenv("이런건 없을껄?");
	printf("%s\n\n", env_value);
	// (null) 출력
	return (0);
}
