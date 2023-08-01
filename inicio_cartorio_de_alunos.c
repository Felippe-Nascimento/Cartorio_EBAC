#include <stdio.h> // Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> // Biblioteca para aloca��o de mem�ria, Armazenamento de vari�ves, etc..
#include <locale.h> // Biblieta de texto por regi�o.
#include <string.h> // Biblioteca respons�vel por cuidar das Strings.


int registro(){
	char arquivo[20];
	char cpf[20];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\t>> CADASTRO\n\n");
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Copiar valores de Strings - "cps" p/ "arquivo".
	
	FILE *file; // Cria o arquivo.
	file = fopen(arquivo, "w"); // Abre o arquivo, "w" comando p/ escrever.
	fprintf(file, "CPF: ");
	fprintf(file, cpf); // Salva o valor da variavel.
	fclose(file); // Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // Abre o arquivo, "a" comando p/ atualizar.
	fprintf(file, "\nNOME: "); // Adicionando uma virgula entre os dados.
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\nSOBRENOME: "); 
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
		
	file = fopen(arquivo, "a"); 
	fprintf(file, "\nCARGO: "); 
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	
	fclose(file); // Fechando arquivo
	
	
	system("pause");	
}

int consulta(){
	setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem.
	
	// vari�veis
	char cpf [20];
	char conteudo[200];
	
	printf("\t>> CONSULTA\n\n");
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abrindo o arquivo, "r" ler o arquivo.
	
	
	system("cls"); // Limpa tela
	
	printf("\t>> CONSULTA\n\n");
	
	
	if (file == NULL){ // Valida��o do CPF
	
		printf(" > Arquivo n�o localizado, CPF n�o cadastrado. \n");
		
	} else{
		
		printf(" > Informa��es do usu�rio: \n\n");
		
		while (fgets(conteudo, 200, file) != NULL){
			printf("%s", conteudo);
		}
	}
	
	system("pause");
}

int deletar(){
	
	char cpf [20]; // Vari�vel
		
	printf("\t>> DELETAR\n\n");
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	system("cls"); // Limpa tela
	
	FILE *file;
	file = fopen(cpf,"r"); // Abrindo e lendo o arquivo
	
	printf("\t>> DELETAR\n\n");
	
	if (file == NULL){ // Valida��o se existe CPF
		
		printf(" > Arquivo n�o existe no sistema!\n\n");
		
	} else {
		remove(cpf);
		printf(" > Arquivo Deletado!\n\n");
	}
		
	system("pause");
}

// Fun��o principal
int main (){
	
	int opcao = 0; // Definindo vari�veis
	int laco = 1;
	
	for (laco = 1; laco = 1;){
		system("cls"); // Limpa tela

		setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem.
		
		printf("\t###  Cart�rio de Alunos  ###\n\n"); //inicio MENU
		printf("Escolha a op��o desejada no MENU:\n\n");
		
		printf("\t1 - REGISTRAR NOMES\n");
		printf("\t2 - CONSULTAR NOMES\n");
		printf("\t3 - DELETAR NOMES\n\n"); 
		
		printf("Digite a op��o: "); // fim MENU
		scanf("%d", &opcao); // armazenamento, lendo escolha do usu�rio
		
		system("cls"); // Limpa tela 
		
		switch (opcao){ // Sele��o MENU
			case 1:
				registro(); // Chamada da fun��o
			break;
			
			case 2:
				consulta(); // Chamada da fun��o
			break;
			
			case 3:
				deletar(); // Chamada da fun��o
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel \n\n");
				system("pause");
			break;
			// Fim sele��o
	
		}
			
	
	}
}

