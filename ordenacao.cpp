int acharminimo(int comeco, int a[], unsigned int t){
  int menor = a[comeco];
  int indice = comeco;
  for(unsigned int i = comeco+1; i < t; i++){
    if(a[i] < menor) { menor = a[i]; indice = i; }
  }
  return indice;
}

void selecao(int a[], unsigned int t){  //Tempo: O(n²) / espaço: O(n)
  int b[t];
  for(unsigned int i = 0; i < t; i++){
    int indmenor = acharminimo(i, a, t);
    for(unsigned int j = indmenor; j < t-1; j++){
      a[j] = a[j+1];
    }
    b[i] = a[i];
  }
    for(unsigned int j = 0; j < t; j++){
      a[j] = b[j];
    }
}

void insercao(int a[], int t){}

void merge(int a[], int t){}

bool ordenado(int a[], int t){
    for(int i = 0; i < t-1; i++){
        if(a[i] > a[i+1])return false;
    }
    return true;
}


#include <iostream>
#include <chrono>
using namespace std;

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
            cout << "TODO\n";
            break;
        case 'm':
            cout << "TODO\n";
            break;

    }


    auto fim = chrono::high_resolution_clock::now();
    auto duracao = fim - inicio;
    cout << duracao.count() << " Clocks\n";

    for(auto x : lista) cout << x << " ";
    cout << endl;

} 