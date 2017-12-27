#include<iostream>
#include<fstream>

using namespace std;

class chainNode
{
public:
    chainNode(){
        data=0;
        link=0;
    }
    chainNode(int e, chainNode* l=0)
    {
        data=e;
        link=l;
    }
    int data;
    chainNode* link;
};

void dfs(int vertex, chainNode* graph[], int visited[], int black[]
        , int out[], int& outLength, int& blackNum)
{
    out[outLength]=vertex;
    outLength++;
    visited[vertex]=1;
    chainNode* cur=graph[vertex];

    /************mark black*****************/
    int canBlack=1;
    chainNode* blackcur=graph[vertex];
    for(;blackcur;blackcur=blackcur->link)
    {
        if(black[blackcur->data]==1)
            canBlack=0;
    }
    if(canBlack==1)
    {
        black[vertex]=1;
        blackNum++;
    }


    /************mark black-end*************/

    for(;cur;cur=cur->link)
    {
        if(!visited[cur->data])
            dfs(cur->data, graph, visited, black, out, outLength, blackNum);
    }

}

int main()
{
    //file input
    cout<<"Input file name: ";
    ifstream ifs;
    char filename[100];
    for(int i=0;i<100;i++) filename[i]='\0'; //important
    int filenameLength=0;
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

    int testGroup=0;
    ifs>>testGroup;

    //start
    for(int r=0;r<testGroup;r++){
    int n;
    int k;
    ifs>>n;
    ifs>>k;
    chainNode* adjMatrix[n+1];
    for(int i=0;i<n+1;i++) adjMatrix[i]=0;
    //input edge
    for(int i=0;i<k;i++)
    {
        int p1;
        int p2;
        ifs>>p1;
        ifs>>p2;

        chainNode* cur1=adjMatrix[p1];
        if(cur1==0) adjMatrix[p1]=new chainNode(p2, 0);
        else
        {
            for(;cur1->link;cur1=cur1->link);
            cur1->link=new chainNode(p2, 0);
        }

        chainNode* cur2=adjMatrix[p2];
        if(cur2==0) adjMatrix[p2]=new chainNode(p1, 0);
        else
        {
            for(;cur2->link;cur2=cur2->link);
            cur2->link=new chainNode(p1, 0);
        }


    }

    //test
    /*for(int q=1;q<n+1;q++)
    {
        cout<<q<<": ";
        chainNode* cur=adjMatrix[q];
        for(;cur;cur=cur->link) cout<<cur->data<<" ";
        cout<<endl;
    }*/

    /******************DFS AND BLACK*******************/
    int out[n+1];
    int outLength=0;
    int black[n+1];
    int blackNum=0;
    int visited[n+1];
    for(int i=0;i<n+1;i++) {out[i]=0;}
    for(int i=0;i<n+1;i++) {black[i]=0;}
    for(int i=0;i<n+1;i++) {visited[i]=0;}

    //need to try every point be a start point, also record the most black point situation
    for(int u=1;u<n+1;u++){
            //initial
    int blackTemp[n+1];
    int blackTempNum=0;
    for(int i=0;i<n+1;i++) blackTemp[i]=0;
    for(int i=0;i<n+1;i++) visited[i]=0;
    for(int i=0;i<n+1;i++) out[i]=0;
    outLength=0;


    dfs(u, adjMatrix, visited, blackTemp, out, outLength, blackTempNum);
    for(int q=1;q<n+1;q++)
    {
        if(!visited[q]){
            dfs(q, adjMatrix, visited, blackTemp, out, outLength, blackTempNum);
        }
    }
    if(blackTempNum>blackNum)
    {
        blackNum=blackTempNum;
        for(int i=1;i<n+1;i++)
        {
            black[i]=blackTemp[i];
        }
    }

    }// u for end

    //test
    /*cout<<"out: ";
    for(int q=0;q<outLength;q++) cout<<out[q]<<" ";
    cout<<endl;
    cout<<"blackNum: "<<blackNum<<endl;
    cout<<"black: ";
    for(int q=1;q<n+1;q++) cout<<black[q]<<" ";
    cout<<endl;*/

    cout<<blackNum<<endl;
    for(int i=1;i<n+1;i++)
    {
        if(black[i]==1)
            cout<<i<<" ";
    }
    cout<<endl;




    }//testGroup for end


}
