#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DESC 0.10
#define DESCCART 0.15
#include <time.h>


///Digitar somente o que esta nas instrucoes, o programa nao esta calibrado para receber comandos diferentes do que se pede.

int main()
{

    ///Declaracao de variaveis
    float preco[]= {36,16,20,10,5},precos,precoo[]= {36,16,20,10,5};
    int i,quant[]= {4,0,6,3,6},id,j,y,x,vali=0,pag,gene=0;

    char remedios[5][100],generico[2][10],receita[5][10],receita_cliente[2][10],receitav[2][10],v[1][3],nao[1][3],cartao[1][10],cartaof[1][10],paga[30];



    strcpy(nao[0],"nao");


    strcpy(receita_cliente[0],"nao");
    strcpy(receita_cliente[1],"sim");


    strcpy(receita[0],"sim");
    strcpy(receita[1],"sim");
    strcpy(receita[2],"sim");
    strcpy(receita[3],"nao");
    strcpy(receita[4],"nao");



    strcpy(generico[0],"nao");
    strcpy(generico[1],"sim");



    strcpy(remedios[0],"Ritalina");
    strcpy(remedios[1],"Trembolona");
    strcpy(remedios[2],"Rivotril");
    strcpy(remedios[3],"Cebion");
    strcpy(remedios[4],"Dramin");


    ///Funcao para colocar data e hora no programa
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );


    ///Tabela que informa os produtos da farmacia a quantidade em estoque de cada produto, o preco original de cada produto sem nenhum desconto e se o produto
    ///precisa de receita
    printf(" \t\t\t\t             Farmacia CEFET\n \n\n");

    printf("  Remedios em estoque \t\tID \t    Quantidade  \t Preco(unidade) \t Receita \n\n");

    for(i=0; i<5; i++)
    {
        printf(" |%s  \t\t\t%d         \t%d      \t\t     R$ %2.f \t\t   %s \n",remedios[i],i,quant[i],preco[i],receita[i]);
    }

    ///Escaneando o id do produto para ser usado em outras etapas, tambem verifica se o id digita esta entre os ids existentes no programa

    while(vali!= 1)
    {
        printf("\nDigite o ID do remedio que deseja comprar: \n");
        scanf("%d",&id);

        if (id>=0 && id<=4)
        {
            vali=1;
        }
        else
        {

            printf("Digite um id valido\n\n");

        }
    }

    ///Verifica se ha o medicamento em questao em estoque
    if(quant[id]==0)
    {
        printf("\nNao ha este medicamento em estoque.\n");
        return 0;
    }


    ///Verifica se o cliente quer um produto generico. Todo produto generico ganha um desconto de 20% sobre o preco original

    printf("Deseja comprar um remedio generico? (sim ou nao)\n");
    scanf("%s",generico[0]);

    for(j=0; j<1; j++)
    {
        if(strncmp(generico[j],"nao",3))
        {
            preco[id]=preco[id]-preco[id]*0.20;

        }
    }



    ///Verifica automaticamente se o remedio em questao precisa de receita e caso precise o cliente deve informar se tem a receita ou nao.


    if(strcmp(receita[id],nao[0]))
    {


        printf("O cliente apresentou a receita? (sim ou nao)\n");
        scanf("%s",receitav[0]);

        for(x=0; x<1; x++)
        {
            if(strncmp(receitav[x],"sim",3))
            {
                printf("Sua compra foi cancelada  (apresente a receita para comprar este medicamento)\n");
                return 0;

            }
        }

    }

    ///Conferindo se o cliente tem o cartao da farmacia e caso nao o tenha perguntando se deseja faze-lo

    printf("Voce tem o cartao da farmacia?(sim ou nao)\n");
    scanf("%s",cartao[0]);

    if(strncmp(cartao[0],"sim",3))
    {
        printf("Voce deseja fazer o cartao da farnacia?(sim ou nao)\n");
        scanf("%s",cartaof[0]);

        if(strncmp(cartaof[0],"nao",3))
        {
            printf("--FAZENDO CARTAO--\n\n");
        }
    }


    ///Escolhendo a forma de pagamento desejada

    printf("\t\t\t        Metodos de pagamento \n");
    printf("\n \tDinheiro \tDebito \t\tCredito \tCartao da Farmacia");
    printf("\n\t   0 \t\t   1 \t\t   2 \t\t        3");
    printf("\n\nDigite o numero correspondente ao metodo de pagamento desejado: ");
    scanf("%d",&pag);

    /// Descontos dado ao preco do produto de acordo com a forma de pagamento escolhido

    if(pag==0)
    {
        preco[id]=preco[id] - (preco[id]*DESC);
    }
    else if(pag==1)
    {
        preco[id]=preco[id] - (preco[id]*DESC);
    }
    else if(pag==2)
    {
        preco[id]=preco[id];
    }
    else if(pag==3)
    {
        preco[id]=preco[id] - (preco[id]*DESCCART);
    }
    else
    {
        printf("\nDigite um numero valido.\n");
        return 0;
    }

    ///Imprimindo a nota fiscal da compra do produto


    printf("\n\n\t\tFarmacia CEFET \n R. Jose Peres, 558 - Centro, Leopoldina \n MG, 36700-000 \n CNPJ:05.714.190/0001-22 /n IE:66994360-NO");
    printf("\n----------------------------------------------\n");
    printf ( " %s", asctime (timeinfo) );
    printf("\n----------------------------------------------\n");
    printf("\t\t Cupom fiscal\n");
    printf("Produto comprado: %s\n",remedios[id]);
    printf("Produto generico: %s\n",generico[0]);

    ///Imprimindo o modo de pagamento

    if(pag==0)
    {
        printf("O metodo de pagamento utilizado foi: Dinheiro\n");
    }
    else if(pag==1)
    {
        printf("O metodo de pagamento utilizado foi: Debito\n");
    }
    else if(pag==2)
    {
        printf("O metodo de pagamento utilizado foi: Credito\n");
    }
    else if(pag==3)
    {
        printf("O metodo de pagamento utilizado foi: Cartao da Farmacia\n");
    }

    printf("Preco sem desconto: R$ %.2f\n",precoo[id]);
    printf("Preco com desconto: R$ %.2f\n",preco[id]);

    return 0;
}
