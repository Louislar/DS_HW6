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


/***************** start from here ********************/

void dfs(int vertice, int out[])
{

}


int main()
{
    /*chainNode* graph[8];*/


    int x;
    cin>>x;                  //how many test data
    for(int i=0;i<x;i++)
    {
        int n;              //  vertice
        int k;              //  edge
        cin>>n;
        cin>>k;
        chainNode* graph[n+1];  //  vertices number start from 1
        for(int l=0;l<n+1;l++) graph[l]=0; //initial

        for(int j=0;j<k;j++)//  input k edges
        {
            int temp1;
            int temp2;
            cin>>temp1;
            cin>>temp2;

            chainNode* cur1=graph[temp1];
            for(;cur1->link!=0;cur1=cur1->link);
            cur1=new chainNode(temp2, 0);

            chainNode* cur2=graph[temp2];
            for(;cur2->link!=0;cur2=cur2->link);
            cur2=new chainNode(temp1, 0);
        }

        //dfs
        int out[n+1];
        for(int l=0;l<n+1;l++) out[l]=0; //initial




    }// x for end
}
