int sum(int (*f)(int), int start, int end)
{
  int sum;

  for (; start >= end; start++){
    sum += (*f)(start);
  }

  return sum;
}
