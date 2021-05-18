#include <stdio.h>  
#include <stdlib.h>
#include <string.h> 
#include "bloom_filter.h"

void displayInfo(){
    printf("\n1.insert a string in the bloom filter : \n"); 
    printf("2.Look up a string in the bloom filter : \n");
    printf("3.Show bloom filter health : \n"); 
    printf("4.Reset the filter : \n"); 
    printf("5.Clear Screen : \n");
    printf("6.Exit : \n"); 
    printf("\n\nNOTE : Reset the bloom filter if health becomes POOR"); 
}

int main()
{
    bloom_filter b;
    
    bloom_filter b1; 
    bloom_filter b2; 
    int m; 
    float p;
    printf("Bloom filter Inputs : \n");
    printf("Enter estimate : "); 
    scanf("%d", &m); 
    printf("Enter false positivity (0.0 < p < 1.0) : "); 
    scanf("%f",&p);  

    if(BLOOM_SUCCESS == bloom_filter_init(&b, m, p, NULL))
    {
        printf("Successfully !! initialized the bloom filter \n");
    }else{ 
        printf("<< ERROR in initializing bloom filter >> \n"); 
        exit(1); 
    }
    int choice;  
    int start = 1; 
    displayInfo(); 
    while(start)
    {   
        printf("\nEnter the choice : ");
        scanf("%d",&choice); 
        switch(choice)
        {
            case 1: 
                {
                    char string[100]; 
                    printf("\nEnter string to insert : "); 
                    scanf("%s",string); 
                    if(BLOOM_SUCCESS == add_string(&b, string)){
                        printf("added\n"); 
                    }else{ 
                        printf("<<Fatal error occured >>\n"); 
                    }
                    break;
                }
            case 2:
                {
                    char searchString[100]; 
                    printf("\nEnter string to find in bloom filter : "); 
                    scanf("%s",searchString); 
                    if(BLOOM_SUCCESS == is_present_bloom_filter(&b, searchString)){
                        printf("present !!"); 
                    }else{
                        printf("Not found !!\n"); 
                    }
                    break;
                }
            case 3:
                {
                    stats_bloom_filter(&b);
                    break;
                }
            case 4:
                {
                    reset_bloom_filter(&b);
                    printf("\nBloom filter reset done check health to more : ");  
                    break;
                }
            case 5: 
                {
                    system("clear");
                    displayInfo();
                    break;
                }
            case 6:
                {
                    start = 0;
                    break; 
                }
            default: 
                printf("\nInvalid Input :");
        }
    }



}