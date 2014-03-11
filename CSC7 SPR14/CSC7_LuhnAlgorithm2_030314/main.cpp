/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 3, 2014, 9:49 AM
 * Luhn Algorithm 2
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants
enum CrdCard { AM_EXP, VISA, M_CRD, DSCVR, ALL };

//Function Prototypes
void dblNum(char&);
int sumDgts(char*,int);
void prntNum(char*,int);
bool valid(char*,int);
char rndDgit();
void prpLuhn(char*,int,int);
void Luhn(char*,int);
char *genCC(CrdCard,int&);
void flipDig(char*,int);

//Execution
int main(int argc, char** argv) {
//    //Declare variables
//    int SIZE=16;
//    char account[SIZE];
    srand(static_cast<unsigned int>(time(0)));
//    //Begin Luhn Algorithm
//    prpLuhn(account,SIZE-2);
//    Luhn(account,SIZE-2);
    
    //Declare variables
    int choice;
    CrdCard type;
    
    //Prompt user for type of credit card
    do{
        cout << "Please indicate which credit card you would "
                "like to generate a number for.\nEnter in the "
                "corresponding number:" << endl;
        cout << "    1. American Express " << endl;
        cout << "    2. Visa " << endl;
        cout << "    3. MasterCard " << endl;
        cout << "    4. Discover " << endl;
        cout << "    5. ANY " << endl;
        cin >> choice;
        cout << endl;
    }while(choice > 5 || choice < 1);
    
    //Convert choice to CrdCard
    switch(choice){
        case 1:
            type = AM_EXP;
            break;
        case 2:
            type = VISA;
            break;
        case 3:
            type = M_CRD;
            break;
        case 4:
            type = DSCVR;
            break;
        case 5:
            type = ALL;
            break;
        default:
            break;
    }
    
    //Generate card
    int size;
    char *account = genCC(type,size);
    
    //Output generated card
    cout << "Card number: ";
    prntNum(account,size);
    
    //Output card with checking digit
    Luhn(account,size-1);
    
    //Flip a digit
    flipDig(account,size);
    cout << "Altered account number: ";
    prntNum(account,size);
    
    //Validate card
    if(valid(account,size))cout << "Card number is valid" << endl;
    else cout << "Card number is invalid" << endl;
    
    //Exit
    return 0;
}

void dblNum(char &a){
    int num=(a-'0');
    num*=2;
    if(num>9){
        num%=10;
        num++;
    }
    a=(num+'0');
}

int sumDgts(char *a,int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=a[i]-'0';
        //cout << "Index " << i << ": " << a[i] 
        //        << ", " << a[i]-'0' << endl;
    }
    return sum;
}

void prntNum(char *a,int size){
    for(int i=0;i<size;i++){
        cout << a[i];
    }
    cout << endl;
}

bool valid(char *a,int size){
//    int sum=0;
//    for(int i=0;i<size;i++){
//        sum+=(a[i]-'0');
//    }
//    //int sum=sumDgts(a,size);
//    cout << "Validating total: " << sum << endl;
//    if(sum%10==0)return true;
//    else return false;
    //Double numbers
    int pos=size-1,sum,chkDgt;
    char b[size+1];
    for(int i=0;i<size+1;i++){
        b[i]=a[i];
    }
    do{
        dblNum(b[pos]);
        pos=pos-2;
    }while(pos>0);
    
    //Sum digits
    sum=sumDgts(b,size-2);
    //cout << "Sum: " << sum << endl;
    //Find checking digit
    chkDgt=sum*9%10;
    //cout << "checking digit: " << chkDgt << endl;
    
    //Validate
    if((a[size-1]-'0')==chkDgt)return true;
    else return false;
    
}

