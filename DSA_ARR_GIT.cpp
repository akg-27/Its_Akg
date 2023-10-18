#include<iostream>
using namespace std;

void menu()
{
    cout<<"\n\t\tAll Array Operations\t\t\n"<<endl;
    cout<<"1. Add a Value in Array"<<endl;
    cout<<"2. Delete a Value by position"<<endl;
    cout<<"3. Search any Value"<<endl;
    cout<<"4. Delete a Value"<<endl;
    cout<<"5. Display all Values of Array"<<endl;
    cout<<"6. Insert any Value at particular position"<<endl;
    cout<<"7. Get Highest Value in Array."<<endl;
    cout<<"8. Reverse Array"<<endl;
    cout<<"9. Get Second Maximum Value in Arrray"<<endl;
    cout<<"10. Check Sorted or Unsorted "<<endl;
    cout<<"11. Remove Duplicates in Array"<<endl;
    cout<<"12. Move even and odd in different sides of Array"<<endl;
    cout<<"13. Rotate Clock wise one time "<<endl;
    cout<<"14. Rotate Clock wise n times "<<endl;
    cout<<"15. Exit the Program"<<endl;

}

void addval(int t[],int s,int c)
{
        if (c==s-1)
                cout<<"Array is full";
        else
                cout<<"Enter value to be inserted :";cin>>t[++c];
}

void delbypos(int t[],int &c)
{
        int p;
        if (c==-1)
                cout<<"Array is empty";
        else
                cout<<"Enter pos to perform Delete Operation :";cin>>p;p--;
        if (p<0 || p>c)
                cout<<"Invalid Position has been given..";
        else
        {
                cout<<t[p]<<"is deleted.";
                for (int i = p; i <= c-1; i++)
                        t[i]=t[i+1];
                c--;
        }
}

int searchval(int t[],int c,int x)
{
        for(int i=0;i<=c;i++)
        {
                if(t[i]==x)
                        return(i);
        }     
        return(-1);
}

void delbyval(int t[],int &c)
{
        int x,in;
        cout<<"\nEnter any value:";
        cin>>x;
        in=searchval(t,c,x);
        if(in==-1)
                cout<<"\nElement is not present for delete";
        else
        {
	        cout<<"\n"<<x<<" has been deleted";
	        for(int j=in;j<=c-1;j++)
	               t[j]=t[j+1];
	        c--;
        }
}

void disall(int t[],int c)
{
        cout<<"\n";
        for(int i=0;i<=c;i++)
                cout<<t[i]<<"   ";
}

void insele(int t[],int &c,int s)
{
        int n,pos,j;
        if(c==s-1)
        {
                cout<<"Array is full";
                return;
        }
        cout<<"Enter any no :";
        cin>>pos;
        if(pos>=1 && pos<=c+2)
        {
	        cout<<"\nEnter new value to insert at "<<pos<<" location:";
	        cin>>n;
	        pos--;
	        for(j=c;j>=pos;j--)
	                t[j+1]=t[j];
	        t[j+1]=n;
	        c++;
        }
        else
                cout<<"\nInvalid position";
}

int highval(int t[],int c)
{
        int m=0;
        for(int i=1;i<=c;i++)
        {
                if(t[i]>t[m])
                m=i;
        }
    return(m);
}

int checksort(int t[],int c)
{
        for(int i=1;i<=c;i++)
        {
                if(t[i]<t[i-1])
                return(0);
        }
        return(1);
}

void removedupsorted(int t[],int &c)
{
        int i,j=0;
        for(i=0;i<=c-1;i++)
        {
                if(t[i]!=t[i+1])
                        t[j++]=t[i];
        }
        t[j]=t[i];
        c=j;
}

void oddeve(int t[],int &c)
{
        int i,j,temp;
        i=0;
        j=c;

        while(i<j)
        {
                while(t[i]%2==0)
                     i++;

                while(t[j]%2==1)
                     j--;

                if(i<j)
                {
                        temp=t[i];
                        t[i]=t[j];
                        t[j]=temp;
                }

                i++;
                j--;
        }
}

int main()
{
        int const size = 10;
        int a[size] = {1,2,3,4,5,6,7,8,9,10};
        int cur = 9,n,x,p;
    

                while(1)
                {
                        menu();
                        cout<<"\nEnter your choice :";cin>>n;

                        if(n==16)
                        exit(0);

                        switch(n)
                        {
                        case 1:addval(a,size,cur);
                                break;
                
                        case 2:delbypos(a,cur);
                                break;

                        case 3:cout<<"\nEnter any value:";
		                cin>>x;
		                p=searchval(a,cur,x);
                                break;

                        case 4:delbyval(a,cur);
                                break;

                        case 5:disall(a,cur);
                                break;
                        
                        case 6:insele(a,cur,size);
                                break;

                        case 7: p=highval(a,cur);
		                cout<<"\n Highest element is "<<a[p]<<" at "<<p+1<<" location";
		                break;
                        /*case 8:disall(a,cur);
                                break;

                        case 9:addval(a,size,cur);
                                break;*/
                        
                        case 10:x=checksort(a,cur);
                                if(n==1)
                                        cout<<"\nGiven array is sorted";
                                else
                                        cout<<"\nGiven array is unsorted";
                                break;

                        case 11:removedupsorted(a,cur);
                                break;

                        case 12:oddeve(a,cur);
                                break;

                       /*case 13:addval(a,size,cur);
                                break;
                        
                        case 14:delbypos(a,cur);
                                break;

                        case 15:delbyval(a,cur);
                                break;

                        case 16:disall(a,cur);
                                break; */

                        default:
                                cout<<"\nInvalid Choice";
                                break;
                }
        }
        return 0;
}