#include <stdio.h>
#include <stdlib.h>

void add();      // ADD X int arguments
void addf();     // ADD X float arguments
void addo();     // ADD X int/float odd arguments
void adde();     // ADD X int/float even arguments
void sub();      // SUB X int arguments
void subf();     // SUB X float arguments
void subo();     // SUB X int/float odd arguments
void sube();     // SUB X int/float even arguments
void read();     // Read instruction
void decode();   // Decode instruction
void run();      // Run application
void help();     // Help printer
void printIni(); // Print initial markup
char op[20];     // Input operation
int quantOp = 0, // Number of arguments
    i = 0,       // for controller
    acumI = 0,   // Acumulate int results 
    inI = 0,     // Input int numbers
    ok = 0,      // Controller flag
    ex = 0;      // Rxit flag
float acumF = 0, // Acumulate float results
    inF = 0;     // Input float numbers

//-----------------------------------------------------

int main(void)
{
  printf("%s", ">>> Type an operation, use --help/-h or --exit\n");
  run();

  return 0;
}

//-----------------------------------------------------

void run()

{
  printIni();
  while (!ex)
  {
    read();
    decode();
  }
}

//-----------------------------------------------------

void read()
{
  fgets(op, 20, stdin);
}

//-----------------------------------------------------

void decode()
{
  if (!strcmp(op, "add\n"))
  {
    add();
    printIni();
  }

  else if (!strcmp(op, "add -f\n"))
  {
    addf();
    printIni();
  }

  else if (!strcmp(op, "add odd\n"))
  {
    addo(0);
    printIni();
  }

  else if (!strcmp(op, "add odd -f\n"))
  {
    addo(1);
    printIni();
  }

  else if (!strcmp(op, "add even\n"))
  {
    adde(0);
    printIni();
  }

  else if (!strcmp(op, "add even -f\n"))
  {
    adde(1);
    printIni();
  }

  else if ((!strcmp(op, "-h\n")) || (!strcmp(op, "--help\n")))
  {
    help();
    printIni();
  }

  // -------------------------------------------------------------------

  if (!strcmp(op, "sub\n"))
  {
    sub();
    printIni();
  }

  else if (!strcmp(op, "sub -f\n"))
  {
    subf();
    printIni();
  }

  else if (!strcmp(op, "sub odd\n"))
  {
    subo(0);
    printIni();
  }

  else if (!strcmp(op, "sub odd -f\n"))
  {
    subo(1);
    printIni();
  }

  else if (!strcmp(op, "sub even\n"))
  {
    sube(0);
    printIni();
  }

  else if (!strcmp(op, "sub even -f\n"))
  {
    sube(1);
    printIni();
  }

  else if (!strcmp(op, "--exit\n"))
    ex = 1;
}

//-----------------------------------------------------

