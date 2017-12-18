#include<iostream>
#include<fstream>

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
    /***********file input**********/
    ifstream ifs;
    char filename[100];
    for(int i=0;i<100;i++) filename[i]='\0';
    int filenameLength=0;
    cout<<"Input file name: ";
    {
        char temp;
        while(cin.get(temp))
        {
            if(temp=='\n') break;
            else
            {
                filename[filenameLength]=temp;
                filenameLength++;
            }
        }
    }
    ifs.open(filename, ios::in);






    /*********input********/
    int x;
    ifs>>x;                  //how many test data
    cout<<x<<endl;
    for(int i=0;i<x;i++)
    {
        int n;              //  vertice
        int k;              //  edge
        ifs>>n;
        ifs>>k;
        chainNode* graph[n+1];  //  vertices number start from 1
        for(int l=0;l<n+1;l++) graph[l]=0; //initial

        for(int j=0;j<k;j++)//  input k edges
        {
            int temp1;
            int temp2;
            ifs>>temp1;
            ifs>>temp2;

            chainNode* cur1=graph[temp1];
            if(cur1==0)
            {
                graph[temp1]=new chainNode(temp2, 0);
            }
            else
            {
                for(;cur1->link!=0;cur1=cur1->link);
                cur1->link=new chainNode(temp2, 0);
            }

            chainNode* cur2=graph[temp2];
            if(cur2==0)
            {
                graph[temp2]=new chainNode(temp1, 0);
            }
            else
            {
                for(;cur2->link!=0;cur2=cur2->link);
                cur2->link=new chainNode(temp1, 0);
            }
        }


        /**********input-test**********/
        /*for(int i=1;i<n+1;i++)
        {
            cout<<i<<": ";
            if(graph[i])
            {
                chainNode* cur=graph[i];
                for(;cur;cur=cur->link) cout<<cur->data<<" ";
            }
            cout<<endl;
        }*/

        /**********dfs**********/
        /**********undone**********/
        int out[n+1];
        for(int l=0;l<n+1;l++) out[l]=0; //initial




    }// x for end
}
