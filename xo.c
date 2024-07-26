#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void initialize_board(char AB[3][3]) {
    AB[0][0] = '1';
    AB[0][1] = '2';
    AB[0][2] = '3';
    AB[1][0] = '4';
    AB[1][1] = '5';
    AB[1][2] = '6';
    AB[2][0] = '7';
    AB[2][1] = '8';
    AB[2][2] = '9';
}

void display_board(char AB[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", AB[i][0], AB[i][1], AB[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

void inputhandler(char AB[3][3], char move, int num) {
    switch (num) {
        case 1:
            AB[0][0] = move;
            break;
        case 2:
            AB[0][1] = move;
            break;
        case 3:
            AB[0][2] = move;
            break;
        case 4:
            AB[1][0] = move;
            break;
        case 5:
            AB[1][1] = move;
            break;
        case 6:
            AB[1][2] = move;
            break;
        case 7:
            AB[2][0] = move;
            break;
        case 8:
            AB[2][1] = move;
            break;
        case 9:
            AB[2][2] = move;
            break;
        default:
            break;
    }
}

int WinningOrNot(char AB[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (AB[i][0] == AB[i][1] && AB[i][1] == AB[i][2]) {
            return 1;
        }
        if (AB[0][i] == AB[1][i] && AB[1][i] == AB[2][i]) {
            return 1;
        }
    }
    if (AB[0][0] == AB[1][1] && AB[1][1] == AB[2][2]) {
        return 1;
    }
    if (AB[0][2] == AB[1][1] && AB[1][1] == AB[2][0]) {
        return 1;
    }
    return 0;
}

int replayornot() {
    char conti;

    printf("Wanna replay? (Y/N): ");
    scanf(" %c", &conti);
    while (toupper(conti) != 'Y' && toupper(conti) != 'N') {
        printf("Please enter a valid answer (Y/N): ");
        scanf(" %c", &conti);
    }
    if (toupper(conti) == 'Y') {
        return 1;
    } else {
        return 0;
    }
}

void gameplay(char AB[3][3]) {
    int i = 0;
    int play;
    char player = 'X';

    while (i < 9 && WinningOrNot(AB) == 0) {
        system("cls"); // Use "clear" if on Unix-based systems
        display_board(AB);
        printf("Player %c, choose a tile (1-9): ", player);
        scanf("%d", &play);

        while (play < 1 || play > 9 || AB[(play - 1) / 3][(play - 1) % 3] == 'X' || AB[(play - 1) / 3][(play - 1) % 3] == 'O') {
            printf("Invalid move. Enter a valid tile (1-9): ");
            scanf("%d", &play);
        }

        inputhandler(AB, player, play);
        player = (player == 'X') ? 'O' : 'X';
        i++;
    }

    system("cls");
    display_board(AB);

    if (WinningOrNot(AB)) {
        printf("Player %c wins!\n", (player == 'X') ? 'O' : 'X');
    } else {
        printf("It's a draw!\n");
    }
}

int main() {
    char XO[3][3];
    int replay = 1;

    while (replay) {
        initialize_board(XO);
        gameplay(XO);
        replay = replayornot();
    }

    return 0;
}
