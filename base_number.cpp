#include <iostream>
#include <math.h>
#include <cstring>



using namespace std;


char hexDec[50];

void con_dec_bin(int n);
void con_bin_dec(int n);
void con_dec_oct(int n);
void con_oct_dec(int n);
int con_dec_hex(int n,int m);
void con_hex_dec();
void con_bin_oct(int n);
void con_oct_bin(int n);
void con_bin_hex(int n);
void con_hex_bin();
void con_oct_hex(long long n);
void con_hex_oct();

int main()
{
  bool Continue = true;
  int input;
  int numb;
  while (Continue)
  {
  
  cout << '\n'<<" ************************************* "<<'\n';
  cout << " * " << "Wellcom, please enter your choise *" << '\n';
  cout << " * " << "1)Binery to Decimal               *"<<'\n';
  cout << " * " << "2)Decimal to Binery               *"<<'\n';
  cout << " * " << "3)Decimal to octal                *"<<'\n';  
  cout << " * " << "4)Octal to Decimal                *"<<'\n';  
  cout << " * " << "5)Decimal to Hexadecimal          *"<<'\n';  
  cout << " * " << "6)Hexadecimal to Decimal          *"<<'\n';
  cout << " * " << "7)Binery to Octal                 *"<<'\n';  
  cout << " * " << "8)Octal to Binery                 *"<<'\n';
  cout << " * " << "9)Binery to Hexadecimal           *"<<'\n';  
  cout << " * " << "10)Hexadecimal to Binery          *"<<'\n';  
  cout << " * " << "11)Octal to Hexadecimal           *"<<'\n';  
  cout << " * " << "12)Hexadeimal to Octal            *"<<'\n';
  cout << " * " << "13)exit                           *"<<'\n';
  cout << " ************************************* "<<'\n';

  cin >> input;
  switch (input)
  {
  case 13:
    Continue = false;
    break;
  
  case 1:
    cout << "Please enter your number:";
    cin >> numb;
    con_bin_dec(numb);
    break;
  case 2:
    cout << "Please enter your number:";
    cin >> numb;
    con_dec_bin(numb);
    break;
  case 3:
    cout << "Please enter your number:";
    cin >> numb;
    con_dec_oct(numb);
    break;
  case 4:
    cout << "Enter the Octal Number:";
    cin >> numb;
    con_oct_dec(numb);
    break;
  case 5:
    int i;
    cout << "Please enter your number:";
    cin >> numb;
    i = con_dec_hex(numb,0);
    cout << "Your Heximal number is: ";
    for (i = i-1 ; i >=0; i--)
    {
      cout << hexDec[i];
    }
    break;
  case 6:
    con_hex_dec();
    break;
  case 7:
    cout << "Enter the Binary Number: ";
    cin >> numb;
    cout << numb <<" in binery = " ;
    con_bin_oct(numb);
    break;
  case 8:
    cout << "Enter an octal number: ";
    cin >> numb;
    cout << numb << " in octal = ";
    con_oct_bin(numb);
    break;
  case 9:
    cout << "Enter a binery number: ";
    cin >> numb;
    con_bin_hex(numb);
    break;
  case 10:
    con_hex_bin();
    break;
  case 11:
    cout << "Enter any Octal Number: ";
    cin >> numb;
    con_oct_hex(numb);
    break;
  case 12:
   
    con_hex_oct();
    break;
  }

  
  }

}

void con_bin_dec(int n){
  int i=1 ;
  int rem;
  int decnum=0;
  while (n!=0)
  {
    rem = n%10;
    decnum = decnum + (rem*i) ;
    i = i*2;
    n = n/10;
  }

  cout << "Your decimal number " <<decnum << '\n';

}
void con_dec_bin(int n){
  int binerynum[20],i=0;
  
  
  while (n!=0){

    binerynum[i] = n%2;
    n = n/2;
    i++;
  }
  cout << "your binery number is: "<<'\n';
  for ( i = (i-1); i>=0; i--)
  {
    cout<<binerynum[i];
  }
  
  
}

