// a16.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#define _CRT_SECURE_NO_WARNINGS
#include"fa16.h"
#include <malloc.h>
int main()
{
    double R, C;
    double CU;
    double* f0, * L;
    int i, j;
    char szZeile[81];
    char szEinh[11];
    FILE* af;



    af=OeffneTxtDat("r+t+");
    if (!af)
    {
       
        getchar();
        return 1;
    }
  

    while (fgets(szZeile, 100, af))	fputs(szZeile, stdout);
    rewind(af);
    fscanf(af, "%*s%*s%*s%*s%lg", &R);
    fscanf(af, "%*s%*s%*s%lg%s", &C,&szEinh);
    fscanf(af, "%i", &i);

    L = (double*)malloc(i * sizeof(double));
    f0= (double*)malloc(i * sizeof(double));

   /* fscanf(af, "%*s%*s%*s%*s");*/
    fgets(szZeile, 80, af);
    fgets(szZeile, 80, af);

  
    puts("\ndazu gehoerende Resonanzfrequenzen");
    puts("---------------------------------------------------------");
    for (j = 0; j < i; j++) {
        fscanf(af, "%lg", &L[j]);
        if (!strcmp(szEinh, "MikroF"))CU = 1e-6;
        else CU = 1e-9;

        f0[j] = ResoFrequ(C * CU, L[j]*1e3, R);

        if (j % 8 != 0)printf("%7.2lf", f0[j]);
        else printf("\n%7.2lf", f0[j]);
    }
    free(L);
    free(f0);
    fclose(af);
    printf("\nProgramm mit Enter beenden...");
    getchar();
    return 0;
}

