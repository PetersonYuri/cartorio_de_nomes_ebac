#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	// In�cio da cria��o de vari�veis/string
	char usuario[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	
	printf("CPF: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); // Salvando as informa��es na vari�vel cpf - %s refere-se a string
	
	strcpy(usuario, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(usuario, "w"); // Cria o arquivo - "w" significa escrever
	fprintf(file,"CPF: "); // Adiciona a descri��o "CPF: " antes de mostrar o CPF solicitado
	fprintf(file,cpf); // Salva dentro do arquivo as informa��es da string citada 
	fclose(file); //fecha o arquivo
	
	file = fopen(usuario, "a"); // Abre o arquivo onde armazena os dados da vari�vel "usuario" - "a" significa atualizar
	fprintf(file, "\n"); // Pula uma linha depois da vari�vel ser inserida (melhora a visualiza��o quando consultado)
	fclose(file); //Fecha o arquivo ap�s atualiza-lo
	
	printf("Nome: "); // Mostra a qual informa��o deve ser fornecida para salvar dentro da string
	scanf("%s",nome); // string a ser salva
	
	file = fopen(usuario, "a"); // Abre o arquivo a ser atualizado
	fprintf(file,"Nome: "); // Adiciona a descri��o "Nome: " antes de mostrar o nome solicitado
	fprintf(file,nome); // Salva dentro do arquivo as informa��es da string citada 
	fclose(file); //Fecha o arquivo ap�s atualiza-lo
	
	file = fopen(usuario, "a"); // Abre o arquivo onde armazena os dados da vari�vel "arquivo" - "a" significa atualizar
	fprintf(file, "\n"); // Pula uma linha depois da vari�vel ser inserida (melhora a visualiza��o quando consultado)
	fclose(file); //Fecha o arquivo ap�s atualiza-lo
	
	printf("Sobrenome: "); // Mostra a qual informa��o deve ser fornecida para salvar dentro da string
	scanf("%s",sobrenome); // string a ser salva
	
	file = fopen(usuario, "a"); // Abre o arquivo a ser atualizado
	fprintf(file,"Sobrenome: "); // Adiciona a descri��o "Sobrenome: " antes de mostrar o sobrenome solicitado
	fprintf(file,sobrenome); // Salva dentro do arquivo as informa��es da string citada 
	fclose(file); //Fecha o arquivo ap�s atualiza-lo
	
	file = fopen(usuario, "a"); // Abre o arquivo onde armazena os dados da vari�vel "arquivo" - "a" significa atualizar
	fprintf(file, "\n"); // Pula uma linha depois da vari�vel ser inserida (melhora a visualiza��o quando consultado)
	fclose(file); //Fecha o arquivo ap�s atualiza-lo
	
	printf("Cargo: "); // Mostra a qual informa��o deve ser fornecida para salvar dentro da string
	scanf("%s",cargo); // string a ser salva
	
	file = fopen(usuario, "a"); // Abre o arquivo a ser atualizado
	fprintf(file,"Cargo: "); // Adiciona a descri��o "Cargo: " antes de mostrar o cargo solicitado
	fprintf(file,cargo); // Salva dentro do arquivo as informa��es da string citada
	fclose(file); //Fecha o arquivo ap�s atualiza-lo
	
	file = fopen(usuario, "a"); // Abre o arquivo onde armazena os dados da vari�vel "arquivo" - "a" significa atualizar
	fprintf(file, "\n"); // Pula uma linha depois da vari�vel ser inserida (melhora a visualiza��o quando consultado)
	fclose(file); //Fecha o arquivo ap�s atualiza-lo
	
	system("pause"); // Pause o sistema antes de voltar ao menu
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Determinando a regi�o de linguagem 
	
	// In�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio a ser consultado
	scanf("%s",cpf); // Salvando as informa��es na vari�vel cpf
	printf("\n"); // Salta uma linha depois da coleta de informa��o
	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo e l� ele - "r" � read (ler)
	
	if(file == NULL) // Se o arquivo n�o existir no banco de dados mostra a msg abaixo
	{
		printf("N�o foi poss�vel abrir o arquivo. Arquivo n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Se o arquivo existir no banco de dados ele ser� apresentado seguindo as regras abaixo
	{
		printf("\t"); //D� um espa�o antes de apresentar as informa��es
		printf("%s", conteudo); // Apresenta as informa��es solicitadas
	}
	
	fclose(file);
	printf("\n"); // Salta uma linha no final para a mensagem do sistema n�o ficar colada com a informa��o solicitada
	system("pause"); // Pausa o sistema antes de voltar para o menu (Para poder visualizar as informa��es)
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o encontra-se no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usu�rio deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
		
}

int main()
{   
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
    int opcao=0; //Definindo vari�vel
    int laco=1;
    char senhadigitada[]="a";
    int comparacao;
    
    printf("    Cart�rio da EBAC    \n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
    {
    	system("cls");
    	for(laco=1;laco=1;)
    	{	
    		system("cls"); // Respons�vel por limpar a tela
    	
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
			printf("    Cart�rio da EBAC    \n\n"); //In�cio do Menu
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //Fim do Menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls");
		
		
			switch(opcao) //In�cio da sele��o do Menu
			{
				case 1:
				registrar(); //In�cio da chamada de fun��es
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
			
				default:
				printf("Esta op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			} //Fim da sele��o de fun��es
    	} 
    }
	
	else
		printf("Senha incorreta!");	
}
