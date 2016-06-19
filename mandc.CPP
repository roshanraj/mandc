#include <iostream.h>
#include <conio.h>
#include <stdio.h>


//// [0] - mis
//// [1] - com

int side1[]={3,3};
int boat[]={0,0};
int side2[]={0,0};
int final[]={3,3};


	//////////////////// different flags //////////////////
    int mflag=1; /// flag for menu change
    int erflag=0;

	//////////////////// different flags //////////////////



int test()
{

/////// check for the boat
  if (mflag==1)
  {
  		if((boat[1]+side1[1]) > (boat[0]+side1[0]) && side1[0]!=0)
      {
  			cout<< "game over"<<endl;
   		return 0;
  		}
  }
  else
  {
  	if(side1[1]>side1[0] && side1[0]!=0)
      {
  			cout<< "game over"<<endl;
   		return 0;
  		}
  }

       ////////// side 2 check
  if(mflag==0)
  {
  		if(side2[1]>side2[0] && side2[0]!=0)
  		{
  			cout<< "game over"<<endl;
   		return 0;
  		}

  }
  else
   {
  		if((boat[1]+side2[1]) > (side2[0]+boat[0]) && side2[0]!=0)
  		{
  			cout<< "game over "<<endl;
   		return 0;
  		}

  }

            return 1;
}

int win()
{
	int c=0;
	for (int i=0;i<3;i++)
   {
    if((final[i]==side2[i]))
  		 c++;
    }

   if (c==2)
   {
   	cout<<"won"<<endl;
      return c;
   }
   return c;

}




void disp()
{
  	cout<<"        "<<"coast 1"<<"--------";
   cout<<"boat"<<"---------";
   cout<<"coast 2"<<endl;

   cout<<"         "<<"M"<<" "<<"C"<<"   ||||||   ";
   cout<<"M"<<" "<<"C"<<"   ||||||   ";
   cout<<"M"<<" "<<"C"<<"   ||||||   "<<endl;

	cout<<"state is "<<side1[0]<<" "<<side1[1]<<"   ||||||   ";
   cout<<boat[0]<<" "<<boat[1]<<"   ||||||   ";
   cout<<side2[0]<<" "<<side2[1]<<"   ||||||   "<<endl;

   cout<<endl;
}




