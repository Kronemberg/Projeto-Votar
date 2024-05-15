#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[50];
	int num;
	char part[5];
	int votos;

} Candidato;

typedef struct usuario
{
	long long cpf;
	int pref;
	int vere;
} Usuario;

Candidato *cand;

Usuario user;

void candidatos()
{
	int i;
	for (i = 0; i < 15; i++)
	{
		cand[i].votos = 0;
	}

	strcpy(cand[0].nome, "Bernardo Rossi");
	cand[0].num = 22;
	strcpy(cand[0].part, "PL");

	strcpy(cand[1].nome, "Rubens Jose Franca Bomtempo");
	cand[1].num = 40;
	strcpy(cand[1].part, "PSB");

	strcpy(cand[2].nome, "Jamil Miguel Sabra Neto");
	cand[2].num = 20;
	strcpy(cand[2].part, "PSC");

	strcpy(cand[3].nome, "Marcos Jose Marques Novaes");
	cand[3].num = 12;
	strcpy(cand[3].part, "PDT");

	strcpy(cand[4].nome, "Livia De Lima Miranda");
	cand[4].num = 65;
	strcpy(cand[4].part, "PCDOB");

	strcpy(cand[5].nome, "Josiane Alves Da Costa");
	cand[5].num = 20110;
	strcpy(cand[5].part, "PSC");

	strcpy(cand[6].nome, "Francisco Thomaz De Oliveira JR");
	cand[6].num = 65333;
	strcpy(cand[6].part, "PSDOB");

	strcpy(cand[7].nome, "Joao Da Vitoria Costa");
	cand[7].num = 40963;
	strcpy(cand[7].part, "PSB");

	strcpy(cand[8].nome, "Vinicius Vargas Freire");
	cand[8].num = 12012;
	strcpy(cand[8].part, "PDT");

	strcpy(cand[9].nome, "Domingos Galante Neto");
	cand[9].num = 20013;
	strcpy(cand[9].part, "PSC");

	strcpy(cand[10].nome, "Adriana Alcaires Da Conceicao Queiroz");
	cand[10].num = 22111;
	strcpy(cand[10].part, "PL");

	strcpy(cand[11].nome, "Sonia Silva Paiva");
	cand[11].num = 40080;
	strcpy(cand[11].part, "PSB");

	strcpy(cand[12].nome, "Rafael Dos Santos");
	cand[12].num = 65000;
	strcpy(cand[12].part, "PCDOB");

	strcpy(cand[13].nome, "Fabio Felipe Dos Santos Rodrigues");
	cand[13].num = 12345;
	strcpy(cand[13].part, "PDT");

	strcpy(cand[14].nome, "Edmar De Oliveira Dias");
	cand[14].num = 22422;
	strcpy(cand[14].part, "PL");

	return;
}

void gravar()
{

	FILE *pref;
	pref = fopen("prefeitos.txt", "w");
	if (pref == NULL)
	{
		printf("Erro ao criar o arquivo");
	}
	fprintf(pref, "22 PL %d Bernado Chim Rossi\n", cand[0].votos);
	fprintf(pref, "40 PSB %d Rubens Jose Franca Bomtempo\n", cand[1].votos);
	fprintf(pref, "20 PSC %d Jamil Miguel Sabra Neto\n", cand[2].votos);
	fprintf(pref, "12 PDT %d Marcos Jose Marques Novaes\n", cand[3].votos);
	fprintf(pref, "65 PCDOB %d Livia De Lima Miranda\n", cand[4].votos);
	fclose(pref);

	printf("\n");

	FILE *vere;
	vere = fopen("vereadores.txt", "w");
	if (vere == NULL)
	{
		printf("Erro ao criar o arquivo");
	}
	fprintf(vere, "20110 PSC %d Josiane Alves Da Costa\n", cand[5].votos);
	fprintf(vere, "65333 PSDOB %d Francisco Thomaz De Oliveira JR\n", cand[6].votos);
	fprintf(vere, "40963 PSB %d Joao Da Vitoria Costa\n", cand[7].votos);
	fprintf(vere, "12012 PDT %d Vinicius Vargas Freire\n", cand[8].votos);
	fprintf(vere, "20013 PSC %d Domingos Galante Neto\n", cand[9].votos);
	fprintf(vere, "22111 PL %d Adriana Alcaires Da Conceicao Queiroz\n", cand[10].votos);
	fprintf(vere, "40080 PSB %d Sonia Silva Paiva\n", cand[11].votos);
	fprintf(vere, "65000 PCDOB %d Rafael Dos Santos\n", cand[12].votos);
	fprintf(vere, "12345 PDT %d Fabio Felipe Dos Santos Rodrigues\n", cand[13].votos);
	fprintf(vere, "22422 PL %d Edmar De Oliveira Dias\n", cand[14].votos);

	fclose(vere);
}

