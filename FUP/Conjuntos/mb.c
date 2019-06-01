#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>
#include "colors.h"

#define VALIDO   1
#define INVALIDO 0



int main(){
    foreground(WHITE);//Chamada da biblioteca Colors, para deixar o texto com a fonte branca
    int contido_a =100,contido_b=100,tamCompleA=0,tamCompleB=0;
    int tamA=1,tamB=1,status,dife=0,repete=0,saida=1;
    int tam, inter,qtd=0,count=0;
    int *a, *b, *c, *intersecao, *diferencaAB, *diferencaBA, *universo, *complementoA, *complementoB;
    int i=0,j=0,k=0,x,aux=0,aux1=0,n=0,ab=0,ba=0;
    int cod=11,maior=INT_MIN,menor=INT_MAX,encontrou=0;
    
    printf("Pressione Enter!\n");
    getchar();
    system("clear");
    srand(time(NULL));
    //Gerando conjunto A
        do{
        repete=VALIDO; 
        printf("Informe o tamanho do Conjunto A:\n");
        scanf("%d",&tamA);
        system("clear");
        if(tamA > 101 || tamA < 0){
            repete=INVALIDO;    
            foreground(RED);
            printf("Valor inválido!\n");
            foreground(WHITE);
        }
        else{    
            a = (int*)malloc(sizeof(int)*tamA);
                for (i = 0; i < tamA; ++i) {
                    do {
                        a[i] = (rand()%101)-50;
                        status = VALIDO;
                        for (j = 0; j < i; ++j)
                            if (a[i] == a[j])
                                status = INVALIDO;
                        } while (status == INVALIDO);
                }
        }    
                
        }while (repete==INVALIDO);
        //Bouble SOrt para ordenar o cunjunto A
        for(i = 0; i < tamA; i++)
            for(j = 0; j < tamA-1; j++)
                if(a[j]>a[j+1]){
                    aux=a[j];
                    a[j]=a[j+1];
                    a[j+1]=aux;
                }
        //Mostrando Conjunto A
        printf("Conjunto A{");
            for( i = 0; i < tamA; i++)
            {

            printf("%d ", a[i]);

            }
            printf("} \n");
            
        //Gerando o conjunto B
        do{
            foreground(WHITE);
            repete=VALIDO;
            foreground(WHITE);
            printf("\nInforme o tamanho do conjunto B:\n");
            scanf("%d",&tamB);
            if(tamB > 101 || tamB < 0){
                repete=INVALIDO;
                foreground(RED);
                printf("Valor inválido!\n");
                foreground(WHITE);
            }    
            else{
       
                b = (int*)malloc(sizeof(int)*tamB);

                for (i = 0; i < tamB; ++i) {

                    do {
                        if (status==INVALIDO){
                            foreground(RED);
                            printf("Valor inválido! Digite outro número.\n");
                            foreground(WHITE);
                        }
                        printf("Elemento %d ",i+1);
                        scanf("%d",&b[i]);
                        if ((b[i]>-51) && (b[i]<51) ){    
                            status = VALIDO;
                            for (j = 0; j < i; ++j)
                                if (b[i] == b[j])
                                    status = INVALIDO;
                        }
                        else{
                            status = INVALIDO;
                        }
                    } while (status == INVALIDO);
                }
            }                
        }while(repete==INVALIDO);

        //Boubble Sort para ordenar o conjunto B
        for(i = 0; i < tamB; i++)
            for(j = 0; j < tamB-1; j++)
                if(b[j]>b[j+1]){
                    aux=b[j];
                    b[j]=b[j+1];
                    b[j+1]=aux;
                }
        
        
        system("clear");
    //------------------------------------------------------Mostrando os Conjuntos---------------------------------------------------------------------------------------------
        foreground(WHITE);
        printf("Conjunto A{");
        for( i = 0; i < tamA; i++)
            printf("%d ", a[i]);
        printf("}\n");

        printf("Conjunto B{");
        for( i = 0; i < tamB; i++)
            printf("%d ", b[i]);
        printf("}\n");
    
        //Aqui inicia a Condição de parada onde o sistema executará até que o usuário digite o código 0
        do{
        printf("\n\n");
        
        
        //Apresentando menu
        //--------------------------   
        printf("\033[34m%c", 35);
        for(i=0;i<64;i++)
            printf("\033[34m%c",61);
        printf("\033[34m%c\n",35); 
        //--------------------------
        printf("#");
        foreground(WHITE);
        printf("\t\t\t\tMENU\t\t\t\t\033[34m #\n");
        style(RESETALL);
        //---------------------------
        printf("\033[34m%c", 35);
        for(i=0;i<64;i++)
            printf("\033[34m%c",61);
        printf("\033[34m%c\n",35); 
        //--------------------------
        printf("\033[34m#\033[37m 1-Verificar pertinência de um elemento                         \033[34m#\n");
        printf("\033[34m#\033[37m 2-Exibir os elementos de maior e menor valor de A e B          \033[34m#\n");
        printf("\033[34m#\033[37m 3-Verificar igualdade dos conjuntos                            \033[34m#\n");
        printf("\033[34m#\033[37m 4-Verificar se A é subconjunto de B ou se B é subconjunto de A \033[34m#\n");
        printf("\033[34m#\033[37m 5-gerar um conjunto união de A de B                            \033[34m#\n");
        printf("\033[34m#\033[37m 6-Gerar conjunto de interseção de A e de B                     \033[34m#\n");
        printf("\033[34m#\033[37m 7-Gerar os conjuntos de Diferença de A-B e B-A                 \033[34m#\n");
        printf("\033[34m#\033[37m 8-Gerar os conjuntos de Complemento de A e Complemento de B    \033[34m#\n");
        printf("\033[34m#\033[37m 0-Sair                                                         \033[34m#\n");
        //----------------------------------
        printf("\033[34m%c", 35);
        for(i=0;i<64;i++)
            printf("\033[34m%c",61);
        printf("\033[34m%c\n",35);
        printf("# \033[37m99-Gerar novos conjuntos                                       \033[34m#\n");
        //----------------------------------
        printf("\033[34m%c", 35);
        for(i=0;i<64;i++)
            printf("\033[34m%c",61);
        printf("\033[34m%c\n",35);
        //----------------------------------
        printf("\033[34m%c", 35);
        for(i=0;i<64;i++)
            printf("\033[34m%c",61);
        printf("\033[34m%c\n",35);
        //-----------------------------------
        printf("Opção_");
        style(BLINKSLOW);
        printf(">");
        style(RESETALL);
        //-----------------------------------
        scanf("%d",&cod);
        system("clear");
        //verificão de código válido
        if((cod<0)&&(cod>8))
            printf("Digite um código válido!");
        //Apresentando Conjunto
        foreground(WHITE);
        printf("Conjunto A{");
        for( i = 0; i < tamA; i++)
            printf("  %d  ", a[i]);
        printf("} \n");
        printf("Conjunto B{");
        for( i = 0; i < tamB; i++)
            printf("  %d  ", b[i]);
        printf("}\n");
        printf("\n");
        //Iniciando opções do menu com Switch Case
        foreground(WHITE);
        switch (cod){
            //Primeiro caso, Verificando a pertinência de uma Elemento
            case 1:{
                    
                    if(tamA>0 && tamB>0){
                        printf("\nDigite o elemento para verificar a pertinencia em  A e B: ");
                        scanf("%d",&x);
                        if((x<51)&&(x>-51)){
                            aux=0;
                            for ( i = 0; i < tamA; i++)
                                if(a[i]==x)
                                    aux=aux+1;
                            if(aux==1)
                                printf("Elemento pertence ao conjunto A!\n");
                            if(aux==0)
                                printf("Elemento não pertence ao conjunto A!\n");
                            aux=0;
                            for ( i = 0; i < tamB; i++)
                                if(b[i]==x)
                                    aux=aux+1;
                            if(aux==1)
                                printf("Elemento pertence ao conjunto B!\n");
                            if(aux==0)
                                printf("Elemento não pertence ao conjunto B!\n"); 

                            printf("\n");
                        }
                        else
                            printf("\033[33mNúmero inválido!\n");    
                    }
                    else
                        printf("Os conjuntos são vazios!\n");
                    break;
                }
            //Buscando o Maior e o menor valor dos conjuntos, caso o mesmo não seja vazio    
            case 2:{
                    if (tamA==0)
                        printf("Conjunto A é um conjunto vazio!\n");
                    else{    
                    
                        for ( i = 0; i < tamA; i++){
                            if (a[i]>maior)
                                maior=a[i];
                            if (a[i]<menor)
                                menor=a[i];
                        }
                        printf("\nElemento de maior valor em A é: %d",maior );
                        printf("\nElemento de menor valor em A é: %d",menor );
                    }
                    if (tamB==0)
                        printf("\nConjunto B é um conjunto vazio!\n");
                    else{    
                    
                    maior=INT_MIN;
                    menor=INT_MAX;
                    printf("\n");
                    for(i = 0;i < tamB; i++){
                        if(b[i]>maior)
                            maior=b[i];
                        if(b[i]<menor)
                            menor=b[i];    
                    }
                    printf("\nElemento de maior valor em B é: %d",maior);
                    printf("\nElemento de menor valor em B é: %d",menor);
                    printf("\n");
                    }
                    break;
                }
            //Verificando se existe a igualdade de conjuntos    
            case 3:{
                    if(tamA!=tamB)
                        printf("Os conjuntos são disjuntos!\n");
                    else{
                        for(i=0; i<tamA; i++)
                            for(j=0; j<tamB; j++)
                                if(a[i]==b[j])
                                    qtd=qtd+1;
                        if (qtd==tamA)
                            printf("Os conjuntos iguais!\n");
                        else
                            printf("Os conjuntos são diSjuntos!\n");
                    }
                    printf("\n");    
                    break;    
                            
                }
            //Verificando Se A é subconjunto de B ou se B é subconjunto de A
            case 4:{
                    if(tamA==tamB){
                        aux=0;
                        for (i = 0; i < tamA; i++)
                            for ( j = 0; j < tamB; j++)
                                if (a[i]==b[j])            
                                    aux=aux+1;
                        if (aux==tamA)
                            printf("Conjuntos iguais!\n");
                        if (aux!=tamA)
                            printf("A e B não são subconjuntos!\n");
                            
                    }
                    aux=0;
                    if (tamA>tamB){
                        aux=0;
                        for (i = 0; i < tamA; i++)
                            for ( j = 0; j < tamB; j++)
                                if (a[i]==b[j])            
                                    aux=aux+1;
                        if (aux==tamB)
                            printf("B  é subconjunto de A!\n");
                        if (aux!=tamB)
                            printf("B não é um subconjunto de A!");                
                    }
                    
                    if (tamB>tamA){
                        aux=0;
                        for (i = 0; i < tamB; i++)
                            for ( j = 0; j < tamA; j++)
                                if (b[i]==a[j])            
                                    aux=aux+1;
                        if (aux==tamA)
                            printf("A é subconjunto de B!\n");
                        if (aux!=tamA)
                            printf("A não é um subconjunto de B!");    
                    }
                    
                    break;
                }
                //Criando o conjunto união, Aqui por ter sido a parte mais complicada do trabalho vou detar melhor
                case 5:{
                    k=0;
                    tam=tamA+tamB;
                    c = (int*)malloc(sizeof(int)*tam);
                    //Aqui estou unindo os dois vetores através de operador ternário
                    for ( i = 0; i < tam; i++){
                        c[i] = i < tamA ? a[i] : b[i-tamA];
                    }
                    //Boubble Sort para organizar o vetor
                    for(i = 0; i < tam; i++)
                        for(j = 0; j < tam-1; j++)
                            if(c[j]>c[j+1]){
                                aux=c[j];
                                c[j]=c[j+1];
                                c[j+1]=aux;
                            }
                    //Excluindo os números repetidos caso existam    
                    for( i = 0; i < tam; i++ )
                        for( j = i + 1; j < tam; ){
                            if( c[j] == c[i] ){
                                for( k = j; k < tam; k++ )
                                    c[k] = c[k + 1];
                                tam--;
                            }
                            else
                                j++;
                        }
                    //mostrando conjunto união
                    printf("Conjunto AUB{");
                    for( i = 0; i < tam; i++ )
                        printf("%d ", c[i] );
                    printf("}\n");
                    
                    break;
                }
                //Fazendo a interseção dos conjuntos
                case 6:{
                    if(tamA>0 && tamB>0){
                        intersecao = (int*)malloc(sizeof(int)*(tamA+tamB));
                        for(i=0; i<tamA; i++)
                            for(j=0; j<tamB; j++)
                                if(a[i]==b[j]){
                                    intersecao[n] = a[i]; 
                                    n=n+1;
                                }
                        if (n==0)
                            printf("Os conjuntos são disjuntos!\n");
                        else{
                            aux1=0;
                            printf("Conjunto interseção de A e B{");
                            for(i=0; i<n; i++)
                                for(i=0; i<n; i++)
                                    if(intersecao[j]>intersecao[j+1]){
                                        aux1 = intersecao[j];
                                        intersecao[j] = intersecao[j+1];
                                        intersecao[j+1] = aux1;
                                    }
                            aux=0;    
                            for(i = 0; i < n; i++)
                                for(j = 0; j < n-1; j++)
                                    if(intersecao[j]>intersecao[j+1]){
                                        aux=intersecao[j];
                                        intersecao[j]=intersecao[j+1];
                                        intersecao[j+1]=aux;
                                    }        
                            for(i=0;i<n;i++)
                                printf("%d ", intersecao[i]);
                            printf("}\n");    
                        }
                    }
                    else{
                        printf("Conjuntos vazios!\n");
                    }    
                    break;
                //Fazendo a diferença de A-B e B-A
                case 7:{
                    diferencaAB = (int*)malloc(sizeof(int)*(tamA));
                    aux=0;
                    ab=0;
                    for(i=0; i<tamA; i++){
                        for(j=0; j<tamB; j++)
                            if(a[i]!=b[j])
                                aux++;
                        if(aux==tamB){
                            diferencaAB[ab]=a[i];
                            ab++;
                        }

                        aux = 0;
                    }  
                    //Mostrando conjunto A-B            
                    printf("\nConjunto A-B{");
                    for(i=0; i<ab; i++)
                        printf(" %d ",diferencaAB[i]);    
                    printf("}\n\n");
                    ba=0;
                    aux=0;
                    //--------------------------------------------
                    diferencaBA = (int*)malloc(sizeof(int)*(tamB));
                    for(i=0; i<tamB; i++){
                        for(j=0; j<tamA; j++)
                            if(b[i]!=a[j])
                                aux++;
                        if(aux==tamA){
                            diferencaBA[ba]=b[i];
                            ba++;
                        }

                        aux = 0;
                    }
                    //Mostrando conjunto B-A              
                    printf("\nConjunto B-A{");
                    for(i=0; i<ba; i++)
                        printf(" %d ",diferencaBA[i]);    
                    printf("}\n\n");
                    break;
                }
                //Gerando conjunto universo e fazendo Complemento de A e B em relação ao Universo
                case 8:{
                    universo = (int*)malloc(sizeof(int)*101);
                    complementoA = (int*)malloc(sizeof(int)*101);
                    complementoB = (int*)malloc(sizeof(int)*101);
                    count=-50;
                    for (i=0;i<101;i++){
                        universo[i]=count;
                        count++;
                    }
                    for(i=0; i<101; i++){
                        for(j=0; j<tamA; j++)
                            if(universo[i]!=a[j])
                                aux++;
                        if(aux==tamA){
                            complementoA[tamCompleA] = universo[i];
                            tamCompleA++;
                        }
                        aux = 0;
                    }  
                    printf("Complemento de A{"); 
                    for(i=0;i<tamCompleA;i++)
                        printf(" %d ",complementoA[i]);
                    printf("}\n\n");
                    for(i=0; i<101; i++){
                        for(j=0; j<tamB; j++)
                            if(universo[i]!=b[j])
                                aux++;
                        if(aux==tamB){
                            complementoB[tamCompleB] = universo[i];
                            tamCompleB++;
                        }
                        aux = 0;
                    }  
                    printf("Complemento de B{"); 
                    for(i=0;i<tamCompleB;i++)
                        printf(" %d ",complementoB[i]);
                    printf("}\n");        
                    break;
                }
                //Opção extra para q não precise fechar e iniciar o programa novamente para mais testes caso necessário
                case 99:{
                    main();
                }
                case 0:{
                    system("clear");
                    foreground(RED);
                    printf("Código criado por MT(Matheus Alves)!\n");
                    return 0;
                }
            }    
        }
    }while(cod!=0);   
    

}