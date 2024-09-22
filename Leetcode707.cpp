#include <bits/stdc++.h>

using namespace std;

class DNode
{
    private:
        int data;
        DNode* frontNode;
        DNode* backNode;

    public:
        DNode()
        {
            frontNode = backNode = nullptr;
        }

        void SetData(int temp = 0)
        {
            data = temp;
        }

        int GetData()
        {
            return data;
        }

        void SetPrior(DNode* temp)
        {
            frontNode = temp;
        }

        void SetNext(DNode* temp)
        {
            backNode = temp;
        }

        DNode* GetPrior()
        {
            return frontNode;
        }

        DNode* GetNext()
        {
            return backNode;
        }
};

class MyLinkedList 
{
    private:
        int length;
        DNode* headNode;
        DNode* tailNode;

    public:

    MyLinkedList() 
    {
        length = 0;
        headNode = tailNode = nullptr;
        CreatList();
    }
    
    void CreatList()
    {
        headNode = new DNode;
        tailNode = new DNode;

        headNode->SetNext(tailNode);
        tailNode->SetPrior(headNode);
    }

    DNode* GetNode(int pos = 0)
    {
            if(pos < 0 || pos >= length)
                return NULL;

            auto temp = headNode->GetNext();
            int myPos = 0;

            while(myPos < pos)
            {
                temp = temp->GetNext();
                myPos++;
            }

            return temp;
    }
    
    int get(int index) 
    {
        auto temp = GetNode(index);
        return ((temp != NULL) ? temp->GetData() : -1);
    }
    
    void addAtHead(int data) 
    {
        auto temp = new DNode;
        temp->SetData(data);

        auto lastNode = headNode->GetNext();

        temp->SetNext(lastNode);
        lastNode->SetPrior(temp);
        temp->SetPrior(headNode);
        headNode->SetNext(temp);

        length++;
    }
    
    void addAtTail(int data) 
    {
        auto temp = new DNode;
        temp->SetData(data);

        auto lastNode = tailNode->GetPrior();

        temp->SetPrior(lastNode);
        lastNode->SetNext(temp);
        temp->SetNext(tailNode);
        tailNode->SetPrior(temp);

        length++;
    }
    
    void addAtIndex(int pos, int data) 
    {
        if(pos == length)
        {
            addAtTail(data);
            return;
        }

        auto nextNode = GetNode(pos);

        if(nextNode == NULL)
                return ;
            
        auto priorNode = nextNode->GetPrior();

        DNode* temp = new DNode;
        temp->SetData(data);
        temp->SetPrior(priorNode);
        temp->SetNext(nextNode);
        priorNode->SetNext(temp);
        nextNode->SetPrior(temp);

        length++;

        //return true;
    }
    
    void deleteAtIndex(int pos) 
    {
        auto Node = GetNode(pos);

        if(Node == NULL)
            return ;

        auto nextNode = Node->GetNext(), priorNdoe = Node->GetPrior();

        nextNode->SetPrior(priorNdoe), priorNdoe->SetNext(nextNode);

        delete(Node);

        length --;

        //return true;
    }
};