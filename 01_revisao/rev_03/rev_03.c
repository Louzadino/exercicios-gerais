#include <stdio.h>

void livrosSemCopias(int livros[], int n) {
    int identificadores[10001] = {0}; // Array para armazenar os identificadores
    int temCopias[10001] = {0}; // Array para verificar se já encontrou cópias
    int i, id;
    
    for (i = 0; i < n; i++) {
        id = livros[i];
        if (!temCopias[id]) { // Se não encontrou cópias desse livro
            if (!identificadores[id]) { // Se é a primeira vez que encontra esse livro
                identificadores[id] = 1; // Adiciona à lista de identificadores
            } else {
                temCopias[id] = 1; // Marca como tendo cópias
            }
        }
    }
    
    for (int i = 1; i <= 10000; i++) {
        if (identificadores[i] && !temCopias[i]) {
            printf("%d ", i); // Imprime os livros sem cópias
        }
    }
}

int main() {
    int N, i;
    scanf("%d", &N);
    
    int livros[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &livros[i]);
    }
    
    livrosSemCopias(livros, N);
    
    return 0;
}
