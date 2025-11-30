/*Calcular área máxima en histograma*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int calcularAreaMaximaHistograma(const vector<int>& histograma) {
    if (histograma.empty()) return 0;
    
    const size_t n = histograma.size();
    stack<size_t> pila;
    int areaMaxima = 0;
    size_t i = 0;
    
    while (i < n) {
        if (pila.empty() || histograma[pila.top()] <= histograma[i]) {
            pila.push(i);
            ++i;
        } else {
            const size_t tope = pila.top();
            pila.pop();
            
            const int altura = histograma[tope];
            const size_t ancho_size = pila.empty() ? i : i - pila.top() - 1;
            const int ancho = static_cast<int>(ancho_size);
            
            areaMaxima = max(areaMaxima, altura * ancho);
        }
    }
    
    while (!pila.empty()) {
        const size_t tope = pila.top();
        pila.pop();
        
        const int altura = histograma[tope];
        const size_t ancho_size = pila.empty() ? i : i - pila.top() - 1;
        const int ancho = static_cast<int>(ancho_size);
        
        areaMaxima = max(areaMaxima, altura * ancho);
    }
    
    return areaMaxima;
}

int main() {
    vector<vector<int>> pruebas = {
        {2, 1, 5, 6, 2, 3},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {1, 3, 2, 1, 2},
        {6, 2, 5, 4, 5, 1, 6}
    };
    
    for (const auto& prueba : pruebas) {
        int area = calcularAreaMaximaHistograma(prueba);
        cout << "Histograma: [";
        for (size_t j = 0; j < prueba.size(); ++j) {
            cout << prueba[j];
            if (j < prueba.size() - 1) cout << ", ";
        }
        cout << "] -> Area maxima: " << area << endl;
    }
    
    return 0;
}