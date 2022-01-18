#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int gerarNumeroAleatorio(){
    srand(time(NULL));
    const int aleatorio=(rand()%100)+1;
    cout << "ALEATÓRIO: "<<aleatorio<<endl;
    return aleatorio;
}
int main(){
    cout<<"***************************************"<<endl;
    cout<<
"* Bem-vindos ao jogo da adivinhação ! *"<<endl;
    cout<<"***************************************" <<endl;

    cout << "Escolha o nível de dificuldade do jogo: "<<endl;
    cout << "Fácil (F), Médio (M), Difícil (D)"<<endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F'){
        numero_de_tentativas=15;
    } else if(dificuldade == 'M'){
        numero_de_tentativas=10;
    }else {
        numero_de_tentativas=5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO=(rand()%100)+1;

    bool nao_acertou=true;
    int tentativas = 0;

    double pontos = 1000;

    for(tentativas=1; tentativas <= numero_de_tentativas; tentativas++){
        int chute;
        cout << "Tentativa "<< tentativas << endl;
        cout << "Qual o seu chute ?";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;

        pontos = pontos - pontos_perdidos;

        cout << "O valor do seu chute é " << chute<<endl;

        bool acertou = chute==NUMERO_SECRETO;
        bool eMaior = chute >NUMERO_SECRETO;
        if(acertou){
            cout << "Parabéns ! Você acertou o número secreto !"<<endl;

            nao_acertou=false;
            break;
        } else if(eMaior){
            cout << "Seu chute foi maior que o número secreto !"<<endl;
        } else {
            cout << "Seu chute foi menor que o número secreto !"<<endl;
        }
    }
     cout << "Fim do jogo !"<<endl;
     if(nao_acertou){
        cout << "Você perdeu dessa vez. Tente novamente."<<endl;
     } else{
        cout << "Você acertou o número secreto com "<<tentativas<<" tentativas."<<endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de "<< pontos <<" pontos."<<endl;
     }
    
}


