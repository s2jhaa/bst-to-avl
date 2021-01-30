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

struct avl {
   int d;
   struct avl *l;
   struct avl *r;
}*r;


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


void displayTree(Elem *root) { //print the tree
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


 class avl_tree {
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl*);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, int);
      void show(avl*, int);
      void preorder(avl *);
      void postorder(avl*);
      avl_tree() {
         r = NULL;
      }
};
int avl_tree::height(avl *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation \n";
   return rr_rotat(parent);
}
avl *avl_tree::balance(avl *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl *r, int v) {
   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->l = NULL;
      r->r = NULL;
      return r;
   } else if (v< r->d) {
      r->l = insert(r->l, v);
      r = balance(r);
   } else if (v >= r->d) {
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::show(avl *p, int l) {
   int i;
   if (p != NULL) {
      show(p->r, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->d;
         show(p->l, l + 1);
   }
}

void avl_tree::preorder(avl *t) {
   if (t == NULL)
      return;
      cout << t->d << " ";
      preorder(t->l);
      preorder(t->r);
}
void avl_tree::postorder(avl *t) {
   if (t == NULL)
      return;
      postorder(t ->l);
      postorder(t ->r);
      cout << t->d << " ";
}

 avl* convertTree(Elem *root, avl_tree avl) { //print the tree
   Elem *temp = root, *p;
//   avl_tree avl;

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
    //   cout<<temp->k<<" ";

      r = avl.insert(r, temp->k);
   }
   return r;
//   cout<<endl;
 }



int main() {
   int c, v;
   Elem *root = new Elem();
      root->r= root;
      root->l= NULL;
      root->k = MAX_VALUE;
    T *t = new T();
    Key *key = new Key();
    Elem *lastLeft = NULL;
    avl_tree avl;


     while(1) {
      cout<<"1. Insert "<<endl;
      cout<<"2. Display"<<endl;
      cout<<"3. DestructCode"<<endl;
      cout<<"4. ConvertTree"<<endl;
      cout<<"5. Show Balanced AVL Tree" << endl;
      cout<<"6. Exit"<< endl;
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
            displayTree(root);
            break;

        case 3:
            cout<<"Destroy tree: \n ";
            destructCode(root);
            break;

        case 4:
            cout<<"Convert tree: \n ";
            r = convertTree(root, avl);
            break;

        case 5:
            if (r == NULL) {
              cout << "Tree is Empty" << endl;
              continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(r, 1);
            cout<<endl;
            break;
        case 6:
            exit(1);
        default:
            cout<<"\nInvalid type! \n";
      }
   }
   cout<<"\n";
   return 0;
}
