#include <stdlib.h>

#define ZERO_SEGMENT {1, 1, 1, 1, 1, 1}
#define ONE_SEGMENT {[1] = 1, 1}
#define TWO_SEGMENT {1, 1, 0, 1, 1, 0, 1}
#define THREE_SEGMENT {1, 1, 1, 1, [6] = 1}
#define FOUR_SEGMENT {0, 1, 1, [5] = 1, 1}
#define FIVE_SEGMENT {1, 0, 1, 1, 0, 1, 1}
#define SIX_SEGMENT {1, 0, 1, 1, 1, 1, 1}
#define SEVEN_SEGMENT {1, 1, 1}
#define EIGHT_SEGMENT {1, 1, 1, 1, 1, 1, 1}
#define NINE_SEGMENT {1, 1, 1, 1, 0, 1, 1}

int main(int argc, char *argv[])
{
  const int segments[10][7] = {
    ZERO_SEGMENT,
    ONE_SEGMENT,
    TWO_SEGMENT,
    THREE_SEGMENT,
    FOUR_SEGMENT,
    FIVE_SEGMENT,
    SIX_SEGMENT,
    SEVEN_SEGMENT,
    EIGHT_SEGMENT,
    NINE_SEGMENT
  };

  return EXIT_SUCCESS;
}

