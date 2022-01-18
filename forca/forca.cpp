#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include <ctime>
#include<cstdlib>
#include "nao_acertou.cpp"
#include "letra_existe.cpp"

using namespace std;

string palavra_secreta="FINLANDES";
map<char, bool> chutou;
vector<char> chutes_errados;

void imprimir_chutes_errados(){
    cout << "Chutes errados: ";
    for(char letra : chutes_errados){
        cout << letra << " ";
    }
}
void imprimir_acertos(){
    cout<<endl;
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }else{
            cout << "_ ";
        }
    }
    cout<<endl;
}
void imprimir_titulo(){
    cout << "*************************"<<endl;
    cout << "  *** Jogo da Forca ****"<<endl;
    cout << "*************************"<<endl;
    cout << endl;
 
}

void tratar_chute_e_mostrar_feedback(){
    char chute;
    cout << "Seu chute: ";
    cin >> chute;

    chutou[chute]=true;
    cout << "O seu chute foi "<< chute << endl;

    if(letra_existe(chute)){
        cout << "Você acertou ! Seu chute está na palavra."<<endl;
    } else {
        cout << "Você errou ! Seu chute não está na palavra"<<endl;
        chutes_errados.push_back(chute);
    }
    cout<<endl;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

vector<string> ler_arquivo(){
    ifstream arquivo;
    arquivo.open("pasta_do_arquivo/palavras.txt");

    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
/*
        cout << "O arquivo possui "<<quantidade_palavras<<" palavras."<<endl;*/

        vector<string> palavras_do_arquivo;

        for(int i = 0; i < quantidade_palavras;i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            //cout <<"Na linha "<< i <<": " << //palavra_lida << endl;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    }else{
        cout<<"Não foi possível acessar o banco de palavras."<<endl;
        exit(0);
    }
}

void sorteia_palavra(){
    vector<string> palavras = ler_arquivo();

    srand(time(NULL));
    int indice_palavra = rand()%palavras.size();

    palavra_secreta=palavras[indice_palavra];
}

void salvar_no_arquivo(vector<string> nova_lista_de_palavras){
    ofstream arquivo;
    arquivo.open("pasta_do_arquivo/palavras.txt");

    if(arquivo.is_open()){
        arquivo << nova_lista_de_palavras.size()<<endl;

        for(string palavra:nova_lista_de_palavras){
            arquivo << palavra<<endl;
        }

        arquivo.close();
    } else {
        cout << "Não foi possível acessar o banco de palavras";
        exit(0);
    }
}
void adicionar_palavra(){
    cout << "Digite a nova palavra, usando letras maiúsculas."<<endl;

    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(nova_palavra);

    salvar_no_arquivo(lista_palavras);
}
int main(){
    imprimir_titulo();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()){
        imprimir_chutes_errados();
        imprimir_acertos();
        tratar_chute_e_mostrar_feedback();
       
    }

    cout << "Fim de jogo !"<< endl;
    cout << "A palavra secreta era: "<<palavra_secreta<<endl;

    if(nao_acertou()){
        cout << "Você perdeu dessa vez !Tente novamente !"<<endl;
    }else {
        cout<<"Parabéns ! Você acertou a palavra secreta !"<<endl;

        cout << "Você gostaria de adicionar uma nova palavra ao banco ? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adicionar_palavra();
        }
    }
}