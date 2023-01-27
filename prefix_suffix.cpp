
#include <iostream>
constexpr int MAX = 100;

void show_result(int n, int temp[]){ 
    std::cout << "\n  Resultant array after adding \n prefix to each element in the array." << std::endl;
       for(int i=0; i<2*n-1; i++){
         std::cout << "\n\t >>> " << temp[i] << std::endl;
      }
}

void add_prefix(int array[], int n, int prefix){
    int temp[MAX], counter=1;

    for(int i=0; i<2*n-1; i++){
        if(i % 2 == 0){
            temp[i] = prefix;
        }
        else {
            temp[i] = array[i-counter];
            counter++;
        }
    }
    show_result(n, temp);
}

void add_suffix(int arr[], int n, int suffix){
    int temp[MAX];

    for(int i=0; i<2*n-1; i++){
       if(i % 2 == 1){
          temp[i] = suffix;
        }
        else {
          temp[i] = arr[i/2];
        }
     show_result(n, temp);       
    }
}

void process_option(int ch, int arr[], int n){
    int prefix = 0, suffix = 0;
    
    switch(ch)
  {
    case 1: 
      std::cout<<"\nEnter prefix: ";
      std::cin>>prefix;
      add_prefix(arr,n,prefix);
      break;
      
    case 2:
      std::cout<<"\nEnter suffix: ";
      std::cin>>suffix;
      add_suffix(arr,n,suffix);
      break;
    
    /* Writing default case is not compulsory but it is a good programming practice. We can write default case anywhere in the switch block */  
    default:
      std::cout<<"\nInvalid choice..!!";
      break;
  }
}

int main(){
    int n, ch, arr[MAX], i;

    std::cout << "Enter no. of elements of the list: ";
    std::cin >> n;
  
    std::cout << "\nEnter elements of the list: ";
    for( i = 0; i < n; i++)
    {
      std::cin >> arr[i];
    }

    std::cout << "\n ****menu****";
    std::cout << "\n 1) Add prefix to each element in a list";
    std::cout << "\n 2) Add suffix to each element in a list";
    std::cout << "\n Enter your choice (1 or 2): ";
    std::cin >> ch;
    
    process_option(ch, arr, n);

  return 0;
}