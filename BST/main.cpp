#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;
struct Elem { //node declaration
   public:
      int k;
   Elem *l, *r;
   bool rightTh;
};

struct T {
  public: string name;
};

struct Key {
   public: int value;
};



   void destructCode(Elem * &root) { //clear tree
      root= new Elem();
      root->r = root;
      root->rightTh = true;
      root->l = NULL;
      root->k = MAX_VALUE;
   }

   bool insert(Elem * &root, T *t,Key *key, Elem *lastLeft) {
      Elem *p = root;
      for (;;) {
         if (p->k < key->value) {
            if (p->rightTh)
               break;
            p = p->r;
         } else if (p->k > key->value) {
            if (p->l == NULL)
               break;
            p = p->l;
         } else {
            return false;
         }
      }
      Elem *temp = new Elem();
      temp->k = key->value;
      temp->rightTh = true;
      temp->l = NULL;
      if (p->k < key->value) {
         temp->r = p->r;
         temp->l = NULL;
         p->r = temp;
         p->rightTh = false;
      } else {
         temp->r = p;
         temp->l = p->l;
         p->l = temp;
      }
      return true;
   }

void printTree(Elem *root) { //print the tree
   Elem *temp = root, *p;
   for (;;) {
      p = temp;
      temp = temp->r ;
      if (!p->rightTh) {
         while (temp->l != NULL) {
            temp = temp->l;
         }
      }
      if (temp == root)
         break;
      cout<<temp->k<<" ";
   }
   cout<<endl;
 }

int main() {
   cout<<"RightThreadedBinaryTree\n";
   int c, v;
   Elem *root = new Elem();
      root->r= root;
      root->l= NULL;
      root->k = MAX_VALUE;
    T *t = new T();
    Key *key = new Key();
    Elem *lastLeft = NULL;
   while(1) {
      cout<<"1. Insert "<<endl;
      cout<<"2. Display"<<endl;
      cout<<"3. DestructCode"<<endl;
      cout<<"4. Exit"<<endl;
      cout<<"Enter Your Choice: ";
      cin>>c;
      //perform switch operation
      switch (c) {
         case 1 :
            cout<<"Enter integer element to insert: ";
            cin>>v;
            key->value = v;
            if (insert(root,t, key, lastLeft)) {
                cout<<"Element added successfully \n";
            } else cout<<"something went wrong \n";
            break;

         case 2:
            cout<<"Display tree: \n ";
            printTree(root);
            break;

        case 3:
            cout<<"Destroy tree: \n ";
            destructCode(root);
            break;

         case 4:
            exit(1);
         default:
            cout<<"\nInvalid type! \n";
      }
   }
   cout<<"\n";
   return 0;
}
