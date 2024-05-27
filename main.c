#include "main.h"

int main(void)
{
    chess();
    return 0;
}

void pointers(void)
{
    int a = 10;
    int *p = &a;
    printf("VARIABLE &a: %d | Value  a: %d\n", &a, a);
    printf("POINTER   p: %d | Value *p: %d\n", p, *p);
}

void vectors_and_matrices(void)
{
    int a[10];
    int *p = a;

    /**
     * Both *p and a have now the very same value
     * which is the address of the first element of a.
     */

    printf(" a = hexadecimal: %08x | decimal: %d\n", a);
    printf("*p = hexadecimal: %08x | decimal: %d\n", p);

    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    a[4] = 50;
    a[5] = 60;
    a[6] = 70;
    a[7] = 80;
    a[8] = 90;
    a[9] = 100;

    // x prints an unsigned number in hexadecimal.
    // o prints an unsigned number in octal.
    // u prints an unsigned number in decimal.
    // d prints a signed number in decimal.
    // i prints a signed number in decimal.
    // We can then attach l to the format string for formats like %lx
    // to specify that instead of an int, we're using a long int
    // (That is, an unsigned long int, or long int).

    /**
     * while p is less than the address of the last element of a
     */
    int i = 0;
    while (p < &a[10])
    {
        // To print a pointer with printf(), you should cast the pointer to void* and use "%p"
        printf("a[%d] | %d | %p | %08lx | %lu\n", i, *p, (void *)p, p, p);
        p++; // increment pointer
        i++;
    }

    // point back to the first element of a
    p = a;
    p = (int *)(((int)p) + (3 * sizeof(int))); // *p will be 40 because we are jumping to the 4th index = 0 + 3
    printf("\na[0] | %d | &a[1] | %p | %lu | p | %p | %lu | *p | %d\n", a[0], &a[0], &a[0], p, p, *p);

    p = a;
    // Get the 7th element = 70
    p = (int *)(((int)p) + (6 * sizeof(int)));
    int seventh = *p;
    printf("Seventh Element through *p = (int*)(((int)p) + (5 * sizeof(int))) = %d\n", seventh);
}

