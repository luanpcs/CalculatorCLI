#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add();
void addf();
void addo();
void adde();
void onf();
void printIni();
void read();
void decode();
void help();

int quantOp = 0,
    i = 0,
    acumI = 0,
    inI = 0,
    ok = 0,
    ex = 0;

float acumF = 0,
      inF = 0;

char op[20];

//-----------------------------------------------------

int main(void)
{
  while (!ex)
  {
    printIni();
    printf("%s", "Type an operation, use --help/-h, or --exit\n");
    read();
    decode();
  }
  return 0;
}

//-----------------------------------------------------
void add()
{
  acumI = 0;
  printIni();
  printf("%s", "Number of operands: ");

  scanf("%d", &quantOp);

  printIni();
  for (i = 0; i < quantOp; i++)
  {
    scanf("%d", &inI);
    acumI += inI;
  }
  printIni();
  printf("%d\n", acumI);
}

//-----------------------------------------------------

void addf()
{
  acumF = 0;
  printIni();
  printf("%s", "Number of operands: ");
  scanf("%d", &quantOp);
  printIni();
  for (i = 0; i < quantOp; i++)
  {
    scanf("%f", &inF);
    acumF += inF;
  }
  printIni();
  printf("%0.2f\n", acumF);
}

//-----------------------------------------------------

void addo(int f)
{
  if (!f)
  {
    acumI = 0;
    ok = 0;
    printIni();
    printf("%s", "Number of operands: ");

    scanf("%d", &quantOp);

    printIni();
    for (i = 0; i < quantOp; i++)
    {
      ok = 0;
      while (!ok)
      {
        scanf("%d", &inI);
        if (inI % 2 != 0)
        {
          acumI += inI;
          ok = 1;
        }
        else
        {
          printf("%s", "Only odd numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%d\n", acumI);
  }
  else
  {
    acumF = 0;
    ok = 0;
    printIni();
    printf("%s", "Number of operands: ");

    scanf("%d", &quantOp);

    printIni();
    for (i = 0; i < quantOp; i++)
    {
      ok = 0;
      while (!ok)
      {
        scanf("%f", &inF);
        if ((int)inF % 2 != 0)
        {
          acumF += inF;
          ok = 1;
        }
        else
        {
          printf("%s", "Only odd numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%0.2f\n", acumF);
  }
}

//-----------------------------------------------------

void adde(int f)
{
  if (!f)
  {
    acumI = 0;
    ok = 0;
    printIni();
    printf("%s", "Number of operands: ");

    scanf("%d", &quantOp);

    printIni();
    for (i = 0; i < quantOp; i++)
    {
      ok = 0;
      while (!ok)
      {
        scanf("%d", &inI);
        if (inI % 2 == 0)
        {
          acumI += inI;
          ok = 1;
        }
        else
        {
          printf("%s", "Only even numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%d\n", acumI);
  }
  else
  {
    acumF = 0;
    ok = 0;
    printIni();
    printf("%s", "Number of operands: ");

    scanf("%d", &quantOp);

    printIni();
    for (i = 0; i < quantOp; i++)
    {
      ok = 0;
      while (!ok)
      {
        scanf("%f", &inF);
        if ((int)inF % 2 == 0)
        {
          acumF += inF;
          ok = 1;
        }
        else
        {
          printf("%s", "Only even numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%0.2f\n", acumF);
  }
}

//-----------------------------------------------------

void onf()
{
  printf("%s", "Operation was not found, use --help or -h\n");
}

//-----------------------------------------------------

void printIni()
{
  printf("%s", ">>> ");
}

//-----------------------------------------------------

void read()
{
  printIni();
  fgets(op, 20, stdin);
}

//-----------------------------------------------------

void decode()
{
  if (strcmp(op, "add\n") == 0)
    add();

  else if (strcmp(op, "add -f\n") == 0)
    addf();

  else if (strcmp(op, "add odd\n") == 0)
    addo(0);

  else if (strcmp(op, "add odd -f\n") == 0)
    addo(1);

  else if (strcmp(op, "add even\n") == 0)
    adde(0);

  else if (strcmp(op, "add even -f\n") == 0)
    adde(1);

  else if ((strcmp(op, "-h\n") == 0) ||
           (strcmp(op, "--help\n") == 0))
    help();

  else if (strcmp(op, "--exit\n") == 0)
    ex = 1;

  else
    onf();
}

//-----------------------------------------------------

void help()
{
  printf("%s", "HELP!!\n");
}