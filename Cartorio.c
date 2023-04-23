#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salve no arquivo file a variaável cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //mandou a file abrir o arquivo
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //quero abrir o arquivo
	fprintf(file,nome); //quero que o usuário digita na file o nome do arquivo
	fclose(file); //quero que o arquivo feche
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //armazenar (é o s) dentro da variável "sobrenome"
	
	file = fopen(arquivo, "a"); //abra o arquivo que já está salvo; atualiza ele ("a")
	fprintf(file,sobrenome); //jogue dentro do arquivo o  sobrenome que o usuário digitar
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

int consulta() //função responsável por consultar cpfs de usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //biblioteca que permite a língua portuguesa no sistema

	//início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final criação de variáveis/string

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r"); //r de read, é pra ler o arquivo
	
	if(file == NULL) //se não achou o arquivo...
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); //digite esse texto para o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //ele está salvando na string conteúdo de 200 caracteres que estão dentro do arquivo file
	{
		printf("\nEssas são as informações do usuário: "); //exiba esse texto para o usuário
		printf("%s", conteudo); //exiba o conteúdo da string conteúdo
		printf("\n\n"); //exiba pular duas linhas
	}
	
	system("pause"); //o sistema encerra a função consulta
	
}

int deletar() //função responsável por deletar cpfs dos usuários do sistema
{
	//início criação de variáveis/string
	char cpf[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //função de deletar o arquivo cpf com a string designada acima
	
	FILE *file; //abrir o arquivo
	file = fopen(cpf,"r"); //ler o arquivo cpf
	
	if(file == NULL) //se não há nenhum arquivo com esse nome...
	{
		printf("O usuário não se encontra no sistema!.\n"); //exiba esse texto ao usuário
		system("pause"); //o sistema encerra a função deletar
	}
	
}

int main() //menu principal
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do mundo
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Essa opção não está disponível!\n");
			system("pause");	
			break;
			
		} //fim da seleção
	
	}
	
}
