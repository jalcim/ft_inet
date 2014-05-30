#include "servpipe.h"

int main()
{
  init_chat();
  if (!fork())
    {
      chat("jalcim", "test 1");
      chat("jalcim", "test 2");
      chat("joe", "tesst 1");
      chat("jalcim", "test 3");
      chat("joe", "tesst 2");
      chat("jalcim", "test 4");
      chat("minot", "tesst 1");
      chat("minot", "tesst 2");
      chat("minot", "tesst 3");
      chat("minas", "tesst 1");
      exit(0);
    }
  sleep(1);
  start_chat();
  recup_chat((t_conv *)-1);
  return (0);
}
