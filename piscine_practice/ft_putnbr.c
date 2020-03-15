/* In the C and C++ programming languages, unistd.h is the name of the header
file that provides access to the POSIX operating system API. It is defined by
the POSIX.1 standard, the base of the Single Unix Specification, and should
therefore be available in any conforming (or quasi-conforming) operating
system/compiler (all official versions of UNIX, including macOS, Linux, etc.).

On Unix-like systems, the interface defined by unistd.h is typically made up
largely of system call wrapper functions such as fork, pipe and I/O primitives
(read, write, close, etc.). Source => https://en.wikipedia.org/wiki/Unistd.h */
#include <unistd.h>

int ft_put_char(char c)
{
  // https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h/write
  write(1, &c, 1);
  return (0);
}

void ft_put_number(int number)
{
  if (number < 0)
  {
    ft_put_char('-');

    if (number == -2147483648)
    {
      ft_put_char('2');
      ft_put_number(147483648);
      return;
    }

    number = -number;
  }

  if (number > 9)
    ft_put_number(number / 10);

  ft_put_char(number % 10 + '0');
}

int main()
{
  ft_put_number(4242424);
  return 0;
}
