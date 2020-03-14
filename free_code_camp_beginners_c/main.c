#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Shapes
  printf("   /|\n");
  printf("  / |\n");
  printf(" /  |\n");
  printf("/___|\n");

  // Variables
  char name[] = "Luisito";
  int age = 22;
  printf("I am %s and I'm %d years old!\n", name, age);
  age++;
  printf("Today's my birthday and I'm now %d.\n", age);

  // Data types
  int age2 = 42;
  double frequency = 1.353;
  char grade = 'A';
  char phrase[] = "Money is the root of all motivation.\n";

  // printf
  float favenum = 42.424242;
  printf("%s", phrase);
  printf("My favouriye %s is %f\n","number", favenum);
  printf("Hello\nWorld\n");
  printf("Hello\\nWorld%c", grade);

  return 0;
}