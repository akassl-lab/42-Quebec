/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmallett <nmallett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:23:46 by nmallett          #+#    #+#             */
/*   Updated: 2021/08/25 21:19:01 by nmallett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H "libs.h"

# include "ft_libs.h"

int		g_globalX = 0;
int		g_globalY = 0;

extern	int	calculateFileSize(char *buffer, char *file);
extern	void	aka_terminateProcess(char *buffer, unsigned int flag);
extern	int	aka_readFile(char *buffer, char *file);
extern	int	calculateTotalLines(char *buffer, int fileContent);
extern	int	calculateTotalLength(char *buffer, int fileContent);

void	aka_terminateProcess(char *buffer, unsigned int flag)
{
	if (*buffer || flag == 1)
	{
		free(buffer);
		exit(0);
	}
}

int	aka_readFile(char *buffer, char *file)
{
	int		fileSize;
	int		fileEx;
	int		fileOutput;

	fileSize = calculateFileSize(buffer, file);
	fileEx = open(file, O_RDONLY);
	if (fileEx == -1)
	{
		map("Error: The file is non-existance or empty\n");
		return (-1);
	}
	fileOutput = read(fileEx, buffer, fileSize);
	return (fileOutput);
}

int	calculateFileSize(char *buffer, char *file)
{
	int		fileEx;
	int		i[3];

	fileEx = open(file, O_RDONLY);
	if (fileEx == -1)
		return (-1);
	i[0] = 0;
	i[1] = 1;
	i[2] = 0;
	while (i[1] < 200000)
	{
		i[0] = read(fileEx, buffer, i[1]);
		i[2] += i[0];
		i[1]++;
	}
	return ((i[2] + (i[2] % i[1])) + (sizeof(char ) * i[1]));
}

extern	int	calculateTotalLines(char *buffer, int fileContent)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (i[0] <= fileContent)
	{
		if (buffer[i[0]] == '\n')
			i[1]++;
		i[0]++;
	}
	return (i[1]);
}

extern	int	calculateTotalLength(char *buffer, int fileContent)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] <= fileContent)
	{
		if (buffer[i[0]] != '\n' && i[2] < 3)
			i[1]++;
		if (buffer[i[0]] == '\n')
		{
			i[2]++;
			if (i[2] != 2)
				i[1] = 0;
		}
		if (i[2] == 2)
			return (i[1]);
		i[0]++;
	}
	return (i[1]);
}
#endif