void contarvoto(int *p)
{
	*p += 1;
}

int cadastro()
{

	printf("Insira o CPF: ");
	scanf("%lld", &user.cpf);
	if (user.cpf > 99999999999 || user.cpf < 999999999)
	{
		printf("CPF INVALIDO, TENTE NOVAMENTE\n");
		system("pause");
		system("cls");
		return 1;
	}
	long long cpf;
	FILE *cpfd;
	cpfd = fopen("cpf.txt", "r");

	while (fscanf(cpfd, "%lld", &cpf) != EOF)
	{
		if (user.cpf == cpf)
		{
			printf("CPF JA UTILIZADO\n");
			system("pause");
			system("cls");
			return 1;
		}
	}

	printf("=== VOTO PARA PREFEITO ===\n");
	printf("Numero candidato a Prefeito: ");
	scanf("%d", &user.pref);
	
	switch (user.pref)
	{
	case 22:
		contarvoto(&cand[0].votos);
		break;
	case 40:
		contarvoto(&cand[1].votos);
		break;
	case 20:
		contarvoto(&cand[2].votos);
		break;
	case 12:
		contarvoto(&cand[3].votos);
		break;
	case 65:
		contarvoto(&cand[4].votos);
		break;
	default:
		printf("Numero Invalido\n");
		system("pause");
		return 1;
	}

	printf("=== VOTO PARA VEREADOR ===\n");
	printf("Numero candidato a Vereador: ");
	scanf("%d", &user.vere);
	
	switch (user.vere)
	{
	case 20110:
		contarvoto(&cand[5].votos);
		break;
	case 65333:
		contarvoto(&cand[6].votos);
		break;
	case 40963:
		contarvoto(&cand[7].votos);
		break;
	case 12012:
		contarvoto(&cand[8].votos);
		break;
	case 20013:
		contarvoto(&cand[9].votos);
		break;
	case 22111:
		contarvoto(&cand[10].votos);
		break;
	case 40080:
		contarvoto(&cand[11].votos);
		break;
	case 65000:
		contarvoto(&cand[12].votos);
		break;
	case 12345:
		contarvoto(&cand[13].votos);
		break;
	case 22422:
		contarvoto(&cand[14].votos);
		break;

	default:
		printf("Numero Invalido\n");
		system("pause");
		return 1;
	}

	printf("VOTACAO ENCERRADA\n");

	cpfd = fopen("cpf.txt", "a");
	fprintf(cpfd, "%lld\n", user.cpf);
	fclose(cpfd);
	
	gravar();

	system("pause");
	system("cls");

	return 1;
}


void relatorio(){
	int i;
	int total = cand[0].votos + cand[1].votos + cand[2].votos + cand[3].votos + cand[4].votos;
	int totalv = cand[5].votos + cand[6].votos + cand[7].votos + cand[8].votos + cand[9].votos + cand[10].votos + cand[11].votos + cand[12].votos + cand[13].votos + cand[14].votos;
	FILE *rela;
	rela = fopen("relatorio1.txt", "w");
	fprintf(rela,"Prefeitos\n");
	for(i=0;i<5;i++){
		fprintf(rela,"%s - %d  (%.1f%%)\n",cand[i].nome,cand[i].votos,(float)(cand[i].votos * 100) / total);
	}
   	
	fprintf(rela,"\n Vereadores\n");
	
	for(i=5;i<15;i++){
		fprintf(rela,"%s - %d  (%.1f%%)\n",cand[i].nome,cand[i].votos,(float)(cand[i].votos * 100) / totalv);
	}
	fclose(rela);
	
	rela = fopen("relatorio2.txt", "w");
		printf("%f",(float)(cand[0].votos+cand[10].votos+cand[14].votos * 100) / (totalv+total));
		fprintf(rela,"PL - %d (%.1f%%)\n",(cand[0].votos+cand[10].votos+cand[14].votos),(float)((cand[0].votos+cand[10].votos+cand[14].votos) * 100) / (totalv+total));
		fprintf(rela,"PSB - %d (%.1f%%)\n",(cand[1].votos+cand[7].votos+cand[11].votos),(float)((cand[1].votos+cand[7].votos+cand[11].votos) * 100) / (totalv+total));
		fprintf(rela,"PSC - %d (%.1f%%)\n",(cand[2].votos+cand[5].votos+cand[9].votos),(float)((cand[2].votos+cand[5].votos+cand[9].votos) * 100) / (totalv+total));
		fprintf(rela,"PDT - %d (%.1f%%)\n",(cand[3].votos+cand[8].votos+cand[13].votos),(float)((cand[3].votos+cand[8].votos+cand[13].votos) * 100) / (totalv+total));
		fprintf(rela,"PSDOB- %d (%.1f%%)\n",(cand[4].votos+cand[6].votos+cand[12].votos),(float)((cand[4].votos+cand[6].votos+cand[12].votos) * 100) / (totalv+total));
	fclose(rela);
	system("cls");

}

