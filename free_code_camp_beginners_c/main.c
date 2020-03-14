#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("\nFreeCodeCamp C in 4 hours.\n\n"); // Shapes
  printf("   /|\n");
  printf("  / |\n");
  printf(" /  |\n");
  printf("/___|\n");

  printf("\n"); // Variables
  char name[] = "Luisito";
  int age = 22;
  printf("I am %s and I'm %d years old!\n", name, age);
  age++;
  printf("Today's my birthday and I'm now %d.\n", age);

  printf("\n"); // Data types
  int age2 = 42;
  double frequency = 1.353;
  char grade = 'A';
  char phrase[] = "Money is the root of all motivation.\n";

  printf("\n"); // printf
  float favenum = 42.424242;
  printf("%s", phrase);
  printf("My favouriye %s is %f\n", "number", favenum);
  printf("Hello\nWorld\n");
  printf("Hello\\nWorld%c\n", grade);

  printf("\n"); // Maths
  printf("%f\n", pow(2, 3));
  printf("%f\n", pow(2.5, 3));
  printf("%f\n", pow(4, 3));
  printf("%f\n", sqrt(36));
  printf("%f\n", sqrt(2.5));
  printf("%f\n", sqrt(2));
  printf("%f\n", ceil(41.223));
  printf("%f\n", floor(42.9999));

  printf("\n"); /* Muiltiline
  Comment and Variables */
  const int COOLEST_NUMBER = 42;
  // COOLEST_NUMBER++ throws error (cant modify a constant).
  printf("We love this number: %d\n", COOLEST_NUMBER);

  printf("\n"); // std input w/ libstdio (std::scanf)
  int age_input;
  printf("Please tell me your age: "); scanf("%d", &age_input);
  printf("You are %d years old!\n", age_input);
  double gpa_input;

  printf("What's your GPA? "); scanf("%lf", &gpa_input);
  if (gpa_input < 2.0)
    printf("You need to study more!\n");
  if (gpa_input > 2.0 && gpa_input < 3.0)
    printf("Your GPA is %f, nothig special here.\n", gpa_input);
  if (gpa_input >= 3.0)
    printf("Your going places...\n");
  if (gpa_input >= 4.0)
    printf("Looks like wegot ourselves a valedictorian!\n");

  return 0;
}