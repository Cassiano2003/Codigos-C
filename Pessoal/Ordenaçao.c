//Bibliotecas usadas.
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//troca os numeros dos vetores.
void troca(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void imprecoes(int controle){
    switch (controle){
    case 1:
        printf("-------------------------------------------------------\n");
        printf("-Vetor de ordenacao Aleatorio: ");
        break;
    case 2:
        printf("-------------------------------------------------------\n");
        printf("-Vetor de ordenacao Ordenado: ");
        break;
    case 3:
        printf("-------------------------------------------------------\n");
        printf("-Vetor de ordenacao Decressente: ");
        break;
    case 4:
        printf("-------------------------------------------------------\n");
        printf("-Vetor de ordenacao Quase Ordenado: ");
        break;
    default:
        printf("-------------------------------------------------------\n");
        printf("-Vetror de ordenacao nao implemtado.\n");
        printf("-Fim do modo manual.\n");
        printf("-------------------------------------------------------\n");
        break;
    }
}
//Gerador de vetores, os aleatorios, ordenados, decressentes e quase ordenados.
void gerador(int *vet1,int *vet2,int *vet3,int *vet4,int *vet5, int n,int b) {
    int i,j=0,num1=0,num2=0;
    switch (b) {
    case 1:
        //aleatorio.
        for (i = 0; i < n; i++) {
            vet1[i] = rand() % n;
            vet2[i] = vet1[i];
            vet3[i] = vet1[i];
            vet4[i] = vet1[i];
            vet5[i] = vet1[i];
        }
        break;
    case 2:
        //ordenado.
        for (i = 0; i < n; i++) {
            vet1[i] = i;
            vet2[i] = i;
            vet3[i] = i;
            vet4[i] = i;
            vet5[i] = i;
        }
        break;
    case 3:
        //decresente.
        for (i = n; i >= 0; i--) {
            vet1[j] = i;
            vet2[j] = i;
            vet3[j] = i;
            vet4[j] = i;
            vet5[j] = i;
            j++;
        }
        j=0;
        break;
    case 4:
        //quase oredenado.
        for (i = 0; i < n; i++) {
            vet1[i] = i;
        }
        for(i=0; i<(n/8); i++) {
            num1 = rand() % n;
            num2 = rand() % n;
            troca(&vet1[num1],&vet1[num2]);
        }
        for (i = 0; i < n; i++) {
            vet2[i] = vet1[i];
            vet3[i] = vet1[i];
            vet4[i] = vet1[i];
            vet5[i] = vet1[i];
        }
        break;
    }
}

//selectionSort.
void selectionSort(int *vet, int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (vet[j] < vet[min_idx])
                min_idx = j;
        if(min_idx != i)
            troca(&vet[min_idx], &vet[i]);
    }
}
//insertionSort.
void insertionSort(int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//quickSort.
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low,high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//mergeSort.
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int * arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
//BubbleSort
void BubbleSort(int *vetor, int tamanho){
	int aux, i, j;
	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
            }
        }
    }
}
//Funçao que faz todos os calculos.
void calcula(int n,int escolha,int quan_teste) {
    // dodas a variaves utilizadas.
    clock_t start, end;
    int *vet1,*vet2,*vet3,*vet4,*vet5;
    double * vet_tem1,*vet_tem2,*vet_tem3,*vet_tem4,*vet_tem5;
    double time1=0,time2=0,time3=0,time4=0,time5=0,DP1=0,DP2=0,DP3=0,DP4=0,DP5=0;
    for(int i=0; i<quan_teste; i++) {
        //criando vetores de alocaçao dinamica.
        vet1=(int*)malloc(n*sizeof(int));
        vet2=(int*)malloc(n*sizeof(int));
        vet3=(int*)malloc(n*sizeof(int));
        vet4=(int*)malloc(n*sizeof(int));
        vet5=(int*)malloc(n*sizeof(int));
        time1=time2=time3=time4=time5=0;
        //uma funçao feita para gerar os numeros dos vetores.
        gerador(vet1,vet2,vet3,vet4,vet5,n,escolha);
        vet_tem1=(double*)malloc(quan_teste*sizeof(double));
        vet_tem2=(double*)malloc(quan_teste*sizeof(double));
        vet_tem3=(double*)malloc(quan_teste*sizeof(double));
        vet_tem4=(double*)malloc(quan_teste*sizeof(double));
        vet_tem5=(double*)malloc(quan_teste*sizeof(double));
        //a partir daqui começa a fazer as ordenaçoes.
        //Funçoes de O(n^2):
        start = clock();
        selectionSort(vet1,n);
        end = clock();
        //para calcular a desvio padao estou guardando os numeros nos vetores vet_time1 a 4,para cada funçao;
        vet_tem1[i] = ((double) (end - start));
        //para calcular a media estou guardando os numeros nas variaves time1 a 4, para cada funçao;
        time1+=((double) (end - start));

        start = clock();
        insertionSort(vet2,n);
        end = clock();
        vet_tem2[i] = ((double) (end - start));
        time2+=((double) (end - start));

        start = clock();
        BubbleSort(vet5,n);
        end = clock();
        vet_tem5[i] = ((double) (end - start));
        time5+=((double) (end - start));
        //Funoes de O(n*log n):
        start = clock();
        quickSort(vet3,0,n-1);
        end = clock();
        vet_tem3[i] = ((double) (end - start));
        time3+=((double) (end - start));

        start = clock();
        mergeSort(vet4,0,n-1);
        end = clock();
        vet_tem4[i] = ((double) (end - start));
        time4+=((double) (end - start));
        //aqui irei dezalocar todos os vetores, alocados para nao sobre carregar o sistema operacinal.
        free(vet1);
        free(vet2);
        free(vet3);
        free(vet4);
        free(vet5);
    }
    /*faz o somatorio do desvio padao.
    for(int i=0; i<quan_teste; i++) {
        DP1 += pow((vet_tem1[i]-(time1/quan_teste)),2);
        DP2 += pow((vet_tem2[i]-(time1/quan_teste)),2);
        DP3 += pow((vet_tem3[i]-(time1/quan_teste)),2);
        DP4 += pow((vet_tem4[i]-(time1/quan_teste)),2);
        DP5 += pow((vet_tem5[i]-(time1/quan_teste)),2);
    }
    //aqui ja faz a impreçao e o resto dos calculos do desvio padao.
    printf("-Desvio padrao: \n");
    printf("-------------------------------------------------------\n");
    printf("-select desvio padrao: %.2f\n",sqrt(DP1/quan_teste));
    printf("-insert desvio padrao: %.2f\n",sqrt(DP2/quan_teste));
    printf("-bubble desvio padrao: %.2f\n",sqrt(DP5/quan_teste));
    printf("-quickS desvio padrao: %.2f\n",sqrt(DP3/quan_teste));
    printf("-mergeS desvio padrao: %.2f\n",sqrt(DP4/quan_teste));
    printf("-------------------------------------------------------\n");
    free(vet_tem1);
    free(vet_tem2);
    free(vet_tem3);
    free(vet_tem4);
    free(vet_tem5);    
    //vai fazer a impreçao da media de tempo das funçoes de ordenaçao.*/
    printf("-Media dos testes: \n");
    printf("-------------------------------------------------------\n");
    printf("-select media: %.2f\n",time1/quan_teste);
    printf("-insert media: %.2f\n",time2/quan_teste);
    printf("-bubble media: %.2f\n",time5/quan_teste);
    printf("-quickS media: %.2f\n",time3/quan_teste);
    printf("-mergeS media: %.2f\n",time4/quan_teste);
    printf("-------------------------------------------------------\n");
    //printf("\n");
}

