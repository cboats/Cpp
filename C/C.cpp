//Aleksandra Prodziewicz
struct Number{
   string numb;
   bool negative;
};
void reverse_string(string& s, int n, int r = 0)
{
   if(r >= n / 2)
   {
      return;
   }
   if(s[0] == '-')
   {
      if(r == 0)
      {
         r = 1;
      }
      swap(s[r], s[n - r]);
      reverse_string(s, n, r + 1);
   }
   else
   {
      swap(s[r], s[n - r - 1]);
      reverse_string(s, n, r + 1);
   }
}
void make_pretty(Number* s, int n)
{
   if(n == 1)
   {
      return;
   }
   if(s->numb[0] == '0' or  s->numb[0] == '\0')
   {
      s->numb = s->numb.substr(1, n);
      make_pretty(s, n - 1);
   }
   else
   {
      return;
   }
}

int is_bigger(string one, string two, int n1, int n2, int i = 0)
{
   if(n1 > n2)
   {
      return 1;
   }
   else if(n1 < n2)
   {
      return 2;
   }
   else
   {
      if(one[i] < two[i])
      {
         return 2;
      }
      else if(one[i] > two[i])
      {
         return 1;
      }
      else if(one[i] == two[i] and n1 > 1 and n2 > 1)
      {
         is_bigger(one, two, n1 - 1, n2 - 1, i + 1);
      }
   }
   if(n1 == 1 and n2 == 1)
   {
      return 0;
   }
}
void add_string(Number* one, Number* three, Number* temp, int n, int repeat = 0, int added = 0)
{
   char one_char = one->numb[repeat];
   int one_int = one_char - '0';
   if(three->numb.length() > repeat)
   {
      char three_char = three->numb[repeat];
      int three_int = three_char - '0';
      int temp_int = one_int + three_int + added;
      added = 0;
      if(temp_int >= 10)
      {
         added = temp_int / 10;
         temp_int = temp_int % 10;
      }
      char ct = '0' + temp_int;
      if(repeat == 0)
      {
         temp->numb = ct;
      }
      else
      {
         temp->numb = ct + temp->numb;
      }
   }
   else
   {
      int temp_int = one_int + added;
      added = 0;
      if(temp_int >= 10)//przerzut
      {
         added = temp_int / 10;
         temp_int = temp_int % 10;
      }
      char ct = '0' + temp_int;
      if(repeat == 0)
      {
         temp->numb = ct;
      }
      else
      {
         temp->numb = ct + temp->numb;
      }
   }
   if(repeat == n - 1)
   {
      if(added == 1)
      {
         temp->numb = "1" + temp->numb;
      }
      return;
   }
   add_string(one, three, temp, n, repeat + 1, added);
}
void sub_string(Number* one, Number* three, Number* temp, int n, int repeat = 0, int added = 0)
{
   char one_char = one->numb[repeat];
   int one_int = one_char - '0';
   if(three->numb.length() > repeat)
   {
      char three_char = three->numb[repeat];
      int three_int = three_char - '0';
      int temp_int = one_int - three_int - added;
      added = 0;
      if(temp_int < 0)//pozyczenie
      {
         temp_int = 10 + temp_int;
         added = 1;
      }
      char ct = '0' + temp_int;
      if(repeat == 0)
      {
         temp->numb = ct;
      }
      else
      {
         temp->numb = ct + temp->numb;
      }
   }
   else
   {
      int temp_int = one_int - added;
      added = 0;
      if(temp_int < 0)//pozyczenie
      {
         temp_int = 10 + temp_int;
         added = 1;
      }
      char ct = '0' + temp_int;
      if(repeat == 0)
      {
         temp->numb = ct;
      }
      else
      {
         temp->numb = ct + temp->numb;
      }
   }
   if(repeat == n - 1)
   {
      return;
   }
   sub_string(one, three, temp, n, repeat + 1, added);
}
void determine_string(Number* one, Number* three)
{
   Number tt;
   Number* t= &tt;
   t->numb = three->numb + "0";
   if(one -> negative == 1 and three->negative == 0)//1 ujemny
   {
      if(is_bigger(one->numb, three->numb, one->numb.length(), three->numb.length()) == 1)//1 dluszy
      {
         int n = one->numb.length();
         reverse_string(one->numb, one->numb.length());
         reverse_string(three->numb, three->numb.length());
         sub_string(one, three, t, n);
         t->negative = 1;
      }
      else if(is_bigger(one->numb, three->numb, one->numb.length(), three->numb.length()) == 2)//3 dluzszy
      {
         int n = three->numb.length();
         reverse_string(one->numb, one->numb.length());
         reverse_string(three->numb, three->numb.length());
         sub_string(three, one, t, n);
         t->negative = 0;
      }
      else
      {
         t->negative = 0;
         t->numb = "0";
      }
   }
   else if(one->negative == 0 and three->negative == 1)//3 ujemny
   {
      if(is_bigger(one->numb, three->numb, one->numb.length(), three->numb.length()) == 1)//1 dluzszy
      {
         int n = one->numb.length();
         reverse_string(one->numb, one->numb.length());
         reverse_string(three->numb, three->numb.length());
         sub_string(one, three, t, n);
         t->negative = 0;
      }
      else if(is_bigger(one->numb, three->numb, one->numb.length(), three->numb.length()) == 2)//3 dluzszy
      {
         int n = three->numb.length();
         reverse_string(one->numb, one->numb.length());
         reverse_string(three->numb, three->numb.length());
         sub_string(three, one, t, n);
         t->negative = 1;
      }
      else
      {
         t->negative = 0;
         t->numb = "0";
      }
   }
   else//oba dodatnie ujemne
   {
      if(one->negative == 1)
      {
         t->negative = 1;
      }
      else
      {
         t->negative = 0;
      }
      if(is_bigger(one->numb, three->numb, one->numb.length(), three->numb.length()) == 1)
      {
         int n = one->numb.length();
         reverse_string(one->numb, one->numb.length());
         reverse_string(three->numb, three->numb.length());
         add_string(one, three, t, n);
      }
      else if(is_bigger(one->numb, three->numb, one->numb.length(), three->numb.length()) == 2)
      {
         int n = three->numb.length();
         reverse_string(one->numb, one->numb.length());
         reverse_string(three->numb, three->numb.length());
         add_string(three, one, t, n);
      }
      else
      {
         int n = three->numb.length();
         reverse_string(one->numb, one->numb.length());
         reverse_string(three->numb, three->numb.length());
         add_string(three, one, t, n);
      }
   }
   three->negative = t->negative;
   three->numb = t->numb;
}
void sign_combine(Number* t)
{
   int len = t->numb.length();
   if(t->numb[0] == '-' or t->numb[0] == '+')
   {
      if(t->numb[0] == '-')
      {
         t->negative = 1;
         t->numb= t->numb.substr(1, len);
      }
      else
      {
         t->negative = 0;
         t->numb= t->numb.substr(1, len);
      }
   }
   else
   {
      t->negative = 0;
   }
   if(len - 1 > 0)
   {
      make_pretty(t, len - 1);
   }
}
void adding(int amount, const string* s, Number* tp, int repeat = 1)
{
   Number temp;
   temp.numb = *(s + repeat);
   Number* temp_ptr = &temp;
   sign_combine(temp_ptr);
   make_pretty(temp_ptr, temp_ptr->numb.length());
   determine_string(temp_ptr, tp);
   //make_pretty(tp, tp->numb.length());
   repeat = repeat + 1;
   if(repeat >= amount)
   {
      return;
   }
   adding(amount, s, tp,repeat);
}
string Sum(int amount, const string* st)
{
   Number trail;
   trail.numb = *st;
   Number* trail_ptr = &trail;
   sign_combine(trail_ptr);
   make_pretty(trail_ptr, trail_ptr->numb.length());
   adding(amount, st, trail_ptr);
   make_pretty(trail_ptr, trail_ptr->numb.length());
   if(trail_ptr->numb == "0")
   {
      trail_ptr->negative =0;
   }
   if(trail_ptr->negative == 1)
   {
      trail_ptr ->numb= '-' + trail_ptr->numb;
   }
   return trail_ptr ->numb;
}
void Sum(string* anwser, int amount, const string* st)
{
   *anwser = Sum(amount, st);
}
void Sum(string& anwser, int amount, const string* st)
{
   anwser = Sum(amount, st);
}
void write_to(string* st, int amount, va_list args, int i = 0)
{
   *(st+i) = (string)va_arg(args, char*);
   if(i == amount - 1)
   {
      return;
   }
   write_to(st, amount, args, i + 1);
}
string Sum(int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   string anwser = Sum(amount, st);
   return anwser;
}
void Sum(string* anwser, int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   *anwser = Sum(amount, st);
}
void Sum(string& anwser, int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   anwser = Sum(amount, st);
}
void correct_string(Number* s, int amount)
{
   s->numb = s->numb + '0';
   if(amount == 1)
   {
      return;
   }
   correct_string(s, amount - 1);
}
void mult_this(Number* ed, Number* to, int xmult, int n_ed, int repeat = 0, int added = 0)
{
   char ed_c = ed->numb[repeat];
   int ed_i = ed_c - '0';
   int insert_it = (ed_i * xmult) + added;
   added = 0;
   if(insert_it >= 10)
   {
      added = insert_it / 10;
      insert_it = insert_it % 10;
      char insert_c = '0' + insert_it;
      if(repeat == 0)
      {
         to->numb = insert_c;
      }
      else
      {
         to->numb = insert_c + to->numb;
      }
   }
   else
   {
      char insert_c = '0' + insert_it;
      if(repeat == 0)
      {
         to->numb = insert_c;
      }
      else
      {
         to->numb = insert_c + to->numb;
      }
   }
   if(repeat == n_ed - 1)
   {
      if(added != 0)
      {
         char add = '0' + added;
         to->numb = add + to->numb;
      }
      return;
   }
   mult_this(ed, to, xmult, n_ed, repeat + 1, added);
}

