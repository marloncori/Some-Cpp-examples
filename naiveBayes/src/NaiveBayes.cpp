
#include <vector>
#include "NaiveBayes.h"

void probability::NaiveBayes::fit(std::vector<std::vector<float>> dataset){
    unique_label = dataset[dataset.size()-1];
    std::sort(unique_label.begin(), unique_label.end());
    unique_label.erase(std::unique(unique_label.begin(),
        unique_label.end()), unique_label.end());
    for(auto row = unique_label.begin(); row != unique_label.end(); ++row){
        summary.push_back(calculateClassSummary(dataset, *row));
    }
}

int probability::NaiveBayes::predict(const std::vector<float>& test_data){
    std::vector<float> out;
    for(auto row = unique_label.begin(); row != unique_label.end(); ++row){
        out.push_back(probBySummary(test_data, summary[*row]));
    }
    int maxElementIndex = std::max_element(out.begin(), out.end()) - out.begin();
    return maxElementIndex;
}

class_summary probability::calculateClassSummary(std::vector<std::vector<float>> dataset, float class_label){
    auto class_data = split_by_class(dataset, class_label);
    
    class_summary summary;
    std::vector<float> temp;
    for(auto row = unique_label.begin(); row != unique_label.end()-1; row++){
        temp.clear();
        temp.push_back(alg_math::Math_Mean(*row));
        temp.push_back(alg_math::Math_Var(*row));
        summary.Mean_StDev.push_back(temp);
    }
    summary.class_prob = float(class_data[0].size()/dataset[0].size());
    
    return summary;
}

float probability::probBySummary(cost std::vector<float> &test_data, const class_summary &summary){
    int index = 0;
    float prob = 1;
    for(auto row = summary.Mean_Stdev.begin(); row != summary.Mean_Stdev.end()-1; row++){
        prob *= calc_prob(test_data[index], (*row)[0], (*row)[1]);
        index++;
    }
    // multiply by the class probability
    prob *= summary.class_prob;
    return prob;
 }




