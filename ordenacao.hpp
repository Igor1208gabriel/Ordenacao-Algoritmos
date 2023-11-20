#ifndef __ORDENACAO__
#define __ORDENACAO__

/*
  Função que retorna se um vetor 'a' de 't' elementos 
  está ordenado não decrescentemente

  Retorno: false Se 'a' não estiver ordenado
           true caso contrário
*/
bool ordenado(int a[], unsigned int t){
    for(unsigned int i = 0; i < t-1; i++){
      if (a[i] > a[i+1]) return false;
    }
    return true;
}

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por seleção.
  A ordenação é feita diretamente no vetor 'a'
*/

int acharminimo(int a[], unsigned int t){
  int menor = a[0];
  int indice = 0;
  for(unsigned int i = 1; i < t; i++){
    if(a[i] < menor) { menor = a[i]; indice = i; }
  }
  return indice;
}
void selecao(int a[], unsigned int t){
  int b[t];
  for(unsigned int i = 0; i < t; i++){
    int indmenor = acharminimo(a, t);
    for(unsigned int j = indmenor; j < t; j++){
      a[j+1] = a[j];
    }
    b[i] = a[indmenor];
  }
}

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por inserção.
  A ordenação é feita diretamente no vetor 'a'
*/
void insercao(int a[], unsigned int t){
    int b[t];
  for(unsigned int i = 0; i < t; i++){
    int indmenor = acharminimo(a, t);
    for(unsigned int j = indmenor; j < t; j++){
      a[j+1] = a[j];
    }
    b[i] = a[indmenor];
  }
}

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação merge-sort.
  A ordenação é feita diretamente no vetor 'a'
*/
void merge_sort(int a[], unsigned int t){
    int b[t];
  for(unsigned int i = 0; i < t; i++){
    int indmenor = acharminimo(a, t);
    for(unsigned int j = indmenor; j < t; j++){
      a[j+1] = a[j];
    }
    b[i] = a[indmenor];
  }
}
#endif