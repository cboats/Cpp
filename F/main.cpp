#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "BST.h"



int main() {
    srand (time(NULL));
    const int tries=1000;
    const int tries1=tries*10;
    for(int i = 0; i < tries; i ++){
        BST<int,int>* bst = new BST<int,int>();
        for(int j = 0; j<tries1; j++){
            bst->Insert(rand()%tries1+1,rand()%tries1+1);
        }
        for(int j = 0; j<tries1; j++){
            bst->Delete(rand()%tries1+1);
        }
        delete bst;
    }

}



