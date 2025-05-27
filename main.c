#include "main.h"

int main(int ac, char **av)
{
	char *prompt = "(Eshell) $ ";
	char *line = NULL, *line_copy = NULL;
	const char *delim = " \n";
	size_t len = 0;
	ssize_t read;
	int num_tokens = 0;
	char *token;
	int i;

	(void) ac;

	/* create an infinite loop */
	while (1)
	{
		printf("%s", prompt);
		read = getline(&line, &len, stdin);
		/* check if the getline function failed or reached EOF or user use CTRL + D */
		if (read == -1)
		{
			printf("\n");
			return (-1);
		}

		/* allocate space for a copy of the lineptr */
		line_copy = malloc(sizeof(char) * read);
		if (line_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		/* copy lineptr to lineptr_copy */
		strcpy(line_copy, line);

		/********** split the string (lineptr) into an array of words ********/
		/* calculate the total number of tokens */
		token = strtok(line, delim);

		/* determine how many tokens are there*/
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		/* Allocate space to hold the array of strings */
		av = malloc(sizeof(char *) * num_tokens);

		/* Store each token in the argv array */
		token = strtok(line_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;

		execmd(av);
	}
	free(line_copy);
	free(line);

	return (0);
}
