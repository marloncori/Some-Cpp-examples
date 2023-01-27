#include<iostream> 
#include<chrono> 
#include<random> 
#include<iomanip>

namespace algorithm {
   float sigmoid(float number){
     return 1.0 / 1.0 + std::exp(-number);
   }  
   float softmax(float input){
     return std::exp(input) / (float)(std::exp(input)+std::exp(input));
   }
}

int main() 
{ 
    /* Create random engine with the help of seed */
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count(); 
    std::default_random_engine e (seed); 
  
    /* declaring normal distribution object 'distN' and initializing its mean and standard deviation fields. */
  /* Mean and standard deviation are distribution parameters of Normal distribution. Here, we have used mean=5, and standard deviation=2. You can take mean and standard deviation as per your choice */
    std::normal_distribution<double> distN(5,2); 
    
    int n;
    std::cout<<"\nEnter no. of samples: ";
    std::cin>>n;
    std::cout<<"\nNormal distribution for "<<n<<" samples (mean=5, standard deviation=2) =>\n";
    for (int i=1; i<=n; i++)
    {
      std::cout <<i <<". " << distN(e); 
      std::cout << std::setw(10) << i <<". " << algorithm::sigmoid(distN(e));
      std::cout << std::setw(20) << i <<". " << algorithm::softmax(distN(e))<<"\n";  
    }   
  
  return 0; 
}