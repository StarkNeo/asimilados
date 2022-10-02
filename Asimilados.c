/*PROGRAMA QUE CALCULA EL IMPUESTO SOBRE LA RENTA DE UNA PERSONA FISICA QUE RECIBE HONORARIOS ASIMILADOS A SALARIOS*/
#include <stdio.h>

float monto, base, ingMes, ingPer, ingAcum, baseImp, retIsr, isrPagar, neto, limInf, cuotaFija, porcentaje, excedente, impMarg, isrDet, pago;
int opcion; // variable para decidir se calcula neto o bruto//
int dec;	// variable para decidir si realizo pagos anteriormnente//
int opcionB;

float calculoIsr(float base);
int reconstruccion();
int main()
{
	printf("\t\tJESUS HERNANDEZ 2022\n\n\n");
	printf("\t\tCALCULO DE RETENCIONES DE ISR POR HONORARIOS ASIMILADOS A SALARIOS\n Version 3.0\n\n");
	
		float tablaIsr2022[11][3] = {
			{0.01, 0.0, 1.92},
			{644.59, 12.38, 6.4},
			{5470.93, 321.26, 10.88},
			{9614.67, 772.10, 16.00},
			{11176.63, 1022.01, 17.92},
			{13381.48, 1417.12, 21.36},
			{26988.51, 4323.58, 23.52},
			{42537.59, 7980.73, 30.00},
			{81211.26, 19582.83, 32.00},
			{108281.68, 28245.36, 34.00},
			{324845.02, 101876.90, 35.00}

		};

		printf("\t\tLimite Inferior\t Cuota Fija \t %Porcentaje \n");

	for (int i = 0; i < 11; i++)
	{
		printf("fila: %d =\t", i);
		for (int j = 0; j < 3; j++)
		{
			printf("%9.2f \t", tablaIsr2022[i][j]);
		}
		printf("\n");
	}

	do

	{

		printf("\t\t\t\t ***MENU DE OPCIONES***\n\n");
		printf("1.-Capture [1] para determinar el importe neto a pagar\n");
		printf("2.-Capture [2] para determinar el importe bruto, dado un pago realizado\n");
		printf("3.-Capture [3] para obtener los importes bruto y neto, dada una cantidad deseada de ISR a pagar\n");
		printf("4.-Capture [4] para obtener los importes bruto y neto, dada una tasa deseada de ISR a pagar\n");
		printf("Que desea hacer?: ");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			printf("Capture el monto a pagar(Subtotal): ");
			scanf("%f", &ingMes);
			printf("Realizo pagos anteriormente dentro del mismo mes?:\n Si[1] No[2]: ");
			scanf("%d", &dec);
			if (dec == 1)
			{
				printf("Capture la suma de los pagos realizados(Subtotal): ");
				scanf("%f", &ingPer);
			}

			else
			{
				ingPer = 0.0;
			}

			ingAcum = ingMes + ingPer;
			printf("\n\n");
			baseImp = ingAcum;

			if (baseImp < 0)
			{
				printf("LA BASE PARA CALCULO ES NEGATIVA POR LO QUE NO HAY IMPUESTO A PAGAR EN ESTE PERIODO");
			}

			else
			{
				
				calculoIsr(baseImp);
			};

			printf("\n\n\t\t\t RESULTADO \n\n");
			printf("\t\tINGRESOS ACUMULADOS: %.2f\n", ingAcum);
			printf("\t\tLA BASE DEL IMPUESTO ES DE %.2f \n", baseImp);

			printf("\t\tEL IMPUESTO DETERMINADO ES DE: %.2f \n", isrDet);
			if (isrDet == 0)
				printf("\t\tEL ISR A RETENER POR ESTE PAGO ES DE: %.2f PESOS\n", isrPagar = 0);
			else
			{
				printf("\t\tCAPTURE LA SUMA DEL ISR RETENIDO CON ANTERIORIDAD: ");
				scanf("%f", &retIsr);
				isrPagar = isrDet - retIsr;
				printf("\t\tEL ISR A RETENER POR ESTE PAGO ES DE: %.2f PESOS\n", isrPagar);
				neto = ingAcum - isrPagar;
				printf("\t\tEL IMPORTE NETO A PAGAR ES DE: %.2f\n\n", neto);
			}
			break;

		case 2:
			reconstruccion();
			break;

		case 3:
			printf("Not available at this moment\n");
			break;

		case 4:
		
			printf("Not available at this moment\n");
			break;
		};

		printf("\nDesea continuar con el programa?: \n\n");
		printf("Capture [1] para continuar\n");
		printf("Capture [2] para salir del sistema\n");
		scanf("%d", &opcionB);
	} while (opcionB == 1);

	return 0;
}

// calcular el impuesto dado un importe a pagar.
float calculoIsr(float baseImp)
{
	float tablaIsr2022[11][3] = {
		{0.01, 0.0, 1.92},
		{644.59, 12.38, 6.4},
		{5470.93, 321.26, 10.88},
		{9614.67, 772.10, 16.00},
		{11176.63, 1022.01, 17.92},
		{13381.48, 1417.12, 21.36},
		{26988.51, 4323.58, 23.52},
		{42537.59, 7980.73, 30.00},
		{81211.26, 19582.83, 32.00},
		{108281.68, 28245.36, 34.00},
		{324845.02, 101876.90, 35.00}

	};

	for (int i = 0; i < 11; i++)
	{
		if (baseImp < tablaIsr2022[i][0])
		{
			limInf = tablaIsr2022[i - 1][0];
			cuotaFija = tablaIsr2022[i - 1][1];
			porcentaje = tablaIsr2022[i - 1][2];
			break;
		}
	};

	excedente = baseImp - limInf;
	impMarg = excedente * (porcentaje / 100);
	isrDet = impMarg + cuotaFija;

	return isrDet;
};

// calcular la base del impuesto dado un importe pagado.
int reconstruccion()
{

	base = 0.0;
	printf("Cual es el importe pagado?: \n");
	scanf("%f", &pago);
	while (monto < pago)
	{

		base = base + 1;
		monto = base - calculoIsr(base);
	}
	printf("\n\n\t\t RESULTADO \n");

	printf("LA BASE DEL IMPUESTO ES DE %.2f \n", base);

	printf("EL IMPUESTO DETERMINADO ES DE: %.2f \n", isrDet);
};
