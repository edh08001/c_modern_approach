#define BOARD_SIZE 8

typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
typedef enum {WHITE, BLACK} Color;

typedef struct {
  Piece piece;
  Color color;
} Square;

int main(void)
{
  Square board[BOARD_SIZE][BOARD_SIZE] = {
    {(Square) {.piece = ROOK, .color = BLACK}, (Square) {.piece = KNIGHT, .color = WHITE}, (Square) {.piece = BISHOP, .color = BLACK}}};
      // And the above continues for all pieces on the chess board...
}
