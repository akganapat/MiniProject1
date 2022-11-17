#include <stdio.h>
#include <math.h>
#include <stdlib.h> // allows the inclusion of files in the program
#include <string.h>

//remember file name to be called cryptoMagic

int main()
{


FILE *int_file; // this is the file used for the input of the user
FILE *out_file; // this is the file used for the output of the user. 

// important variable declaration:
char user_inputName [1024]={0};
char user_outputName [1024]={0};
char passing[2]={0};
char userLine[120]={0};
char previousUserLine[120]={0};
char encryptUserLine [255]={0};
char PEUL[255]={0}; // the PEUL stands for Previous Encrypted User Line

int lettVar = i, j;
char HexaValue[2]={0};

int E(char *argv[], int num)
{
    //creating the file of the input to be what the user inputs into the terminal.
    strcpy(user_inputName, argv[num]);
    user_inputName = fopen(user_inputName, "r");
    if (user_inputName == NULL)
    {
        printf("file cannot be opened");
        exit (1);
    }
    printf("\n%s will be encrypted..", user_inputName);

    for (i=0; i<strlen(user_inputName); i++)
    {
        passing[0] = user_inputName[i];
        if (user_inputName != '.') 
        {
            strcat(user_outputName, passing)
        }
        else 
        {
            break;
        }
    }
    strcat(user_outputName, ".crp");

    out_file = fopen(user_outputName, "w");

    // while loop will takes the input of the user until the maximum count is reached
    while (!feof(int_file))
    { 
        fgets(userLine, 120, user_inputName);

        //if statement will determine if the line and the previous line are the same, and if that condition is met, AS WELL AS the feof the input file, the function will copy the previous line to the current one.
        if (strcmp(userLine, previousUserLine) == 0 && feof(int_file))
        {
            srtcpy(previousUserLine)
        }
    } 

    //creating a for loop dedicated to the char characters 
    for (i=0; i<120; i++) // i<120 due to the max for the encryption being 120 characters 
    {
        lettVar = userLine[i];
    }
    if (lettVar == 0)
    {
        break;
        // if the value of the letter is 0, then the program will simply break.
    }

    if (lettVar == '\n')
    {
        fputc('\n', out_file);
        break;
        // this basically states that if there is a case that the input has a tab, the tab will be included in the output of the code. 
    }

    else if (lettVar == 9)
    {
        fputs("tab", out_file);
        break;
        // if there is a tab in the input, the program will put 'tab' to indicate the placement of the tab.
    }

    else
    {
        lettVar -= 16; // represents the length of hexadecimal
        if (lettVar < 32) lettVar = (lettVar - 32) + 144;
        fprintf(out_file, "%X", lettVar);
        
    }
    if (feof(int_file))
    {
        printf("\n the end of the file was reached");
    }  
    else 
    {
        printf("\n something went wrong!");
        return (0);
    }

    printf("\n the encrypted file is:", out_file);

    return (0);
// end of function for the encryption portion
}

int D (char *argv[], int num)
{
    // making the input of the user what the file is defining and opens that defined file

    strcpy(user_inputName, argv[num]);
    user_inputName = fopen(user_inputName, "r");
    // recall that the r is used to indicate that the file is going to be read, hence the r.

    if (int_file == NULL)
    {
        printf("the file cannot be opened");
        exit(1);
    }

    printf("\n%s is going to be decrypted...", user_inputName);

    // now, rather than the file being converted from a .txt, the program needs to convert the file into a .txt from a .crp.

    for (i = 0; i<strlen(user_inputName); i++)
    // with decryption, the limit is 255 rather than 120
    {
        passing[0] = user_inputName[i];

        if (user_inputName[i] != '.')
        {
            strcat(user_outputName, passing);
        }
        else
        {
            break;
        }
        
    }

    strcat(user_outputName, ".txt");

    out_file = fopen(user_outputName, "w");
    // opening up the file for the output and writing the contents of the input on it. 

    while(!feof(int_file))
    {
        fgets(encryptUserLine, 255, int_file);

        if (strcmp(encryptUserLine, PEUL) == 0 && feof(int_file))
        {
            break;
        }

        strcpy(PEUL, encryptUserLine);

    }

    for (i=0; i<255; i++)
    {
        HexaValue[0] = encryptUserLine[i];
        HexaValue[1] = encryptUserLine[i+1];

        if (HexaValue[0] == 0)
        {
            break;
        }
        

        if (HexaValue[0] == '\n')
        {
            fputc('\n', out_file);
            break;
        }
        else if (HexaValue[0] == 't' && HexaValue[1] == 't')
        {
            fprintf(out_file, "\t");

        }
        else
        {
            scanf(HexaValue, "%X", &lettVar);
            lettVar += 16;

            if (lettVar > 127)
            {
                lettVar = (lettVar - 144) + 32;
                fprintf(out_file, "%c", lettVar);
            }
        }
        
        if (feof(int_file))
        {
            printf("\n the end of the file is reached.");
        }
        else 
        {
            printf("\n somehting is wrong!");
            return(1);
        }

        printf("\n the decrypted file is: %s", user_outputName);

        return(0);
// this is the end of the decrypted function
    }
    
}

int main(int argc, char argv[])
{
    if (argc < 2)
    {
        printf("request failed.");
        exit(1);
    }

    if (strcmp(argv[1], "-E")== 0)
    {
        printf(" encrypt\n");
        encrypt(argv, 2);
        // allow the contents of argv[2] to be encrypted
    }

    else if (strcmp(argv[1], "-D")== 0)
    {
        printf("decrypt\n");
        decrypt(argv, 2);
        // this allows the decryption to occur
    }

    else
    {
        printf("due to no selection, default encryption is selected\n");
        emcrypt(argv, 1);
    }

    //all files must be closed

    fclose(int_file);
    fclose(out_file);
    return(0);
}



}