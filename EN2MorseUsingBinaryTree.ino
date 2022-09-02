//each node will be part of a binary tree
class Node {
public:
  Node *left;
  Node *right;
  Node(char ch){
    val = ch;
    left = NULL;
    right = NULL;
  }
  bool translate(char searchee);
  void setupTree();
private:
  char val;  
};

// the setup function runs once when you press reset or power the board
int incomingByte = 0; // for incoming serial data
Node* root = new Node('\n');
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  root->setupTree();
}

// the loop function runs over and over again forever
void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    if(incomingByte == ' '){
      delay(2333);//morse code requires 7 unit delay inbetween words
    }
    root->translate(incomingByte);
    delay(1000); //and a 3 unit delay inbetween letters
  }
}

//uses tail end recursion to traverse the tree and then "print" out the morse code once the matching node is found
//@returns true if the searchee has been found, or if any of the nested functions are true
//@params searchee is what to look for ie. 'E'
bool Node::translate(char searchee){    
  if(val == searchee){
    return true;
  }
  if(left != NULL){
    if(left->translate(searchee)){
      digitalWrite(LED_BUILTIN, HIGH);
      delay(333); //1 unit delay
      digitalWrite(LED_BUILTIN, LOW);
      delay(333)
      return true;
    }
  }
  if(right != NULL){
    if(right->translate(searchee)){ 
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);//3 unit delay
      digitalWrite(LED_BUILTIN, LOW);
      delay(333)
      return true;
     }
  }
}

//setup the binary tree we're using for morse code. https://upload.wikimedia.org/wikipedia/commons/1/19/Morse-code-tree.svg
void Node::setupTree(){
  Node* E = new Node('E');
  this->left = E;
  
  Node* I = new Node('I');
  E->left = I;
  
  Node* S = new Node('S'); 
  I->left = S;
  Node* H = new Node('H'); 
  S->left = H;
  Node* five = new Node('5'); //leaf
  Node* four = new Node('4'); //leaf
  H->left = five;
  H->right = four;
  Node* V = new Node('V');
  S->right = V;
  Node* three = new Node('3'); //leaf
  V->right = three;
  
  Node* U = new Node('U'); 
  I->right = U;
  Node* F = new Node('F'); //leaf
  U->left = F;
  Node* blank1 = new Node(' ');
  U->right = blank1;
  Node* two = new Node('2'); //leaf
  blank1->right = two;

  Node* A = new Node('A');
  E->right = A;
  Node* R = new Node('R');
  A->left = R;
  Node* L = new Node('L'); //leaf
  R->left = L;
  Node* blank2 = new Node(' ');
  R->right = blank2;
  Node* plus = new Node('+'); //leaf
  blank2->left = plus;

  Node* W = new Node('W');
  A->right = W;
  Node* P = new Node('P'); //leaf
  W->left = P;
  Node* J = new Node('J');
  W->right = J;
  Node* one = new Node('1'); //leaf
  J->right = one;
  
  
  Node* T = new Node('T');
  this->right = T;

  Node* N = new Node('N');
  T->left = N;
  Node* D = new Node('D');
  N->left = D;
  Node* B = new Node('B');
  D->left = B;
  Node* six = new Node('6');//leaf
  B->left = six;
  Node* equalSign = new Node('=');//leaf
  B->right = equalSign;
  Node* X = new Node('X');
  D->right = X;
  Node* slash = new Node('/');//leaf
  X->left = slash;
  Node* K = new Node('K');
  N->right = K;
  Node* C = new Node('C'); //leaf
  K->left = C; 
  Node* Y = new Node('Y'); //leaf
  K->right = Y;

  Node* M = new Node('M');
  T->right = M;
  Node* G = new Node('G');
  M->left = G;
  Node* Z = new Node('Z');
  G->left = Z;
  Node* seven = new Node('7'); //leaf
  Z->left = seven;
  Node* Q = new Node('Q'); //leaf
  G->right = Q;
  Node* O = new Node('O');
  M->right = O;
  Node* blank3 = new Node(' ');
  O->left = blank3;
  Node* eight = new Node('8'); //leaf
  blank3->left = eight;
  Node* blank4 = new Node(' ');
  O->right = blank4;
  Node* nine = new Node('9'); //leaf
  blank4->left = nine;
  Node* zero = new Node('0');//leaf
  blank4->right = zero;
}
