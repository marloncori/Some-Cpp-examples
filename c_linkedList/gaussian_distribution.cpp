
#include<iostream> 
#include<chrono> 
#include<random> 

using namespace std; 
  
int main() 
{ 
    /* Create random engine with the help of seed */
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); 
    default_random_engine e (seed); 
  
    /* declaring normal distribution object 'distN' and initializing its mean and standard deviation fields. */
  /* Mean and standard deviation are distribution parameters of Normal distribution. Here, we have used mean=5, and standard deviation=2. You can take mean and standard deviation as per your choice */
    normal_distribution<double> distN(5,2); 
    
    int n;
    cout<<"\nEnter no. of samples: ";
    cin>>n;
    cout<<"\nNormal distribution for "<<n<<" samples (mean=5, standard deviation=2) =>\n";
    for (int i=1; i<=n; i++)
    {
      cout<<i<<". "<<distN(e)<<"\n"; 
    }   
  
  return 0; 
}