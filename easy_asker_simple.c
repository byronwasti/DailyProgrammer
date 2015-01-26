#include <stdio.h>

#define BUFF_LEN 128

int main(void)
{
  char name[BUFF_LEN];
  int age;
  char username[BUFF_LEN];
  FILE *fh;
  printf("Enter your name: ");
  scanf("%s", name);
  printf("Enter your age: ");
  scanf("%d", &age);
  printf("Enter your reddit username: ");
  scanf("%s", username);
  fh = fopen("log.txt","a");
  if (fh == NULL) {
    fprintf(stderr,"Unable to create / open file log.txt\n");
    return 1;
  }
  fprintf(fh, "%s;%d;%s\n", name, age, username);
  fclose(fh);
  printf("Hello %s, you are %d years old and your username is %s\n",name,age,username);
  return 0;
}