void prpLuhn(char *cc,int size,int pos){
    //Create a random cc in prep for Luhn checksum
    for(int i=pos;i<size-2;i++){
        cc[i]=rndDgit();
    }
//    //Print out generated number
//    cout << "Card number: ";
//    prntNum(cc,size-2);
    //Put null terminator at the end
    for(int i=size-1;i<=size;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}

void Luhn(char *a, int size){
    //Double numbers
    int pos=size-2,sum,chkDgt;
    char b[size+2];
    for(int i=0;i<size+2;i++){
        b[i]=a[i];
    }
    do{
        dblNum(b[pos]);
        pos=pos-2;
    }while(pos>0);
    
    //Sum digits
    sum=sumDgts(b,size-1);
    //cout << "Sum: " << sum << endl;
    //Find checking digit
    chkDgt=sum*9%10;
    //cout << "checking digit: " << chkDgt << endl;
    //Add checking digit to account number
    a[size]=chkDgt+'0';
    cout << "Card number (plus checking digit): ";
    prntNum(a,size+1);
    //Validate card
    if(valid(a,size+1))cout << "Your card is valid " << endl;
    else cout << "Invalid" << endl;
}

char *genCC(CrdCard type,int& actSize){
    char *card = new char[20];
    switch(type){
        case AM_EXP:{
            //Start with 34, 37; length 15
            actSize = 15+1;
            //char *card = new char[size];
            card[0] = 3+'0';
            rand()%2==0 ? card[1] = 4+'0' : card[1] = 7+'0';
            //cout << "Index 0 " << card[0] << ", Index 1 " << card[1] << endl;
            int pos = 2;
            for(int i=pos;i<actSize;i++)
                card[i]='\0';
            //Pass card, size and position to start into 
            //prpLuhn function
            prpLuhn(card,actSize,pos);
            //return card;
            break;
        }case VISA:{
            //Start with 4; length 13-16
            int length[] = {13,14,15,16};
            actSize = length[rand()%4]+1;
            //char *card = new char[length[size]];
            card[0] = 4+'0';
            int pos = 1;
            for(int i=pos;i<actSize;i++)
                card[i]='\0';
            //Pass card, size and position to start into 
            //prpLuhn function
            prpLuhn(card,actSize,pos);
            //return card;
            break;
        }case M_CRD:{
            //Start with 51,52,53,54,55; length 16-19
            int length[] = {16,17,18,19};
            actSize = length[rand()%4]+1;
            //char *card = new char[length[size]];
            card[0]=5+'0';
            card[1]=(rand()%5+1)+'0';
            int pos = 2;
            for(int i=pos;i<actSize;i++)
                card[i]='\0';
            //Pass card, size and position to start into 
            //prpLuhn function
            prpLuhn(card,actSize,pos);
            //return card;
            break;
        }case DSCVR:{
            //Start with  6011, 622126 to 622925, 644, 
            //645, 646, 647, 648, 649, 65; length 16 
            actSize = 16+1;
            int pos;
            //char *card = new char[size];
            //int range[] = {1,2,3,4};
            card[0]=6+'0';
            switch(rand()%4){
                case 0:{
                    card[1]=0+'0';
                    card[2]=card[3]=1+'0';
                    pos = 4;
                    break;
                }case 1:{
                    card[1]=card[2]=2+'0';
                    card[3]=(rand()%9+1)+'0';
                    if(card[3]==1||card[3]==9)card[4]=2+'0';
                    else card[4]=(rand()%10)+'0';
                    if(card[3]==9&&card[4]==2)card[5]=(rand()%6)+'0';
                    else if (card[3]==1&&card[4]==2){
                        int num[] = {6,7,8,9};
                        int indx = rand()%4;
                        card[5]=(num[indx])+'0';
                    }else card[5]=(rand()%10)+'0';
                    pos = 6;
                    break;
                }case 2:{
                    card[1]=4+'0';
                    int num[] = {4,5,6,7,8,9};
                    int indx=rand()%6;
                    card[2]=(num[indx])+'0';
                    pos = 3;
                    break;
                }case 3:{
                    card[1]=5+'0';
                    pos = 2;
                    break;
                }
            }
            for(int i=pos;i<actSize;i++)
                card[i]='\0';
            prpLuhn(card,actSize,pos);
            //return card;
            break;
        }case ALL:{
            CrdCard options[] = {AM_EXP,VISA,M_CRD,DSCVR};
            int indx = rand()%4;
            card = genCC(options[indx],actSize);
            break;
        }default:{
            break;
        }
    }
    return card;
}

void flipDig(char *a,int size){
    //int size = sizeof(a);
    int indx = rand()%size;
    int temp;
    do{
    temp=rand()%10;
    }while(a[indx]==temp+'0');
    a[indx]=temp+'0';
}