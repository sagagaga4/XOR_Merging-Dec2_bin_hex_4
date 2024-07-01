#include <stdio.h>
#include <string.h>
#define N 50

void filtered(char *s,char *temp)
{ // FILTERING WORDS WHICH ARE EXCLUDED IN VALID CHARACTERS ARRAY
    int length = strlen(s);
    char Valid[]= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int Validlength = strlen(Valid);
    int temp_index = 0;
    int Val = 0;

    for(int i = 0; i  < Validlength; i++)
    {
        for(int j = 0; j < length; j++)
        {
            if(s[j] == Valid[i])
            {
                Val = 1;
                temp[temp_index] = s[j];
                temp_index++;
                break;
            }
        }
        if(!Val)
        {
            continue;
        }
    }
    temp[temp_index] = '\0';
    int lengthTemp = strlen(temp);
// BUBBLE SORTING THE STRING
    for(int i = 0; i < lengthTemp; i++)
    {
        for(int j = i + 1; j < lengthTemp ; j++)
        {
            if((temp[i] >= 'A' && temp[i] <= 'Z')) 
            {
                    if(temp[j] >= '0' && temp[j] <= '9' )
                {
                    char swappy = temp[i];
                    temp[i] = temp[j];
                    temp[j] = swappy;
                }
            }
            if(temp[i] >= 'A' && temp[i] <= 'Z')
                {
                    if(temp[j] >= 'A' && temp[j] <= 'Z')
                    {
                        if(temp[i] > temp[j])
                        {
                            int swappy = temp[i];
                            temp[i] = temp[j];
                            temp[j] = swappy;
                        }
                    }
                }
        }
    }
}

void differerent_characters(char* str1,char* str2, char* result)
{
    char filtered_str1[N];
    char filtered_str2[N];
    
    filtered(str1,filtered_str1);
    filtered(str2,filtered_str2);
    
    int length_str2 = strlen(filtered_str2);
    int length_str1 = strlen(filtered_str1);

    int res_index = 0;

    for(int i = 0; i < length_str2; i++ )
    {
        if(filtered_str2[i] != filtered_str1[i] && filtered_str2[i] > filtered_str1[i])
        {
            result[res_index] = filtered_str1[i];
            res_index++;
            result[res_index] = filtered_str2[i];
            res_index++;
        }
        if(filtered_str2[i] != filtered_str1[i] && filtered_str1[i] > filtered_str2[i] )
        {
            result[res_index] = filtered_str2[i];
            res_index++;
            result[res_index] = filtered_str1[i];
            res_index++;
        }
    }

    result[res_index] = '\0';
    char filtered_result[N];

    filtered(result,filtered_result);
    printf("%s",filtered_result);
}

void intToNumberBaseString(const char* format, int num, char* intToCharArr)
{
    int index = 0;

    if (format[0] == '%' && format[1] == 'd') 
    {
        printf("%d",num);
        printf("(10)");

    }
    else if (format[0] == '%' && format[1] == 'b') 
    { 
        while (num)
        {
            int remainder = num % 2;
            num = num / 2;
            intToCharArr[index++] = remainder + '0'; 
        }

        intToCharArr[index] = '\0'; 

        while(index--)
        {  
            printf("%c",intToCharArr[index]);
        }
        printf("(2)");
    }

    else if (format[0] == '%' && format[1] == '4') 
    { 
        while (num)
        {
            int remainder = num % 4;
            num = num / 4;
            intToCharArr[index++] = remainder + '0'; 
        }

        intToCharArr[index] = '\0'; 

        while(index--)
        {  
            printf("%c",intToCharArr[index]);
        }
        printf("(4)");
    }

    else if (format[0] == '%' && format[1] == 'x') 
    {
        while(num)
        {            
            int remainder = num % 16;
            num = num/16;

            if(remainder < 10)
            {
                intToCharArr[index++] = remainder + '0';
            }
            if(remainder > 10)
            {
                intToCharArr[index++] = (remainder - 10) + 'A';
            }

        }
        intToCharArr[index] = '\0';
        
        while(index--)
        {  
            printf("%c",intToCharArr[index]);
        }
        printf("(16)");
    }
    printf("\n");
    return;
}

int main(void) 
{
  printf("Please select the function you want to run:\n");
  int choice = 0;
  printf("1 - different characters:\n");
  printf("2 - print formated integers:\n");
  printf("3 - Exit the program:\n");
  if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) 
  {
    printf("Input Error");
  }

  if (choice == 1) 
  {
    char str1[N];
    char str2[N];
    char result[N];

    printf("Enter the first string:\n");
    scanf("%s", str1);
    if (*str1 == '\0' || strlen(str1) > N)
    {
        printf("Input Error\n");
        return 1;
    }
        printf("Enter the second string:\n");
        scanf("%s", str2);
    if (*str2 == '\0' || strlen(str2) > N) 
    {
        printf("Input Error\n");
        return 1;
    }
        differerent_characters(str1,str2,result);
  }

  else if (choice == 2) 
    {
        char format[3];
        int num = 0;
        char intToCharArr[N] = ""; 

        printf("Enter format and number: ");
        scanf("%2s %d", format, &num);
        
        intToNumberBaseString(format, num, intToCharArr);
    }
    
  else if (choice == 3) 
  {
    return 1;
  }
return 0;
}