//Aleksandra Prodziewicz
bool Emptiness(int zbior)
{
   if (zbior == 0)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
bool Nonempty(int zbior)
{
   if (zbior == 0)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}
int this_bit(int number, int which_bit)
{
   int anwser = ((number >> which_bit) & 1U);
   return anwser;
}
void set_bit_1(int *number, int which_bit)
{
   *number ^= (-1 ^ *number) & (1UL << which_bit);
}
void set_bit_0(int* number, int which_bit)
{
   *number ^= (-0 ^ *number) & (1UL << which_bit);
}
int count_bits(int zbior, int reps = 31, int bit_count = 0)
{
   if (this_bit(zbior, reps) == 1)
   {
      bit_count = bit_count + 1;
   }
   if(reps == 0)
   {
      return bit_count;
   }
   count_bits(zbior, reps - 1, bit_count);
}
int value(int number, int anwser = 0)
{
   anwser = (anwser + number)*2;
   return anwser;
}
int bit_to_char(int intiger, int position)
{
   int bit;
   int bit_5 = intiger % 2;
   intiger = (((intiger - (intiger % 2))/2));
   int bit_4 = intiger % 2;
   intiger = (((intiger - (intiger % 2))/2));
   int bit_3 = intiger % 2;
   intiger = (((intiger - (intiger % 2))/2));
   int bit_2 = intiger % 2;
   intiger = (((intiger - (intiger % 2))/2));
   int bit_1 = intiger % 2;
   if(position == 1)
   {
      bit = bit_1;
   }
   else if(position == 2)
   {
      bit = bit_2;
   }
   else if(position == 3)
   {
      bit = bit_3;
   }
   else if(position == 4)
   {
      bit = bit_4;
   }
   else if(position == 5)
   {
      bit = bit_5;
   }
   return bit;
}
int find_1(int zbior, int reps = 31)
{
   if(this_bit(zbior, reps) == 1)
   {
      return reps;
   }
   else if(reps == 0)
   {
      reps = 777;
      return reps;
   }
   find_1(zbior, (reps - 1));
}
void Print(int zbior, char* wynik)
{
   int id = find_1(zbior);
   if(id != 777)
   {
      int bit_1 = bit_to_char(id, 1);
      int bit_2 = bit_to_char(id, 2);
      int bit_3 = bit_to_char(id, 3);
      int bit_4 = bit_to_char(id, 4);
      int bit_5 = bit_to_char(id, 5);
      *wynik = bit_1 + '0';
      *(wynik + 1) = bit_2 + '0';
      *(wynik + 2) = bit_3 + '0';
      *(wynik + 3) = bit_4 + '0';
      *(wynik + 4) = bit_5 + '0';
      set_bit_0(&zbior, id);
      *(wynik + 5) = ' ';
      if(find_1(zbior) == 777)
      {
         *(wynik + 5) = '\0';
      }
   }
   else if(Emptiness(zbior))
   {
      *wynik = 'e';
      *(wynik + 1) = 'm';
      *(wynik + 2) = 'p';
      *(wynik + 3) = 't';
      *(wynik + 4) = 'y';
      *(wynik + 5) = '\0';
   }
   if(*(wynik + 5) == '\0')
   {
      return;
   }
   Print(zbior, (wynik + 6));
}
void Insert(char* ciag_in, int* incik)
{
   if(*ciag_in == '0' || *ciag_in == '1')
   {
      int tmp_5 = (*ciag_in - '0');
      int tmp_4 = (*(ciag_in + 1) - '0');
      int tmp_3 = (*(ciag_in + 2) - '0');
      int tmp_2 = (*(ciag_in + 3) - '0');
      int tmp_1 = (*(ciag_in + 4) - '0');
      int tmp = ((((tmp_5 * 2 + tmp_4) * 2 + tmp_3) * 2 + tmp_2) * 2 + tmp_1);
      set_bit_1(incik, tmp);
      Insert((ciag_in + 5), incik);
   }
   else if(*ciag_in == '\0')
   {
      return;
   }
   else
   {
      Insert((ciag_in + 1), incik);
   }
}
void Erase(char* ciag_in, int* incik)
{
   if(*ciag_in == '0' || *ciag_in == '1')
   {
      int tmp_5 = (*ciag_in - '0');
      int tmp_4 = (*(ciag_in + 1) - '0');
      int tmp_3 = (*(ciag_in + 2) - '0');
      int tmp_2 = (*(ciag_in + 3) - '0');
      int tmp_1 = (*(ciag_in + 4) - '0');
      int tmp = ((((tmp_5 * 2 + tmp_4) * 2 + tmp_3) * 2 + tmp_2) * 2 + tmp_1);
      set_bit_0(incik, tmp);
      Erase((ciag_in + 5), incik);
   }
   else if(*ciag_in == '\0')
   {
      return;
   }
   else
   {
      Erase((ciag_in + 1), incik);
   }
}
int Cardinality (int zbior)
{
   return count_bits(zbior);
}
void Emplace(char* ciag_in, int* incik)
{
   if(Nonempty(*incik))
   {
      *incik = 0;
   }
   Insert(ciag_in, incik);
}
bool Member(char* ciag, int incik)
{
   if(*ciag == '0' || *ciag == '1')
   {
      int tmp_5 = (*ciag - '0');
      int tmp_4 = (*(ciag + 1) - '0');
      int tmp_3 = (*(ciag + 2) - '0');
      int tmp_2 = (*(ciag + 3) - '0');
      int tmp_1 = (*(ciag + 4) - '0');
      int tmp = ((((tmp_5 * 2 + tmp_4) * 2 + tmp_3) * 2 + tmp_2) * 2 + tmp_1);
      if(this_bit(incik, tmp) == 1)
      {
         return 1;
      }
      else
      {
         return 0;
      }
   }
   /*else if(*ciag == '\0')
   {
      return;
   }*/
   else
   {
      Member((ciag + 1), incik);
   }
}
void Complement(int zbior1, int* incik)
{
   *incik = ~zbior1;
}
int dis(int zbior1, int zbior2, int reps = 31)
{
   if(this_bit(zbior1, reps) == this_bit(zbior2, reps))
   {
      if(this_bit(zbior1, reps) == 1)
      {
         return 0;
      }
   }
   if(reps == 0)
   {
      return 1;
   }
   dis(zbior1, zbior2, reps - 1);
}
bool Disjoint(int zbior1, int zbior2)
{
   return dis(zbior1, zbior2);
}
int each_bit(int zbior1, int zbior2, int reps = 31)
{
   if(this_bit(zbior1, reps) == this_bit(zbior2, reps))
   {
      if(this_bit(zbior1, reps) == 1)
      {
         return 1;
      }
   }
   if(reps == 0)
   {
      return 0;
   }
   each_bit(zbior1, zbior2, reps - 1);
}
bool Conjunctive(int zbior1, int zbior2)
{
   return each_bit(zbior1, zbior2);
}
int eq(int z1, int z2, int ids = 31)
{
   if(this_bit(z1, ids) == this_bit(z2, ids))
   {
      if(ids == 0)
      {
         return 1;
      }
      eq(z1, z2, (ids - 1));
   }
   else
   {
      return 0;
   }
}
bool Equality(int zbior1, int zbior2)
{
   return eq(zbior1, zbior2);
}
int ic(int z1, int z2, int ids = 31)
{
   if(this_bit(z1, ids) == 1 && this_bit(z2, ids) == 0)
   {
      return 0;
   }
   if(ids == 0)
   {
      return 1;
   }
   ic(z1, z2, (ids - 1));
}
bool Inclusion(int zbior1, int zbior2)
{
  return ic(zbior1, zbior2);
}
void Union(int z1, int z2, int* z3)
{
   if (*z3 != 0)
   {
      *z3 = 0;
   }
   *z3 = (z1 | z2);
}
void Intersection(int z1, int z2, int* z3)
{
   if (*z3 != 0)
   {
      *z3 = 0;
   }
   *z3 = (z1 & z2);
}
void Symmetric(int z1, int z2, int* z3)
{
   if (*z3 != 0)
   {
      *z3 = 0;
   }
   *z3 = (z1 ^ z2);
}
void Difference(int z1, int z2, int* z3)
{
   if (*z3 != 0)
   {
      *z3 = 0;
   }
   *z3 = (z1 & ~z2);
}
bool LessThen(int zbior1, int zbior2)
{
   if(Cardinality(zbior1) == Cardinality(zbior2))
   {
      return(zbior1 < zbior2);
   }
   else
   {
      return (Cardinality(zbior1) < Cardinality(zbior2));
   }
}
bool LessEqual(int zbior1, int zbior2)
{
   if(Cardinality(zbior1) == Cardinality(zbior2))
   {
      return(zbior1 <= zbior2);
   }
   else
   {
      return (Cardinality(zbior1) <= Cardinality(zbior2));
   }
}
bool GreatEqual(int zbior1, int zbior2)
{
   if(Cardinality(zbior1) == Cardinality(zbior2))
   {
      return(zbior1 >= zbior2);
   }
   else
   {
      return (Cardinality(zbior1) >= Cardinality(zbior2));
   }
}
bool GreatThen(int zbior1, int zbior2)
{
   if(Cardinality(zbior1) == Cardinality(zbior2))
   {
      return(zbior1 > zbior2);
   }
   else
   {
      return (Cardinality(zbior1) > Cardinality(zbior2));
   }
}
