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
   c[7] = '\0';
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
   char sCadastro[50][25], sCPF_nDot[15], sCPF_Dot2[15], sCPF_Dot[15], sConta_nDot[7],sConta_Dot[10], cChoice ;
   int iClient = 0;
   int imenu, iSubMenu = 0, iSubRela;
   int i, j;//Controladoras
   //INICIA A ULTIMA POSIÇÃO DA STRING COM 9
   for(i = 0; i < 50 ; i++ ){
      
   }

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
                        do{
                           //CPF
                           gera_cpf_valido(sCPF_nDot);
                           insere_pontuacao_cpf(sCPF_nDot, sCPF_Dot);

                           //Copia o CPF para outra variavel
                           strcpy(sCPF_Dot2, sCPF_Dot);
                           //printf("CPF: ");
                           //puts(sCPF_Dot2);
                           //CONTA
                           geraContaCorrente(sConta_nDot);
                           insere_pontuacao_conta(sConta_nDot, sConta_Dot);
                           printf("sCPF_Dot => %s\nsCPF_Dot2 => %s\nsCPF_nDot => %s\n",sCPF_Dot, sCPF_Dot2, sCPF_nDot);
                           printf("Conta: \n");
                           puts(sConta_Dot);
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
                        strcpy(sCadastro[iClient], sCPF_Dot2);
                        puts(sCadastro[iClient]);
                        strcat(sCadastro[iClient], sConta_Dot);
                        printf("%13s", sCadastro[iClient]);
                        iClient += 1;
                     }break;

                     case 2:{//Mostrar Clientes
                        printf("\t======== Clientes =========\n");
                        for(i = 0; i <= iClient; i++){
                           printf("Cliente %d", i);
                           printf("CPF: \n");
                           for(j=0; j<15; j++){
                              printf("%c", sCadastro[iClient][j]);
                           }
                           printf("Conta: \n");
                           for(j = 15; j<25; j++){
                              printf("%c", sCadastro[iClient][j]);
                           }
                           printf("\n===================================\n");
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