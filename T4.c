#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void flush_in() 
{ 
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

//objetivo:escolhe dentre as letras do alfabeto ('a'..'z') uma letra aleatoriamente
//parametros: nenhum
//retorno:a letra do alfabeto
char geraAlfabeto() {
   int i;
   char letras[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   i=rand()%26;
   return(letras[i]-32);
}

//objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
//parametros: nenhum
//retorno:o numero
char geraNumero() {
   int i;
   char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};
   i=rand()%9; 
   return(numeros[i]);
}

//objetivo:gera aleatoriamente um numero de conta corrente no formato 999.999-X
//parametros: c onde armazera a conta gerada
//retorno:nenhum
void geraContaCorrente(char c[]) {
   int i;
   for (i = 0; i < 6 ; i++){
      c[i] = geraNumero();
   }
   c[6] = geraAlfabeto();
   c[0] = '\0';
}

//objetivo:verifica se um cpf no formato 999.999.999-99 e valido
//parametros: cpf a ser verificado
//retorno: 1 se cpf e valido ou 0 se cpf nao e valido
int verifica_cpf_valido(char cpf[]) {
   int valido=1;

   //implemente aqui

   return(valido);
}

//objetivo:insere pontuacoes '.' e '- ' em uma conta
//parametros: conta_origem o conta recebido no format 999.999-x
//            conta_destino o conta com as pontuacoes inseridas no formato 999.999-x
void insere_pontuacao_conta(char conta_origem[], char conta_destino[]){
   int i;
   for (i=0;i<3; i++){
      conta_destino[i] = conta_origem[i];
   }
   conta_destino[3] = '.';
   for (i=4;i<7; i++){
      conta_destino[i] = conta_origem[i-1];
   }
   conta_destino[7] = '-';
   conta_destino[8] = conta_origem[6];
   conta_destino[9] = '\0';
}



//objetivo:insere pontuacoes '.' e '- ' em um cpf
//parametros: cpf_origem o cpf recebido no format 99999999999
//            cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[]) {
   char hyphen = "-", dot = "."; 
   //MODO DE ATRIBUIÇÃO
   int i ;
   for (i=0;i<3;i++){
      cpf_destino[i] = cpf_origem[i];  
   }
   cpf_destino[3] = '.';
   for (i=4;i<7;i++){
      cpf_destino[i] = cpf_origem[i-1];  
   }
   cpf_destino[7] = '.';
   for (i=8;i<11;i++){
      cpf_destino[i] = cpf_origem[i-2];  
   }
   cpf_destino[11] = '-';
   for (i=12;i<14;i++){
      cpf_destino[i] = cpf_origem[i-3];  
   }
   cpf_destino[14] = '\0';
   //printf("DotCPF: %s\n", cpf_destino);
  
}
//Objetivo: mostra por extenso o valor de 
//Parametro: de entrada que sera o valor total do ou valor de saque
void Saquextenso(int saque)
{
    int CM;//CENTENA DE MILHAR
    int DM;//DEZENA DE MILHAR
    int UNM;//UNIDADE DE MILHAR
    int CEN;//CENTENA
    int DEZ;//DEZENA
    int UN;//UNIDADE

    CM = saque/100000 ; // centena de milhar recebe valor do saque dividido por 100000
    DM = (saque - CM*100000)/10000; // dezena de milhar recebe valor do saque menos centena de milhar vezes 100000 dividido por 10000
    UNM = (saque - CM*100000 - DM*10000)/1000; // unidade de milhar recebe saque menos centena de milhar vezes 100000 menos dezena de milhar vezes 10000 dividido por 1000
    CEN = (saque - CM*100000 - DM*10000 - UNM*1000)/100; // centena recebe saque menos centena de milhar vezes 100000 menos dezena de milhar vezes 10000 menos unidade de milhar vezes 1000 dividido por 100
    DEZ = (saque - CM*100000 - DM*10000 - UNM*1000 - CEN*100)/10; // dezena recebe daque menos centena de milha vezes 100000 menos dezena de milhar vezes 10000 menos unidade de milhar vezes 1000 menos centena vezes 100 dividido por 10
    UN = saque - CM*100000 - DM*10000 - UNM*1000 - CEN*100 - DEZ*10; // unidade recebe saque menos centena de milhar vezes 100000 menos dezena de milhar vezes 10000 menos unidade de milhar vezes 1000 menos centena vezes 100 menos dezena vezes 10
    if ((CM == 1) && (DM == 0) && (UNM == 0) && (CEN == 0) && (DEZ == 0) && (UN == 0)) // condicao para somente 100.000
    {
        printf("CEM MIL");
    }
    // condicao para imprimir cem mil caso a centena, dezena ou unidade possuir valores diferentes de 0
    if ((CM == 1) && (DM == 0) && (UNM == 0) && ((CEN != 0) || (DEZ != 0) || (UN != 0)))
    {
        printf ("CEM MIL");
    }
    // imprime "cento e" caso a unidade de milhar ou dezena de milhar seja diferente de 0
    if ((CM == 1) && ((DM != 0) || (UNM != 0)))
        printf("CENTO E ");
        // imprimir valores da dezena de milhar
        if (DM == 9)
            printf("NOVENTA");
        else{
            if (DM == 8)
                printf ("OITENTA");
            else{
                if (DM == 7)
                    printf ("SETENTA");
                else{
                    if (DM == 6)
                        printf ("SESSENTA");
                    else{
                        if (DM == 5)
                            printf ("CINQUENTA");
                        else{
                            if (DM == 4)
                                printf ("QUARENTA");
                            else{
                                if (DM == 3)
                                    printf ("TRINTA");
                                else{
                                    if (DM == 2)
                                        printf ("VINTE");
                                    else{
                                        if ((DM == 1) && (UNM ==0))
                                            printf ("DEZ");
                                        else{
                                            if (DM ==1)
                                                if (UNM == 9)
                                                    printf ("DEZENOVE");
                                                else{
                                                    if (UNM == 8)
                                                        printf ("DEZOITO");
                                                    else{
                                                        if (UNM == 7)
                                                            printf("DEZESSETE");
                                                        else{
                                                            if (UNM == 6)
                                                                printf ("DEZESSEIS");
                                                            else{
                                                                if (UNM == 5)
                                                                    printf ("QUINZE");
                                                                else{
                                                                    if (UNM == 4)
                                                                        printf ("QUATORZE");
                                                                    else{
                                                                        if (UNM == 3)
                                                                            printf ("TREZE");
                                                                        else{
                                                                            if (UNM == 2)
                                                                                printf ("DOZE");
                                                                            else{
                                                                                if (UNM ==1)
                                                                                    printf ("ONZE");

                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                // condicao para valores de com a dezena de milhar igual a 1, com valores particulares de treze, onze...
                                                if ((CM == 0) && (DM==1))
                                                    printf(" MIL");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    // imprime "mil" antes do valor da centena, dezena e unidade
    if ((CM != 0) && (DM != 0) && (UNM == 0))
        printf(" MIL");
    else{
        if ((CM==0) && (DM != 0) && (UNM == 0))
            printf(" MIL");
        else{
            if ((DM != 1) && (DM!=0) && (UNM != 0)) // imprime o "e" para separação de dezena e unidade, para ex: noventa E três
                printf(" E");
            }
        }
    // para aparecer vinte e três a dezena de milhar tem que ser diferente de 1,
    // se for 1 deveria sair valores como, treze, onze. casos particulares
    if (DM!=1)
    {
        if (UNM == 9)
            printf (" NOVE");
        if (UNM == 8)
            printf (" OITO");
        if (UNM == 7)
            printf(" SETE");
        if (UNM == 6)
            printf (" SEIS");
        if (UNM == 5)
            printf (" CINCO");
        if (UNM == 4)
            printf (" QUATRO");
        if (UNM == 3)
            printf (" TRES");
        if (UNM == 2)
            printf (" DOIS");
        if (UNM ==1)
            printf (" UM");
    }
    // imprime "mil" antes dos valores das centenas, dezenas e unidades
    if ((CM == 0 ) && (DM!=1) && (UNM != 0))
        printf(" MIL");
    if ((CM != 0) && (DM == 0) && (UNM != 0))
    {
        printf(" MIL");
    }
    // aparece o "e" para valores particulares como 1009, 2020, 2300.
    if ((CM==0) && (DM==0) && (UNM!=0) && ((CEN!=0) || (DEZ!=0) || (UN!=0)))
    {
        printf(" E");
    }
    // imprime "mil" antes dos valores das centenas, dezenas e unidades
    if ((CM != 0) && (DM != 0) && (UNM != 0))
    {
        printf(" MIL");
    }
    // imprime "e" para valores com final de dezena e unidade iguais a 0
    if ((CM != 0) && (DM != 0) && (UNM != 0) && (CEN != 0) && (DEZ == 0) && (UN==0))
    {
        printf(" E");
    }
    // imprime valores da centena
    if (CEN == 9)
        printf ("  NOVECENTOS");
    if (CEN == 8)
        printf (" OITOCENTOS");
    if (CEN == 7)
        printf (" SETECENTOS");
    if (CEN == 6)
        printf (" SEISCENTOS");
    if (CEN == 5)
        printf (" QUINHENTOS");
    if (CEN == 4)
        printf (" QUATROCENTOS");
    if (CEN == 3)
        printf (" TREZENTOS");
    if (CEN == 2)
        printf (" DUZENTOS");
    // caso particular para o valor 100
    if ((CEN == 1) && (DEZ==0) && (UN==0))
        printf (" CEM");
    // caso para centena igual a 1 e os demais valores diferentes de 0, pelo ou menos a dezena ou unidade
    if ((CEN == 1) && ((DEZ!=0) || (UN!=0)))
    {
        printf(" CENTO");
    }
    // condicao para imprimir o "e" em casos da centena de milhar e unidade de milhar forem 0,
    // aparece ex: nove mil trezentos "e" oito
    if ((UNM !=0) && (CEN != 0) && (DEZ!=0))
        printf(" E");
    else // caso para centenas
        if ((UNM == 0) && (CEN != 0) && (DEZ!=0))
            printf(" E");
    // imprime valores da dezena
    if (DEZ == 9)
        printf (" NOVENTA");
    if (DEZ == 8)
        printf(" OITENTA");
    if (DEZ == 7)
        printf (" SETENTA");
    if (DEZ == 6)
        printf (" SESSENTA");
    if (DEZ == 5)
        printf (" CINQUENTA");
    if (DEZ ==4)
        printf (" QUARENTA");
    if (DEZ == 3)
        printf (" TRINTA");
    if (DEZ == 2)
        printf (" VINTE");
    // caso particular para o numero 10
    if ((DEZ == 1) && (UN==0))
        printf (" DEZ");
    // casos para dezena igual a 1, aparecendo doze, treze...
    if ((DEZ == 1) && (UN!=0))
    {
        if (UN == 9)
            printf (" DEZENOVE");
        if (UN == 8)
            printf (" DEZOITO");
        if (UN == 7)
            printf (" DEZESSETE");
        if (UN == 6)
            printf (" DEZESSEIS");
        if (UN == 5)
            printf (" QUINZE");
        if (UN == 4)
            printf (" QUATORZE");
        if (UN == 3)
            printf (" TREZE");
        if (UN == 2)
            printf (" DOZE");
        if (UN == 1)
            printf (" ONZE");
    }
    // imprime "e" em valores do tipo cento "e" nove, cento "e" vinte
    if ((CEN!=0) && (DEZ!=1) && (UN != 0))
        printf(" E");
    else{
        if ((DEZ!=1) && (DEZ != 0) && (UN != 0))
            printf(" E");

        }
    // imprime os valores da unidade
    if (DEZ != 1)
    {
        if (UN == 9)
            printf (" NOVE");
        if (UN == 8)
            printf (" OITO");
        if (UN == 7)
            printf (" SETE");
        if (UN == 6)
            printf (" SEIS");
        if (UN == 5)
            printf (" CINCO");
        if (UN == 4)
            printf (" QUATRO");
        if (UN == 3)
            printf (" TRES");
        if (UN == 2)
            printf (" DOIS");
        if (UN == 1)
            printf (" UM");
        if (UN == 0)
            printf (" ZERO");    
    }
    printf(" ");

}
//objetivo:calcula o primeiro digito verificador de um cpf no formato 999999999
//parametros: cpf o cpf sem os digitos verificadores
//retorno: o calculo do primeiro digito verificador
int obtem_primeiro_digito_verificador(char cpf[]) {
   int digito, digitos[9];
   long int liCPF;
   liCPF = atol(cpf);
   digitos[8] = (liCPF%10);
   digitos[7] = (liCPF/10)%10;
   digitos[6] = (liCPF/100)%10;
   digitos[5] = (liCPF/1000)%10;
   digitos[4] = (liCPF/10000)%10;
   digitos[3] = (liCPF/100000)%10;
   digitos[2] = (liCPF/1000000)%10;
   digitos[1] = (liCPF/10000000)%10;
   digitos[0] = (liCPF/100000000)%10;
   digito = ((10*digitos[0]) + (9*digitos[1]) + (8*digitos[2]) + (7*digitos[3]) + (6*digitos[4]) + (5*digitos[5]) + (4*digitos[6]) + (3*digitos[7]) + (2*digitos[8])) % 11;
   if (digito<2)
      digito = 0;
   else
      digito = 11 - digito;
   return(digito);
}

//objetivo:calcula o segundo digito verificador de um cpf no formato 999999999
//parametros: cpf sem os digitos verificadores
//retorno: o calculo do segundo digito verificador
int obtem_segundo_digito_verificador(char cpf[]) {
   int digito, digitos[10];
   long long int lliCPF;
   lliCPF = atoll(cpf);
   digitos[9] = (lliCPF%10);
   digitos[8] = (lliCPF/10)%10;
   digitos[7] = (lliCPF/100)%10;
   digitos[6] = (lliCPF/1000)%10;
   digitos[5] = (lliCPF/10000)%10;
   digitos[4] = (lliCPF/100000)%10;
   digitos[3] = (lliCPF/1000000)%10;
   digitos[2] = (lliCPF/10000000)%10;
   digitos[1] = (lliCPF/100000000)%10;
   digitos[0] = (lliCPF/1000000000)%10;
   digito = ((11*digitos[0]) + (10*digitos[1]) + (9*digitos[2]) + (8*digitos[3]) + (7*digitos[4]) + (6*digitos[5]) + (5*digitos[6]) + (4*digitos[7]) + (3*digitos[8]) + (2*digitos[9])) % 11;
   if(digito < 2)
      digito = 0;
   else
      digito = 11 - digito;
   return(digito);
}

//objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
//parametros: cpf onde sera armazenado o cpf valido e o cliente  
//retorno: nenhum
void gera_cpf_valido(char cpf[]) {
   char sCPF_Dig1[2], sCPF_Dig2[2];// Armazena localmente o CPF para guarda-lo mais tarde no "Cadastro"
   int i;//Contador do for
   int iFirstDig, iSecondDig;// Primeiro e segundo digito verificadores

   //gera os 9 primeiros digitos do cpf
   for (i = 0; i < 9; i++){
      cpf[i] = geraNumero();
   }
   //Convertendo o cpf pra string
   cpf[9] = '\0' ;
   //puts(cpf);

   //primeiro digito verificador
   iFirstDig = obtem_primeiro_digito_verificador(cpf);
   //printf("1 Dig Verificador: %d\n", iFirstDig);
   
   sprintf(sCPF_Dig1, "%d", iFirstDig);
   strcat(cpf, sCPF_Dig1);
   //puts(cpf);

   //segundo digito verificador
   iSecondDig = obtem_segundo_digito_verificador(cpf);
   
   //Converte  o segundo digito pra string
   sprintf(sCPF_Dig2, "%d", iSecondDig);
   strcat(cpf, sCPF_Dig2);
   
}
//Objetivo: Mostrar as opções de todos os menus
//parametros: valor do menu a ser gerado
//retorno: nenhum
void gera_menu(int iMenu){
   switch(iMenu){
      case 0:{
         printf("\t========= MENU PRINCIPAL =========\n");
         printf(" 1 - Cliente\n 2 - Saque\n 3 - Relatorios\n 4 - Finalizar\n");
         printf("Insira a opcao desejada: ");
      }break;
      case 1:{
          printf("\t========= MENU CLIENTE ==========\n");
          printf(" 1 - Incluir\n 2 - Mostrar\n 3 - Alterar\n 4 - Excluir\n 5 - Voltar\n");
          printf("Insira a opcao desejada: ");      
      }break;
      case 3:{
          printf("\t======== MENU RELATORIOS =========\n");
          printf(" 1 - Valores sacados\n 2 - Valor do saldo existente \n 3 - Quantidades de cedulas existentes \n 4 - Voltar ao menu principal\n");
          printf("Insira a opcao desejada: ");
      }break;
      default:
      break;
   }
}

//Isso vai fazer o programa acontecer
void menu(){
   char sCadastroCPF[50][15], sCadastroConta[50][10], sCPF_nDot[12], sCPF_Dot2[15], sCPF_Dot[15], sConta_nDot[7],sConta_Dot[10], cChoice ;
   int iClient = 0;
   int imenu, iSubMenu = 0, iSubRela;
   int i, j;//Controladoras
   
   do{
      imenu = 0;
      gera_menu(imenu);
      //Refinamento de dados do Menu
      do{
         scanf("%d", &imenu);
         if(imenu < 1 || imenu > 4)
         {
            printf("Opcao Invalida...");
         }
      }while(imenu < 1 || imenu > 4);

      if ( imenu != 4 )
      {
         switch (imenu)
         {
            case 1://Menu Cliente
            {  
               system("cls");
               do{
                  gera_menu(imenu);
                  do
                  {
                     scanf("%d",&iSubMenu);
                     if (iSubMenu < 1 ||iSubMenu > 5){
                        printf("Opcao Invalida...\n");
                     }
                  }while ((iSubMenu < 1) || (iSubMenu > 5));
                  switch (iSubMenu)
                  {
                     case 1://Incluir cliente
                     {  
                        system("cls");                    
                        do{
                           //CPF
                           gera_cpf_valido(sCPF_nDot);
                           insere_pontuacao_cpf(sCPF_nDot, sCPF_Dot);

                           //Copia o CPF para outra variavel, pois estava tendo problema com sCPF_Dot (Estava zerando o valor dela)
                           strcpy(sCPF_Dot2, sCPF_Dot);
                           puts(sCPF_Dot);
                           //CONTA
                           //sConta_nDot[0] = '\0';
                           geraContaCorrente(sConta_nDot);
                           insere_pontuacao_conta(sConta_nDot, sConta_Dot);

                           printf("CPF: \n");
                           puts(sCPF_Dot2);
                           puts(sCPF_Dot);
                           printf("Conta: \n");
                           puts(sConta_nDot);
                           do{
                              printf("Confirma o CPF e a Conta[S/N]: ");
                              flush_in();
                              scanf("%c", &cChoice);
                              if (cChoice == 'n' || cChoice == 's')
                                 cChoice -= 32;
                              if (cChoice != 'N' && cChoice != 'S')
                                 printf("Opcao Invalida\n");
                           }while(cChoice != 'N' && cChoice != 'S');
                        }while(cChoice == 'N' );

                        //Guarda os dados dentro de sCadastro
                        strcpy(sCadastroCPF[iClient], sCPF_Dot2);
                        puts(sCadastroCPF[iClient]);
                        strcpy(sCadastroConta[iClient], sConta_Dot);
                        puts (sCadastroConta[iClient]);
                        iClient += 1;
                     }break;

                     case 2:{//Mostrar Clientes
                        system("cls");
                        printf("\t======== Clientes =========\n");
                        for(i = 0; i < iClient; i++){
                           printf("\tCliente %d\n", i+1);
                           printf("CPF: ");
                           puts(sCadastroCPF[i]);
                           printf("Conta: ");
                           puts(sCadastroConta[i]);
                           printf("\n===================================\n");
                           puts("CLIQUE EM QUALQUER TECLA PARA VOLTAR AO MENU DO CLIENTE...");
                           system("pause>nul");
                        }
                     }break;

                     default:{

                     }break;
                  }
               }while(iSubMenu != 5);
            }break;

            case 2://Saque
            {
               system("cls");
               gera_menu(imenu);
            }break;
            
            case 3://Relatorio
            {
               system("cls");
               gera_menu(imenu);
               do
               {
               scanf("%d",&iSubRela);
                  if ((iSubRela < 1) || (iSubRela > 4))
                     printf("Opcao Invalida...");
               }while ((iSubRela < 1) || (iSubRela > 4));
               switch (iSubRela)
               {
                  case 1://valores sacados 
                  {

                  }
                  break;
                  case 2://valor de saldo existente  
                  {

                  }
                  break;
                  case 3://quantidade de cedulas existentes 
                  {

                  }break;    
                  
                  default:
                   break;
               }    
            }break;                
            default:
               break;
         }  
      }
   }while(imenu != 4);
}

//Primeira Chamada
int main(){
    srand(time(NULL));
    menu();
    system("pause");
    return 0;
}