void mult_string(Number* ed, Number* ing, Number* nu, int n_ed, int n_ing, int rep= 0)
{
   char ing_c = ing->numb[rep];
   int ing_i = ing_c - '0';
   Number ff;
   Number* f= &ff;
   f->negative = 0;
   f->numb = "0";
   mult_this(ed, f, ing_i, n_ed);
   if(rep >= 1)
   {
      correct_string(f, rep);
   }
   if(rep == 0)
   {
      nu->numb = f->numb;
   }
   else
   {
      determine_string(f, nu);
   }
   if(rep == n_ing - 1)
   {
      return;
   }
   mult_string(ed, ing, nu, n_ed, n_ing, rep + 1);
}
void det_string(Number* one, Number* three)
{
   Number t;
   Number* ptr = &t;
   ptr->negative = 0;
   int n = three->numb.length();
   if(n > 1)
   {
      reverse_string(three->numb, n);
   }
   int m = one->numb.length();
   if(m > 1)
   {
      reverse_string(one->numb, m);
   }
   mult_string(one, three, ptr, m, n);
   three->numb = ptr->numb;
}
void multing(int amount, const string* st, Number* an, int repeat = 1)
{
   int minusb = 0;
   Number temp;
   temp.numb = *(st + repeat);
   Number* temp_ptr = &temp;
   sign_combine(temp_ptr);
   if((an->negative == 1 and temp_ptr->negative == 1) or (an->negative == 0 and temp_ptr->negative == 0))
   {
      minusb = 0;
   }
   else if((an->negative == 1 and temp_ptr->negative == 0) or (an->negative == 0 and temp_ptr->negative == 1))
   {
      minusb = 1;
   }
   if(temp_ptr->numb == "0")
   {
      an->numb = "0";
      return;
   }
   det_string(temp_ptr, an);
   //make_pretty(an, an->numb.length());
   an->negative = minusb;
   repeat = repeat + 1;
   if(repeat == amount)
   {
      return;
   }
   multing(amount, st, an, repeat);
}
string Mult(int amount, const string* st)
{
   Number anwser;
   anwser.numb = *st;
   Number* a_ptr = &anwser;
   sign_combine(a_ptr);
   if(a_ptr->numb == "0")
   {
      return a_ptr->numb;
   }
   multing(amount, st, a_ptr);
   make_pretty(a_ptr, a_ptr->numb.length());
   if(a_ptr->negative == 1 and a_ptr->numb != "0")
   {
      a_ptr->numb= "-" + a_ptr->numb;
   }
   return a_ptr ->numb;
}
void Mult(string* anwser, int amount, const string* st)
{
   *anwser = Mult(amount, st);
}
void Mult(string& anwser, int amount, const string* st)
{
   anwser = Mult(amount, st);
}

string Mult(int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   string anwser = Mult(amount, st);
   return anwser;
}

void Mult(string* anwser, int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   *anwser = Mult(amount, st);
}
void Mult(string& anwser, int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   anwser = Mult(amount, st);
}
string Operation(string(*func)(int, const string*), int amount, const string* st)
{
   string an = func(amount, st);
   return an;
}
string Operation(string(*func)(int, const string*), int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   string sw = func(amount, st);
   return sw;
}
void Operation(string* anwser, string(*func)(int, const string*), int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   *anwser = func(amount, st);
}
void Operation(string* anwser, string(*func)(int, const string*), int amount, const string* st)
{
   *anwser = func(amount, st);
}
void Operation(string& anwser, void(*funcja)(string*, int, const string*), int amount, const string* st)
{
   funcja(&anwser, amount, st);
   anwser = anwser;
}
void Operation(string& anwser, void(*funcja)(string*, int, const string*), int amount, ...)
{
   string s[amount];
   string* st = &s[0];
   va_list args;
   va_start(args, amount);
   write_to(st, amount, args);
   va_end(args);
   funcja(&anwser, amount, st);
   anwser = anwser;
}
