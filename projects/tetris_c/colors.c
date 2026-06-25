#include "colors.h"

typedef enum {
  darkGrey,  // 0
  green,     // 1
  red,       // 2
  orange,    // 3
  yellow,    // 4
  purple,    // 5
  cyan,      // 6
  blue,      // 7
  lightBlue, // 8
  darkBlue   // 9
} Colors;

const Color colors[] = {{26, 31, 40, 255},   {47, 230, 23, 255},
                        {232, 18, 18, 255},  {226, 116, 17, 255},
                        {237, 234, 4, 255},  {166, 0, 247, 255},
                        {21, 204, 209, 255}, {13, 64, 216, 255},
                        {59, 85, 162, 255},  {44, 44, 127, 255}};

Color GetCellColors(int cell)
{
  return colors[cell];
}
