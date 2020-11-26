#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DESC 0.10
#define DESCCART 0.15
#include <time.h>


///Digitar somente o que esta nas instrucoes, o programa nao esta calibrado para receber comandos diferentes do que se pede.


//Estruturas
typedef struct
{

    char receitav[2][10];

} ReceitaCliente;

typedef struct
{
    int j;
    float loop;
} Auxiliar;

//funcoes
int EstoqueAtt(int quant)
{
    quant = quant - 1;
    return quant;
}

float DescontoGenerico(float preco)
{
    preco = preco - preco*0.20;
    return preco;
}



int main()
{
    ///Declaracao de variaveis
    float preco[]= {36,16,20,10,5},precoo[]= {36,16,20,10,5};
    int i,quant[]= {4,0,6,3,6},id,y,x,vali=0,pag=-1,gene=0,dig,z=0,est=0;

    char remedios[5][100],generico[2][10],receita[5][10],v[1][3],nao[1][3],cartao[1][10],cartaof[1][10],paga[30];

    Auxiliar Aux;
    ReceitaCliente RC;

    strcpy(nao[0],"nao");


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


    while(Aux.loop != -1)
    {
        do
        {
            do
            {



                ///Tabela que informa os produtos da farmacia a quantidade em estoque de cada produto, o preco original de cada produto sem nenhum desconto e se o produto
                ///precisa de receita
                printf(" \t\t\t\t             Farmacia CEFET\n \n\n");

                printf("  Remedios em estoque \t\tID \t    Quantidade  \t Preco(unidade) \t Receita \n\n");

                for(i=0; i<5; i++)
                {
                    printf(" |%s  \t\t\t%d         \t%d      \t\t     R$ %2.f \t\t   %s \n",remedios[i],i,quant[i],preco[i],receita[i]);
                }

                ///Escaneando o id do produto para ser usado em outras etapas, tambem verifica se o id digita esta entre os ids existentes no programa

                do
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
                while (vali!= 1);

                ///Verifica se ha o medicamento em questao em estoque
                if(quant[id]==0)
                {
                    printf("\n\n!!! Nao ha este medicamento em estoque. !!!\n\n");

                }
                else
                {
                    est=-2;
                }
            }
            while (est>=0);

            ///Verifica se o cliente quer um produto generico. Todo produto generico ganha um desconto de 20% sobre o preco original

            printf("Deseja comprar um remedio generico? (sim ou nao)\n");
            scanf("%s",generico[0]);

            for(Aux.j=0; Aux.j<1; Aux.j++)
            {
                if(strncmp(generico[Aux.j],"nao",3))
                {
                    preco[id]= DescontoGenerico(preco[id]);

                }
            }


            ///Verifica automaticamente se o remedio em questao precisa de receita e caso precise o cliente deve informar se tem a receita ou nao.

            if(strcmp(receita[id],nao[0]))
            {


                printf("O cliente apresentou a receita? (sim ou nao)\n");
                scanf("%s",RC.receitav[0]);

                for(x=0; x<1; x++)
                {
                    if(strncmp(RC.receitav[x],"sim",3))
                    {
                        printf("\n\n!!! Sua compra foi cancelada  (apresente a receita para comprar este medicamento)!!! \n\n");

                    }

                    else
                    {
                        z=-2;
                    }

                }
            }
            if(id>=3)
            {
                z=-2;
            }

        }
        while(z>=0);


        ///Conferindo se o cliente tem o cartao da farmacia e caso nao o tenha perguntando se deseja faze-lo

        printf("Voce tem o cartao da farmacia?(sim ou nao)\n");
        scanf("%s",cartao[0]);

        if(strncmp(cartao[0],"sim",3))
        {
            printf("Voce deseja fazer o cartao da farmacia?(sim ou nao)\n");
            scanf("%s",cartaof[0]);

            if(strncmp(cartaof[0],"nao",3))
            {
                printf("--FAZENDO CARTAO--\n\n");
            }
        }


        ///Escolhendo a forma de pagamento desejada



        /// Descontos dado ao preco do produto de acordo com a forma de pagamento escolhido

            printf("\t\t\t        Metodos de pagamento \n");
            printf("\n \tDinheiro \tDebito \t\tCredito \tCartao da Farmacia");
            printf("\n\t   0 \t\t   1 \t\t   2 \t\t        3");
            printf("\n\nDigite o numero correspondente ao metodo de pagamento desejado: ");
            scanf("%d",&pag);

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
                printf("\n\n\n!!! Digite um metodo de pagamento valido !!!\n\n\n");
            }

        while(pag<0 || pag>3)
        {
            printf("\t\t\t        Metodos de pagamento \n");
            printf("\n \tDinheiro \tDebito \t\tCredito \tCartao da Farmacia");
            printf("\n\t   0 \t\t   1 \t\t   2 \t\t        3");
            printf("\n\nDigite o numero correspondente ao metodo de pagamento desejado: ");
            scanf("%d",&pag);


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
                printf("\n\n\n!!! Digite um metodo de pagamento valido !!!\n\n\n");
            }



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

        printf("\n\n\n !!!!! Digite -1 para encerrar a compra ou qualquer outro numero para continuar comprando. !!!!! \n --->");
        scanf("%d",&dig);

        if(dig==-1)
        {
            Aux.loop = -1;
        }
        z=0;
        est=0;
        quant[id]= EstoqueAtt(quant[id]);
        preco[0]= 36;
        preco[1]= 16;
        preco[2]= 20;
        preco[3]= 10;
        preco[4]= 5;



        printf("\n\n");
    }
    return 0;
}



