#include <iostream>
#include <vector>
#include <ctime>

#include "Helpers.hpp"
#include "preprocessing.h"
#include "iris.h"
#include "NaiveBayes.h"

int main(){
    std::vector<std::vector<float>> dataset = ReadIrisDataset();
    NaiveBayes theorem = new NaiveBayes();

    std::srand (unsigned (std::time(0)));
    dataset = vect_transpose(dataset);

    std::random_shuffle(dataset.begin(), dataset.end());
    dataset = vect_transpose(dataset);

    float percentage = 70;
    std::vector<std::vector<float>> training_data = 
           vector_train_split(dataset, percentage);
    std::vector<std::vector<float>> testing_data = 
            vector_test_split(dataset, 100-percentage);
    
    std::cout << " IRIS testing data size is ( " << testing_data.size() 
       << " , " << testing_data[0].size() << ")." << std::endl;

    std::cout << " IRIS training data size is ( " << testing_data.size() 
       << " , " << training_data[0].size() << ")." << std::endl;

    theorem.fit(training_data);

    std::vector<float> predicitions;
    testing_data = vect_tranpose(testing_data);

    for(int i=0; i<testing_data; i++){
        auto index = theorem.predict(testing_data[i]);
        predictions.push_back(index);
    }

    testing_data = vect_transpose(testing_data); 
    std::cout<<"   score is :" << vect_match_Score(testing_data[4],predicitions) << std::endl;
 
   return 0;
 }





