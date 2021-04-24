

template <class T> class dlist;
template <class T>
class node_iterator
{
public:
    friend class dlist<T>;
    node_iterator(dnode<T> *initial = NULL)
    {
        current = initial;
    } 
    T operator*()
    {
        return current->data();
    }
    node_iterator &operator++()
    {
        current = current->next();
        return *this;
    }
    node_iterator operator++(int)
    {
        node_iterator original(current);
        current = current->next();
        return original;
    }
    bool operator==(const node_iterator other)
    {
        return current == other.current;
    }
    bool operator!=(const node_iterator other)
    {
        return current != other.current;
    }
    node_iterator operator--()
    {
        current = current->previous();
        return *this;
    }
    node_iterator operator--(int)
    {
        node_iterator orginal(current);
        current = current->previous();
        return orginal;
    }

private:
    dnode<T> *current;
};