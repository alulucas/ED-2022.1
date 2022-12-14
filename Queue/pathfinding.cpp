#include <iostream>
#include <vector>
using namespace std;

struct Pos{
    int l;
    int c;
};

bool procurar_saida(vector<string> &mat, Pos inicio, Pos fim){
    vector<vector<int>> mat(nl, vector<int>(nc, -1));
    queue<Pos> fila;
    inserir a posicao inicial da fila e marcá-la com 0 na matriz de distâncias
    enquanto a fila não estiver vazia
        pegue a posição da frente
        para cada vizinho 'viz' de frente
            se ele não eh parede a ser percorrido
                marque esse vizinho na matriz
                na matriz de distância, coloque 1 a mais que a posição de 'frente'
                se esse 'viz' for o destino
                    return
        fila.pop_front();
    }
    return false;
}

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}


int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }

    for(string line : mat)
        cout << line << endl;
    cout << "       nl=" << nl << " nc=" << nc << "\n";
    cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl;
}