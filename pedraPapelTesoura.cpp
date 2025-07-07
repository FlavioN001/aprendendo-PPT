#include <cctype>
#include <cstdlib>
#include <iostream>
#include <ctime>
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void setWinner(char player, char computer);
void startGame();
int resetGame();
void clear();
int checksystem();

int main(){
        //reset
        int reset;
        do {
        
        //início
        char userChoice;
        char computerChoice;
        startGame();
        
        // usuário
        userChoice = getUserChoice();
        std::cout << "Você escolheu ";
        showChoice(userChoice);
        std::cout << ".\n";
        
        //computador
        computerChoice = getComputerChoice();
        std::cout << "O computador escolheu ";
        showChoice(computerChoice);
        std::cout << ".\n";
        
        //vencedor
        setWinner(userChoice, computerChoice);
        
        //reset
        reset = resetGame();
    } while (reset == 1);
    
    return 0;
}
char getUserChoice(){
    char escolha;
    while (escolha!='H'&&escolha!='O'&&escolha!='V')
    {
        std::cout<< ">";
        std::cin >> escolha;
        escolha = std::toupper(escolha);
        if  (escolha!='H'&&escolha!='O'&&escolha!='V'){
            std::cout << "Insira um valor válido \n";
        }
    }
    
    return escolha;
}
char getComputerChoice(){
    srand(time(0));
    int num = rand()%3;

    switch (num) {
        case 0: return 'O';
        case 1: return 'H';
        case 2: return 'V';
        }
        return 0;
    }
void showChoice(char userchoice){
    switch (userchoice) {
        case 'O': std::cout << "Pedra";
            break;
        case 'H': std::cout << "Papel";
            break;
        case 'V': std::cout << "Tesoura";
            break;
    }

}
void setWinner(char player, char computer){
    switch (player){
        case 'O':   if (computer == 'O'){
                    std::cout << "\n O jogo empatou! \n";
                    }
                    else if (computer == 'H') {
                    std::cout << "\n Você perdeu! :C \n";
                    }
                    else if (computer == 'V') {
                    std::cout << "\n Você ganhou!! :D \n";
                    }
                    break;
        case 'H':   if (computer == 'H'){
                    std::cout << "\n O jogo empatou! \n";
                    }
                    else if (computer == 'V') {
                    std::cout << "\n Você perdeu! :C \n";
                    }
                    else if (computer == 'O') {
                    std::cout << "\n Você ganhou!! :D \n";
                    }
                    break;
        case 'V':   if (computer == 'V'){
                    std::cout << "\n O jogo empatou! \n";
                    }
                    else if (computer == 'O') {
                    std::cout << "\n Você perdeu! :C \n";
                    }
                    else if (computer == 'H') {
                    std::cout << "\n Você ganhou!! :D \n";
                    }
                    break;
        }
}
void startGame(){
    clear();
    std::cout<<"   _______________________\n";
    std::cout<<"   **PEDRA PAPEL TESOURA**\n";
    std::cout<<"   ***********************\n\n";
    std::cout<<"O = PEDRA\n";
    std::cout<<"H = PAPEL\n";
    std::cout<<"V = TESOURA\n";

}
int resetGame(){
    int resetall;
    char resp;
    while (resp != 'S' || resp != 'N') {

    
    std::cout<<"\ngostaria de jogar novamente? \n";
    std::cout<<"[S = Sim] [N = Não] \n";
    std::cout<<"> ";
    std::cin >> resp;
    resp = toupper(resp);
    if (resp == 'S') {
        resetall = 1;
        std::cout << "Reiniciando...\n";
        break;
    }
    else if (resp == 'N'){
        resetall = 0;
        std::cout << "Encerrando...\n";
        break;
    }
    else {
        std::cout << "Insira uma resposta válida.\n";
    }
}
return resetall;
}
void clear(){
    int so = checksystem();
    if (so == 1) {
        system("clear");
    }
    else if (so == 0) {
        system("cls");
    }
    else {
        std::cout << "Sistema operacional desconhecido :(";
    }
}
int checksystem(){
    int SO;
    #ifdef _WIN32
        SO = 0;
    #else
        SO = 1;
    #endif
    return SO;
}