# get_next_line


## tester

```
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	// Tente abrir um arquivo de texto qualquer que você tenha criado na pasta
	fd = open("teste.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro ao abrir o arquivo\n");
		return (1);
	}

	// Loop para chamar o GNL várias vezes até ele retornar NULL
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("linha %d: %s", i, line); // Lembrete: a 'line' já deve ter o \n!
		free(line); // O usuário que chamou o GNL tem que dar free!
		i++;
	}
	close(fd);
	return (0);
}
´´´
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test

./gnl_test

valgrind --leak-check=full ./gnl_test