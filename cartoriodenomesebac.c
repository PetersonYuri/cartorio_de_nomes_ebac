#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar() //Função responsável por cadastrar os usuários no sistema
{	
	// Início da criação de variáveis/string
	char usuario[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	
	printf("CPF: "); //Coletando informação do usuário
	scanf("%s", cpf); // Salvando as informações na variável cpf - %s refere-se a string
	
	strcpy(usuario, cpf); //responsável por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(usuario, "w"); // Cria o arquivo - "w" significa escrever
	fprintf(file,"CPF: "); // Adiciona a descrição "CPF: " antes de mostrar o CPF solicitado
	fprintf(file,cpf); // Salva dentro do arquivo as informações da string citada 
	fclose(file); //fecha o arquivo
	
	file = fopen(usuario, "a"); // Abre o arquivo onde armazena os dados da variável "usuario" - "a" significa atualizar
	fprintf(file, "\n"); // Pula uma linha depois da variável ser inserida (melhora a visualização quando consultado)
	fclose(file); //Fecha o arquivo após atualiza-lo
	
	printf("Nome: "); // Mostra a qual informação deve ser fornecida para salvar dentro da string
	scanf("%s",nome); // string a ser salva
	
	file = fopen(usuario, "a"); // Abre o arquivo a ser atualizado
	fprintf(file,"Nome: "); // Adiciona a descrição "Nome: " antes de mostrar o nome solicitado
	fprintf(file,nome); // Salva dentro do arquivo as informações da string citada 
	fclose(file); //Fecha o arquivo após atualiza-lo
	
	file = fopen(usuario, "a"); // Abre o arquivo onde armazena os dados da variável "arquivo" - "a" significa atualizar
	fprintf(file, "\n"); // Pula uma linha depois da variável ser inserida (melhora a visualização quando consultado)
	fclose(file); //Fecha o arquivo após atualiza-lo
	
	printf("Sobrenome: "); // Mostra a qual informação deve ser fornecida para salvar dentro da string
	scanf("%s",sobrenome); // string a ser salva
	
	file = fopen(usuario, "a"); // Abre o arquivo a ser atualizado
	fprintf(file,"Sobrenome: "); // Adiciona a descrição "Sobrenome: " antes de mostrar o sobrenome solicitado
	fprintf(file,sobrenome); // Salva dentro do arquivo as informações da string citada 
	fclose(file); //Fecha o arquivo após atualiza-lo
	
	file = fopen(usuario, "a"); // Abre o arquivo onde armazena os dados da variável "arquivo" - "a" significa atualizar
	fprintf(file, "\n"); // Pula uma linha depois da variável ser inserida (melhora a visualização quando consultado)
	fclose(file); //Fecha o arquivo após atualiza-lo
	
	printf("Cargo: "); // Mostra a qual informação deve ser fornecida para salvar dentro da string
	scanf("%s",cargo); // string a ser salva
	
	file = fopen(usuario, "a"); // Abre o arquivo a ser atualizado
	fprintf(file,"Cargo: "); // Adiciona a descrição "Cargo: " antes de mostrar o cargo solicitado
	fprintf(file,cargo); // Salva dentro do arquivo as informações da string citada
	fclose(file); //Fecha o arquivo após atualiza-lo
	
	file = fopen(usuario, "a"); // Abre o arquivo onde armazena os dados da variável "arquivo" - "a" significa atualizar
	fprintf(file, "\n"); // Pula uma linha depois da variável ser inserida (melhora a visualização quando consultado)
	fclose(file); //Fecha o arquivo após atualiza-lo
	
	system("pause"); // Pause o sistema antes de voltar ao menu
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Determinando a região de linguagem 
	
	// Início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário a ser consultado
	scanf("%s",cpf); // Salvando as informações na variável cpf
	printf("\n"); // Salta uma linha depois da coleta de informação
	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo e lê ele - "r" é read (ler)
	
	if(file == NULL) // Se o arquivo não existir no banco de dados mostra a msg abaixo
	{
		printf("Não foi possível abrir o arquivo. Arquivo não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Se o arquivo existir no banco de dados ele será apresentado seguindo as regras abaixo
	{
		printf("\t"); //Dá um espaço antes de apresentar as informações
		printf("%s", conteudo); // Apresenta as informações solicitadas
	}
	
	fclose(file);
	printf("\n"); // Salta uma linha no final para a mensagem do sistema não ficar colada com a informação solicitada
	system("pause"); // Pausa o sistema antes de voltar para o menu (Para poder visualizar as informações)
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não encontra-se no sistema!.\n");
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
			printf("Usuário deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
		
}

int main()
{   
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
    int opcao=0; //Definindo variável
    int laco=1;
    char senhadigitada[]="a";
    int comparacao;
    
    printf("    Cartório da EBAC    \n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
    {
    	system("cls");
    	for(laco=1;laco=1;)
    	{	
    		system("cls"); // Responsável por limpar a tela
    	
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
			printf("    Cartório da EBAC    \n\n"); //Início do Menu
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //Fim do Menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usuário
	
			system("cls");
		
		
			switch(opcao) //Início da seleção do Menu
			{
				case 1:
				registrar(); //Início da chamada de funções
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
				printf("Esta opção não está disponível!\n");
				system("pause");
				break;
			} //Fim da seleção de funções
    	} 
    }
	
	else
		printf("Senha incorreta!");	
}
