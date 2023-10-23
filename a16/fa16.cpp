#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"fa16.h"
FILE* OeffneTxtDat(const char* szModus)
{
	FILE* waf;
	char szName[31];
	printf("Name der Textdatei ohne Erweiterung:");
	scanf("%s", &szName);
	FLUSH_STDIN;
	strcat(szName, ".txt");
	
	waf = fopen(szName, "rt");
	
	
	if (!waf)
	{
		puts("\nDatei konnte nicht geöffnet werden,\n"
			"Programm wird mit ENTER beendet.!!!");
		getchar(); 
	}
	
	return waf;
}
double ResoFrequ(double dC, double dL, double dR)
{
	double R0, Omg0;

	R0 = dL / (dR * dC);
	Omg0 = sqrt((R0 - dR) / (dL * dC * R0));

	return (Omg0 / (2 * 3.14));
}