void chess(void)
{
    printf("Chess by Cm573r\n\n");
    typedef enum
    {
        NO_PIECE,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING,
        NOT_USED,
        PAWN

    } Chessmen;

    typedef enum
    {
        NO_COLOR,
        WHITE,
        BLACK
    } Chess_Piece_Color;

    typedef struct
    {
        Chessmen piece;
        Chess_Piece_Color color;

    } Chess_Piece;

    printf("Types defined.\n");

    /**
     * The Board
     */

    Chess_Piece chess_board[8][8];
    printf("Board created.\n");

    /**
     * The White Pieces
     */
    Chess_Piece QR_W = {ROOK, WHITE};
    Chess_Piece QN_W = {KNIGHT, WHITE};
    Chess_Piece QB_W = {BISHOP, WHITE};
    Chess_Piece Q_W = {QUEEN, WHITE};
    Chess_Piece K_W = {KING, WHITE};
    Chess_Piece KB_W = {BISHOP, WHITE};
    Chess_Piece KN_W = {KNIGHT, WHITE};
    Chess_Piece KR_W = {ROOK, WHITE};
    Chess_Piece P_QR_W = {PAWN, WHITE};
    Chess_Piece P_QN_W = {PAWN, WHITE};
    Chess_Piece P_QB_W = {PAWN, WHITE};
    Chess_Piece P_Q_W = {PAWN, WHITE};
    Chess_Piece P_K_W = {PAWN, WHITE};
    Chess_Piece P_KB_W = {PAWN, WHITE};
    Chess_Piece P_KN_W = {PAWN, WHITE};
    Chess_Piece P_KR_W = {PAWN, WHITE};

    /**
     * The Black Pieces
     */
    Chess_Piece QR_B = {ROOK, BLACK};
    Chess_Piece QN_B = {KNIGHT, BLACK};
    Chess_Piece QB_B = {BISHOP, BLACK};
    Chess_Piece Q_B = {QUEEN, BLACK};
    Chess_Piece K_B = {KING, BLACK};
    Chess_Piece KB_B = {BISHOP, BLACK};
    Chess_Piece KN_B = {KNIGHT, BLACK};
    Chess_Piece KR_B = {ROOK, BLACK};
    Chess_Piece P_QR_B = {PAWN, BLACK};
    Chess_Piece P_QN_B = {PAWN, BLACK};
    Chess_Piece P_QB_B = {PAWN, BLACK};
    Chess_Piece P_Q_B = {PAWN, BLACK};
    Chess_Piece P_K_B = {PAWN, BLACK};
    Chess_Piece P_KB_B = {PAWN, BLACK};
    Chess_Piece P_KN_B = {PAWN, BLACK};
    Chess_Piece P_KR_B = {PAWN, BLACK};

    printf("Pieces created.\n");

    // Make the board blank
    const Chess_Piece EMPTY_SQUARE = {NO_PIECE, NO_COLOR};
    Chess_Piece *board_pointer = &chess_board[0][0];

    printf("Emptying the Board...\n");

    while (board_pointer <= &chess_board[7][7])
    {
        *board_pointer = EMPTY_SQUARE;
        board_pointer++;
    }

    /**
     * Back to the first square
     */
    board_pointer = &chess_board[0][0];

    printf("Initializing the Board...\n");

    /**
     * Putting the White Pieces
     */

    chess_board[0][0] = QR_W;
    chess_board[0][1] = QN_W;
    chess_board[0][2] = QB_W;
    chess_board[0][3] = Q_W;
    chess_board[0][4] = K_W;
    chess_board[0][5] = KB_W;
    chess_board[0][6] = KN_W;
    chess_board[0][7] = KR_W;
    chess_board[1][0] = P_QR_W;
    chess_board[1][1] = P_QN_W;
    chess_board[1][2] = P_QB_W;
    chess_board[1][3] = P_Q_W;
    chess_board[1][4] = P_K_W;
    chess_board[1][5] = P_KB_W;
    chess_board[1][6] = P_KN_W;
    chess_board[1][7] = P_KR_W;

    /**
     * Putting the Black Pieces
     */

    chess_board[7][0] = QR_B;
    chess_board[7][1] = QN_B;
    chess_board[7][2] = QB_B;
    chess_board[7][3] = Q_B;
    chess_board[7][4] = K_B;
    chess_board[7][5] = KB_B;
    chess_board[7][6] = KN_B;
    chess_board[7][7] = KR_B;
    chess_board[6][0] = P_QR_B;
    chess_board[6][1] = P_QN_B;
    chess_board[6][2] = P_QB_B;
    chess_board[6][3] = P_Q_B;
    chess_board[6][4] = P_K_B;
    chess_board[6][5] = P_KB_B;
    chess_board[6][6] = P_KN_B;
    chess_board[6][7] = P_KR_B;

    /**
     * Print the Board
     */
    printf("Printing the Chess Board...\n\n");
    int row = 0;

    while (board_pointer <= &chess_board[7][7])
    {
        if (row == 8)
        {
            printf("\n");
            row = 0;
        }
        printf("%d ", ((Chess_Piece)*board_pointer).piece);
        board_pointer++;
        row++;
    }

    /**
     * Back to the first square
     */
    board_pointer = &chess_board[0][0];
}

void memory_dump(void)
{
    char start[1];
    char *c = start;
    int i = 0;
    int j = 0;

    while (i < 1000000)
    {
        if (j == 255)
        {
            printf("\n");
            j = 0;
        }
        printf("%c", *c);
        i++;
        j++;
        c++;
    }
}

void malloc_and_free(void)
{
    int *p = (int *)malloc(sizeof(int));

    if (p == NULL)
    {
        printf("ERROR: memory allocation for p failed.\n");
        exit(1);
    }
    else
    {
        printf("%d bytes allocated for p.\n", sizeof(int));
        *p = 10;
    }

    printf("p = %d\n", *p);
    free(p);
}

void dynamic_vector(void)
{
    int vector_size = 10;
    int *vector = (int *)malloc(sizeof(int) * vector_size);

    if (vector == NULL)
    {
        printf("ERROR: memory allocation for vector failed.\n");
        exit(1);
    }
    else
    {
        printf("%d bytes allocated for vector.\n", sizeof(int) * vector_size);
    }

    vector[0] = 10;
    vector[1] = 200;
    vector[2] = 3000;
    vector[3] = 40000;
    vector[4] = 500000;
    vector[5] = 6000000;
    vector[6] = 70000000;
    vector[7] = 800000000;
    vector[8] = 900000000;
    vector[9] = 100000000;

    for (int i = 0; i < vector_size; i++)
    {
        printf("%d\n", vector[i]);
    }
    free(vector);
}