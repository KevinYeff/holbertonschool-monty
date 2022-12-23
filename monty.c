#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	/* Inicializar variables */
	int *ptr;
	int line_number = 1;
	char line[1024];
	/* Comprobar que se ha proporcionado un único argumento */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Abrir el archivo con el código Monty */
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* Leer líneas del archivo */
	while (fgets(line, sizeof(line), fp))
	{
		/* Separar la línea en palabras */
		char *opcode = strtok(line, " \t\n");

		/* Si no se proporcionó una opcode, saltar a la siguiente línea */
		if (opcode == NULL)
		{
			line_number++;
			continue;
		}

		/* Verificar que la opcode sea válida */
		if (strcmp(opcode, "push") == 0)
		{
			/* Obtener el valor a empujar */
			char *value = strtok(NULL, " \t\n");

			/* Convertir el valor a entero */
			int n = atoi(value);

			/* Asignar memoria para almacenar el valor */
			ptr = malloc(sizeof(int));
			if (ptr == NULL)
			{
				printf("Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}

			/* Almacenar el valor en la memoria asignada */
			*ptr = n;

			/* Hacer algo con el valor empujado (por ejemplo, imprimirlo) */
			printf("%d\n", *ptr);

			/* Liberar la memoria asignada */
			free(ptr);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			/* Hacer algo con el valor que se desea sacar (por ejemplo, imprimirlo) */
			printf("%d\n", *ptr);

			/* Liberar la memoria asignada */
			/*free(ptr);*/
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		/* Incrementar el número de línea */
		line_number++;
	}

	/* Cerrar el archivo */
	fclose(fp);

	/* Salir con éxito */
	return EXIT_SUCCESS;
}