void add()
{
  acumI = 0;

  printf("%s", ">>> Number of operands: ");

  scanf("%d", &quantOp);

  printIni();
  for (i = 0; i < quantOp; i++)
  {

    scanf("%d", &inI);
    acumI += inI;
  }
  printIni();
  printf("%s", "ans: ");
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
  printf("%s", "ans: ");
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
          printf("%s", ">>> Only odd numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%s", "ans: ");
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

        if ((((int)(inF * 10)) % 2) != 0)
        {

          acumF += inF;
          ok = 1;
        }
        else
        {
          printf("%s", ">>> Only odd numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%s", "ans: ");
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
          printf("%s", ">>> Only even numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%s", "ans: ");
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
        if ((((int)(inF * 10)) % 2) == 0)
        {
          acumF += inF;
          ok = 1;
        }
        else
        {
          printf("%s", ">>> Only even numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%s", "ans: ");
    printf("%0.2f\n", acumF);
  }
}

//-----------------------------------------------------

void sub()
{
  acumI = 0;

  printf("%s", ">>> Number of operands: ");

  scanf("%d", &quantOp);

  printIni();
  scanf("%d", &inI);
  acumI = inI;
  for (i = 0; i < quantOp - 1; i++)
  {
    scanf("%d", &inI);
    acumI -= inI;
  }
  printIni();
  printf("%s", "ans: ");
  printf("%d\n", acumI);
}

//-----------------------------------------------------

void subf()
{
  acumF = 0;
  printIni();
  printf("%s", "Number of operands: ");
  scanf("%d", &quantOp);
  printIni();
  scanf("%f", &inF);
  acumF = inF;
  for (i = 0; i < quantOp - 1; i++)
  {
    scanf("%f", &inF);
    acumF -= inF;
  }
  printIni();
  printf("%s", "ans: ");
  printf("%0.2f\n", acumF);
}

//-----------------------------------------------------

void subo(int f)
{
  if (!f)
  {
    acumI = 0;
    ok = 0;
    printIni();
    printf("%s", "Number of operands: ");

    scanf("%d", &quantOp);
    printIni();

    scanf("%d", &inI);
    acumI = inI;
    for (i = 0; i < quantOp - 1; i++)
    {
      ok = 0;
      while (!ok)
      {
        scanf("%d", &inI);
        if (inI % 2 != 0)
        {
          acumI -= inI;
          ok = 1;
        }
        else
        {
          printf("%s", ">>> Only odd numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%s", "ans: ");
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
    scanf("%f", &inF);
    acumF = inF;
    for (i = 0; i < quantOp - 1; i++)
    {
      ok = 0;
      while (!ok)
      {
        scanf("%f", &inF);
        if ((((int)(inF * 10)) % 2) != 0)
        {
          acumF -= inF;
          ok = 1;
        }
        else
        {
          printf("%s", ">>> Only odd numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%s", "ans: ");
    printf("%0.2f\n", acumF);
  }
}

//-----------------------------------------------------

void sube(int f)
{
  if (!f)
  {
    acumI = 0;
    ok = 0;
    printIni();
    printf("%s", "Number of operands: ");

    scanf("%d", &quantOp);

    printIni();
    scanf("%d", &inI);
    acumI = inI;
    for (i = 0; i < quantOp - 1; i++)
    {
      ok = 0;
      while (!ok)
      {
        scanf("%d", &inI);
        if (inI % 2 == 0)
        {
          acumI -= inI;
          ok = 1;
        }
        else
        {
          printf("%s", ">>> Only even numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%s", "ans: ");
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
    scanf("%f", &inF);
    acumF = inF;
    for (i = 0; i < quantOp - 1; i++)
    {
      ok = 0;
      while (!ok)
      {
        scanf("%f", &inF);
        if ((((int)(inF * 10)) % 2) == 0)
        {
          acumF -= inF;
          ok = 1;
        }
        else
        {
          printf("%s", ">>> Only even numbers!\n");
          printIni();
        }
      }
    }
    printIni();
    printf("%s", "ans: ");
    printf("%0.2f\n", acumF);
  }
}

//-----------------------------------------------------

void printIni()
{
  printf("%s", ">>> ");
}

//-----------------------------------------------------

void help()
{
  printf("%s\n", "********************** HELP! *********************");
  printf("%s\n", "******************** COMMANDS ********************");
  printf("%s\n", ">>>>> add                          Sum X arguments");
  printf("%s\n", ">>>>> sub                     Subtract X arguments");
  printf("%s\n", "**************************************************\n");

  printf("%s\n", "****************** SUB-COMMANDS ******************");
  printf("%s\n", ">>>>> odd                      Sum X odd arguments");
  printf("%s\n", ">>>>> even               Subtract X even arguments");
  printf("%s\n", "**************************************************\n");

  printf("%s\n", "********************* FLAGS **********************");
  printf("%s\n", ">>>>> -f                 Flag to use float numbers");
  printf("%s\n", ">>>>> --exit                  Exit the application");
  printf("%s\n", "**************************************************\n");
}