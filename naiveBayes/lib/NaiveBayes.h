#ifndef NAIVE_BAYES_H
#define NAIVE_BAYES_H

namespace probability {
  typedef struct {
      std::vector<std::vector<float>> Mean_Stdev;
      float class_prob;
  } class_summary;

  class NaiveBayes {
       private:
          std::vector<class_summary> Summary;
          std::vector<float> unique_label;
       
       public:
          void fit(std::vector<std::vector<float>> dataset);
          int  predict(const std::vector<float>& test_data);
  };

  class_summary calculateClassSummary(std::vector<std::vector<float>> dataset, float class_label);
  float probBySummary(cost std::vector<float> &test_data, const class_summary &summary);
}

#endif // naiveBayes.h




