// I WANT TO PLAY WITH YOU
//         /YOUR FRIEND, AI
#include <stdio.h>

int main() {
    int Player1_count = 0;       //Счёт 1ого игрока
    int Player2_count = 0;       //Счёт 2ого игрока
    int X_MAX = 80;              //Максимум по X игрового поля
    int Y_MAX = 25;              //Максимум по Y игрового поля
    int Player1_raketka_Y = 12;  // Актуальная коорлината ракетки 1ого игрока
    int Player2_raketka_Y = 12;  // Актуальная коорлината ракетки 2ого игрока
    int Boll_X = X_MAX / 2;  // Актуальная координата мяча по X  (по умолчанию - X_MAX/2)
    int Boll_Y = Y_MAX / 2;  // Актуальная координата мяча по Y  (по умолчанию -X_MAX/2)
    int tag_of_diraction_X_of_Boll = 1;  // Направление движения мяча 1 - право, -1 - влево
    int tag_of_diraction_Y_of_Boll = 0;  // Направление движения мяча 1 - вверх , -1 - вниз, 0 - прямо
    char simb;  // Символ котороый мы вводим
    char term;
    while (1) {
        printf("\033[0d\033[2J");  // Очистка экрана

        for (int y = Y_MAX - 1; y >= 0; y--) {
            for (int x = 0; x <= X_MAX - 1; x++) {
                if ((y == 0 || y == 24) && (x > 0 && x < 79)) {  //Нижняя и верхняя грани
                    printf("-");
                } else if ((x == 0 || x == 79)) {  //Правая и лева грани
                    printf("|");
                } else if (y == Boll_Y && x == Boll_X) {  // Движение мяча
                    printf("o");
                } else if (x == X_MAX / 2 && y % 2 == 1) {  // Сетка по середине
                    printf("|");
                } else if (x == 2 && (y == Player1_raketka_Y - 1 || y == Player1_raketka_Y ||
                                      y == Player1_raketka_Y + 1)) {  // Левая ракетка 1 игрока
                    printf(")");
                } else if (x == 77 && (y == Player2_raketka_Y - 1 || y == Player2_raketka_Y ||
                                       y == Player2_raketka_Y + 1)) {  // Правая ракетка 2 игрока
                    printf("(");
                } else if (x == 37 && y == 23) {  // Отрисовка счёта игроков
                    if (Player1_count < 10) {
                        printf("0");
                    } else {
                        printf("%d", Player1_count / 10);
                    }
                } else if (x == 38 && y == 23) {
                    if (Player1_count < 10) {
                        printf("%d", Player1_count);
                    } else {
                        printf("%d", Player1_count % 10);
                    }
                } else if (x == 42 && y == 23) {
                    if (Player2_count < 10) {
                        printf("0");
                    } else {
                        printf("%d", Player2_count / 10);
                    }
                } else if (x == 43 && y == 23) {
                    if (Player1_count < 10) {
                        printf("%d", Player2_count);
                    } else {
                        printf("%d", Player2_count % 10);
                    }
                } else
                    printf(" ");
            }
            printf("\n");
        }

        // Логика для движения ракетки игроков
        if (scanf("%c%c", &simb, &term) != 2 || term != '\n') {  // Считывание символов
            printf("error\n");
        }

        switch (simb) {
            case 'A':
                if (Player1_raketka_Y <= 21) {
                    Player1_raketka_Y++;
                }
                // printf ("A");
                break;
            case 'Z':
                if (Player1_raketka_Y >= 3) {
                    Player1_raketka_Y--;
                }
                // printf ("Z");
                break;
            case 'K':
                if (Player2_raketka_Y <= 21) {
                    Player2_raketka_Y++;
                }
                // printf ("K");
                break;
            case 'M':
                if (Player2_raketka_Y >= 3) {
                    Player2_raketka_Y--;
                }
                // printf ("M");
                break;
        }
        simb = '0';
        // Логика движения мяча
        if (tag_of_diraction_X_of_Boll == 1) {
            Boll_X++;
        } else {
            Boll_X--;
        }
        if (tag_of_diraction_Y_of_Boll == 1) {
            Boll_Y++;
        }
        if (tag_of_diraction_Y_of_Boll == -1) {
            Boll_Y--;
        }

        // Логика столкновения с ракетками

        if ((Boll_X - 1 == 75) && (Player2_raketka_Y == Boll_Y)) {  //Отскок от центра ракетки 2ого игрока
            tag_of_diraction_X_of_Boll = -1;
        }
        if ((Boll_X + 1 == 4) && (Player1_raketka_Y == Boll_Y)) {  //Отскок от центра ракетки 1ого игрока
            tag_of_diraction_X_of_Boll = 1;
        }
        if ((Boll_X - 1 == 75) &&
            (Player2_raketka_Y + 1 == Boll_Y)) {  //Отскок от верхней части ракетки 2ого игрока
            tag_of_diraction_X_of_Boll = -1;
            tag_of_diraction_Y_of_Boll = 1;
        }
        if ((Boll_X + 1 == 4) &&
            (Player1_raketka_Y + 1 == Boll_Y)) {  //Отскок от верхней части ракетки 1ого игрока
            tag_of_diraction_X_of_Boll = 1;
            tag_of_diraction_Y_of_Boll = 1;
        }
        if ((Boll_X - 1 == 75) &&
            (Player2_raketka_Y - 1 == Boll_Y)) {  //Отскок от нижней части ракетки 2ого игрока
            tag_of_diraction_X_of_Boll = -1;
            tag_of_diraction_Y_of_Boll = -1;
        }
        if ((Boll_X + 1 == 4) &&
            (Player1_raketka_Y - 1 == Boll_Y)) {  //Отскок от нижней части ракетки 1ого игрока
            tag_of_diraction_X_of_Boll = 1;
            tag_of_diraction_Y_of_Boll = -1;
        }

        // Логика столкновения с гранями (верхняя и нижняя)

        if (Boll_Y == 23) {
            tag_of_diraction_Y_of_Boll = -1;
        }
        if (Boll_Y == 1) {
            tag_of_diraction_Y_of_Boll = 1;
        }

        // Логика столкновения с гранями (Левая и правая) + увеличение счётчика

        if (Boll_X == 0) {
            Player2_count++;
            Boll_X = X_MAX / 2;  // Перенос мяча в центр
            Boll_Y = Y_MAX / 2;
            tag_of_diraction_X_of_Boll = 1;
        }
        if (Boll_X == 79) {
            Player1_count++;
            Boll_X = X_MAX / 2;  // Перенос мяча в центр
            Boll_Y = Y_MAX / 2;
            tag_of_diraction_X_of_Boll = -1;
        }

        // Логика выйгрыша
        if (Player1_count == 21) {
            printf("\033[0d\033[2J");  // Очистка экрана
            printf("Congratulations!!! 1st player wins!\n");
            break;
        }
        if (Player2_count == 21) {
            printf("\033[0d\033[2J");  // Очистка экрана
            printf("Congratulations!!! 2nd player wins!\n");
            break;
        }
    }

    return 0;
}