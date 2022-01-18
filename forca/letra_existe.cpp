#include<string>

std::string palavra_secreta;

bool letra_existe(char letra_do_chute){
    for(char letra_da_palavra : palavra_secreta){
        if(letra_do_chute == letra_da_palavra){
            return true;
        }
    }
    return false;
}