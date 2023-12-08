#include "get_next_line.h"
int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    int line_count = 1;

    // Read lines until the end of the file
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%d. %s\n", line_count++, line);
        free(line); // Remember to free the allocated memory
    }
    return 0;
}