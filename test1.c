
int main()
{
  int fd1 = open("file1", I_WRONLY, S_IWUSR);
  int fd2 = open("file2", I_RDONLY, S_IRUSR);

  

}

void error()
{
  perror("error -> ");
  exit(0);
}


void read_file_sock(int socket, int fd)
{
  if (socket == -1 || buffer == NULL)
    error();
  while (write(sock, fd, 1024) > 0);
}
void read_file_sock(int socket, int fd)
{
  char *buffer;

  buffer = (char *)malloc(1024 * sizeof(char));
  strsock(socket, buffer);
  write(buffer, fd, 1023);
}

void strsock(int socket, char *buffer)
{
  if (socket == -1 || buffer == NULL)
    error();
  while (read(socket, buffer, 1023) > 0)
    if (sizeof(*buffer) > 0)
      realloc(buffer, sizeof(*buffer) + 1024);
  strncat(buffer, "\0", 1);
}
