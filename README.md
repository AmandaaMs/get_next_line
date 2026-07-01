*This project has been created as part of the 42 curriculum by amoura-d <amoura-d@student.42.fr>*

# Custom C Library

## Description

📖 get_next_line

This project involves implementing a C function that reads an entire line from a file descriptor (FD). The primary objective is to understand the operation of the `read()` function, dynamic memory allocation, and the strategic use of static variables.

📌 Project Overview
The `get_next_line` function must return the line read from a file. When called in a loop, it allows reading the entire text, line by line, until the end of the file (EOF).

| Functionality | Mandatory | Bonus |
| :--- | :--- | :--- |
| File Descriptors | 1 at a time | Multiple simultaneously |
| Static Variables | 1 simple | Array of variables (`storage[FD_MAX]`) |
| Compiled Files | `get_next_line.c` | `get_next_line_bonus.c` |
---
## Instructions

### Requirements

* GCC or Clang
* Make
* Linux or macOS

git clone [git@github.com:AmandaaMs/get_next_line.git] [repo-name]
cd [repo-name]

Include the header:

```c
#include "get_next_line.h"
```
## 🛠️ How to use and test (Mandatory Part)
To compile and test the standard version of the function, you will need to create a `teste.txt` file in your directory containing a few lines of text.

Next, create a `main.c` file with the code below:

```c
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
```

## compiling
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test

## executing
./gnl_test

## Checking for memory leaks
valgrind --leak-check=full ./gnl_test

---

## 🚀 How to use and test (Bonus Part)
The key feature of this bonus section is the ability to manage multiple file descriptors (FDs) simultaneously without losing track of the current line position in each file.

Create three text files (arquivo1.txt, arquivo2.txt, and arquivo3.txt) and use the main.c code below to verify the interleaved operation:

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	// 1. Abrindo 3 arquivos diferentes (Garanta que eles existam na pasta!)
	fd1 = open("arquivo1.txt", O_RDONLY);
	fd2 = open("arquivo2.txt", O_RDONLY);
	fd3 = open("arquivo3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Erro: Certifique-se de criar arquivo1.txt, arquivo2.txt e arquivo3.txt\n");
		return (1);
	}

	printf("--- Começando o Teste Intercalado (Bônus) ---\n\n");

	// Lendo a Linha 1 do Arquivo 1
	line = get_next_line(fd1);
	printf("[FD %d - Arq 1][Linha 1]: %s", fd1, line);
	free(line);

	// Lendo a Linha 1 do Arquivo 2
	line = get_next_line(fd2);
	printf("[FD %d - Arq 2][Linha 1]: %s", fd2, line);
	free(line);

	// Lendo a Linha 1 do Arquivo 3
	line = get_next_line(fd3);
	printf("[FD %d - Arq 3][Linha 1]: %s", fd3, line);
	free(line);

	printf("\n--- Alternando de volta para ler as próximas linhas ---\n\n");

	// Voltando para o Arquivo 1 (Linha 2)
	line = get_next_line(fd1);
	printf("[FD %d - Arq 1][Linha 2]: %s", fd1, line);
	free(line);

	// Voltando para o Arquivo 2 (Linha 2)
	line = get_next_line(fd2);
	printf("[FD %d - Arq 2][Linha 2]: %s", fd2, line);
	free(line);

	// Testando um FD inválido no meio (Não pode dar SegFault!)
	line = get_next_line(-1);
	if (!line)
		printf("[FD -1]: Retornou NULL corretamente para FD inválido.\n");
	free(line);

	// Fechando os arquivos
	close(fd1);
	close(fd2);
	close(fd3);

	printf("\n--- Teste concluído com sucesso! ---\n");
	return (0);
}
```

## compiling
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test

## executing
./gnl_test

## Checking for memory leaks
valgrind --leak-check=full ./gnl_test

---

## Resources
### Documentation

* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
* Linux Manual Pages (`man`)
* POSIX Documentation
* GNU C Documentation
* 42 Subject PDF

### References

* https://man7.org/linux/man-pages/
* https://cplusplus.com/
* https://developer.mozilla.org/

### AI Usage

Artificial Intelligence tools were used as learning assistants for:

* Concept clarification
* Documentation support
* Debugging guidance
* Understanding edge cases
* Code review suggestions

All implementations, testing, debugging, and final validation were completed manually by the author.

### 🛠️ Testers 

* Norminette
* gnlTester - by Tripouille (git@github.com:Tripouille/gnlTester.git)

---

## Author

Amanda Moura

42 Login: amoura-d

GitHub: https://github.com/AmandaaMs
