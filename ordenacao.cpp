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

//void merge(int a[], int t){}

bool ordenado(int a[], int t){
    for(int i = 0; i < t-1; i++){
        if(a[i] > a[i+1])return false;
    }
    return true;
}




int main(){
    int n;
    
    cout << "Quantidade de itens na estrutura:";
    cin >> n;
    int lista[n];

    cout << "\nInsira os dados:";
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        lista[i] = temp;
    }

    cout << "\nSelecione o metodo de ordenacao:\ns-Selecao\ni-Insercao\nm-Merge\n";
    char escolha; cin >> escolha;

    cout << endl;
    if(ordenado(lista, n)) cout << "Ordenado";
    else cout << "Nao ordenado";
    cout << endl; 

    auto inicio = chrono::high_resolution_clock::now();

    switch(escolha) {
        case 's':
            selecao(lista, n);
            break;
        case 'i':
            insercao(lista, n);
            break;
        case 'm':
            //merge(lista, n);
            cout << "TODO\n";
            break;
    }


    auto fim = chrono::high_resolution_clock::now();
    auto duracao = fim - inicio;
    cout << duracao.count() << " Clocks\n";

    for(auto x : lista) cout << x << " ";
    cout << endl;

} 