//MAIN
//se quiser pode implementar o bobbleSort.
int main() {
    while(1){
    char es;
    setbuf(stdin,NULL);
    printf("M(Manual), A(Altomatico)\nModo Altomatico ou manual: ");
    setbuf(stdin,NULL);
    scanf("%c",&es);
    if(es=='M'||es=='m'){
        int n,quan_teste,escolha;
        printf("-------------------------------------------------------\n");
        while (1) {
            //Interfaçe simples para o uzuario.
            printf("-Aleatorio = 1\n");
            printf("-Ordenado = 2\n");
            printf("-Decresente = 3\n");
            printf("-Quase Ordenado = 4\n");
            printf("-------------------------------------------------------\n");
            //Faa para o usuario qual teste ele gostaria de fazer.
            printf("-Qual sera o teste de ordenacao: ");
            scanf("%d",&escolha);
            if(escolha==1||escolha==2||escolha==3||escolha==4) {
                //qual seria o tamanho do vetor
                printf("-Qual o tamho do vetor: ");
                scanf("%d",&n);
                //a quantidade de testes.
                printf("-Quantidade de testes: ");
                scanf("%d",&quan_teste);
                //chama a funçao calcula para fazer todos os calculos e printar todas as respostas.
                imprecoes(escolha);
                printf("%d\n",n);
                calcula(n,escolha,quan_teste);
            } else {
                imprecoes(escolha);
                break;
            }
        }
    }else if(es=='A'||es=='a'){
            //Teste altomatico:
            int num=100;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=4;j++){
                    imprecoes(j);
                    printf("%d\n",num);
                    calcula(num,j,10);
                }
                num=num*10;
            }
        }else{
            printf("FIM!!!\n");
            break;
        }
    }
    return 0;
}