#include<stdio.h>
#define MAX_LIMIT 999

int graph[10][10], completed[10];
int numberOfPlaces, cost=0;

void adorn(){
    const char* line = "\n ==========================================\n";
    const char* title = "  ** TRAVELLING * SALESPERSON * PROBLEM ** \n"; 
    printf("%s", line);
    printf("%s", title);
    printf("%s", line);
}

void takeInput(){
    int i, j;
    adorn();
    printf("  Enter how many villages should be visited.\n");
    printf("  Total of places: ");
    scanf("%d", &numberOfPlaces);
    printf(" Ok. Now provide us with the Cost Matrix.\n");
    for(i=0; i<numberOfPlaces; i++){
        printf(" --> Enter element of row: %d\n", i+1);
        for(j=0; j<numberOfPlaces; j++){
            scanf("%d", &graph[i][j]);
        }
        completed[i] = 0;
    }
    printf("\n The cost list is: ");
    for(i=0; i<numberOfPlaces; i++){
        printf("\n");
        for(j=0; j<numberOfPlaces; j++){
            printf("\t %d", graph[i][j]);
        }
    }
    adorn();
}

int least(int place){
    int i, nc = MAX_LIMIT;
    int min = nc, kmin;
    for(i=0; i<numberOfPlaces; i++){
        if((graph[place][i] != 0) && (completed[i]==0)){
            if(graph[place][i] + graph[i][place] < min){
                min = graph[i][0] + graph[place][i];
                kmin = graph[place][i];
                nc = i;
            }

        }
    }
    if(min != MAX_LIMIT){
            cost += kmin;
    }
  return nc;
}

void mininumCost(int city){
    int numCities;

    completed[city] = 1;
    printf("Village %d----->", city+1);
    numCities = least(city);
    if(numCities == MAX_LIMIT){
        numCities = 0;
        printf("\n \t back to village-->%d\n", numCities+1);
        cost += graph[city][numCities];
        return;
    }
    mininumCost(numCities);
}

int main(void){

  takeInput();
  printf("\n\t The path is: \n\n");

  mininumCost(0); // passing zero because of starting vertex
  printf("\n\t  Minimum cost is: %d\n", cost);
  
  adorn();
  return 0;
}