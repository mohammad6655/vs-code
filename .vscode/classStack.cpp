

template <class ST>

class Stack
{
private:
    List<ST> s;

public:
    void push(const ST &data)
    {
        s.insertAtFront(data);
    }
    bool pop(ST &data)
    {
        return s.removeFromFront(data);
    }
    bool isStackEmpty() const
    {
        return s.isEmpty();
    }
    void printStack() const
    {
        s.print();
    }
};


// inheratance for stack
class Stack : private list<ST>
{
public:
    void push(const ST &data)
    {
        insertAtFront(data);
    }
    bool pop(ST &data)
    {
        return removeFromFront(data);
    }
    bool isStackEmpty() const
    {
        return isEmpty();
    }
    void printStack() const
    {
        print();
    }
}