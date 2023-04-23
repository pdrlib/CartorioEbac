#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salve no arquivo file a varia�vel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //mandou a file abrir o arquivo
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //quero abrir o arquivo
	fprintf(file,nome); //quero que o usu�rio digita na file o nome do arquivo
	fclose(file); //quero que o arquivo feche
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //armazenar (� o s) dentro da vari�vel "sobrenome"
	
	file = fopen(arquivo, "a"); //abra o arquivo que j� est� salvo; atualiza ele ("a")
	fprintf(file,sobrenome); //jogue dentro do arquivo o  sobrenome que o usu�rio digitar
	fclose(file); //comando para o computador fechar o arquivo
	
	file = fopen(arquivo, "a"); //mandou a file abrir o arquivo
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta() //fun��o respons�vel por consultar cpfs de usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //biblioteca que permite a l�ngua portuguesa no sistema

	//in�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final cria��o de vari�veis/string

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r"); //r de read, � pra ler o arquivo
	
	if(file == NULL) //se n�o achou o arquivo...
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); //digite esse texto para o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //ele est� salvando na string conte�do de 200 caracteres que est�o dentro do arquivo file
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //exiba esse texto para o usu�rio
		printf("%s", conteudo); //exiba o conte�do da string conte�do
		printf("\n\n"); //exiba pular duas linhas
	}
	
	system("pause"); //o sistema encerra a fun��o consulta
	
}

int deletar() //fun��o respons�vel por deletar cpfs dos usu�rios do sistema
{
	//in�cio cria��o de vari�veis/string
	char cpf[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //fun��o de deletar o arquivo cpf com a string designada acima
	
	FILE *file; //abrir o arquivo
	file = fopen(cpf,"r"); //ler o arquivo cpf
	
	if(file == NULL) //se n�o h� nenhum arquivo com esse nome...
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //exiba esse texto ao usu�rio
		system("pause"); //o sistema encerra a fun��o deletar
	}
	
}

int main() //menu principal
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do mundo
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");	
			break;
			
		} //fim da sele��o
	
	}
	
}
