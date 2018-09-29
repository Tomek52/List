#pragma once
#include "Node.hpp"
#include <memory>

template<class T>
class List
{
    private:
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
    public:
        List();
        void add(std::shared_ptr<Node<T>> node);
        std::shared_ptr<Node<T>> getHead() const;
        std::shared_ptr<Node<T>> getTail() const;
        std::shared_ptr<Node<T>> find(const T& value);
};

template <class T>
List<T>::List()
    : head(nullptr)
    , tail(nullptr)
{}

template <class T>
void List<T>::add(std::shared_ptr<Node<T>> node)
{
    if(head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

template <class T>
std::shared_ptr<Node<T>> List<T>::getHead() const
{
    return head;
}

template <class T>
std::shared_ptr<Node<T>> List<T>::getTail() const
{
    return tail;
}

template <class T>
std::shared_ptr<Node<T>> List<T>::find(const T& value)
{
    auto iter = head;
    while(iter != tail)
    {
        if (iter->value == value) return iter;
        else iter = iter->next;
    }
    return nullptr;
}
