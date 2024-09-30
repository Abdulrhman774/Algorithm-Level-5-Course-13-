#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
     T _Size = 0;
     
public:

    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;

        Node(T data)
        {
            value = data;
            next = prev = NULL;
        }

    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {
        Node* new_node = new Node(value);

        new_node->next = head;         
        new_node->prev = NULL;         
                                       
        if (head != NULL)              
            head->prev = new_node;     
                                       
        head = new_node;               
                                                                              
        _Size++;                       
    }                                  
                                       
                                       
    Node* Find(T value)                
    {
        Node* Current = head;

        while (Current != NULL)
        {
            if (Current->value == value)
                return Current;

            Current = Current->next;
        }
        return NULL;
    }


    void InsertAfter(Node* prev_node, T value)
    {
        if (prev_node == NULL) return;

        Node* new_node = new Node(value);

        new_node->next = prev_node->next;
        if (prev_node->next != NULL) prev_node->next->prev = new_node;
        prev_node->next = new_node;
        new_node->prev = prev_node;
        _Size++;
    }


    void InsertAtEnd(T value)
    {
        Node* last_node = head;

        // Creat new node.
        Node* new_node = new Node(value);
        new_node->next = NULL;

        if (head == NULL)
        {
            new_node->prev = NULL;
            head = new_node;
            _Size++;
            return;
        }


        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        new_node->prev = last_node;
        last_node->next = new_node;

        _Size++;
    }


    void DeleteNode(Node* NodeToDelete)
    {
        if (head == NULL || NodeToDelete == NULL)  return;

        if (head == NodeToDelete)
        {
            head = NodeToDelete->next;
        }

        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }

        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }

        delete NodeToDelete; // free from memory

        _Size--;
    }


    void DeleteFirstNode()
    {
        if (head == NULL)  return;

        Node* temp = head;

        head = head->next;

        if (head != NULL)
            head->prev = nullptr;

        delete temp;

        _Size--;
    }


    void DeleteLastNode()
    {
        Node* current_node = head;
        Node* temp = head;


        if (head == NULL)  return;

        _Size--;

        if (current_node->next == NULL)
        {
            head = NULL;
            delete current_node; // free from memory
            return;
        }

        while (current_node->next->next != NULL)
        {
            temp = current_node;
            current_node = current_node->next;
        }
        temp = current_node->next;
        current_node->next = NULL;
        delete temp; // free from memory
    }


    T Size()
    {
        return _Size;
    }
        

    void Reverse()
    {
        //if (IsEmpty() || head->next == NULL) return;

        Node* Current = head;
        Node* temp = nullptr;

        while (Current != nullptr) {
            temp = Current->prev;
            Current->prev = Current->next;
            Current->next = temp;
            Current = Current->prev;   
        }

        if (temp != nullptr)
            head = temp->prev;
    }                            


    bool IsEmpty()
    {
        return (_Size == 0);
    }


    void Clear()
    {
        Node* Current = head;

        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void PrintList()
    {
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
    }

    //void PrintList()
    /*{
        Node* Current = head;

        cout << "NULL <--> ";
        while (Current != NULL) {
            cout << Current->value << " <--> ";
            Current = Current->next;
        }
        cout << "NULL";

    }*/

    Node* GetNode(T Index)
    {
        T counter = 0;

        if ((Index < 0 || Index >= _Size))
            return NULL;

        Node* Current = head;

        while (Current != NULL && Current->next != NULL) {
            if (Index == counter) return Current;

            Current = Current->next;
            counter++;
        }
    }

    T GetItem(T Item)
    {
        Node* ItemNode = GetNode(Item);

        return (ItemNode != nullptr) ? ItemNode->value : NULL;
    }

    bool UpdateItem(T Item, T NewValue)
    {
        Node* ItemNode = GetNode(Item);

        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        else
            return false;
    }

    bool InsertAfter(T Index, T value)
    {
        Node* prev_node = GetNode(Index);

        if (prev_node == NULL) return false;

        InsertAfter(prev_node, value);
        return true;
    }
};

