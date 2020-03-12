#include <iostream>
#include "Diretorio.h"
#include <stack>
#include <queue>

using namespace std;


void QtS(queue<string> &q , stack<string> &s , string str) //Tranformar Queue para Stack e acessa a proxima pasta
{
    while(!q.empty()){
        s.push(str + "/" + q.front()); //adiciona o caminho juntos ao subdiretorios
        q.pop();
        cout << s.top() << endl;
    }
}

/* void mostra_fila(queue<string> & q) {
    while (! q.empty()) {
        string e = q.front();
        q.pop();
        if (q.empty()) cout << e;
        else cout << e << ", ";
    }
}*/

int main(int argc, char *argv[]) {

    if(argv[1] == NULL || argv[2] == NULL) // checagem de passagem de parâmetros
    {
        cout << "Não foi passado 1 ou 2 parametros" << endl;
        return 0;
    }

    Diretorio dir;

    stack<string> DFS;         // Stack para busca em profundidade

    DFS.push(argv[1]); //Adiona o Raiz para pilha

    while (!DFS.empty()){

        queue<string> q2 = dir.lista_arquivos(DFS.top()); //Adicionas os Arquivos dentro do diretorio em uma fila
        while (!q2.empty())
        {
                if (q2.front()==argv[2]) //Checa se algum Arquivo na fila é o desejado
            {
                cout << "arquivo encontrado em: " << DFS.top(); //mostra mensagem de onde é encontrado o arquivo
                return 1;
            }
            q2.pop(); //Tira os arquivos que não são desejados
        }

        queue<string> q1 = dir.lista_subdiretorios(DFS.top()); // Adiciona os Subdiretorios para uma fila
        string temp = DFS.top(); //adioca o caminho em uma string temporaria
        DFS.pop();
        QtS(q1,DFS,temp);

    }


/*    cout << "Subdiretórios: ";
    mostra_fila(q1);

    cout << endl;
    cout << "Arquivos: ";
    mostra_fila(q2);
*/
}