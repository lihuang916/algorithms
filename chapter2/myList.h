/* myList.h 
 * Linked list
 */

struct Node {
  int data;
  Node* next;
};

class MyList {
 public:
  MyList();
  MyList(const MyList& list); 
  MyList(int data, unsigned int len);
  ~MyList();
  
  unsigned int size() const;
  
  int getAt(unsigned int index) const;

  void pushFront(int data);

  void pushBack(int data);

  int popFront();

  int popBack();

  void insertAt(unsigned int index);
  
  void removeAt(unsigned int index);

  MyList rmDup();

  void sort(bool isAscend);
  
  MyList subList(unsigned int pos = 0, unsigned int len = -1) const;
  
  bool isCircular();

  Node* loopStartAt();

  void printList() const;
  
 private:
  Node* _head;
  unsigned int _size;
};
