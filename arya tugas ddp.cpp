 #include <iostream>

void printBoard(char board[3][3]) {
	std:: cout<<"_____________"<<std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 3) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 3) std::cout << "_____________" << std::endl;
    }
}

bool checkWinner(char board[3][3], char player) {
   
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);

        int baris, kolom;
        std::cout << "Player " << currentPlayer << ", pilih baris dan kolom (0, 1, atau 2): ";
        std::cin >> baris >> kolom;
        

        if (board[baris][kolom] == ' ') {
            board[baris][kolom] = currentPlayer;

            if (checkWinner(board, currentPlayer)) {
                printBoard(board);
                std::cout << "Player " << currentPlayer << " Menang!" << std::endl;
                break;
            } else if (isBoardFull(board)) {
                printBoard(board);
                std::cout << "SERI!" << std::endl;
                break;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            std::cout << "Tempat sudah terisi. Coba lagi." << std::endl;
        }
    }

    return 0;
}
