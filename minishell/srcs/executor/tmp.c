#include <unistd.h>
int main (void) {
    char * const argv[] = {"ls", "-lh", "-a", NULL}; //O primeiro arg pode ser qualquer string, o último = NULL.
    char * const envp[] = {NULL};
    int rc = execve ("/bin/ls", argv, envp); //Precisa ter o PATH completo.
    return rc;
}
