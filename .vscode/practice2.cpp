

template <class T>

class ListNode
{
    friend class List<T>;

private:
    T data;
    ListNode<T> *next;

public:
    ListNode(const T &);
    T getData() const {return data};
};
ListNode<T>::ListNode(cinst T &info) : data(info), next(0)
{
    // empty body
}

template<class T>
T ListNode<T>::getData()const{
    return data;
}
class List
{
private:
    ListNode<T> *first;
    ListNode<T> *last;
    ListNode<T> *getNewNode(const T &);

public:
    List();
    ~List();
    void insertAtFront(const T &);
    void InsertAtBack(const T &);
    bool removeFromFront(const T &);
    bool removeFromBack(const T &);
    bool isEmpty() const;
    void print() const;
};
List<T>::~List()
{
    if (!isEmpty())
    {
        ListNode<T> *c, *t;
        c = first;
        while (c != 0)
        {
            t = c;
            std::cout << t->data;
            c = c->next;
            delete t;
        }
    }
    std::cout << "All nodes destroyed";
}
List<T>::List() : first(0), last(0)
{
    // empty body
}
bool List<T>::isEmpty() const
{
    return first == 0;
}
ListNode<T> *List<T>::getNewNode(const T &item)
{
    return new ListNode<T>(item);
}

void List<T>::insertAtFront(const T &item)
{
    ListNode<T> *n;
    n = getNewNode(item);

    if (isEmpty())
        first = last = n;

    else
    {
        n->next = fist;
        first = n;
    }
}
void List<T>::insertAtBack(cosnt T &item)
{
    ListNode<T *> n;

    n = getNewNode(item);
    if (isEmpty())
        first = last = n;
    else
    {
        last->next = n;
        last = n;
    }
}
bool List<T>::removeFromFront(T &item)
{
    if (isEmpty())
        return false;
    else
    {
        ListNode<T> *t;
        t = first;
        if (firt == last)
            first = last = 0;
        else
            first = first->next;

        item = t->data;
        delete t;
        return true;
    }
}
bool List<T>::removeFromBack(T &item)
{
    if (isEmpty())
        return false;
    else
    {
        ListNode<T> *t = last;
        if (first == last)
            first = last = 0;
        else
        {
            ListNode<T> *t = first;
            while (t->next != last)
                t = t->next;
            last = t;
            t->next = 0;
        }
        item = t->data;
        delete t;
        return true;
    }
}
void List<T> : print() const
{
    if (isEmpty())
    {
        std::cout << "The list is empty";
        return;
    }
    ListNode<T> *t;
    t = first;

    while (t != 0)
    {
        std::cout << t->data;
        t = t->next;
    }
}