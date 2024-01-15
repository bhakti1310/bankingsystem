/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include "validation.h"
#include <stdio.h>
#include <string.h>
#define Max 200
#define size 100

//structure defination
struct Bank {
  int Age, Balance;
  char AccountHolderName[Max];
  char DateOfBirth[Max];
  char Gender[Max];
  char Address[Max]; 
  char City[Max];
  char TypeOfAccount[Max]; 
  char PANNumber[Max];
  char AadharNumber[Max];
  char AccountNumber[Max];
};


//Banck account creation function
struct Bank CreateAccount() {
  struct Bank b;
  printf("Good Morning,\nlets start creating your Account.\n");
  printf("Bank Name: Bank Of India\n");
  printf("IFSC Code: BOI0000781\n");
  
  //name
  printf("Enter Name(Full Name): ");
  fgets(b.AccountHolderName, Max, stdin);
  b.AccountHolderName[strlen(b.AccountHolderName) - 1] = '\0';
  
  //age
  do{
  printf("Enter Age: ");
  scanf("%d", &b.Age);
  }while(!validAge(b.Age));  
  getchar();
  
  //gender
  do{
  printf("Enter Gender(M/F): ");
  fgets(b.Gender, Max, stdin);
  b.Gender[strlen(b.Gender) - 1] = '\0';
  }while(!ischar(b.Gender));
  
  //Date of Birth
  do{
  printf("Enter Date of Birth(DD/MM/YYYY): ");
  fgets(b.DateOfBirth, Max, stdin);
  b.DateOfBirth[strlen(b.DateOfBirth) - 1] = '\0';
  }
  while(!isvalidDOB(b.DateOfBirth));

  //address
  printf("Enter Address: ");
  fgets(b.Address, Max, stdin);
  b.Address[strlen(b.Address) - 1] = '\0';

  //city
  printf("Enter City: ");
  fgets(b.City, Max, stdin);
  b.City[strlen(b.City) - 1] = '\0';
  
  //account type
  int z;
  printf("Enter type of account:\n1.Savings\n2.Salary\n3.Current\n4.Joint\n");
  do{
  scanf("%d", &z);
  switch(z){
    case 1:
      strcpy(b.TypeOfAccount, "Savings");
      break;
    case 2:
      strcpy(b.TypeOfAccount, "Salary");
      break;
    case 3:
      strcpy(b.TypeOfAccount, "Current");
      break;
    case 4:
      strcpy(b.TypeOfAccount, "Joint");
      break;
    default:
      printf("Invalid input");
    }
  } while(z!=1 && z!=2 && z!=3);

  

  //initial balance
  do{
  printf("Initial Balance: ");
  scanf("%d", &b.Balance);
  getchar();
  }
  while(!isinitialbalance(b.Balance));
 
  //pan card
  do{
  printf("Enter PAN Card Number: ");
  fgets(b.PANNumber, Max, stdin);
  b.PANNumber[strlen(b.PANNumber) - 1] = '\0';
  }
  while(!isvalidPAN(b.PANNumber)); 
  
  
  //aadhar card 
  do{
    printf("Enter Aadhar Card: ");
  fgets(b.AadharNumber, Max, stdin);
  b.AadharNumber[strlen(b.AadharNumber) - 1] = '\0';
  }
  while(!isvalidaadhar(b.AadharNumber));  

  //Account number
   strcpy(b.AccountNumber,generateaccountnumber(b.AccountHolderName));
   printf("\nDetails added Successfuly.\n");
  return b;
}

//Display of account details
void Display(struct Bank b[],int index) { 
   for (int i = 0; i<index; i++) {
      printf("Bank Name: Bank Of India\nIFSC Code: BOI0000781\nName: %s\nAge: %d\nGender: %s\nDate of Birth: %s\nAddress: %s\nCity: %s\nType of Account: %s\nPAN Number: %s\nAadhar Number: %s\nAccount Number: %s\nBalance: %d\n\n\n",b[i].AccountHolderName,b[i].Age,b[i].Gender,b[i].DateOfBirth,b[i].Address,b[i].City,b[i].TypeOfAccount,b[i].PANNumber,b[i].AadharNumber,b[i].AccountNumber,b[i].Balance);
  }
  }


//updation of account details
void Update(struct Bank b[],int index) 
{
  char num[Max];
  int n;
  char newname[Max],newaddress[Max],newdob[Max]; 
  printf("Enter Account Number: ");
  fgets(num, Max, stdin);
  num[strlen(num) - 1] = '\0';
  for (int i = 0; i<index; i++) 
  {
    do{
    if(strcmp(num,b[i].AccountNumber)==0){
      printf("what do you want to update?\n1.Name\n2.Address\n3.Date Of Birth\n");
      do{
      scanf("%d",&n); 
      switch(n){
        case 1:
              getchar();
              printf("Enter Updated Name: ");
              fgets(newname, Max, stdin);
              newname[strlen(newname) - 1] = '\0';
              strcpy(b[i].AccountHolderName,newname);
              printf("Name Updated Successfully\n");
              printf("Updated Name:%s\n ",b[i].AccountHolderName);
              break;

        case 2:
              getchar();
              printf("Enter Updated Address: ");
              fgets(newaddress, Max, stdin);
              newaddress[strlen(newaddress) - 1] = '\0';
              strcpy(b[i].Address,newaddress);
              printf("Address Updated Successfully\n");
              printf("Updated Address:%s\n ",b[i].Address);
              break;
        case 3:
              getchar();
              printf("Enter Updated Date of Birth: ");
              fgets(newdob, Max, stdin);
              newdob[strlen(newdob) - 1] = '\0';
              strcpy(b[i].DateOfBirth,newdob);
              printf("Date of Birth Updated Successfully\n");
              printf("Updated Date of Birth:%s\n ",b[i].DateOfBirth);
              break;
        default:
              printf("invalid choice\n");
              printf("Enter choice again");
              break;                
       }  }while(n!=1 && n!=2 && n!=3);
    }
  }
  while(strcmp(num,b[i].AccountNumber)!=0);}
}

