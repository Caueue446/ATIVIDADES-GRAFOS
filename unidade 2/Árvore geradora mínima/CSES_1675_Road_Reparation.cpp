#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000


int pai[MAX], tamanho[MAX], posto[MAX];

int getPai(int a) {
    if(pai[a] == a) return a;
    pai[a] = getPai(pai[a]);
    return pai[a];
}

void uniao(int a, int b) {
    a = getPai(a);
    b = getPai(b);
    if(a != b) {
        if(posto[a] > posto[b]) {
            pai[b] = a;
            tamanho[a] += tamanho[b];
        } else {
            pai[a] = b;
            tamanho[b] += tamanho[a];
        } 
        if(posto[a] == posto[b])
            posto[b]++;
    }
}

void inicializacao(int max){
    for(int i = 0; i <= max; i++) {
        pai[i] = i;
        tamanho[i] = 1;
        posto[i] = 0;
    }
}

typedef struct{
    int o, d;
    long long custo; 
    bool inTree;
} Aresta;

int n;
bool conexo;
Aresta arestas[MAX];

int cmp(const void * a1, const void * a2){
    Aresta * e1 = (Aresta *)a1, * e2 = (Aresta *)a2;
    if (e1->custo < e2->custo) return -1;
    if (e1->custo > e2->custo) return 1;
    return 0;
}

long long Kruskal(int numArestas){
    int ind = 0;
    long long custo = 0;
    conexo = true;
    int arestas_na_arvore = 0;

    qsort(arestas, numArestas, sizeof(arestas[0]), cmp);
    inicializacao(n);

    while(arestas_na_arvore < n - 1 && ind < numArestas){
        while(ind < numArestas && getPai(arestas[ind].o) == getPai(arestas[ind].d)) 
            ind++;
            
        if(ind == numArestas){
            break;
        }
        
        arestas[ind].inTree = true;
        custo += arestas[ind].custo;
        uniao(arestas[ind].o, arestas[ind].d);       
        
        arestas_na_arvore++;
        ind++;
    }

    if(arestas_na_arvore < n - 1){
        conexo = false;
    }

    return custo;   
}

int main() {
    int e;
    
    while(scanf("%d %d", &n, &e) != EOF){     
        for(int i = 0; i < e; i++){
            scanf("%d %d %lld", &arestas[i].o, &arestas[i].d, &arestas[i].custo);
            arestas[i].inTree = false;
        }
        
        long long custo_minimo = Kruskal(e);
        
        if(conexo) {
            printf("%lld\n", custo_minimo);
        } else {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}