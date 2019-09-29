#include <stdio.h>
#include <crypt.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./crypt plaintext salt\n");
        return 1;
    }
    printf("%s\n", crypt(argv[1], argv[2]));
}
