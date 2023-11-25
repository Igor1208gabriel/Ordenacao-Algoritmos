#include <iostream>   //para input e output
#include <chrono>     //para contagem de tempo
#include <algorithm>  //para min_element()
using namespace std;
  
//   int acharminimo(int comeco, int a[], unsigned int t){
//   int menor = a[comeco];
//   int indice = comeco;
//   for(unsigned int i = comeco+1; i < t; i++){
//     if(a[i] < menor) { menor = a[i]; indice = i; }
//   }
//   return indice;
// } achei mais prático fazer pelas funções já existentes, mas decidi não apagar a que eu fiz, já que são equivalentes.

//void bbsort(int a[], int t){}


void selecao(int a[], unsigned int t){  //Tempo: O(n²) / espaço: O(1)
  for(unsigned int i = 0; i < t; i++){
    //acha o menor
    int indmenor = distance(a, min_element(a+i, a+t)); //segundo cppreference, O(n)
    
    //troca 
    int temp = a[i];
    a[i] = a[indmenor];
    a[indmenor] = temp;
  }
}

void insercao(int a[], int t){  //o(n²)

  for(int i = 0; i < t; i++){   //O(n)
    int j = i;
    while(j > 0 && a[j-1] > a[j]){ //O(n)
      int temp = a[j];
      a[j] = a[j-1];
      a[j-1] = temp;
      j--;
    }
  }
}


void merge_sort(int a[], int i1, int j1, int i2, int j2){
  int *temp = new int[((j1 - i1) + (j2 - i2) + 2)];
  int i = i1, j = i2, k = 0;
  
  while(i <= j1 && j <= j2){
    if (a[i] < a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }
  while (i <= j1)
    temp[k++] = a[i++];
  while (j <= j2)
    temp[k++] = a[j++];
  for (i = i1, j = 0;i <= j2;i++, j++) 
    a[i] = temp[j];
  delete[] temp;
}

void merge(int a[], int primeiro, int ultimo){
  int meio = (ultimo+primeiro)/2;
  if (primeiro < ultimo) {
    meio = (primeiro + ultimo) / 2;
    merge(a, primeiro, meio);
    merge(a, meio + 1, ultimo);
    merge_sort(a, primeiro, meio, meio + 1, ultimo);
  }
}
bool ordenado(int a[], int t){
    for(int i = 0; i < t-1; i++){
        if(a[i] > a[i+1])return false;
    }
    return true;
}




int main(){
    int n;
    
    //cout << "Quantidade de itens na estrutura:";
    cin >> n;
    int lista[n];

    //cout << "\nInsira os dados:";
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        lista[i] = temp;
    }

    //cout << "\nSelecione o metodo de ordenacao:\ns-Selecao\ni-Insercao\nm-Merge\n";
    char escolha = 's'; //cin >> escolha;

    //cout << endl;
    //if(ordenado(lista, n)) cout << "Ordenado";
    //else cout << "Nao ordenado";
    //cout << endl; 

    auto inicio = chrono::high_resolution_clock::now();

    switch(escolha) {
        case 's':
            selecao(lista, n);
            break;
        case 'i':
            insercao(lista, n);
            break;
        case 'm':
            merge(lista, 0, n-1);
            break;
    }


    auto fim = chrono::high_resolution_clock::now();
    auto duracao = fim - inicio;
    cerr << duracao.count() << "\n";

    //for(auto x : lista) cout << x << " ";
    //cout << endl;

} 