void main()
{


	 clrscr();
	 int i=1;
	while(i!=0)
   {



            //cout <<"value of test "<<test()<<endl;

            test();
            if(win())
            cout <<"value of win "<<win()<<endl;

     /////////////////////////////////////// menu 1
     if((i<5 || i==11) && mflag==1)
     {


       disp();
       //// display move not possible
       if (erflag==1)
       {
       	cout<<"move not possible"<<endl;
         erflag=0;
       }
       //// displaying the move ends

       /////////// to show message when boat is empty
       if((boat[0]+boat[1])<2)
        {
     			cout<<"Enter 1 to shift missionary to the boat\n";
     			cout<<"Enter 2 to shift cannibal to the boat\n";
        }



        /////////// to show message when boat is full
        if( ((boat[0]+boat[1])>0) )
        {
          if(boat[0]>0)
     			cout<<"Enter 3 to shift missionary to the side 1\n";
            if(boat[1]>0)
     			cout<<"Enter 4 to shift cannibal to the  side 1\n";
        }

         if(((boat[0]+boat[1])==2) )
       	cout<<"Enter 5 to send boat to coast 2\n";

      cin>>i;





     }

     /////////////////////////////////////// menu 2
     if(( i>=5 && i!=11) &&  mflag==0)
     {


       //cout<<mflag;
       disp();
       //// display move not possible
       if (erflag==1)
       {
       	cout<<"move not possible"<<endl;
         erflag=0;
       }
       //// displaying the move ends

      if( ((boat[0]+boat[1])<2) )
      {
      cout<<"Enter 7 to shift missionary to the boat\n";
     	cout<<"Enter 8 to shift cannibal to the boat\n";
      }

      if( ((boat[0]+boat[1])>0) )
      {
         if(boat[0]>0)
      	cout<<"Enter 9 to shift missionary to the coast2\n";
         if(boat[1]>0)
     		cout<<"Enter 10 to shift cannibal to the coast2\n";

      }

         if((boat[0]+boat[1])>0 )
      	cout<<"Enter 11 to send boat to coast 1\n";
         if((boat[0]+boat[1])==0 )
         cout<<"No one to drive\n";

      cin>>i;
     }


     //////////////////// for menu 1
     if(mflag==1 && i==1 && ((boat[0]+boat[1])<=2) )
     {
              if (  ((boat[0]==0 && boat[1]<2) || (boat[1]==0 && boat[0]<2) || (boat[0]==0 && (boat[0]==2 || boat[1]==1) )) && (side1[0]!=0 && boat[0]<2) )
              {
                side1[0]-=1;
                boat[0]+=1;
              }
              else
              {
              	erflag = 1;
              }

     }

     //////////////////// for menu 2
     if(mflag==1 && i==2 && ((boat[0]+boat[1])<=2))
     {
    			 // if (  ((boat[0]==0 && boat[1]<=2) || (boat[1]==0 && boat[0]<=2) || (boat[0]==0 && (boat[0]==2 || boat[1]==1) )) && (side1[0]!=0 && boat[0]<2) )
                if (  ((boat[1]==0 && boat[0]<2) || (boat[0]==0 && boat[1]<2) || (boat[1]==0 && (boat[1]==2 || boat[0]==1) )) && (side1[1]!=0 && boat[1]<2) )
              {
                side1[1]-=1;
                boat[1]+=1;
              }
              else
              {
              	erflag = 1;
              }

     }


     ////////////////////////////////// substractors //////////////////////////////////
      //////////////////// for menu 3
     if(mflag==1 && i==3 && ((boat[0]+boat[1])<=2) )
     {
              if (  boat[0]!=0 )
              {
                side1[0]+=1;
                boat[0]-=1;
              }
              else
              {
              	erflag = 1;
              }

     }

     //////////////////// for menu 4
     if(mflag==1 && i==4 && ((boat[0]+boat[1])<=2))
     {

                if (  boat[1]!=0 )
              {
                side1[1]+=1;
                boat[1]-=1;
              }
              else
              {
              	erflag = 1;
              }

     }



     //////////////////// for menu 5
     if(mflag==1 && i==5)
     {
           	mflag=0;
     }




   ///////////////////////////////// menu above 5 to be defined ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   ///////////////////////////////// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   ///////////////////////////////// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


	 ////////////// # 7
     if(mflag==0 && i==7)
     {
     	    if (  ((boat[0]==0 && boat[1]<2) || (boat[1]==0 && boat[0]<2) || (boat[0]==0 && (boat[0]==2 || boat[1]==1) )) && (side2[0]!=0 && boat[0]<2) )
              {
                side2[0]-=1;
                boat[0]+=1;
              }
              else
              {
              	erflag = 1;
              }

     }

      ////////////// # 8
     if(mflag==0 && i==8)
     {
                if (  ((boat[1]==0 && boat[0]<2) || (boat[0]==0 && boat[1]<2) || (boat[1]==0 && (boat[1]==2 || boat[0]==1) )) && (side2[1]!=0 && boat[1]<2) )
              {
                side2[1]-=1;
                boat[1]+=1;
              }
              else
              {
              	erflag = 1;
              }

     }

      ////////////// # 9
     if(mflag==0 && i==9)
     {
              if (  boat[0]!=0 )
              {
                side2[0]+=1;
                boat[0]-=1;
              }
              else
              {
              	erflag = 1;
              }

     }


      ////////////// # 10
     if(mflag==0 && i==10)
     {
        if (  boat[1]!=0 )
              {
                side2[1]+=1;
                boat[1]-=1;
              }
              else
              {
              	erflag = 1;
              }




     }





     if (mflag==0 && i==11)
     {
    	  mflag=1;
     }



   ///////////////////////////////// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   ///////////////////////////////// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   ///////////////////////////////// menu above 5 to be defined ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


















   }


   getch();
}
