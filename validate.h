#include <stdio.h>
#include <string.h>

//initial balance validation
int isinitialbalance(int Balance){  
  if(Balance<0)
  {
    printf("enter vaild balance\n");
    return 0;
  }
  else
  {
    return 1; 
  }
}

//Age Validation
int validAge(int age)
{
  if(age>18)
    return 1;
  else
  {
    printf("Enter valid age\n");
    return 0;
  }
}


//Gender Validation
int ischar(char Gender[])
{
    if(strlen(Gender)==1)
          return 1;
    else{
      printf("Enter Valid Gender\n");
        return 0;
    }
  
}


//Date of Birth Validation
int isvalidDOB(char DateOfBirth[])
{
    if(strlen(DateOfBirth)==10)
    {
        for(int i=0;i<2;i++)
        {
            if(! isdigit(DateOfBirth[i]))
            {
              printf("Enter Vaild Date of Birth\n");
                return 0;
            }
        }
        if(DateOfBirth[2]!='/')
        {
          printf("Enter Vaild Date of Birth\n");
            return 0;
        }
        for(int i=3;i<5;i++)
        {
            if(! isdigit(DateOfBirth[i]))
            {
              printf("Enter Vaild Date of Birth\n");
                return 0;
            }
        }
        if(DateOfBirth[5]!='/')
        {
           printf("Enter Vaild Date of Birth\n");
            return 0;
        }
        for(int i=6;i<10;i++)
        {
            if(! isdigit(DateOfBirth[i]))
            {
              printf("Enter Vaild Date of Birth\n");  
              return 0;
            }
        }
        return 1;
    }
    printf("Enter Vaild Date of Birth\n");
    return 0;  
}


//PAN Card Validation
int isvalidPAN(char PANNumber[])
{  
  if (strlen(PANNumber) == 10) 
  {
    for (int i = 0; i <= 4; i++) 
    {
      if (!isupper(PANNumber[i])) 
      {
        printf("Invalid PAN Number");
        return 0;
      }
    }
    for (int i = 5; i <= 8; i++)
      {
      if (!isdigit(PANNumber[i])) 
      {
        printf("Invalid Pan number");
        return 0;
      }
      }
    if (!isupper(PANNumber[9])) 
    {
      printf("Invalid Pan number");
      return 0;
    }
    
    return 1;
  }
  return 0;
}


//Aadhar Card Validation
int isvalidaadhar(char AadharNumber[])
{
    if(strlen(AadharNumber)==12)
    {
        for(int i=0;i<12;i++)
        {
            if(! isdigit(AadharNumber[i]))
                return 0;
        }
        return 1;
    } 
    return 0;
}


//generation of account number
char* generateaccountnumber(char AccountHolderName[])
{
  srand(time(NULL));
  char AccNumber[30];
  int spaces=0; 
  AccNumber[0]=toupper(AccountHolderName[0]);
  AccNumber[1]='\0';
  for(int i=0;i<strlen(AccountHolderName);i++)
  {
    if(spaces>1) 
      break;
    if(AccountHolderName[i]== ' ')
    {
      char ch= AccountHolderName[i+1];
      char str1[2]={ toupper(ch), '\0' };
      char str2[2]="";
      strcpy(str2,str1);
      strcat(AccNumber,str2);
      spaces++;
    }
  }
  char random[30];
  sprintf(random,"%d",rand()%900+100);
  strcat(AccNumber,random);
  printf("Account number is: %s\n",AccNumber);
  return AccNumber;  
  }


