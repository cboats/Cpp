//Aleksandra Prodziewicz
#include <iostream>
using namespace std;

struct Link{//wezel
   int to_bead_id; //do tego beada (id) dozy wiazanie
   char strand_id1, strand_id2, strand_id3;
   Link* next_link = NULL;
};

struct Bead{//koralik
   int id;
   Bead* next_bead = NULL;
   Link* link_from = NULL; //z niego
   //Link* link_to = NULL; //do niego
};

struct Strand{ //sznur
   char id1, id2, id3;
   Strand* next_strand = NULL;
   Bead* f_bead = NULL;
};

bool is_bigger(Strand* strand1, Strand* strand2)//czy 1 od 2 jest wiekszy
{
	if(strand2 -> id1 > strand1 -> id1)
   {
		return false;
	}
   else if(strand2 -> id1 == strand1 -> id1)
   {
		if(strand2 -> id2 > strand1 -> id2)
		{
			return false;
		}
      else if(strand2 -> id2 == strand1 -> id2)
      {
			if(strand2 -> id3 > strand1 -> id3)
			{
				return false;
			}
         else if(strand2 -> id3 < strand1 -> id3)
         {
				return true;
			}
		}
      else if(strand2 -> id2 < strand1 -> id2)
      {
			return true;
		}
	}
	else if(strand2 -> id1 < strand1 -> id1)
   {
		return true;
	}
	//return false;
}

bool is_later(Link* link1, Link* link2) //czy 1 jest po 2, czy 1 jest wiekszy
{
	if(link2 -> strand_id1 > link1 -> strand_id1) // 2 jest wieksze czyli jedne jest przd 2
   {
		return false; //nie
	}
   else if(link2 -> strand_id1 == link1 -> strand_id1)
   {
		if(link2 -> strand_id2 > link1 -> strand_id2)
		{
			return false;
		}
      else if(link2 -> strand_id2 == link1 -> strand_id2)
      {
			if(link2 -> strand_id3 > link1 -> strand_id3)
			{
				return false;
			}
         else if(link2 -> strand_id3 < link1 -> strand_id3)
         {
				return true;
			}
			else if(link2 -> strand_id3 == link1 -> strand_id3)
         {
            if(link2 -> to_bead_id > link1 -> to_bead_id)
            {
               return false;
            }
            else
            {
               return true;
            }
			}
		}
      else if(link2 -> strand_id2 < link1 -> strand_id2)
      {
			return true;
		}
	}
	else if(link2 -> strand_id1 < link1 -> strand_id1)
   {
		return true;
	}
	//return true;
}

