#include <vector>

template<typename T>
T Mean(std::vector<T> data){
    T mean = std::accumulate(std::begin(data),
             std::end(data), 0.0) / data.size();
 
    return mean;
}

template<typename M>
double standardDeviation(std::vector<M> &datsa){
    M mean = std::accumulate(std::begin(data),
              std::end(data), 0.0) / data.size();
    
    double sq_sum = std::inner_product(data.begin(),
         data.end(), data.begin(), 0.0);
    
    double standard_deviation = std::sqrt(sq_sum / data.size() 
          - (double) (mean * mean));

    return standard_deviation;
}

template<typename U>
U calcProbability(U value, U mean, U deviation){
    
    static const U inv_sqrt_2pi = 0.3989422804014327;
    U a = (value - mean) / deviation;
    U probability = inv_sqrt_2pi / deviation * std::exp(-0.5f * a * a);
    
    return probability;
}

template<typename F>
F Vect_match_Score (const std::vector<F> &labels, const std::vector<F> &predictions )
{
    F result = 0.0; 
    size_t index = 0;
    std::for_each(labels.begin(), labels.end(), [&](F label)
    { 
        if(label == predictions[index])
        {
            result++;
        }
        index++; 
    });
    return F(100*result/labels.size());
}



