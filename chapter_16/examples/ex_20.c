enum {NORTH, SOUTH, EAST, WEST} direction;

int main(void){
  int x, y;
  switch(direction)
  {
    case NORTH: y+=1; 
      break;
    case SOUTH: y-=1;
      break;
    case EAST: x+=1;
      break;
    case WEST: x-=1;
      break;
  }
}