void con_dec_oct(int n){
  int octnumber[50],i=0;
  while(n!=0)
  {
    octnumber[i] = n%8;
    i++;
    n = n/8;
  }
  cout << "your octal Number: ";
  for(i=(i-1); i>=0;i--){
    cout<<octnumber[i];  
    }
}
void con_oct_dec(int n)
{
  int decimal=0,i=0,rem;
  while (n!=0)
  {
    rem = n%10;
    decimal = decimal+(rem*pow(8,i));
    i++;
    n=n/10;
  }
  cout <<"\n your Decimal Number is: "  <<decimal << '\n';
  

}
int con_dec_hex(int n,int m)
{
  int rem;
  while (n!=0)
  {
    rem = n%16;
    if(rem<10)
    {
      rem +=48;
    }
    else
    {
      rem +=55;
    }
    hexDec[m] = rem;
    m++;
    n=n/16;
  }
  return m;
}
void con_hex_dec(){
  int decimalNum=0, rem, i=0, len=0;
  char hexDecNum[20];
  cout<<"Enter the Hexadecimal Number: ";
  cin>>hexDecNum;
  while(hexDecNum[i]!='\0')
  {
    len++;
    i++;
  }
  len--;
  i=0;
  while(len>=0)
  {
    rem = hexDecNum[len];
    if(rem>=48 && rem<=57)
        rem = rem-48;
    else if(rem>=65 && rem<=70)
        rem = rem-55;
    else if(rem>=97 && rem<=102)
        rem = rem-87;
    else
    {
      cout<<"\nInvalid Hex Digit!";
      cout<<endl;
      
    }
    decimalNum = decimalNum + (rem*pow(16, i));
    len--;
    i++;
  }
    cout<<"\nEquivalent Decimal Value: "<<decimalNum;
    cout<<endl;
  
}
void con_bin_oct(int n)
{
  int octanum = 0 , decnum = 0 , i=0;
  while(n!=0)
  {
    decnum += (n%10)*pow(2,i);
    ++i;
    n/=10;
  } 
  i=1;
  while(decnum!=0)
  {
    octanum += (decnum%8)*i;
    decnum /= 8;
    i *= 10;
  }
  cout << octanum ;
}
void con_oct_bin(int n)
{
  int decnum = 0,i = 0,binnum=0;
  while (n!=0)
  {
    decnum += (n%10)*pow(8,i);
    ++i;
    n /=10;
  }
  i=1;
  
  while (decnum!=0)
  {
    binnum += (decnum%2)*i;
    decnum /= 2;
    i *= 10;
  }
  cout << binnum;
  
}
void con_bin_hex(int n){
  int hex=0,mul=1,check=1,rem,i=0;
  // char hexDec[50];
  while (n!=0){
    rem = n%10;
    hex += (rem*mul);
    if (check%4==0)
    {
      if (hex<10){
        hexDec[i] = hex+48;
      }
      else{
        hexDec[i] = hex+55;
      }
      mul=1;
      hex=0;
      check=1;
      i++;
    }
    else
    {
      mul*=2;
      check++;
    }
    n = n/10;
    
  }
  if (check!=1){
    hexDec[i] = hex+48;
  }
  if (check==1){
    i--;
  }
  cout<<"\nEquivalent Value in Hexadecimal: ";
  for (i-i; i>=0; i--)
  {
    cout << hexDec[i];
  }
  cout << '\n';

}
void con_hex_bin(){
  int i=0;
  char hex[100];
  cout << "\n Enter Hexadecimal Number: ";
  cin >> hex;
  cout << "\n Conversion of Hexadecimal Number to Binary Number";
  while (hex[i])
  {
    switch (hex[i])
    {
    case '0':cout<<"0000";
      break;
    case '1':cout<<"0001";
      break;
    case '2':cout<<"0010";
      break;
    case '3':cout<<"0011";
      break;
    case '4':cout<<"0100";
      break;
    case '5':cout<<"0101";
      break;
    case '6':cout<<"0110";
      break;
    case '7':cout<<"0111";
      break;
    case '8':cout<<"1000";
      break;
    case '9':cout<<"1001";
      break;
    case 'A' : cout<<"1010";
      break;
    case 'B' : cout<<"1011";
        break;
    case 'C' : cout<<"1100";
        break;
    case 'D' : cout<<"1101";
        break;
    case 'E' : cout<<"1110";
        break;
    case 'F' : cout<<"1111";
      break;
    case 'a' : cout<<"1010";
      break;
    case 'b' : cout<<"1011";
      break;
    case 'c' : cout<<"1100";
      break;
    case 'd' : cout<<"1101";
      break;
    case 'e' : cout<<"1110";
      break;
    case 'f' : cout<<"1111";
      break;
    default : cout<<"\n Invalid Hexadecimal Digit... "<<hex[i];
    }
  i++;
  }

}
void con_oct_hex(long long n){
  int octalval[]={0,1,10,11,100,101,110,111};
  long long temp_octal,binary,place;
  char hex[65] = "";
  int rem;
  place = 1;
  binary = 0;
  temp_octal = n;
  while (temp_octal>0)
  {
    rem = temp_octal %10;
    binary = (octalval[rem]*place)+binary;
    temp_octal /=10;
    place *= 1000;
  }
  // convert binary to hexadecmal
  while (binary>0)
  {
    rem = binary%10000;
    switch(rem)
    {
      case 0:strcat(hex,"0");
        break;
      case 1:strcat(hex,"1");
        break;
      case 10:strcat(hex,"2");
        break;
      case 11:strcat(hex,"3");
        break;
      case 100:strcat(hex,"4");
        break;
      case 101:strcat(hex,"5");
        break;
      case 110:strcat(hex,"6");
        break;
      case 111:strcat(hex,"7");
        break;
      case 1000:strcat(hex,"8");
        break;
      case 1001:strcat(hex,"9");
        break;
      case 1010:strcat(hex,"A");
        break;
      case 1011:strcat(hex,"B");
        break;
      case 1100:strcat(hex,"C");
        break;
      case 1101:strcat(hex,"D");
        break;
      case 1110:strcat(hex,"E");
        break;
      case 1111:strcat(hex,"F");
        break;
    }
    binary /=10000;
  }
  strrev(hex);
  cout<<" Equivalent Hexadecimal number: "<< hex;
  
}

void con_hex_oct()
{
  int decimalNum = 0,octNum[30] , rem,i=0,len=0;
  char hexdecimal[50];
  cout << "Enter the Hexadecimal Number: ";
  cin >> hexDec;
  while (hexDec[i]!='\0')
  {
    len++;
    i++;
  }
  len--;
  i=0;
  while (len>=0)
  {
    rem = hexDec[len];
    if(rem>=48 && rem<=57){
      rem -=48; 
    }
    else if(rem>=65 && rem<=70){
      rem-=55;
    }
    else if(rem>=97 && rem<=102){
      rem-=87;
    }
    else{
      cout<<"\nInvalid Hex Digit!";
      cout<<endl;
    }
    decimalNum += (rem*pow(16,i));
    len--;
    i++;
  }
  i=0;
  while (decimalNum != 0){
    octNum[i] = decimalNum%8;
    i++;
    decimalNum = decimalNum/ 8;
  }
  cout<<"\nEquivalent Octal Value:";
  for (i= (i-1); i >=0; i--)
  {
    cout << octNum[i];
  }
  cout << endl;

  
  
}