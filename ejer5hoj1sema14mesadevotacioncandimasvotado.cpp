#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;
using namespace System;



void ingresadatos(int **votacion)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
		{
			cout << "ingrese votacion [" << i + 1 << "][" << j + 1 << "]:";
			cin >> votacion[i][j];
		}
}


void salidadatos(int **votacion)
{
	cout << "cand 1" << "\t" << "cand 2" << "\t" << "cand 3" << "\t" << "cand 4" << "\t" << "cand 5" << "\t" << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << votacion[i][j] << "\t";

		cout << endl;
	}
}





void votosxcandidato(int **votacion, float *porcent)
{
	float sumatotal = 0;
	for (int j = 0; j < 5; j++)
		for (int i = 0; i < 4; i++)
		{
			sumatotal = sumatotal + votacion[i][j];
		}

	float suma; int i; float porcentaje; float porce;	float mayor = 0; int candidato;
	for (int j = 0; j < 5; j++)
	{
		suma = 0;
		for (int i = 0; i < 4; i++)
		{
			suma = suma + votacion[i][j];
			porcentaje = (suma / sumatotal);

			if (mayor < suma)
			{
				mayor = suma;
				candidato = j + 1;
				porce = porcentaje;
			}

		}
		float temp;
		porcent[j] = porcentaje;
		if (porcent[j] > porcent[j + 1])
		{
			temp = porcent[j];
			porcent[j] = porcent[j + 1];
			porcent[j + 1] = temp;
		

		}
		cout << "votacion del candidato " << j + 1 << " es: " << suma << "      " << porcentaje * 100 << "%" << endl;
	}
	cout << "votacion total: " << sumatotal << endl;
	cout << "el candidato mas votado es " << candidato << " " << porce << endl;
	if (porce > 0.5)
		cout << "granador" << endl;
	else cout << "los dos candidatos mas botados son: " << candidato <<" "<<<< endl;






}



//
//void ventasañosagencia3(int **ventas)
//{
//	int suma; int i;
//	for (int j = 0; j < 5; j++)
//	{
//		suma = 0;
//		for (int i = 0; i < 12; i++)
//		{
//			suma = suma + ventas[i][2];
//		}
//	}cout << endl;
//	cout << "ventas de la agencia:3 " << " es: " << suma << endl << endl;
//}

//
//void ventaspromdicien(int **ventas)
//{
//	float suma; int i; float prom;
//	for (int i = 0; i < 12; i++)
//	{
//		suma = 0;
//		for (int j = 0; j < 5; j++)
//		{
//			suma = suma + ventas[11][j];
//			prom = suma / 5;
//		}
//	}cout << "ventas promedio de diciembre de todas las agencias:  " << prom << endl << endl;
//}

/*void queagenciamayorventamayo(int **ventas)
{
int mayor; int agencia;
for (int i = 0; i < 12; i++)
for (int j = 0; j < 5; j++)
if (mayor < ventas[4][j])
{
mayor = ventas[4][j];
agencia = j + 1;
}
cout << "la agencia de mayor venta en mayo es: " << agencia << endl << endl;
}*/


//void candimasvotado(int **votacion)
//{
//	float mayor = 0; int candidato; float suma; int i, j;
//	for (int j = 0; j < 5; j++)
//	{
//		suma = 0;
//		for (int i = 0; i < 4; i++)
//			suma = suma + votacion[i][j];
//
//		if (mayor < suma)
//		{
//			mayor = suma;
//			candidato = j + 1;
//		}
//	}
//	//if(candidato>)
//	cout << "el candidato mas votado es " << candidato <<" "<< endl;
//}



int main()
{
	float *porcent;
	porcent = new float[5];
	int *v = new int[4];
	int **votacion;
	votacion = new int *[4];
	for (int i = 0; i < 4; i++)
		votacion[i] = new int[5];
	ingresadatos(votacion);
	salidadatos(votacion);
	votosxcandidato(votacion, porcent);
	//candimasvotado(votacion);

	for (int i = 0; i < 4; i++)
		delete[] votacion[i];
	delete[] votacion;

	_getch();
}