void Deposit(struct Bank b[],int index) {
  char num[Max];
  printf("Enter Account Number: ");
  fgets(num, Max, stdin);
  num[strlen(num) - 1] = '\0';
  int flag=1;
  for (int i = 0; i<index; i++) 
  {
   
    if(strcmp(num,b[i].AccountNumber)==0)
    {
      int amount;
      printf("Enter Amount you want to deposit: ");
      scanf("%d",&amount);
      b[i].Balance+=amount;
      printf("Deposit Successful\n");
      printf("%d is your balance",b[i].Balance);
      flag=0;
    }    
  }
  if (flag)
  {
    printf("Account number not present ");
  }
}
void Withdraw(struct Bank b[],int index){
  char num[Max];
  printf("Enter Account Number: ");
  fgets(num, Max, stdin);
  num[strlen(num) - 1] = '\0';
  int flag=1;
  for (int i = 0; i<index; i++) {
    if(strcmp(num,b[i].AccountNumber)==0){
      int amount;
      printf("Enter Amount you want to deposit: ");
      scanf("%d",&amount);
      if(amount>b[i].Balance){
        printf("Insufficient Balance");
        break;
      }
      else{
        b[i].Balance-=amount;
        printf("Deposit Successful\n");
        printf("%d is your balance",b[i].Balance);
      }
      flag=0;
      }
  }
  if (flag)
  {
    printf("Account number not present ");
  }
}

void FundsTransfer(struct Bank b[],int index){
  char sender[Max];
  char receiver[Max];
  printf("Enter Account Number of Sender: ");
  fgets(sender, Max, stdin);
  sender[strlen(sender) - 1] = '\0';
  for (int i = 0; i<index; i++) {
    
    if(strcmp(sender,b[i].AccountNumber)==0){
      printf("Enter Account Number of Receiver: ");
      fgets(receiver, Max, stdin);
      receiver[strlen(receiver) - 1] = '\0';
      for (int j = 0; j<index; j++) {
        
           if(strcmp(receiver,b[j].AccountNumber)==0){
             int amount;
             printf("Enter the amount you want to send to %s: \n",b[j].AccountHolderName);
             scanf("%d",&amount);
             if(amount>b[i].Balance){
               printf("insufficient balance\n");
               break;
             }
             else{
               b[i].Balance-=amount;
               b[j].Balance+=amount;
               printf("%drs withdrawn from %s account and deposited to %s account\n",amount,b[i].AccountHolderName,b[j].AccountHolderName);
             }
           }        
          }      
      }
    }
    
  }
void Search(struct Bank b[],int index){
    int n,flag=1;
    char num[Max];
    printf("Search:\n1.Search by account number\n2.Search by name\n3.Search by type of account\n");
    scanf( "%d",&n);
     getchar();
    switch(n){
      case 1: 
              
              printf("Enter Account Number: ");
             
              fgets(num, Max, stdin);
              num[strlen(num) - 1] = '\0';
              for (int i = 0; i<index; i++) {       
              if(strcmp(num,b[i].AccountNumber)==0){
                 printf("Account number found\n");
                 Display(b,index);
                flag=0;
                }
              }
              if (flag)
              {
                printf("Account number invalid\n ");
              }
              break;
      case 2: 
              printf("Enter name: ");
              fgets(num, Max, stdin);
              num[strlen(num) - 1] = '\0';
              for (int i = 0; i<index; i++) {
                if(strcmp(num,b[i].AccountHolderName)==0){
                  printf("Account name found");
                  Display(b,index);              
              }
              }
                break;
      case 3: 
                printf("Enter type of account:\n1.Savings\n2.Salary\n3.Current\n4.Joint\n");
                fgets(num, Max, stdin);
                num[strlen(num) - 1] = '\0';
                for (int i = 0; i<index; i++) {
                  if(strcmp(num,b[i].TypeOfAccount)==0){
                    printf("Account type found");
                    Display(b,index);              
                }
                    
                  }
                     
                  
                break;
              }
}
void BalanceEnquiry(struct Bank b[],int index){
  char num[Max];
  printf("Enter Account Number: ");
  fgets(num, Max, stdin);
  num[strlen(num) - 1] = '\0';
  int flag=1;
  for (int i = 0; i<index; i++) {
    if(strcmp(num,b[i].AccountNumber)==0){
      printf("Your balance is %d\n",b[i].Balance);
      flag=0;
      }
      if (flag)
      {
        printf("Account number not present ");
      }
  }}



int main(){
  struct Bank b[size];
  int menu,index=0;
  while (1) {
    printf("\n\n\nMenu: \n1.Create Account\n2.Display Acoount Details\n3.Update details\n4.Deposit\n5.Withdraw\n6.Funds Transfer\n7.Search\n8.Balance Enquiry\n0.Exit\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &menu);
    getchar();
    switch (menu) {
    case 1:
      b[index++] = CreateAccount();
      break;
    case 2:
        Display(b,index);
        break;
    case 3:
        Update(b,index);
        break;
    case 4:
        Deposit(b,index);
        break;
    case 5:
        Withdraw(b,index);
        break;
    case 6:    
        FundsTransfer(b,index);
        break;
    case 7:
       Search(b,index);
      break;
    case 8:
        BalanceEnquiry(b,index);
        break;
    case 9:
       exit(0);
    default:
      printf("Invalid choice\n Please enter valid choice");
    }
  }
}
