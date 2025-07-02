#include <iostream>
using namespace std;

/* void TOH(int n, char start, char mid,char des)
{
    if(n==1){
        cout<<"Disk "<<n<<" moved from "<<start<<" to "<<des<<endl;
        return;
    }
    TOH(n-1, start, des, mid);
    cout<<"Disk "<<n<<" moved from "<<start<<" to "<<des<<endl;
    TOH(n-1, mid, start, des);
} */

void TOH(int n, char start, char mid, char des)
{
    if (n==1)
    {
        cout<<"mov disk "<<start<<" to "<<des<<endl;
        return;
    }
    TOH(n-1, start, des, mid);
    cout<<"mov disk "<<start<<" to "<<des<<endl;
    TOH(n-1, mid, start, des);
    
}

int main()
{
    int n;
    cout<<"Enter number of discs:";
    cin>>n;
    TOH(n, 'A','B','C');
}