#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
// Autor: Baruc Samuel Cabrera Garcia
using namespace std;

struct Zelda{
	int data;
	std::string dir;
};


int min(int x, int y, int z){
	
	int min = x;
	
	if(y < min){
		min = y;
	}
	
	if(z < min){
		min = z;
	}
	
	return min;
}



int dist_L(std::string w2, std::string w1){
	
	int valor;//1 si son diferentes, 0 si son iguales
	
	int up, left, diag;
	
	//Declaramos una matriz, con una casilla vacia y w1 como filas y w2 como columnas
	Zelda matrix[w1.length()+1][w2.length()+1];
	
	//Llenamos cada casilla de la primera columna con el numero del respectivo caracter de w1
	for(int i = 0; i < w1.length()+1; i++){
		matrix[i][0].data = i;
	}
	
	//Llenamos cada casilla de la primera fila con el numero del respectivo caracter de w2
	for(int j = 0; j < w2.length()+1; j++){
		matrix[0][j].data = j;
	}
	
	//Recorrer fila i
	for(int i = 1;i < w1.length()+1; i++){
		
		//Recorrer colimna j
		for(int j = 1; j < w2.length()+1; j++){
			
			if(w1[i-1] == w2[j-1]){
				valor = 0;
			}else{
				valor = 1;
			}
			
			up   = matrix[i-1][j].data + 1;
			left = matrix[i][j-1].data + 1;
			diag = matrix[i-1][j-1].data + valor;			
			
			
			matrix[i][j].data = min(up, left, diag);
			
			if(min(up, left, diag) == diag){
				matrix[i][j].dir ="diag";
			}else{
				
				if(min(up, left, diag) == up){
					matrix[i][j].dir ="up";
				}else{
					matrix[i][j].dir = "left";
				}
				
			}
			
		}
		
		
	}
	
////////////////Para imprimir la matriz
std::cout<<"\t\t";
for(int j = 0; j < w2.length(); j++){
	std:cout<<w2[j]<<"\t";
}
std::cout<<std::endl;

std::cout<<"\t";

std::cout<<matrix[0][0].data<<"\t";
for(int j = 1; j < w2.length()+1; j++){
	std::cout<<"["<<matrix[0][j].data<<"] ["<<matrix[0][j].dir<<"]\t";
}
std::cout<<std::endl;

for(int i = 1; i < w1.length()+1; i++){
	std::cout<<w1[i-1]<<"\t";
	std::cout<<matrix[i][0].data<<"\t";
	for(int j = 1; j < w2.length()+1; j++){
		std::cout<<"["<<matrix[i][j].data<<"] ["<<matrix[i][j].dir<<"]\t";
	}
	std::cout<<std::endl;
}
	std::cout<<std::endl;
///////////////


////////////

	
	return matrix[w1.length()][w2.length()].data;
}



