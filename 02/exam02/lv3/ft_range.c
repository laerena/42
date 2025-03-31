/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:00:42 by lelai             #+#    #+#             */
/*   Updated: 2025/04/01 01:04:30 by lelai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int start, int end)
{
	int i = 0;
	int len = (end - start) < 0 ? (end - start * -1) + 1 : (end - start) + 1;
	int *range = (int *) malloc(len * sizeof(int));

	while (i < len)
	{
		if (start < end)
			range [i] = start++;
		else
			range [i] = start--;
		i++;
	}
	return (range);
}
