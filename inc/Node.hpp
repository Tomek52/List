#pragma once
#include <memory>

template<class T>
class Node
{
    T value;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;

    explicit Node(const T& val);
};

template <class T>
Node<T>::Node(const T& val)
    : next(nullptr)
    , value(val)
{}
