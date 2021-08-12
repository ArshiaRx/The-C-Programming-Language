#include <stdio.h>

//Type the struct here


//Type the function prototypes here



int main()
{
   //Type your code here:
    
    return 0;
}

void menu()
{

}



void displayInventory(const char filename[])
{
    //Define an object of struct Book
    
    
    //Open the file, and check for null pointer
    
    
    //If the file is properly opened, display headers, similar to workshop 8
    
    
    
    //Use a while loop to call readRecord and display the records.
    while(/*call readRecord and check its return value*/)
        //display the record
        
        
        
    //Display the footer
    
    //Close the file

}





void addBook(const char filename[], struct Book *b2Add)
{
    
    //Open the file for appending (a+)
    
    //Type your code here
    
    
    
    //Close the file
}

void checkPrice(const char filename[],const int isbn2find)
{
    
    //Open the file for reading
    
    //Type your code here
    
    
    
    //Close the file
 
}

int searchInventory(FILE *fp,const int isbn2find)
{
    //Define an object of struct Book and other necessary variables
    
    //If the file ponter is not NULL:
        //as long as the record is not found,
        //use the function readRecord to read the recods and look for isbn2find

    
    
}


float calculateCapital(const char filename[])
{
    
    
    //Define an object of struct Book
    
    //Define and initialize total_capital
    
    
    //Open the file, and check for null pointer
    
    
    //If the file is properly opened, use a while loop to call readRecord
    while(/*call readRecord and check its return value*/)
        //Accumulate the multiplication of the price of each item to its quantity
        
        
        
    //Display the footer
        
    //Close the file
        
    //return the total_capital
    
}

int readRecord(FILE *fp, struct Book *b2read)
{
    //Define a variable int rv = 0
    
    rv = fscanf(/*Type your code here*/);
   
    //return rv;

}
