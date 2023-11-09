#include "diamond.h"

char **make_diamond(const char letter);
void free_diamond(char **diamond);

int main(void)
{
    char letter;
    char **diamond;

    printf("Tell me the letter to build the Diamond...\n");
    scanf("%c", &letter);
    diamond = make_diamond(letter);
    free_diamond(diamond);
    return (0);
}

char **make_diamond(const char letter)
{
    size_t dim = letter - 'A';
    char **diamond = malloc((size_t)(2 * dim + 1) * sizeof(char*));
    for (size_t i = 0; i < (size_t)(2 * dim + 1); i++)
        diamond[i] = calloc((size_t)(2 * dim + 2), sizeof(char));
    for (size_t rows = 0; rows <= dim; rows++)
    {
        for (size_t cols = 0; cols <= dim; cols++)
        {
            if (cols != dim - rows)
                diamond[rows][cols] = diamond[rows][2 * dim - cols] = ' ';
            else
                diamond[rows][cols] = diamond[rows][2 * dim - cols] = (char)rows + 'A';
        }
        if (rows < dim)
            strcpy(diamond[2 * dim - rows], diamond[rows]);
    }
    for (size_t i = 0; i < (2 * dim + 1); i++)
    {
        printf("%s\n", diamond[i]);
    }
    return (diamond);
}

void free_diamond(char **diamond)
{   
    for (size_t i = 0; i < strlen(diamond[0]); i++)
        free(diamond[i]);
    free(diamond);
}
