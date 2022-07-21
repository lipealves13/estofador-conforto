#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int QuantidadeInicialPedido = 0, QuantidadeInicialPedido = 0;

	int i, j, a, escolha, nada = 0;
	float SemEnchimento[QuantidadeInicialPedido][QuantidadeInicialPedido], EspecificoEnchimentoBasico[QuantidadeInicialPedido][QuantidadeInicialPedido], EspecificoEnchimento3d[QuantidadeInicialPedido][100];
	float TodosEnchimentosBasicos[QuantidadeInicialPedido][QuantidadeInicialPedido], TodosEnchimento3d[QuantidadeInicialPedido][QuantidadeInicialPedido], valor_total_enchimento[QuantidadeInicialPedido][100];
	float EnchimentoTotalBasico[QuantidadeInicialPedido][QuantidadeInicialPedido], EnchimentoTotal3d[QuantidadeInicialPedido][QuantidadeInicialPedido];
	int zero = 0, existe_pedido = 0;
	int decisao = 0;
	float maior = 0, menor = 0, soma = 0;
	float PrecoMetrosQuadrados[QuantidadeInicialPedido], QuantidadeServico[QuantidadeInicialPedido][QuantidadeInicialPedido], ValorServicoSemEnchimento[QuantidadeInicialPedido][10], ValorEnchimento[QuantidadeInicialPedido][100];
	float AuxiliarMetrosQuadrados[QuantidadeInicialPedido], AuxiliarQuantidade[QuantidadeInicialPedido], AuxliliarSemEnchimento[QuantidadeInicialPedido][QuantidadeInicialPedido], AuxiliarEspecificoEnchimentoBasico[QuantidadeInicialPedido][10], AuxiliarEnchimento3d[QuantidadeInicialPedido][10];
	float faturamento_pedido = 0, faturamento_total = 0, receita_pedido[QuantidadeInicialPedido], ValorTotalServico[QuantidadeInicialPedido][10];
	float faturamento_basico_total, faturamento_3D_total, QuantidadeTotalBasico, QuantidadeTotal3d;
	float faturamento_basico_do_pedido[QuantidadeInicialPedido], faturamento_3D_do_pedido[QuantidadeInicialPedido];

	printf("--------[Respeite os limites acerca dos valores]------\n");
	printf("             ------->[Nao use virgula]<------\n");
	printf("\n");
	printf("      [Maximo de ate 10 pedidos]\n");
	// quantidade de pedidos
	do
	{
		printf("(1) Digite a quantidade de pedidos = ");
		scanf("%d", &QuantidadeInicialPedido);
		if (QuantidadeInicialPedido < 0)
		{
			printf(">Digite novamente a quantidade de pedidos<");
			printf("\n");
		}
		else if (QuantidadeInicialPedido > 10)
		{
			printf(">Digite novamente a quantidade de pedidos<");
			printf("\n");
		}
	} while (QuantidadeInicialPedido < 0 || QuantidadeInicialPedido > 10);

	// quantidade de servicos
	printf("\n      [Maximo de ate 10 servicos]\n");
	do
	{
		printf("(2) Digite a quantidade de servicos = ");
		scanf("%d", &QuantidadeInicialPedido);
		if (QuantidadeInicialPedido < 0)
		{
			printf(">Digite novamente a quantidade de servicos<");
			printf("\n");
		}
		else if (QuantidadeInicialPedido > 10)
		{
			printf(">Digite novamente a quantidade de servicos<");
			printf("\n");
		}
	} while (QuantidadeInicialPedido < 0 || QuantidadeInicialPedido > 10);
	printf("\n");

	// nome do servi�o(OK)
	printf("------->[Digite os nomes dos servicos]<------\n");
	printf("\n");
	char nome[QuantidadeInicialPedido][50];
	for (i = 0; i < QuantidadeInicialPedido; i++)
	{
		printf("Servico %d = ", i + 1);
		fflush(stdin);
		gets(nome[i]);
	}

	printf("\n");

	printf("------->[Digite os valores de m2 dos servicos]<------\n");
	for (i = 0; i < QuantidadeInicialPedido; i++)
	{
		do
		{
			printf("(3)Digite o valor do m2 do servico [%s]= R$", nome[i]);
			scanf("%f", &AuxiliarMetrosQuadrados[i]);
			if (AuxiliarMetrosQuadrados[i] < 0)
			{
				printf("\n");
				printf(">Digite novamente o valor do m2 do servico [%s] <", nome[i]);
				printf("\n");
			}
		} while (AuxiliarMetrosQuadrados[i] < 0);
		PrecoMetrosQuadrados[i] = AuxiliarMetrosQuadrados[i];
	}
	printf("\n");

	// inicio dos pedidos, ate 10
	for (i = 0; i < QuantidadeInicialPedido; i++)
	{
		printf("\n");
		printf("         [Pedido %d ]", i + 1);
		printf("\n");

		for (j = 0; j < QuantidadeInicialPedido; j++)
		{
			do
			{
				printf("\n");
				printf("(4)Digite a quantidade de m2 desejada do servico [%s] =", nome[j]);
				scanf("%f", &AuxiliarQuantidade[j]);
				if (AuxiliarQuantidade[j] < 0)
				{
					printf("\n");
					printf(">Digite novamente a quantidade do servico [%s] <", nome[j]);
					printf("\n");
				}
				else if (AuxiliarQuantidade[j] == 0)
				{
					printf("\n");
					printf(">Digite novamente a quantidade do servico [%s] <", nome[j]);
					printf("\n");
				}
			} while (AuxiliarQuantidade[j] < 0);
			QuantidadeServico[i][j] = AuxiliarQuantidade[j];

			if (QuantidadeServico[i][j] > 0)
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
						scanf("%f", &AuxliliarSemEnchimento[i][j]);
						if (AuxliliarSemEnchimento[i][j] < 0)
						{
							printf("\n");
							printf(">Digite novamente a quantidade sem enchimentos<");
							printf("\n");
						}
					} while (AuxliliarSemEnchimento[j] < 0);
					SemEnchimento[i][j] = AuxliliarSemEnchimento[i][j];
					if (escolha != 1)
					{
						AuxliliarSemEnchimento[i][j] = 0;
						SemEnchimento[i][j] = 0;
					}

					do
					{
						printf("=> Digite a quantidade de estofados com enchimentos Basicos:");
						scanf("%f", &AuxiliarEspecificoEnchimentoBasico[i][j]);
						if (AuxiliarEspecificoEnchimentoBasico[i][j] < 0)
						{
							printf("\n");
							printf(">Digite novamente a quantidade com enchimentos Basicos<");
							printf("\n");
						}
					} while (AuxiliarEspecificoEnchimentoBasico[i][j] < 0);
					EspecificoEnchimentoBasico[i][j] = AuxiliarEspecificoEnchimentoBasico[i][j];

					if (escolha != 1)
					{
						AuxiliarEspecificoEnchimentoBasico[i][j] = 0;
						EspecificoEnchimentoBasico[i][j] = 0;
					}
					do
					{
						printf("=> Digite a quantidade de estofados com enchimentos 3D:");
						scanf("%f", &AuxiliarEnchimento3d[i][j]);
					} while (AuxiliarEnchimento3d[i][j] < 0);
					EspecificoEnchimento3d[i][j] = AuxiliarEnchimento3d[i][j];
					if (escolha != 1)
					{
						AuxiliarEnchimento3d[i][j] = 0;
						EspecificoEnchimento3d[i][j] = 0;
					}
					TodosEnchimentosBasicos[i][j] = 0;
					TodosEnchimento3d[i][j] = 0;
					break;

				case 2:
					printf("\n[Enchimento Basico adicionado em todos os estofados]");
					TodosEnchimentosBasicos[i][j] = QuantidadeServico[i][j];
					TodosEnchimento3d[i][j] = 0;
					EspecificoEnchimento3d[i][j] = 0;
					EspecificoEnchimentoBasico[i][j] = 0;
					SemEnchimento[i][j] = 0;
					if (escolha != 2)
					{
						TodosEnchimentosBasicos[i][j] = 0;
					}

					break;

				case 3:
					printf("\n[Enchimento 3D adicionado em todos os estofados]");
					TodosEnchimento3d[i][j] = QuantidadeServico[i][j];
					TodosEnchimentosBasicos[i][j] = 0;
					EspecificoEnchimento3d[i][j] = 0;
					EspecificoEnchimentoBasico[i][j] = 0;
					SemEnchimento[i][j] = 0;
					if (escolha != 3)
					{
						TodosEnchimento3d[i][j] = 0;
					}

					break;

				default:
					printf("\n[Sem enchimentos nos estofados do servico (%s) ]", nome[j]);
					SemEnchimento[i][j] = AuxiliarQuantidade[j];
					for (int zero = 0; zero < AuxiliarQuantidade[j]; zero++)
					{
						TodosEnchimento3d[i][j] = 0;
						TodosEnchimentosBasicos[i][j] = 0;
						EspecificoEnchimento3d[i][j] = 0;
						EspecificoEnchimentoBasico[i][j] = 0;
						QuantidadeTotalBasico = 0;
						QuantidadeTotal3d = 0;
						faturamento_basico_total = 0;
						faturamento_3D_total = 0;
					}
				}
			}
			EnchimentoTotalBasico[i][j] = (EspecificoEnchimentoBasico[i][j] + TodosEnchimentosBasicos[i][j]) * 30;
			EnchimentoTotal3d[i][j] = (EspecificoEnchimento3d[i][j] + TodosEnchimento3d[i][j]) * 50;

			QuantidadeTotalBasico = QuantidadeTotalBasico + EnchimentoTotalBasico[i][j];
			QuantidadeTotal3d = QuantidadeTotal3d + EnchimentoTotal3d[i][j];

			faturamento_basico_total = faturamento_basico_total + EnchimentoTotalBasico[i][j];
			faturamento_3D_total = faturamento_3D_total + EnchimentoTotal3d[i][j];

			ValorEnchimento[i][j] = EnchimentoTotalBasico[i][j] + EnchimentoTotal3d[i][j];

			ValorServicoSemEnchimento[i][j] = PrecoMetrosQuadrados[j] * QuantidadeServico[i][j];
			ValorTotalServico[i][j] = ValorServicoSemEnchimento[i][j] + ValorEnchimento[i][j];
			printf("\n");
			printf("=>Valor total do servico %d = R$%.2f", j + 1, ValorTotalServico[i][j]);
			printf("\n----------------------------");
		}
		// Quest�o 2
		printf("\n");
		if (QuantidadeTotalBasico > QuantidadeTotal3d)
		{
			printf("[O enchimento basico foi o que teve maior quantidade com %.f]", QuantidadeTotalBasico);
		}
		else if (QuantidadeTotalBasico < QuantidadeTotal3d)
		{
			printf("[O enchimento 3D foi o que teve maior quantidade com %.f]", QuantidadeTotal3d);
		}
		else if (QuantidadeTotal3d == QuantidadeTotalBasico)
		{
			printf("[Os dois enchimentos tiveram a mesma quantidade com %.f]", QuantidadeTotalBasico);
		}
		else if (QuantidadeTotal3d == 0 && QuantidadeTotalBasico == 0)
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

	for (i = 0; i < QuantidadeInicialPedido; i++)
		for (j = 0; j < QuantidadeInicialPedido; j++)
			faturamento_total = faturamento_total + ValorTotalServico[i][j];

	printf("\n");
	printf("--------------------------------------\n");
	// Quest�o 5
	printf("  [O faturamento total dos pedidos = R$%.2f] \n", faturamento_total);
	// Quest�o 6
	printf("  [A media do faturamento = R$%.2f]  ", faturamento_total / QuantidadeInicialPedido);
	printf("\n--------------------------------------");
	printf("\n");

	float numero_maior[QuantidadeInicialPedido], numero_menor[QuantidadeInicialPedido];

	// Quest�o 1
	for (i = 0; i < QuantidadeInicialPedido; i++)
	{
		soma = 0;
		for (j = 0; j < QuantidadeInicialPedido; j++)
		{
			soma += QuantidadeServico[i][j];
		}
		numero_maior[i] += soma;
	}

	for (i = 0; i < QuantidadeInicialPedido; i++)
	{
		soma = 0;
		for (j = 0; j < QuantidadeInicialPedido; j++)
		{
			soma += QuantidadeServico[i][j];
		}
		numero_menor[i] += soma;
	}

	for (i = 0; i < QuantidadeInicialPedido; i++)
	{
		numero_menor[i] = menor;
	}
	for (i = 0; i < QuantidadeInicialPedido; i++)
	{
		if (numero_maior[i] >= QuantidadeServico[i][10])
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
