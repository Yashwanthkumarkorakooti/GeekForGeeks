class MyStack {
  private:
    StackNode *top;

  public:
    bool empty(){
        return top == nullptr ;
    }
    void push(int x) {
        StackNode* temp = new StackNode(x);
        temp->next = top ;
        top = temp ;
    }

    int pop() {
        if(empty()) return -1 ;
        
        int poppedValue = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    MyStack() { top = NULL; }
};