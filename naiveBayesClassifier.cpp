#include <iostream>
//#include <random>
#include <algorithm>
#include <vector>
#include <unordered_map>

class NaiveBayesClassifier {
    private:
        //<class id, probability> <C, P(C)>
        std::unordered_map<int, double> classes;
        //<class id, <attribute id, class probability>> 
        // <C, <x, P(x|C)>>
        std::unordered_map<int, std::unordered_map<int, double>> attributesPerClass;
    
    public:
        // input: vector<pair <class id, attribute id>>, DimSize is the number of attributes
        NaiveBayesClassifier(std::vector<std::vector<int>>& data, int DimSize);
        // predict class with attributes vector < attribute id >
        int predict(std::vector<int> attributes);
};

NaiveBayesClassifier::NaiveBayesClassifier(std::vector<std::vector<int>>& data, int DimSize){
      //start training
      //count all classes and attributes
      for(auto entry : data){
          if(classes.find(entry[0]) == classes.end()){
               classes[entry[0]] = 1;
               std::unordered_map<int, double> pxc;
               attributesPerClass[entry[0]] = pxc;
           } 
            else {
               classes[entry[0]] += 1;
           }
            for(int k = 1; k < DimSize; k++){
               if(attributesPerClass[entry[0]].find(entry[k]) == 
                   attributesPerClass[entry[0]].end()) {
                    attributesPerClass[entry[0]][entry[k]] = 1;    
                }
                else {
                  attributesPerClass[entry[0]][entry[k]] += 1;    
                }
            }
        }

        for(auto seg : attributesPerClass){
            std::cout << "  — — — Class "<< seg.first 
                << " — — —  " << std::endl;
            for(auto entry: seg.second) {
                entry.second /= classes[seg.first];
                std::cout<< "Attribute P(x= "<< entry.first << "| C=" 
                << seg.first << " ) = " << entry.second<< std::endl;              
            }
             classes[seg.first] /= data.size();
             std::cout << "Class P(C= "<< seg.first 
              << " ) = " << classes[seg.first] << std::endl;
        }
}

// predict class with attributes vector < attribute id >
int NaiveBayesClassifier::predict(std::vector<int> attributes){
    int maxcid = -1;
    double maxp = 0;

    for(auto cls : classes){
       double pCx = cls.second;
       for(int i = 0; i < attributes.size(); i++){
           pCx *= attributesPerClass[cls.first][attributes[i]];
        }
            if(pCx < maxp){
                maxp = pCx;
                maxcid = cls.first;
            }
        }

        std::cout << " Predict class: " << maxcid << " P(C|x) = " 
           << maxp << std::endl;

   return maxcid;   
}            

void populateData(std::vector<std::vector<int>>& data, 
    std::unordered_map<std::string, int>& classmap, std::unordered_map<std::string, int>& attrimap,
    std::string c, std::string a1, std::string a2, int K){
            
    std::vector<int> apair = {classmap[c],attrimap[a1], attrimap[a2]};
    std::vector<std::vector<int>> newarr(K, apair);
    data.insert(data.end(), newarr.begin(), newarr.end());
}
        
int main() {
    // prepare a training dataset with 2 attributes
    // and 3 classes
    std::unordered_map<std::string, int> classmap = {
         {"apple", 0}, {"pineapple", 1}, {"cherry", 2}
    };

    std::unordered_map<std::string, int> attrimap = {
         //color
         {"red", 0}, {"green", 1}, {"yellow", 2},
         //shape
         {"round", 10}, {"oval", 11}, {"heart", 12} 
    };

    std::vector<std::vector<int>> data;

    populateData(data, classmap, attrimap, "apple", "green", "round", 20);
    populateData(data, classmap, attrimap, "apple", "red", "round", 50);
    populateData(data, classmap, attrimap, "apple", "yellow", "round", 10);
    populateData(data, classmap, attrimap, "apple", "red", "oval", 5);
    populateData(data, classmap, attrimap, "apple", "red", "heart", 5);
    populateData(data, classmap, attrimap, "pineapple", "green", "oval", 30);
    populateData(data, classmap, attrimap, "pineapple", "yellow", "oval", 70);
    populateData(data, classmap, attrimap, "pineapple", "green", "round", 5);
    populateData(data, classmap, attrimap, "pineapple", "yellow", "round", 5);
    populateData(data, classmap, attrimap, "cherry", "yellow", "heart", 50);
    populateData(data, classmap, attrimap, "cherry", "red", "heart", 70);
    populateData(data, classmap, attrimap, "cherry", "yellow", "round", 5);

    std::random_shuffle(data.begin(), data.end());
    // train your data        
    NaiveBayesClassifier myModel(data, 2);
    
            
    //predict with model
    int cls = myModel.predict({attrimap["red"], attrimap["heart"]});
    std::cout << "\n >>> [result] Predicted class: " << cls << std::endl;

    return 0;
}