void mostrarvotos(){
	int i;
	printf("Prefeitos\n");
	for(i=0;i<5;i++){
		printf("Nome: %s , Numero: %d , Votos: %d\n",cand[i].nome,cand[i].num,cand[i].votos);
	}
	printf("\nVereadores\n");
	for(i=5;i<15;i++){
		printf("Nome: %s , Numero: %d , Votos: %d\n",cand[i].nome,cand[i].num,cand[i].votos);
	}
	system("pause");
	system("cls");
}

int leitura()
{
	int votos, num;
	char nome[50], part[5];
	int i = 0;
	FILE *rpref;
	rpref = fopen("prefeitos.txt", "r");
	if (rpref == NULL)
	{
		return 1;
	}

	while (fscanf(rpref, "%d %s %d %[^\n]s", &num, &part, &votos, &nome) != EOF)
	{
		cand[i].votos = votos;
		i++;
	}
	fclose(rpref);
	
	FILE *rvere;
	rvere = fopen("vereadores.txt", "r");
	if (rpref == NULL)
	{
		return 1;
	}

	while (fscanf(rvere, "%d %s %d %[^\n]s", &num, &part, &votos, &nome) != EOF)
	{
		cand[i].votos = votos;
		i++;
	}
	fclose(rvere);
}

int main()
{
	cand = (Candidato *)malloc(15 * sizeof(Candidato));

	candidatos();
	leitura();
	printf("\n");
	int menu;
	while (1)
	{

     system("cls");
		
	printf("===========================================================\n");
	printf("                        PREFEITOS\n");
	printf("===========================================================\n");
	printf("Bernado Chim Rossi , Numero: 22 , Partido: PL\n");
	printf("Rubens Jose Franca Bomtempo , Numero: 40 , Partido: PSB\n");
	printf("Jamil Miguel Sabra Neto , Numero: 20 , Partido: PSC\n");
	printf("Marcos Jose Marques Novaes , Numero: 12 , Partido: PDT\n");
	printf("Livia De Lima Miranda , Numero: 65 , Partido: PCDOB\n");
	printf("===========================================================\n");
	
	printf("\n");
	
	printf("===========================================================\n");
	printf("                        VEREADORES\n");
	printf("===========================================================\n");
	printf("Josiane Alves Da Costa , Numero: 20110 , Partido: PSC\n"); 
	printf("Francisco Thomaz De Oliveira JR , Numero: 65333 , Partido: PSDOB\n"); 
	printf("Joao Da Vitoria Costa , Numero: 40963 , Partido: PSB\n"); 
	printf("Vinicius Vargas Freire , Numero: 12012 , Partido: PDT\n"); 
	printf("Domingos Galante Neto , Numero: 20013 , Partido: PSC\n"); 
	printf("Adriana Alcaires Da Conceicao Queiroz , Numero: 22111 , Partido: PL\n"); 
	printf("Sonia Silva Paiva , Numero: 40080 , Partido: PSB\n"); 
	printf("Rafael Dos Santos , Numero: 65000 , Partido: PCDOB\n"); 
	printf("Fabio Felipe Dos Santos Rodrigues , Numero: 12345 , Partido: PDT\n"); 
	printf("Edmar De Oliveira Dias , Numero: 22422 , Partido: PL\n"); 
	printf("===========================================================");
	
		printf("\n");
		
		printf("======================\n");
		printf("1 = Inserir Voto\n");
		printf("2 = Mostrar Votos\n");
		printf("3 = Gerar Relatorios\n");
		printf("0 = Sair\n");
		printf("======================\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			system("cls");
			cadastro();
			break;
		case 2:
			system("cls");
			mostrarvotos();
			break;
		case 3:
			relatorio();
			break;
		case 0:
			return 0;
			break;
		default:
			system("cls");
			printf("Numero Invalido\n");
			system("pause");
			
		}
	}
	return 0;
}
