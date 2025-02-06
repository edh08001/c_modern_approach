struct date {
  int day, month, year;
};

int day_of_year(struct date d)
{
  return d.day;
}

int compare_dates(struct date d1, struct date d2)
{
  if (d1.year == d2.year){
    if (d1.month == d2.month){
      if (d1.day == d2.day){
        return 0;
      } else {
        return d1.day > d2.day ? 1 : -1;
      }
    } else {
      return d1.month > d2.month ? 1 : -1;
    }
  } else {
    return d1.year > d2.year ? 1 : -1;
  }
}

int main(void)
{
  return 1;
}
