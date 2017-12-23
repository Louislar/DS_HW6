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

void dfs(int vertice, chainNode* graph[]
         , int out[], int& outLength, int visited[]
         , int black[])
{
    out[outLength]=vertice;
    outLength++;
    visited[vertice]=1;
    //cout<<vertice<<endl;
    /**********make black**********/
    chainNode* black_cur=graph[vertice];
    int cannotBlack=0;
    for(;black_cur;black_cur=black_cur->link)
    {
        if(black[black_cur->data]==1)
            cannotBlack=1;
    }
    if(!cannotBlack) black[vertice]=1;

    /**********make black-end**********/

    chainNode* cur=graph[vertice];
    for(;cur;cur=cur->link)
    {
        if(!visited[cur->data])
            dfs(cur->data, graph, out, outLength, visited, black);
    }
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
    /*cout<<"\nx: ";
    cout<<x<<endl;*/
    for(int y=0;y<x;y++)
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
        int outLength=0;
        int visited[n+1];
        int black[n+1];
        int blacknum=0;
        for(int l=0;l<n+1;l++) out[l]=0; //initial
        for(int l=0;l<n+1;l++) visited[l]=0; //initial
        for(int l=0;l<n+1;l++) black[l]=0; //initial

        for(int q=1;q<n+1;q++){
        int blackTemp[n+1];
        int blackTempnum=0;
        for(int l=0;l<n+1;l++) blackTemp[l]=0; //initial

        dfs(q, graph, out, outLength, visited, blackTemp);

        {//if separate graph
            for(int l=1;l<n+1;l++)
            {
                if(visited[l]==0)
                    dfs(l, graph, out, outLength, visited, blackTemp);
            }

        }
        //count blacknum
        for(int l=0;l<n+1;l++)
        {
            if(blackTemp[l]==1)
                blackTempnum++;
        }
        if(blackTempnum>=blacknum)
        {
            blacknum=blackTempnum;
            for(int l=0;l<n+1;l++)
                black[l]=blackTemp[l];
        }

        /**********initial**********/
        for(int l=0;l<n+1;l++) out[l]=0; //initial
        for(int l=0;l<n+1;l++) visited[l]=0; //initial
        outLength=0;
        }//for q end

        /*********output**********/
        cout<<blacknum<<endl;
        for(int l=1;l<n+1;l++)
        {
            if(black[l]==1)
                cout<<l<<" ";
        }
        cout<<endl;

        /**********out[]-test*********/
        /*cout<<"out[]: ";
        for(int l=0;l<outLength;l++)
            cout<<out[l]<<" ";
        cout<<endl;*/

        /**********black[]-test*********/
        /*cout<<"black[]: ";
        for(int l=1;l<n+1;l++)
            cout<<black[l]<<" ";
        cout<<endl;*/




    }// y for end
}
