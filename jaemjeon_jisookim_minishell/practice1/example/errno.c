/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:43:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/05 03:07:29 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>


// 내부함수 __errno() 는 errno_t 값의 주소를 반환함.
// errno.h에는 errno가 __errno()의 참조값으로 define 되어있음.
// 즉 errno는 내부함수 __errno()가 반환한 errno_t값을 반환함.

// in errno.h

// extern int * __error(void);
// #define errno (*__error())

int	main()
{
	int error_number;
	int	*error_number_pointer;

	error_number_pointer = &error_number;

	error_number = errno;  // errno를 이용해 errno_t 값을 가져옴
	error_number_pointer = __error(); // 내부함수로 int값 주소 가져옴

	printf("%d\n", error_number); // 0 출력
	printf("%d\n", *error_number_pointer); // 0 출력
	opendir("not_exist_dir"); // errno세팅
	printf("%d\n", error_number); // 0 출력
	printf("%d\n", *error_number_pointer); // 2 출력
	return 0;
}
