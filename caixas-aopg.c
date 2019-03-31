#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int h; // height eh a pos no array de memo

} Caixa;

void ftirou(Caixa pilha[], int caixa1_data[], int p, int n);

int main(void)
{
    int n = 3, p = 2, caixa1_data[2]; // data guarda em 0 a pilha, e em 1 a altura da Caixa1
    do  // executa uma vez obrigatoriamente
    {
        scanf("%d %d", &n, &p); // recupera a qtd de caixas(n) e a qtd de pilhas(p)
        // printf("n=%d p=%d\n", n, p);
        if (p < 1 || n < p || n > 1000) exit -1;
        if (p == 0 || n == 0) { //End Program Signal P = N = 0
            return 0;
        } else {
            Caixa pilhas[p];
            int /*m, lado, */tirou = 0; 
            for (int pilha_atu = 0; pilha_atu < p; pilha_atu++) {
                int id, h = pilha_atu+1, size_pilha;
                scanf("%d", &size_pilha);
                if (size_pilha < 1 || size_pilha == 0) exit(-1);
                pilhas[pilha_atu].h = size_pilha;
               // printf("%d ", size_pilha);
                for (int tam_atual = 0; tam_atual < size_pilha; tam_atual++){
                    scanf("%d", &id);
                    if (id == 0 || id > 1000) exit -1;
                   // printf("%d ", id);
                    if (id == 1) {
                        caixa1_data[0] = pilha_atu; 
                        caixa1_data[1] = tam_atual;
                    } // como so quer a caixa 1 n precisa saber onde os outros id tao;
                }
               // printf("------\n");
            }
           // printf("caixa1.h=%d \n", caixa1_data[1]);
           // printf("Tirou \n");
            ftirou(pilhas, caixa1_data, p, n);
            // if (pilhas[caixa1_data[0]-1].h < pilhas[caixa1_data[0]+1].h ) {
            //     tirou = pilhas[caixa1_data[0]].h - (caixa1_data[1] + 1); // quantas tem q remover de cima de caixa1
            //     tirou += pilhas[caixa1_data[0]-1].h - caixa1_data[1]; //quntas tem que tira do lado esuqerdo
            //     // printf("%d\n", tirou);
            // } else {
            //     tirou = pilhas[caixa1_data[0]].h - (caixa1_data[1] + 1); // quantas tem q remover de cima de caixa1
            //     tirou += pilhas[caixa1_data[0]+1].h - caixa1_data[1]; //quntas tem que tira do lado direiro
            //     // printf("%d\n", tirou);
            // }
            
            
        }
    }
    while(p != n && p != 0);
   // printf("Condition End Met\n");
}

void ftirou(Caixa pilha[], int caixa1_data[], int p, int n)
{
   // printf("new caixa1_data[0]=%d  caixa1_data[1]=%d p=%d\n", caixa1_data[0], caixa1_data[1], p);
   // printf("height at pilha of caixa1 is %d\n", pilha[caixa1_data[0]].h);
    int pos = caixa1_data[0], caixa1_h = caixa1_data[1] ;
   // printf("pilha[pos].h=%d caixa1_h=%d | is pilha[pos].h == caixa1_h? %d\n", pilha[caixa1_data[0]].h, caixa1_h, (pilha[pos].h == caixa1_h));
    if (pilha[pos].h == caixa1_h + 1) {
       // printf("caixa esta no topo da pilha\n");
       // printf("pilha[caixa1_data[0]-1].h=%d caixa1_h=%d dif=%d\n", pilha[pos-1].h, caixa1_h, pilha[pos-1].h - caixa1_h);
       // printf("pilha[caixa1_data[0]+1].h=%d caixa1_h=%d dif=%d\n", pilha[pos+1].h, caixa1_h, pilha[pos+1].h - caixa1_h);
        if ((pilha[caixa1_data[0]-1].h - caixa1_h == 0) || (pilha[pos+1].h - caixa1_h == 0)) {
           // printf("ninguem a esquerda\n");
           // printf("ninguem a direita\n");
            printf("0\n");
        }
    }
    else
    {

        int tirou_esq = pilha[caixa1_data[0]].h - (caixa1_data[1]+1), tirou_dir;
        tirou_dir = tirou_esq;
        // printf("init tiro_dir=%d tiro_esq=%d\n", tirou_dir, tirou_esq);
        // printf("left side #################\n");
        for (int i = caixa1_data[0]-1; i >= 0; i--) {
            // printf("--------------entrou------------\n");
            // printf("left side #################\n");
            // printf("it=%d i=%d \n", (caixa1_data[0]-1)-i, i);
            // printf("\t \tpilha[i].h - caixa1_data[1] =%d\n", pilha[i].h - caixa1_data[1]);
            // printf("\t \t i == caixa1_data[0]-1 =%d\n", (i == caixa1_data[0]-1));
            if (i == caixa1_data[0]-1)
                tirou_esq += pilha[i].h - caixa1_data[1];
            // printf("* tiro_dir=%d tiro_esq=%d\n", tirou_dir, tirou_esq);
            if (/*pilha[i-1].h != pilha[0].h && */pilha[i-1].h < n) { 
                // printf("-----------pilha[i-1].h=%d caixa1_data[1]=%d\n", pilha[i-1].h, caixa1_data[1]);
                // printf("-----------pilha[i-1].h - caixa1_data[1] =%d\n", pilha[i-1].h - caixa1_data[1]);
                tirou_esq += pilha[i-1].h - caixa1_data[1];
            }
            // printf("tiro_dir=%d tiro_esq=%d\n", tirou_dir, tirou_esq);
    
        }
        // printf("left side end taken %d boxes\n", tirou_esq);
        for (int i = caixa1_data[0]+1; i < p; i++) {
            // printf("Right side #################\n");
            // printf("it=%d i=%d \n", i - caixa1_data[0], i);
            // printf("\t \tpilha[i].h - caixa1_data[1] =%d\n", pilha[i].h - caixa1_data[1]);
            // printf("\t \t i == caixa1_data[0]-1 =%d\n", (i == caixa1_data[0]-1));
            if (i == caixa1_data[0]+1)
                tirou_dir += pilha[i].h - caixa1_data[1];
            // printf("init tiro_dir=%d tiro_esq=%d\n", tirou_dir, tirou_esq);
            if (/*i < p && */pilha[i+1].h < n)
                tirou_dir += pilha[i+1].h - caixa1_data[1];
            // printf("taken %d from right side\n", tirou_dir);
    
        } 
       // printf("right side end taken %d boxes\n", tirou_dir);
        (tirou_esq < tirou_dir) ? printf ("%d\n", tirou_esq) :   printf("%d\n",tirou_dir);
    }

}
