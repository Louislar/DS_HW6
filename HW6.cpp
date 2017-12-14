#include<iostream>

using namespace std;

class chainNode
{
public:
    chainNode()
    {
        data=0;
        link=0;
    }
    chainNode(int e, chainNode* n=0)
    {
        data=e;
        link=n;
    }
    int data;
    chainNode* link;
};


int main()
{
    chainNode* graph[8];

    //input

}
