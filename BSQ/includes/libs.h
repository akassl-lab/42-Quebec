/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmallett <nmallett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:46:16 by nmallett          #+#    #+#             */
/*   Updated: 2021/08/25 15:42:27 by nmallett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int 	globalX; /* Length */
int		globalY;  /* Height */

#define DEV_MODE true

#define COLOR_RED       "\033[0;31m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_YELLOW    "\033[33m"
#define COLOR_WHITE     "\033[37m"
#define COLOR_RESET     "\033[0m"

#ifdef DEV_MODE
    #define TERMINATE_WAIT      1
#else
    #define TERMINATE_WAIT      5
#endif



extern  void	ft_putchar(char c);
extern  void	ft_putnbr(int nb);
extern  void	ft_swap(int *a, int *b);
extern  void	ft_div_mod(int a, int b, int *div, int *mod);
extern  void	ft_ultimate_div_mod(int *a, int *b);
extern  void	ft_putstr(char *str);
extern  int     ft_strlen(char *str);
extern  char	*ft_strcpy(char *dest, char *src);
extern  int	    ft_strcmp(char *s1, char *s2);
extern  int	    ft_strncmp(char *s1, char *s2, unsigned int n);
extern  char	*ft_strcat(char *dest, char *src);
extern  char	*ft_strstr(char *str, char *to_find);
extern  int     ft_iterative_factorial(int nb);
extern  int     ft_iterative_power(int nb, int power);
extern  int     ft_fibonacci(int index);
extern  int     ft_sqrt(int nb);
extern  int     ft_is_str_numeric(char *str);
extern  int     ft_atoi(char *str);
extern  int     ft_splitnumber(int a, int b);
extern  int     calculateFileSize(char *buffer, char *file);
extern	void    aka_terminateProcess(char *buffer, unsigned int flag);
extern	int    	aka_readFile(char *buffer, char *file);
extern	int		calculateTotalLines(char *buffer, int fileContent);
extern	int		calculateTotalLength(char *buffer, int fileContent);

// Flag 0 = Using the buffer or flag 1 = Ignore the buffer
void    aka_terminateProcess(char *buffer, unsigned int flag)
{
    if(*buffer || flag == 1)
    {
        free(buffer); // Free the allocated address
        #undef FILE_TO_OPEN // Undef our FILE_TO_OPEN
        printf("%sTerminating process in %d second(s)%s", COLOR_RED, TERMINATE_WAIT, COLOR_RESET); // Give it a small delai to let the buffer free completely
        exit(TERMINATE_WAIT); // Terminate the process
    }
    else
        printf("%sERROR:%s Could not terminate process, the buffer was invalid", COLOR_RED, COLOR_RESET);
}

int    aka_readFile(char *buffer, char *file)
{
    int fileSize = calculateFileSize(buffer, file);

    if (fileSize == -1)
        return (-1);

    int fileEx = open(file, O_RDONLY);
    int fileOutput = read(fileEx, buffer, fileSize);
    printf("%sSUCCESS:%s Opening file %s\n", COLOR_GREEN, COLOR_RESET, file);
    return (fileOutput);
}

int    calculateFileSize(char *buffer, char *file)
{
    int fileEx = open(file, O_RDONLY);

    if (fileEx == -1) {
        printf("%sERROR:%s File %s does not exist %s(Skipping to next argument if any)%s\n", COLOR_RED, COLOR_RESET, file, COLOR_YELLOW, COLOR_RESET);
        return (-1);
    }

    int     i[3];


    i[0] = 0;
    i[1] = 1;
    i[2] = 0;



    while ((i[0] = read(fileEx, buffer, i[1])))
    {
        i[2] += i[0];
        i[1]++;
    }

    return ((i[2] + (i[2] % i[1])) + (sizeof(char) * i[1]));
}

extern	int		calculateTotalLines(char *buffer, int fileContent)
{
	int		i[2];

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

extern	int		calculateTotalLength(char *buffer, int fileContent)
{
	int		i[3];

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		i;
	int		i2;

	i = nb / 10;
	i2 = nb % 10;
	ft_putchar(i + 48);
	ft_putchar(i2 + 48);
}

void	ft_swap(int *a, int *b)
{
	int 	aka;

	aka = *a;
	*a = *b;
	*b = aka;
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	*a = *a / *b;
	*b = *a % *b;
}

void	ft_putstr(char *str)
{
	char	finalString;

	while (*str && *str != '\0')
	{
		finalString = *str;
		write(1, &finalString, 1);
		str++;
	}
}

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
	while (str[i] && str[i] != '\0')
		i++;
    return i;
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (src);
}

int	    ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	    ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while (dest[i[0]] != '\0')
	{
		i[0]++;
	}
	while (src[i[1]] != '\0')
	{
		dest[i[0] + i[1]] = src[i[1]];
		i[1]++;
	}
	dest[i[0] + i[1]] = '\0';
	return (dest);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		istr;
	int		ito_find;

	istr = 0;
	ito_find = 0;
	while (str[istr] != '\0')
	{
		ito_find = 0;
		while (to_find[ito_find] == str[istr])
		{
			return ((str - (ito_find - istr)));
			ito_find++;
		}
		istr++;
	}
	return (0);
}

int     ft_iterative_factorial(int nb)
{
	if (nb < 0)
		return 0;

	int		i[2];

	i[0] = 1;
	i[1] = 1;
	while (i[0] <= nb)
	{
		i[1] *= i[0];
		i[0]++;
	}
	return (i[1]);
}

int     ft_iterative_power(int nb, int power)
{
	int 	i;
	int 	result;

	i = 1;
	result = nb;
	while(i <= power)
	{
		printf("a\n");
		result *= nb;
		i++;
	}

	if (result == 0)
		return (1);
	return result;
}

int     ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0 || index == 1)
		return index;
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int     ft_sqrt(int nb)
{
	int result;

	result = nb % 10;
	result = nb / result;
	return result;
}

int     ft_is_str_numeric(char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
        if (str[i] < 48 || str[i++] > 57)
            return (0);
    return (1);
}

int     ft_atoi(char *str)
{
    int i[2];

    i[0] = 0;
    i[1] = 1;

    if(*str == '-')
    {
        i[1] = -1;
        str++;
    }

    while ((*str >= '0') && (*str <= '9'))
    {
      i[0] = i[0] * 10;
      i[0] = i[0] + (*str - 48);
      str++;
    }
    return (i[1] * i[0]);
}

int     ft_splitnumber(int a, int b)
{
    while(a--)
        b/=10;
    return b%10;
}
