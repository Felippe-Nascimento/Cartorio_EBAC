#include <stdio.h> // Biblioteca de comunicação com o usuário.
#include <stdlib.h> // Biblioteca para alocação de memória, Armazenamento de variáves, etc..
#include <locale.h> // Biblieta de texto por região.
#include <string.h> // Biblioteca responsável por cuidar das Strings.


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
	
	// variáveis
	char cpf [20];
	char conteudo[200];
	
	printf("\t>> CONSULTA\n\n");
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abrindo o arquivo, "r" ler o arquivo.
	
	
	system("cls"); // Limpa tela
	
	printf("\t>> CONSULTA\n\n");
	
	
	if (file == NULL){ // Validação do CPF
	
		printf(" > Arquivo não localizado, CPF não cadastrado. \n");
		
	} else{
		
		printf(" > Informações do usuário: \n\n");
		
		while (fgets(conteudo, 200, file) != NULL){
			printf("%s", conteudo);
		}
	}
	
	system("pause");
}

int deletar(){
	
	char cpf [20]; // Variável
		
	printf("\t>> DELETAR\n\n");
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	system("cls"); // Limpa tela
	
	FILE *file;
	file = fopen(cpf,"r"); // Abrindo e lendo o arquivo
	
	printf("\t>> DELETAR\n\n");
	
	if (file == NULL){ // Validação se existe CPF
		
		printf(" > Arquivo não existe no sistema!\n\n");
		
	} else {
		remove(cpf);
		printf(" > Arquivo Deletado!\n\n");
	}
		
	system("pause");
}

// Função principal
int main (){
	
	int opcao = 0; // Definindo variáveis
	int laco = 1;
	
	for (laco = 1; laco = 1;){
		system("cls"); // Limpa tela

		setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem.
		
		printf("\t###  Cartório de Alunos  ###\n\n"); //inicio MENU
		printf("Escolha a opção desejada no MENU:\n\n");
		
		printf("\t1 - REGISTRAR NOMES\n");
		printf("\t2 - CONSULTAR NOMES\n");
		printf("\t3 - DELETAR NOMES\n\n"); 
		
		printf("Digite a opção: "); // fim MENU
		scanf("%d", &opcao); // armazenamento, lendo escolha do usuário
		
		system("cls"); // Limpa tela 
		
		switch (opcao){ // Seleção MENU
			case 1:
				registro(); // Chamada da função
			break;
			
			case 2:
				consulta(); // Chamada da função
			break;
			
			case 3:
				deletar(); // Chamada da função
			break;
			
			default:
				printf("Essa opção não está disponível \n\n");
				system("pause");
			break;
			// Fim seleção
	
		}
			
	
	}
}

