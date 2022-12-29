#include "monty.h"

info_t var = {0, NULL, NULL, NULL, NULL, 0, 0};
/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
*/

int main(int argc, char **argv)
{
	char buff[1024] = {0};

	/* Comprobar que se ha proporcionado un único argumento */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Abrir el archivo con el código Monty */
	var.fp = fopen(argv[1], "r");
	if (var.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Leer líneas del archivo */
	while (fgets(buff, sizeof(buff), var.fp) != NULL)
	{
		var.line_num++;
		/* Separar la línea en palabras */
		var.opcode = strtok(buff, " \t\n");
		if (var.opcode == NULL || var.opcode[0] == '#')
		{
			var.line_num++;
			continue;
		}
		var.argum = strtok(NULL, " \t\n");
		exec_opcode(var.opcode);
	}
	/* Freeing*/
	freeStack();

	/* Cerrar el archivo */
	fclose(var.fp);

	/* Salir con éxito */
	return (EXIT_SUCCESS);
}
