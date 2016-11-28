/*
 * main.cpp
 *
 *  Created on: May 21, 2016
 *      Author: VAMSIKIRAN
 */

#include<iostream>
#include<cmath>

using namespace std;


/// Funtcons prototyping ///////////

int gra_edge_matrix();
void del_matrix();
void ma_lis(int);


///////////////////////////////////


int nodes=0;
bool **edgema_ptr=NULL;
int **edglenma_ptr=NULL;
int sn=0,dn=0;
int temp=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

	cout<<"\n ***** Welcome to Dijkstra Algorithm ***** "<<endl;



	//want to create graph for user defined number of nodes
	cout<<"\n       Enter Number of nodes: ";cin>>nodes;

	//creates edge matrix for defined num of nodes
	gra_edge_matrix();


	/*	for (int a=0;a<nodes;a++)
	  {
	    ma_lis(a);
	  }

	*/

	cout<<"\nEnter source node: ";cin>>sn;
	cout<<"\n Enter destination node: ";cin>>dn;

	ma_lis(sn);

	del_matrix();

	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int gra_edge_matrix()
{
	//matrix of nxn, where row=coulmn=n(nodes)

	//defining bool nxn matrix for getting edge info from user
        //using ponter to pointer

       edgema_ptr=new bool*[nodes];
       for(int a=0; a<nodes; a++)
	 {
	   edgema_ptr[a]= new bool[nodes];

	 }

       //defining edgelen matrix dynamically using pointers


        edglenma_ptr=new int*[nodes];
       for(int d=0; d<nodes; d++)
	 {
	   edglenma_ptr[d]= new int[nodes];

	 }

       /////////////////////////////////////////////////////////

	for(int b=0; b<nodes; b++)
	{
		for(int c=0; c<nodes; c++)
		{
			if(b==c)
			{ 	//For same node to same node we dont want edge
				edgema_ptr[b][c]= false;

			}

			else
			{
				//ask user to enter edge information

				cout<<"Enter edge is present/not 0/1 between node "<<b<<"----> "<<c<<":";
				cin>>edgema_ptr[b][c];


				//if there is edge between node ask for distance
				if(edgema_ptr[b][c]== true)
				{
					cout<<"Enter edge length between node "<<b<<"---->"<<c<<":";

					//save length of edge in anothere int matrix
					cin>>edglenma_ptr[b][c];

				}
				else
				{
					edglenma_ptr[b][c]=0;
				}

			}
		}

	}


	////////////print edge matrix with lenth/////////////////////////

	//prints head of matrix
	cout<<"\n\t[ Node edge matrix of Graph ]\n"<<endl;

	for(int e=0; e<nodes;e++)

	{
		// prints node num of matrix column
		cout<<"\tnode"<<e<<"";
	}

	cout<<"\n";

	//starts looping through node edge matrix starting from [0][0]
	for(int f=0; f<nodes; f++)
		{

			// prints node num of matrix column
		    cout<<"node"<<f;
			for(int i=0; i<nodes; i++)
			{
				//prints edge(length of edge).
				cout<<"\t "<<edgema_ptr[f][i]<<"("<<edglenma_ptr[f][i]<<")";

				if(i==nodes-1)
					{
							cout<<endl;
					}
			}

		}



	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ma_lis(int nodlist)
{



  int li[nodes];



      for(int c=0; c<nodes; c++)
	  {

	       //cout<<"\t"<<edglenma_ptr[b][c];
	       li[c]=edglenma_ptr[nodlist][c];

	  }
		cout<<endl;


       int small=100;

 for(int d=0; d<nodes;d++)
    {

      //cout<<"\t"<<li[d];

      if(li[d]!=0 && li[d]<small)
	{

	  small=li[d];

	}
      else
	{
	  continue;
	}



    }

 cout<<endl<<small;

 for(int e=0;e<nodes;e++)
   {
     if(small==li[e] && dn==e)
       { cout<<"\nshortest path from source node "<<sn<<" to "<<dn<<" is "<<small<<endl;
	 break;
       }
     else if (small==li[e])
       {
	 cout<<"--"<<e<<"("<<small<<")";
	 temp+=small;
	 break;
       }

    }

 /*   if(e!=dn)
      {

	ma_lis(e);

      }
 */
   cout<<endl;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//delete matrix

void del_matrix()
{

  for(int a=0; a<nodes;a++)
    {
      delete[] edgema_ptr[a];
    }

  delete[] edgema_ptr;


  for(int b=0; b<nodes;b++)
    {
      delete[] edglenma_ptr[b];
    }

  delete[] edglenma_ptr;


}

///////////////////////////////////////////////////////////////////////////////////////////////////////
