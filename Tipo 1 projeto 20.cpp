#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int quantidade_inicial_pedidos = 0, quantidade_inicial_servico = 0;

	int i, j, a, escolha, nada = 0;
	float sem_enchimento[quantidade_inicial_pedidos][quantidade_inicial_servico], especifico_enchimentobasico[quantidade_inicial_pedidos][quantidade_inicial_servico], especifico_enchimento3D[quantidade_inicial_pedidos][100];
	float todos_enchimentobasico[quantidade_inicial_pedidos][quantidade_inicial_servico], todos_enchimento3D[quantidade_inicial_pedidos][quantidade_inicial_servico], valor_total_enchimento[quantidade_inicial_pedidos][100];
	float Enchimento_TOTAL_Basico[quantidade_inicial_pedidos][quantidade_inicial_servico], Enchimento_TOTAL_3D[quantidade_inicial_pedidos][quantidade_inicial_servico];
	int zero = 0, existe_pedido = 0;
	int decisao = 0;
	float maior = 0, menor = 0, soma = 0;
	float preco_m2[quantidade_inicial_servico], quantidade_servico[quantidade_inicial_pedidos][quantidade_inicial_servico], valor_servico_sem_enchimento[quantidade_inicial_pedidos][10], valor_enchimento[quantidade_inicial_pedidos][100];
	float aux_m2[quantidade_inicial_servico], aux_quant[quantidade_inicial_servico], aux_sem_enchimento[quantidade_inicial_pedidos][quantidade_inicial_servico], aux_especifico_enchimentobasico[quantidade_inicial_pedidos][10], aux_especifico_enchimento3D[quantidade_inicial_pedidos][10];
	float faturamento_pedido = 0, faturamento_total = 0, receita_pedido[quantidade_inicial_servico], valor_total_servico[quantidade_inicial_servico][10];
	float faturamento_basico_total, faturamento_3D_total, quantidade_basico_total, quantidade_3D_total;
	float faturamento_basico_do_pedido[quantidade_inicial_pedidos], faturamento_3D_do_pedido[quantidade_inicial_pedidos];

	printf("--------[Respeite os limites acerca dos valores]------\n");
	printf("             ------->[Nao use virgula]<------\n");
	printf("\n");
	printf("      [Maximo de ate 10 pedidos]\n");
	// quantidade de pedidos
	do
	{
		printf("(1) Digite a quantidade de pedidos = ");
		scanf("%d", &quantidade_inicial_pedidos);
		if (quantidade_inicial_pedidos < 0)
		{
			printf(">Digite novamente a quantidade de pedidos<");
			printf("\n");
		}
		else if (quantidade_inicial_pedidos > 10)
		{
			printf(">Digite novamente a quantidade de pedidos<");
			printf("\n");
		}
	} while (quantidade_inicial_pedidos < 0 || quantidade_inicial_pedidos > 10);

	// quantidade de servicos
	printf("\n      [Maximo de ate 10 servicos]\n");
	do
	{
		printf("(2) Digite a quantidade de servicos = ");
		scanf("%d", &quantidade_inicial_servico);
		if (quantidade_inicial_servico < 0)
		{
			printf(">Digite novamente a quantidade de servicos<");
			printf("\n");
		}
		else if (quantidade_inicial_servico > 10)
		{
			printf(">Digite novamente a quantidade de servicos<");
			printf("\n");
		}
	} while (quantidade_inicial_servico < 0 || quantidade_inicial_servico > 10);
	printf("\n");

	// nome do servi�o(OK)
	printf("------->[Digite os nomes dos servicos]<------\n");
	printf("\n");
	char nome[quantidade_inicial_servico][50];
	for (i = 0; i < quantidade_inicial_servico; i++)
	{
		printf("Servico %d = ", i + 1);
		fflush(stdin);
		gets(nome[i]);
	}

	printf("\n");

	printf("------->[Digite os valores de m2 dos servicos]<------\n");
	for (i = 0; i < quantidade_inicial_servico; i++)
	{
		do
		{
			printf("(3)Digite o valor do m2 do servico [%s]= R$", nome[i]);
			scanf("%f", &aux_m2[i]);
			if (aux_m2[i] < 0)
			{
				printf("\n");
				printf(">Digite novamente o valor do m2 do servico [%s] <", nome[i]);
				printf("\n");
			}
		} while (aux_m2[i] < 0);
		preco_m2[i] = aux_m2[i];
	}
	printf("\n");

	// inicio dos pedidos, ate 10
	for (i = 0; i < quantidade_inicial_pedidos; i++)
	{
		printf("\n");
		printf("         [Pedido %d ]", i + 1);
		printf("\n");

		for (j = 0; j < quantidade_inicial_servico; j++)
		{
			do
			{
				printf("\n");
				printf("(4)Digite a quantidade de m2 desejada do servico [%s] =", nome[j]);
				scanf("%f", &aux_quant[j]);
				if (aux_quant[j] < 0)
				{
					printf("\n");
					printf(">Digite novamente a quantidade do servico [%s] <", nome[j]);
					printf("\n");
				}
				else if (aux_quant[j] == 0)
				{
					printf("\n");
					printf(">Digite novamente a quantidade do servico [%s] <", nome[j]);
					printf("\n");
				}
			} while (aux_quant[j] < 0);
			quantidade_servico[i][j] = aux_quant[j];

			if (quantidade_servico[i][j] > 0)
			{
				printf("      >[Informe se deseja adicionar enchimento]<  \n");
				printf("=>Digite [0] para nao ter enchimentos\n");
				printf("=>Digite [1] para decidir a quantidade de metros de enchimentos\n");
				printf("=>Digite [2] para colocar Enchimentos Basicos em todos o servico\n");
				printf("=>Digite [3] para colocar Enchimentos 3D em todos o servico\n");
				printf("Digite:");
				scanf("%d", &escolha);

				// Menu para decidir a quantidade de enchimentos
				switch (escolha)
				{
				case 1: // achar a quantidade sem enchimentos
					do
					{
						printf("=> Digite a quantidade de estofados sem enchimentos:");
						scanf("%f", &aux_sem_enchimento[i][j]);
						if (aux_sem_enchimento[i][j] < 0)
						{
							printf("\n");
							printf(">Digite novamente a quantidade sem enchimentos<");
							printf("\n");
						}
					} while (aux_sem_enchimento[j] < 0);
					sem_enchimento[i][j] = aux_sem_enchimento[i][j];
					if (escolha != 1)
					{
						aux_sem_enchimento[i][j] = 0;
						sem_enchimento[i][j] = 0;
					}

					do
					{
						printf("=> Digite a quantidade de estofados com enchimentos Basicos:");
						scanf("%f", &aux_especifico_enchimentobasico[i][j]);
						if (aux_especifico_enchimentobasico[i][j] < 0)
						{
							printf("\n");
							printf(">Digite novamente a quantidade com enchimentos Basicos<");
							printf("\n");
						}
					} while (aux_especifico_enchimentobasico[i][j] < 0);
					especifico_enchimentobasico[i][j] = aux_especifico_enchimentobasico[i][j];

					if (escolha != 1)
					{
						aux_especifico_enchimentobasico[i][j] = 0;
						especifico_enchimentobasico[i][j] = 0;
					}
					do
					{
						printf("=> Digite a quantidade de estofados com enchimentos 3D:");
						scanf("%f", &aux_especifico_enchimento3D[i][j]);
					} while (aux_especifico_enchimento3D[i][j] < 0);
					especifico_enchimento3D[i][j] = aux_especifico_enchimento3D[i][j];
					if (escolha != 1)
					{
						aux_especifico_enchimento3D[i][j] = 0;
						especifico_enchimento3D[i][j] = 0;
					}
					todos_enchimentobasico[i][j] = 0;
					todos_enchimento3D[i][j] = 0;
					break;

				case 2:
					printf("\n[Enchimento Basico adicionado em todos os estofados]");
					todos_enchimentobasico[i][j] = quantidade_servico[i][j];
					todos_enchimento3D[i][j] = 0;
					especifico_enchimento3D[i][j] = 0;
					especifico_enchimentobasico[i][j] = 0;
					sem_enchimento[i][j] = 0;
					if (escolha != 2)
					{
						todos_enchimentobasico[i][j] = 0;
					}

					break;

				case 3:
					printf("\n[Enchimento 3D adicionado em todos os estofados]");
					todos_enchimento3D[i][j] = quantidade_servico[i][j];
					todos_enchimentobasico[i][j] = 0;
					especifico_enchimento3D[i][j] = 0;
					especifico_enchimentobasico[i][j] = 0;
					sem_enchimento[i][j] = 0;
					if (escolha != 3)
					{
						todos_enchimento3D[i][j] = 0;
					}

					break;

				default:
					printf("\n[Sem enchimentos nos estofados do servico (%s) ]", nome[j]);
					sem_enchimento[i][j] = aux_quant[j];
					for (int zero = 0; zero < aux_quant[j]; zero++)
					{
						todos_enchimento3D[i][j] = 0;
						todos_enchimentobasico[i][j] = 0;
						especifico_enchimento3D[i][j] = 0;
						especifico_enchimentobasico[i][j] = 0;
						quantidade_basico_total = 0;
						quantidade_3D_total = 0;
						faturamento_basico_total = 0;
						faturamento_3D_total = 0;
					}
				}
			}
			Enchimento_TOTAL_Basico[i][j] = (especifico_enchimentobasico[i][j] + todos_enchimentobasico[i][j]) * 30;
			Enchimento_TOTAL_3D[i][j] = (especifico_enchimento3D[i][j] + todos_enchimento3D[i][j]) * 50;

			quantidade_basico_total = quantidade_basico_total + Enchimento_TOTAL_Basico[i][j];
			quantidade_3D_total = quantidade_3D_total + Enchimento_TOTAL_3D[i][j];

			faturamento_basico_total = faturamento_basico_total + Enchimento_TOTAL_Basico[i][j];
			faturamento_3D_total = faturamento_3D_total + Enchimento_TOTAL_3D[i][j];

			valor_enchimento[i][j] = Enchimento_TOTAL_Basico[i][j] + Enchimento_TOTAL_3D[i][j];

			valor_servico_sem_enchimento[i][j] = preco_m2[j] * quantidade_servico[i][j];
			valor_total_servico[i][j] = valor_servico_sem_enchimento[i][j] + valor_enchimento[i][j];
			printf("\n");
			printf("=>Valor total do servico %d = R$%.2f", j + 1, valor_total_servico[i][j]);
			printf("\n----------------------------");
		}
		// Quest�o 2
		printf("\n");
		if (quantidade_basico_total > quantidade_3D_total)
		{
			printf("[O enchimento basico foi o que teve maior quantidade com %.f]", quantidade_basico_total);
		}
		else if (quantidade_basico_total < quantidade_3D_total)
		{
			printf("[O enchimento 3D foi o que teve maior quantidade com %.f]", quantidade_3D_total);
		}
		else if (quantidade_3D_total == quantidade_basico_total)
		{
			printf("[Os dois enchimentos tiveram a mesma quantidade com %.f]", quantidade_basico_total);
		}
		else if (quantidade_3D_total == 0 && quantidade_basico_total == 0)
		{
			printf("[Nao existe comparacao, pois nao tem enchimentos]");
		}

		// Quest�o 4

		printf("\n");
		printf("\n");
		if (faturamento_basico_total > faturamento_3D_total)
		{
			printf("[O enchimento basico foi o que teve maior faturamento com R$%.2f]", faturamento_basico_total);
		}
		else if (faturamento_basico_total < faturamento_3D_total)
		{
			printf("[O enchimento 3D foi o que teve maior faturamento com R$%.2f]", faturamento_3D_total);
		}
		else if (faturamento_basico_total == faturamento_3D_total)
		{
			printf("[Os dois enchimentos tiveram o mesmo faturamento com R$%.2f]\n", faturamento_basico_total);
		}
		else if (faturamento_basico_total == 0 && faturamento_3D_total == 0)
		{
			printf("[Nao existe comparacao, pois nao tem enchimentos]\n");
		}
	}

	for (i = 0; i < quantidade_inicial_pedidos; i++)
		for (j = 0; j < quantidade_inicial_servico; j++)
			faturamento_total = faturamento_total + valor_total_servico[i][j];

	printf("\n");
	printf("--------------------------------------\n");
	// Quest�o 5
	printf("  [O faturamento total dos pedidos = R$%.2f] \n", faturamento_total);
	// Quest�o 6
	printf("  [A media do faturamento = R$%.2f]  ", faturamento_total / quantidade_inicial_pedidos);
	printf("\n--------------------------------------");
	printf("\n");

	float numero_maior[quantidade_inicial_servico], numero_menor[quantidade_inicial_servico];

	// Quest�o 1
	for (i = 0; i < quantidade_inicial_servico; i++)
	{
		soma = 0;
		for (j = 0; j < quantidade_inicial_pedidos; j++)
		{
			soma += quantidade_servico[i][j];
		}
		numero_maior[i] += soma;
	}

	for (i = 0; i < quantidade_inicial_servico; i++)
	{
		soma = 0;
		for (j = 0; j < quantidade_inicial_pedidos; j++)
		{
			soma += quantidade_servico[i][j];
		}
		numero_menor[i] += soma;
	}

	for (i = 0; i < quantidade_inicial_servico; i++)
	{
		numero_menor[i] = menor;
	}
	for (i = 0; i < quantidade_inicial_servico; i++)
	{
		if (numero_maior[i] >= quantidade_servico[i][10])
		{
			printf("\nO servico que foi o mais requisitado foi [%s], com volume de: %.2f", nome[i], numero_maior[i]);
		}
	}

	int valor, Servico_mais_contratado = 0;
	float soma_da_coluna[10];
	{
		for (valor = 0; valor < 10; valor++)
		{
			if (soma_da_coluna[valor] > soma_da_coluna[Servico_mais_contratado])
			{
				Servico_mais_contratado = valor;
				printf("[O servico mais contratado foi:(%s)] \n", nome[Servico_mais_contratado]);
			}
		}
	}

	return 0;
}
