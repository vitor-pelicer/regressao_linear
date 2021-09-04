#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){
	int n, i;

	float X[n], Y[n], XY[n], XX[n], EX=0, EY=0, EXY=0, EXX=0, BX, BY, BXY, BXX, A, B;
	
	float DA[n], DA2[n], Ypson[n], EYpson=0, EDA=0, sigmax, epsilon, sigmaa, sigmab;

	setlocale(LC_ALL, "Portuguese");
	printf("REGRESSÃO LINEAR\n");

	printf("\n______________________________________________________\n\nquantos pontos existem no gráfico?\n");
	scanf("%d", &n);
	
	
	printf("\n______________________________________________________\n\n\t\tdigite as coordenadas X e Y dos n pontos\n");
	for(i=1;i<=n;i++){
		printf("\n%d)\t", i);
		scanf("%f %f", &X[i], &Y[i]);
		EX=EX+X[i];
		EY=EY+Y[i];
		XY[i]=X[i]*Y[i];
		EXY=EXY+XY[i];
		XX[i]=pow(X[i], 2);
		EXX=EXX+XX[i];
		
	}
	BX=EX/n;
	BY=EY/n;
	BXY=EXY/n;
	BXX=EXX/n;
	
	A=(BXY-(BX*BY))/(BXX-(pow(BX, 2)));
	B=BY-(A*BX);
	
	
	
	for(i=1;i<=n;i++){
		Ypson[i]=Y[i]-B-A*X[i];

		Ypson[i]=pow(Ypson[i], 2);

		Ypson[i]=Ypson[i]/(n-2);

		
		EYpson=EYpson+Ypson[i];
		DA[i]=(BX-X[i]);
		DA2[i]=pow(DA[i], 2);
		EDA=EDA+DA2[i];
		
     }
     epsilon=sqrt(EYpson);
     //epsilon=0,7;
    sigmax=EDA/(n-1);
	sigmax=sqrt(sigmax);
     sigmaa=(1/sigmax)*(epsilon/sqrt(n));
     sigmab=sigmaa*(sqrt(BXX));

	
	
	printf("\n______________________________________________________\n\n|   ||    X    ||    Y    ||    XY    ||    X�    |\n");
	for(i=1;i<=n;i++){
		printf("| %d |  %.3f  ||  %.3f  ||  %.3f  ||  %.3f  |\n", i,  X[i], Y[i], XY[i], XX[i]);
	}
	printf("\n|Soma|  %.3f  ||  %.3f  ||  %.3f  ||  %.3f  |\n", EX, EY, EXY, EXX);
	printf("\n______________________________________________________\n\n\tA função da reta é:\n\tf(x) = (%f)x + (%f)", A, B);
	printf("\n\nMédia X = %f\nMédia Y = %f\nMédia XY = %f\nMédia X^2 = %f\nMédia X * média Y = %f\nMédia X elevado ao quadrado = %f\n", BX, BY, BXY, BXX, BX*BY, pow(BX, 2));



printf("\n______________________________________________________\n\n");

printf("sigmax=%f\nepsilon=%f\nsigmaa=%f\nsigmab=%f\n", sigmax, epsilon, sigmaa, sigmab);

//calculo do desvio padrão em x

printf("\n______________________________________________________\n\n");
printf("\n\nCálculo do desvio padrão em X\nTabela do cálculo da somatória com os desviosa absolutos\n\n");
printf("|   X   ||   DAX   ||   DAX2   |\n");
for(i=1;i<=n;i++){
printf("|%f||%f||%f|\n", X[i], DA[i], DA2[i]);
}
printf("\n\nSoma DA2=%f\n\nDesvio padrão em X: sigmax=%f\n\n", EDA, sigmax);

printf("\n______________________________________________________\n\n");



//calculo do epsilon

printf("Tabela da somatória da fórmula de epsilon\n\n");
printf("| i ||    E   |\n");
for(i=1;i<=n;i++){
	printf("| %d ||%f|\n", i, Ypson[i]);
}
printf("|soma||%f|\n ", EYpson);
printf("\nDesvio em Y epsilon=%f\n", epsilon);

printf("\n______________________________________________________\n");


}
