#include <iostream>
#include <conio.h>
#include <iomanip>

template<class QT>

class Queue
{
private:
    List<QT> q;

public:
    void enqueue(const QT &data)
    {
        q.insertAtBack(data);
    }
    bool dequeue(QT &data)
    {
        return q.removeFromFront(data);
    }
    bool isQueueEmpty() const
    {
        return q.isEmpty();
    }
    void printqueue() const
    {
        q.print();
    }
};

//inheratance for class queue
class Queue : private List<QT>
{
public:
    void enqueuer(const QT &data)
    {
        insertAtBack(data);
    }
    bool dequeuer(QT &data)
    {
        return removeFromFront(data);
    }
    bool isQueueEmpty() const
    {
        return isEmpty();
    }
    void printqueue() const
    {
        print();
    }
}