#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include "bloom_filter.h"


void disp1()
{
    system("clear"); 
    printf("1. Add string in bloom filter 1 : \n"); 
    printf("2. Find in bloom filter 1 : \n"); 
    printf("3. Bloom filter 1 health : \n"); 
    printf("4. Add string in bloom filter 2 : \n"); 
    printf("5. Find in bloom filter 2 : \n"); 
    printf("6. Bloom filter 2 health : \n"); 
    printf("7. Check in Union of 1 and 2 : \n"); 
    printf("8. Check in Intersection of 1 and 2 : \n"); 
    printf("9. Calculate the Jaccard Index of the two : \n"); 
    printf("0. Exit : \n");
    printf("-1. to clear screen : \n");
}

int main()
{

    bloom_filter b1; 
    bloom_filter b2; 
    bloom_filter * b3 = NULL; 

    int m; 
    float p;
    printf("Bloom filter Inputs : \n");
    printf("Enter estimate : "); 
    scanf("%d", &m); 
    printf("Enter false positivity (0.0 < p < 1.0) : "); 
    scanf("%f",&p);  
    
    
    if(BLOOM_SUCCESS == bloom_filter_init(&b1, m, p, NULL) && BLOOM_SUCCESS == bloom_filter_init(&b2, m, p, NULL))
    {
        printf("Successfully !! initialized the bloom filter \n");
    }
    else{ 
        printf("<< ERROR in initializing bloom filter >> \n"); 
        exit(1); 
    }

    disp1(); 

    int start = 1;
    int choice; 
    while(start)
    {
        printf("\nEnter the choice : "); 
        scanf("%d",&choice); 
        switch(choice)
        {
            case 1: 
                {
                    char string1[100]; 
                    printf("\nEnter the string : "); 
                    scanf("%s",string1); 
                    if(BLOOM_SUCCESS ==  add_string(&b1, string1)){
                        printf("added!!\n");
                    }
                    break; 
                }
            case 2:
                {
                    char string2[100]; 
                    printf("\nEnter the string to search in bloom filter 1 :"); 
                    scanf("%s",string2); 
                    if(BLOOM_SUCCESS == is_present_bloom_filter(&b1,string2)){
                        printf("present !!\n");
                    }else{
                        printf("not found\n");
                    }
                    break; 
                }
            case 3:
                {
                    stats_bloom_filter(&b1); 
                    break;
                }
            case 4: 
                {
                    char string3[100]; 
                    printf("\nEnter the string : "); 
                    scanf("%s",string3); 
                    if(BLOOM_SUCCESS ==  add_string(&b2, string3)){
                        printf("added!!\n");
                    }
                    break; 
                }
            case 5:
                {
                    char string4[100]; 
                    printf("\nEnter the string to search in bloom filter 2 :"); 
                    scanf("%s",string4); 
                    if(BLOOM_SUCCESS == is_present_bloom_filter(&b2,string4)){
                        printf("present !!\n");
                    }else{
                        printf("not found!!\n");
                    }
                    break; 
                }
            case 6: 
                {
                    stats_bloom_filter(&b2); 
                    break;
                }
            case 7:
                {
                    b3 = union_bloom_filters(&b1,&b2); 
                    stats_bloom_filter(b3);
                    char string5[100]; 
                    
                    int go = 1;
                    while(go){
                        printf("\nEnter the string to search in bloom filter union :"); 
                        scanf("%s",string5);
                        if(BLOOM_SUCCESS == is_present_bloom_filter(b3,string5)){
                            printf("present !! \n");
                        } 
                        else{
                            printf("not found !!\n");
                        }
                        int t;
                        printf("check more ? ");
                        scanf("%d",&t); 
                        go = t;
                    }
                    stats_bloom_filter(b3); 
                    free(b3);
                    disp1();
                    break; 
                }
            case 8:
                {
                    b3 = intersection_bloom_filters(&b1,&b2); 
                    stats_bloom_filter(b3);
                    char string6[100]; 
                    
                    int go = 1;
                    while(go){
                        printf("\nEnter the string to search in bloom filter intersection :"); 
                        scanf("%s",string6);
                        if(BLOOM_SUCCESS == is_present_bloom_filter(b3,string6)){
                            printf("present !! \n");
                        } 
                        else{
                            printf("not found !!\n");
                        }
                        int t;
                        printf("check more ? ");
                        scanf("%d",&t); 
                        go = t;
                    }
                    stats_bloom_filter(b3); 
                    free(b3);
                    disp1();
                    break; 
                }
            case 9:
                {
                    printf("\nThe jaccard index of b1 and b2 = %Lf\n",jaccard_index_bloom_filters(&b1,&b2));
                    break;
                }
            case 0: 
                {
                    exit(1);
                }
            case -1:
                {
                    disp1();
                    break;
                }
            default:
                printf("Invalid input \n");
        }
    }   

}