int main()
{
   int s_number = 0;
   Strand* first_strand = NULL; //first to wskaznik do struktury typu strand == NULL
   Strand* current_strand = NULL;
   Bead* first_bead = NULL;
   Bead* current_bead = NULL;
   Link* first_link = NULL;
   Link* current_link = NULL;
   char to_do;
   cin >> to_do;
   while(to_do != 'F'){
         if(to_do == 'S')
         {
            s_number = s_number + 1;
            char i1, i2, i3;
            cin >> i1 >> i2 >> i3;
            if(s_number == 1)
            {
               first_strand = new Strand; //nowa struktura ktora wskazuje wskaznik new_strand
               first_strand -> id1 = i1;
               first_strand -> id2 = i2;
               first_strand -> id3 = i3;
               current_strand = first_strand;
            }
            else if (s_number > 1)
            {
               Strand* new_strand = new Strand;
               new_strand -> id1 = i1;
               new_strand -> id2 = i2;
               new_strand -> id3 = i3;
               if(s_number == 2)
               {
                  if(is_bigger(first_strand, new_strand))
                  {
                     new_strand -> next_strand = first_strand;
                     first_strand = new_strand;
                  }
                  else
                  {
                     first_strand -> next_strand = new_strand;
                     current_strand = new_strand;
                  }
               }
               else if(s_number > 2)
               {
                  bool problem = 1;
                  current_strand = first_strand;
                  while(current_strand -> next_strand)
                  {
                     if(is_bigger(current_strand, new_strand)) //jezeli cur > new, miejsce new przed curr
                     {
                        bool problem = 0;
                        if(first_strand == current_strand)
                        {
                           new_strand -> next_strand = first_strand;
                           current_strand = first_strand;
                           first_strand = new_strand;
                           new_strand -> next_strand = current_strand;
                           break;
                        }
                        else
                        {
                           Strand* temp = first_strand; // temp na 1
                           while(temp -> next_strand != current_strand) //szukamy tempa po ktorym jest current
                           {
                              temp = temp -> next_strand;
                           }
                           temp -> next_strand = new_strand; //za tego tempa dajemmy new
                           (temp -> next_strand) -> next_strand = current_strand;
                           break;
                        }
                     }
                     current_strand = current_strand -> next_strand;
                  }
                  if(problem)
                  {
                   if(is_bigger(new_strand, current_strand))
                     {
                        current_strand -> next_strand = new_strand;
                        current_strand = new_strand;
                     }
                     else //jezeli cur > new
                     {
                        Strand* temp = first_strand; // temp na 1
                        while(temp -> next_strand != current_strand) //szukamy tempa po ktorym jest current
                        {
                           temp = temp -> next_strand;
                        }
                        temp -> next_strand = new_strand; //za tego tempa dajemmy new
                        (temp -> next_strand) -> next_strand = current_strand; //
                     }
                  }
               }
            }
         }
         else if(to_do == 'B')
         {
            int idb;
            cin >> idb;
            char i1, i2, i3;
            cin >> i1 >> i2 >> i3;
            Strand* to_fill_strand = first_strand;
            while(to_fill_strand != NULL)
            {
               if ((i1 == to_fill_strand -> id1) &&  (i2 == to_fill_strand -> id2) && (i3 == to_fill_strand -> id3))
               {
                  if(to_fill_strand -> f_bead == NULL)
                  { //Bead*
                     first_bead = new Bead;
                     first_bead -> id = idb;
                     to_fill_strand -> f_bead = first_bead;
                     //current_bead = first_bead;
                     break;
                  }
                  else//jakies porownaia bidow w nie pustym sznurze
                  {
                     Bead* new_bead = new Bead;
                     new_bead -> id = idb;
                     current_bead = to_fill_strand -> f_bead;
                     if(current_bead -> next_bead == NULL) // tu jest tylko jeden bead
                     {
                        if(current_bead -> id > new_bead -> id)
                        {
                           new_bead -> next_bead = current_bead;// next bead od new bead to f bead
                           to_fill_strand -> f_bead = new_bead;
                        }
                        else
                        {
                           current_bead -> next_bead = new_bead;
                        }
                     }
                     else
                     {
                        current_bead = to_fill_strand -> f_bead;
                        bool is_last = 1;
                        while(current_bead != NULL)
                        {
                           if (current_bead -> id > new_bead -> id)
                           {
                              is_last = 0;
                              Bead* temp_bead = to_fill_strand -> f_bead;
                              if(temp_bead == current_bead)
                              {
                                 first_bead = to_fill_strand -> f_bead;
                                 new_bead -> next_bead = first_bead;
                                 to_fill_strand -> f_bead = new_bead;
                                 break;
                              }
                              else
                              {
                                 while(temp_bead -> next_bead != current_bead)
                                 {
                                    temp_bead = temp_bead -> next_bead;
                                 }
                                 temp_bead -> next_bead = new_bead;
                                 new_bead -> next_bead = current_bead;
                                 break;
                              }
                           }
                           current_bead = current_bead -> next_bead;
                        }
                        if(is_last)
                        {
                           new_bead -> next_bead = NULL;
                           Bead* temp = to_fill_strand -> f_bead;
                           while(temp -> next_bead != NULL)
                           {
                              temp = temp -> next_bead;
                           }
                           temp -> next_bead = new_bead;
                        }

                     }

                  }
               }
               to_fill_strand = to_fill_strand -> next_strand;
            }
         }
         else if(to_do == 'L')
         {
            int sk;
            cin >> sk;
            char i1_1, i1_2, i1_3;
            cin >> i1_1 >> i1_2 >> i1_3;
            int dk;
            cin >> dk;
            char i2_1, i2_2, i2_3;
            cin >> i2_1 >> i2_2 >> i2_3;
            Strand* from_strand = first_strand;
            while(from_strand != NULL)
            {
               if ((i1_1 == from_strand -> id1) &&  (i1_2 == from_strand -> id2) && (i1_3 == from_strand -> id3))
               {
                  Bead* from_bead = from_strand -> f_bead;
                  while(from_bead != NULL)
                  {
                     if(from_bead -> id == sk)
                     {
                        Strand* to_strand = first_strand;
                        while(to_strand != NULL)
                        {
                           if ((i2_1 == to_strand -> id1) &&  (i2_2 == to_strand -> id2) && (i2_3 == to_strand -> id3))
                           {
                              break;
                           }
                           to_strand = to_strand -> next_strand;
                        }
                        Bead* to_bead = to_strand -> f_bead;
                        while(to_bead != NULL)
                        {
                           if(to_bead -> id == dk)
                           {
                              break;
                           }
                           to_bead = to_bead -> next_bead;
                        }
                        if(from_bead -> link_from == NULL)
                        {
                           first_link = new Link;
                           first_link -> strand_id1 = i2_1;
                           first_link -> strand_id2 = i2_2;
                           first_link -> strand_id3 = i2_3;
                           first_link -> to_bead_id = dk;
                           from_bead -> link_from = first_link;
                        }
                        else
                        {
                           Link* new_link = new Link;
                           new_link -> strand_id1 = i2_1;
                           new_link -> strand_id2 = i2_2;
                           new_link -> strand_id3 = i2_3;
                           new_link -> to_bead_id = dk;
                           current_link = from_bead -> link_from;
                           if(current_link -> next_link == NULL)
                           {
                              if(is_later(new_link, current_link)) //new po current
                              {
                                 current_link -> next_link = new_link;
                              }
                              else
                              {
                                 new_link -> next_link = current_link;
                                 from_bead -> link_from = new_link;
                                 first_link = from_bead -> link_from;
                              }
                           }
                           else // tu jest problem mmoze
                           {
                              current_link = from_bead -> link_from; //na pierwszy
                              bool last = 1;
                              while(current_link != NULL) //dopoki jest jakis current link
                              {
                                 if(is_later(current_link, new_link)) //cz current jest po new link
                                 {
                                    last = 0;
                                    Link* temp_link = from_bead -> link_from;
                                    if(temp_link == current_link) //temp jest pierwszy
                                    {
                                       first_link = from_bead -> link_from;
                                       new_link -> next_link = first_link;
                                       from_bead -> link_from = new_link;
                                       first_link = from_bead -> link_from;
                                       break;
                                    }
                                    else
                                    {
                                       while(temp_link -> next_link != current_link)
                                       {
                                          temp_link = temp_link -> next_link;
                                       }
                                       temp_link -> next_link = new_link;
                                       new_link -> next_link = current_link;
                                       break;
                                    }
                                 }
                                 current_link = current_link -> next_link;
                              }
                              if(last)
                              {
                                 new_link -> next_link = NULL;
                                 Link* tlink = from_bead -> link_from;
                                 while(tlink -> next_link != NULL)
                                 {
                                    tlink = tlink -> next_link;
                                 }
                                 tlink -> next_link = new_link;
                              }
                           }
                        }
                        break;
                     }
                     else
                     {
                        from_bead = from_bead -> next_bead;
                     }
                  }
                  break;
               }
               else
               {
                  from_strand = from_strand -> next_strand;
               }
            }
         }
         else if(to_do == 'U')
         {
            int sk;
            cin >> sk;
            char i1_1, i1_2, i1_3;
            cin >> i1_1 >> i1_2 >> i1_3;
            int dk;
            cin >> dk;
            char i2_1, i2_2, i2_3;
            cin >> i2_1 >> i2_2 >> i2_3;
            Strand* from_strand = first_strand;
            Bead* from_bead = NULL;
            while(from_strand != NULL)
            {
               if ((i1_1 == from_strand -> id1) &&  (i1_2 == from_strand -> id2) && (i1_3 == from_strand -> id3))
               {
                  from_bead = from_strand -> f_bead;
                  while(from_bead != NULL)
                  {
                     if(from_bead -> id == sk)
                     {
                        if(from_bead -> link_from != NULL)
                        {
                           Link* temp_l = NULL;
                           temp_l = from_bead -> link_from;
                           while(temp_l != NULL)
                           {
                              if ((i2_1 == temp_l -> strand_id1) &&  (i2_2 == temp_l -> strand_id2) && (i2_3 == temp_l -> strand_id3) && (dk == temp_l -> to_bead_id))
                              {
                                 if(temp_l -> next_link != NULL)
                                 {
                                    if(temp_l == from_bead -> link_from)
                                    {
                                       from_bead -> link_from = temp_l -> next_link;
                                       delete temp_l;
                                       temp_l = NULL;
                                    }
                                    else
                                    {
                                       Link* templ = NULL;
                                       templ = from_bead -> link_from;
                                       while(templ -> next_link != temp_l)
                                       {
                                          templ = templ -> next_link;
                                       }
                                       templ -> next_link = temp_l -> next_link;
                                       delete temp_l;
                                       temp_l = NULL;
                                    }
                                 }
                                 else
                                 {
                                    temp_l = from_bead ->link_from;
                                    if(temp_l -> next_link != NULL)
                                    {
                                       while(temp_l ->next_link ->next_link != NULL)
                                       {
                                          temp_l = temp_l ->next_link;
                                       }
                                       delete temp_l ->next_link;
                                       temp_l -> next_link= NULL;
                                    }
                                    else
                                    {
                                       delete temp_l;
                                       from_bead -> link_from = NULL;
                                    }
                                 }
                                 break;
                              }
                              temp_l = temp_l -> next_link;
                           }
                           break;
                        }
                     }
                     from_bead = from_bead -> next_bead;
                  }
                  break;
               }
               from_strand = from_strand -> next_strand;
            }
         }
         else if(to_do == 'D')
         {
            int k;
            cin >> k;
            char s1, s2, s3;
            cin >>  s1 >> s2 >> s3;
            Strand* from_strand = first_strand;
            Bead* delete_bead = NULL;
            current_strand = first_strand;
            while(current_strand != NULL)
            {
               current_bead = current_strand->f_bead;
               while(current_bead != NULL)
               {
                  current_link = current_bead ->link_from;
                  while(current_link != NULL)
                  {
                     if ((s1 == current_link -> strand_id1) &&  (s2 == current_link -> strand_id2) && (s3 == current_link -> strand_id3) && (k == current_link -> to_bead_id))
                     {
                        Link* temp_l = current_link;
                        if(temp_l -> next_link != NULL) //jezlei temp nie osattai
                        {
                           if(temp_l == current_bead -> link_from)
                           {
                              current_bead -> link_from = temp_l -> next_link;
                              delete temp_l;
                              temp_l = NULL;
                           }
                           else
                           {
                              Link* templ = NULL;
                              templ = current_bead -> link_from;
                              while(templ -> next_link != temp_l)
                              {
                                 templ = templ -> next_link;
                              }
                              templ -> next_link = temp_l -> next_link;
                              delete temp_l;
                              temp_l = NULL;
                           }
                        }
                        else
                        {
                           temp_l = current_bead ->link_from;
                           if(temp_l -> next_link != NULL)
                           {
                              while(temp_l ->next_link ->next_link != NULL)
                              {
                                 temp_l = temp_l ->next_link;
                              }
                              delete temp_l ->next_link;
                              temp_l -> next_link= NULL;
                           }
                           else
                           {
                              delete temp_l;
                              current_bead -> link_from = NULL;
                           }
                        }
                     }
                     current_link = current_link->next_link;
                  }
                  current_bead = current_bead ->next_bead;
               }
               current_strand = current_strand ->next_strand;
            }
            while(from_strand != NULL)
            {
               if ((s1 == from_strand -> id1) &&  (s2 == from_strand -> id2) && (s3 == from_strand -> id3))
               {
                  delete_bead = from_strand -> f_bead;
                  while(delete_bead != NULL)
                  {
                     if(delete_bead -> id == k)
                     {
                        current_link = delete_bead ->link_from;
                        while(current_link != NULL)
                        {
                           Link* tempo = current_link;
                           delete_bead ->link_from = tempo-> next_link;
                           delete tempo;
                           tempo = NULL;

                           current_link = current_link ->next_link;
                        }
                        if(from_strand -> f_bead == delete_bead)
                        {
                           from_strand -> f_bead = delete_bead-> next_bead;
                           delete delete_bead;
                           delete_bead = NULL;
                        }
                        else
                        {
                           Bead* tempo = from_strand -> f_bead;
                           while(tempo -> next_bead !=  delete_bead)
                           {
                              tempo = tempo -> next_bead;
                           }
                           tempo -> next_bead = delete_bead ->next_bead;
                           delete delete_bead;
                           delete_bead = NULL;
                           //delete tempo;
                           tempo = NULL;
                        }
                        break;
                     }
                     delete_bead = delete_bead-> next_bead;
                  }
                  break;
               }
               from_strand = from_strand->next_strand;
            }
         }
         else if(to_do == 'M')
         {
            int k;
            cin >> k;
            char s1_1, s1_2, s1_3; //from
            cin >>  s1_1 >> s1_2 >> s1_3;
            char s2_1, s2_2, s2_3;//to
            cin >>  s2_1 >> s2_2 >> s2_3;
            Strand* to_strand = NULL;
            Bead* to_bead = NULL;
            current_strand = first_strand;
            while(current_strand != NULL) //tworzymy nowy bead
            {
               if ((s2_1 == current_strand ->id1) &&  (s2_2 == current_strand ->id2) && (s2_3 == current_strand ->id3))
               {
                  to_strand = current_strand;
                  if(current_strand -> f_bead == NULL)
                  {
                     first_bead = new Bead;
                     first_bead -> id = k;
                     current_strand -> f_bead = first_bead;
                     to_bead = current_strand -> f_bead;
                  }
                  else
                  {
                     Bead* new_bead = new Bead;
                     new_bead -> id = k;
                     current_bead = current_strand -> f_bead;
                     if(current_bead -> next_bead == NULL) // tu jest tylko jeden bead
                     {
                        if(current_bead -> id > new_bead -> id)
                        {
                           new_bead -> next_bead = current_bead;// next bead od new bead to f bead
                           current_strand -> f_bead = new_bead;
                           to_bead = current_strand -> f_bead;
                        }
                        else
                        {
                           current_bead -> next_bead = new_bead;
                           to_bead = new_bead;
                        }
                     }
                     else
                     {
                        current_bead = current_strand -> f_bead;
                        bool is_last = 1;
                        while(current_bead != NULL)
                        {
                           if (current_bead -> id > new_bead -> id)
                           {
                              is_last = 0;
                              Bead* temp_bead = current_strand -> f_bead;
                              if(temp_bead == current_bead)
                              {
                                 first_bead = current_strand -> f_bead;
                                 new_bead -> next_bead = first_bead;
                                 current_strand -> f_bead = new_bead;
                                 to_bead = current_strand -> f_bead;
                                 break;
                              }
                              else
                              {
                                 while(temp_bead -> next_bead != current_bead)
                                 {
                                    temp_bead = temp_bead -> next_bead;
                                 }
                                 temp_bead -> next_bead = new_bead;
                                 new_bead -> next_bead = current_bead;
                                 to_bead = new_bead;
                                 break;
                              }
                           }
                           current_bead = current_bead -> next_bead;
                        }
                        if(is_last)
                        {
                           new_bead -> next_bead = NULL;
                           Bead* temp = current_strand -> f_bead;
                           while(temp -> next_bead != NULL)
                           {
                              temp = temp -> next_bead;
                           }
                           temp -> next_bead = new_bead;
                           to_bead = new_bead;
                        }
                     }
                  }
                  current_strand = first_strand;
                  while(current_strand != NULL) //przepisanie wizan //t probken
                  {
                     if ((s1_1 == current_strand ->id1) &&  (s1_2 == current_strand ->id2) && (s1_3 == current_strand ->id3))
                     {
                        current_bead = current_strand ->f_bead;
                        while(current_bead != NULL)
                        {
                           if(current_bead ->id == k)
                           {
                              current_link = current_bead -> link_from;
                              while(current_link != NULL) //przepisanie wiazan
                              {
                                 current_link = current_bead -> link_from;
                                 if(to_bead -> link_from == NULL)
                                 {
                                    first_link = new Link;
                                    first_link -> strand_id1 = current_link->strand_id1;
                                    first_link -> strand_id2 = current_link->strand_id2;
                                    first_link -> strand_id3 = current_link->strand_id3;
                                    first_link -> to_bead_id = current_link->to_bead_id;
                                    to_bead -> link_from = first_link;
                                 }
                                 else
                                 {
                                    Link* new_link = new Link;
                                    Link* c_link = NULL;
                                    new_link -> strand_id1 = current_link->strand_id1;
                                    new_link -> strand_id2 = current_link->strand_id2;
                                    new_link -> strand_id3 = current_link->strand_id3;
                                    new_link -> to_bead_id = current_link->to_bead_id;
                                    c_link = to_bead -> link_from;
                                    if(c_link -> next_link == NULL)
                                    {
                                       if(is_later(new_link, c_link)) //new po current
                                       {
                                          c_link -> next_link = new_link;
                                       }
                                       else
                                       {
                                          new_link -> next_link = c_link;
                                          to_bead -> link_from = new_link;
                                          first_link = to_bead -> link_from;
                                       }
                                    }
                                    else
                                    {
                                       c_link = to_bead -> link_from; //na pierwszy
                                       bool last = 1;
                                       while(c_link != NULL) //dopoki jest jakis current link
                                       {
                                          if(is_later(c_link, new_link)) //cz current jest po new link
                                          {
                                             last = 0;
                                             Link* temp_link = to_bead -> link_from;
                                             if(temp_link == c_link) //temp jest pierwszy
                                             {
                                                first_link = to_bead -> link_from;
                                                new_link -> next_link = first_link;
                                                to_bead -> link_from = new_link;
                                                first_link = to_bead -> link_from;
                                                break;
                                             }
                                             else
                                             {
                                                while(temp_link -> next_link != c_link)
                                                {
                                                   temp_link = temp_link -> next_link;
                                                }
                                                temp_link -> next_link = new_link;
                                                new_link -> next_link = c_link;
                                                break;
                                             }
                                          }
                                          c_link = c_link -> next_link;
                                       }
                                       if(last)
                                       {
                                          new_link -> next_link = NULL;
                                          Link* tlink = to_bead -> link_from;
                                          while(tlink -> next_link != NULL)
                                          {
                                             tlink = tlink -> next_link;
                                          }
                                          tlink -> next_link = new_link;
                                       }
                                    }
                                 }
                                 Link* tempo = current_link;
                                 current_bead ->link_from = tempo-> next_link;
                                 delete tempo;
                                 tempo = NULL;
                                 current_link = current_link->next_link;
                              }
                              if(current_strand -> f_bead == current_bead)
                              {
                                 current_strand -> f_bead = current_bead-> next_bead;
                                 delete current_bead;
                                 current_bead = NULL;
                              }
                              else
                              {
                                 Bead* tempo = current_strand -> f_bead;
                                 while(tempo -> next_bead !=  current_bead)
                                 {
                                    tempo = tempo -> next_bead;
                                 }
                                 tempo -> next_bead = current_bead ->next_bead;
                                 delete current_bead;
                                 current_bead = NULL;
                                 //delete tempo;
                                 tempo = NULL;
                              }
                              break;
                           }
                           current_bead = current_bead ->next_bead;
                        }
                        break;
                     }
                     current_strand = current_strand -> next_strand;
                  }
                  break;
               }
               current_strand = current_strand -> next_strand;
            }

         }
         else if(to_do == 'R')
         {
            char s1, s2, s3;
            cin >>  s1 >> s2 >> s3;
            Strand* delete_strand = first_strand;
            Bead* delete_bead = NULL;
            current_strand = first_strand;
            while(current_strand != NULL) //usuwanie wiazan
            {
               current_bead = current_strand->f_bead;
               while(current_bead != NULL)
               {
                  current_link = current_bead ->link_from;
                  while(current_link != NULL)
                  {
                     if ((s1 == current_link -> strand_id1) &&  (s2 == current_link -> strand_id2) && (s3 == current_link -> strand_id3))
                     {
                        Link* temp_l = current_link;
                        if(temp_l -> next_link != NULL) //jezlei temp nie osattai
                        {
                           if(temp_l == current_bead -> link_from)
                           {
                              current_bead -> link_from = temp_l -> next_link;
                              delete temp_l;
                              temp_l = NULL;
                           }
                           else
                           {
                              Link* templ = NULL;
                              templ = current_bead -> link_from;
                              while(templ -> next_link != temp_l)
                              {
                                 templ = templ -> next_link;
                              }
                              templ -> next_link = temp_l -> next_link;
                              delete temp_l;
                              temp_l = NULL;
                           }
                        }
                        else
                        {
                           temp_l = current_bead ->link_from;
                           if(temp_l -> next_link != NULL)
                           {
                              while(temp_l ->next_link ->next_link != NULL)
                              {
                                 temp_l = temp_l ->next_link;
                              }
                              delete temp_l ->next_link;
                              temp_l -> next_link= NULL;
                           }
                           else
                           {
                              delete temp_l;
                              current_bead -> link_from = NULL;
                           }
                        }
                     }
                     current_link = current_link->next_link;
                  }
                  current_bead = current_bead ->next_bead;
               }
               current_strand = current_strand ->next_strand;
            }
            while(delete_strand != NULL)
            {
               if ((s1 == delete_strand -> id1) &&  (s2 == delete_strand -> id2) && (s3 == delete_strand -> id3))
               {
                  current_bead = delete_strand -> f_bead;
                  while(current_bead != NULL)
                  {
                     current_link = current_bead ->link_from;
                     while(current_link != NULL)
                     {
                        Link* tempo = current_link;
                        current_bead ->link_from = tempo-> next_link;
                        delete tempo;
                        tempo = NULL;
                        current_link = current_link ->next_link;
                     }
                     delete_strand -> f_bead = current_bead-> next_bead;
                     delete_bead = current_bead;
                     delete delete_bead;
                     delete_bead = NULL;
                     current_bead = current_bead-> next_bead;
                  }
                  if(delete_strand == first_strand)
                  {
                     first_strand = delete_strand ->next_strand;
                     delete delete_strand;
                     delete_strand = NULL;
                  }
                  else
                  {
                     Strand* tempo = first_strand;
                     while(tempo -> next_strand != delete_strand)
                     {
                        tempo = tempo -> next_strand;
                     }
                     tempo -> next_strand = delete_strand ->next_strand;
                     delete delete_strand;
                     delete_strand = NULL;
                     //delete tempo;
                     tempo = NULL;
                  }
                  break;
               }
               delete_strand = delete_strand->next_strand;
            }
         }
         else if(to_do == 'P')
         {
            current_strand = first_strand;
            while (current_strand != NULL)
            {
               cout << current_strand -> id1 << current_strand -> id2 << current_strand -> id3 << endl;
               if(current_strand -> f_bead != NULL)
               {
                  current_bead = current_strand -> f_bead;
                  while(current_bead != NULL)
                  {
                     cout << current_bead -> id;
                     if(current_bead -> link_from != NULL)
                     {
                        current_link = current_bead -> link_from;
                        while(current_link != NULL)
                        {
                           cout << " " << current_link ->strand_id1 << current_link ->strand_id2 << current_link ->strand_id3 << " " << current_link -> to_bead_id;
                           current_link = current_link -> next_link;
                        }
                     }
                     cout << endl;
                     current_bead = current_bead -> next_bead;
                  }
               }
               current_strand = current_strand -> next_strand;
            }
         }
      cin >> to_do;
   }
   current_strand = first_strand;
	Strand* to_delete = NULL;

	while (current_strand != NULL)
   {
      if(current_strand -> f_bead != NULL)
      {
         current_bead = current_strand -> f_bead;
         Bead* b_delate = NULL;
         while(current_bead != NULL)
         {
            if(current_bead -> link_from != NULL)
            {
               current_link = current_bead -> link_from;
               Link* l_delete = NULL;
               while(current_link != NULL)
               {
                  l_delete = current_link;
                  current_link = current_link -> next_link;
                  delete l_delete;
               }
               current_bead -> link_from = NULL;
            }
            b_delate = current_bead;
            current_bead = current_bead -> next_bead;
            delete b_delate;
         }
         current_strand -> f_bead = NULL;
      }
		to_delete = current_strand;
		current_strand = current_strand -> next_strand;
		delete to_delete;
	}

	first_strand = NULL;
   first_bead = NULL;
   first_link = NULL;
}

