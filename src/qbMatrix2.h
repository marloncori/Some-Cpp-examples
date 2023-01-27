#ifndef QBMATRIX2_H_
#define QBMATRIX2_H_

    #include <system_error>
    #include <errno.h>

template <class T>
class qbMatrix2 {
    public:
        // two dimension matrix class
        qbMatrix2();
        qbMatrix2(int nRows, int nCols);
        qbMatrix2(int nRows, int nCols, const T *inputData);
        qbMatrix2(const qbMatrix2<T>& inputMatrix);

        ~qbMatrix2();
        // configuration method
        bool resize(int numRows, int numCols);
        // element access methods
        T getElement(int row, int col);
        bool setElement(int row, int col, T elemVal);
        int getNumRows();
        int getNumCols();
        //overload == operator 
        bool operator== (const qbMatrix2<T>& rhs);

        //overload +, - and * operators
        template <class U> friend qbMatrix2<U> operator+ (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs);
        template <class U> friend qbMatrix2<U> operator+ (const U& lhs, const qbMatrix2<U>& rhs);
        template <class U> friend qbMatrix2<U> operator+ (const qbMatrix2<U>& lhs, const U& rhs);

        template <class U> friend qbMatrix2<U> operator- (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs);
        template <class U> friend qbMatrix2<U> operator- (const U& lhs, const qbMatrix2<U>& rhs);
        template <class U> friend qbMatrix2<U> operator- (const qbMatrix2<U>& lhs, const U& rhs);

        template <class U> friend qbMatrix2<U> operator* (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs);
        template <class U> friend qbMatrix2<U> operator* (const U& lhs, const qbMatrix2<U>& rhs);
        template <class U> friend qbMatrix2<U> operator* (const qbMatrix2<U>& lhs, const U& rhs);
    
    private:
        int sub2Ind(int row, int col);

    private:
        T *m_matrixData;
        int m_nRows, m_nCols, m_nElems;
};

template <class T>
qbMatrix2<T>::qbMatrix2(){

    m_nRows = 1;
    m_nCols = 1;
    m_nElems = 1;
    m_matrixData = new T[m_nElems];
    m_matrixData[0] = 0.0;
}

template <class T>
qbMatrix2<T>::qbMatrix2(int nRows, int nCols){
 if((nRows <= 0) || (nRows <= 0)){
     throw std::system_error(errno,
            std::system_category(), "Number of columns and number of rows have to be greater than 0!");
 }
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElems = m_nRows * m_nCols;
    m_matrixData = new T[m_nElems];
    for(int i = 0; i < m_nElems; i++){
        m_matrixData[i] = 0.0;
    }
}

template <class T>
qbMatrix2<T>::qbMatrix2(int nRows, int nCols, const T *inputData){
  if((nRows <= 0) || (nRows <= 0)){
     throw std::system_error(errno,
            std::system_category(), "Number of columns and number of rows have to be greater than 0!");
 }

 if(inputData.size() == 0){
   throw std::system_error(errno,
            std::system_category(), "No input data has been provided. It is not possible to create a matrix!");    
 }
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElems = m_nRows * m_nCols;
    m_matrixData = new T[m_nElems];
    for(int i = 0; i < m_nElems; i++){
        m_matrixData[i] = inputData[i];
    }
}

template <class T>
qbMatrix2<T>::qbMatrix2(const qbMatrix2<T>& inputMatrix){
    m_nRows = inputMatrix.m_nRows;
    m_nCols = inputMatrix.m_nCols;
    m_nElems = inputMatrix.m_nElems;
    m_matrixData = new T[m_nElems];
    for(int i = 0; i < m_nElems; i++){
        m_matrixData[i] = inputMatrix.m_matrixData[i];
    }
}

template <class T>
qbMatrix2<T>::~qbMatrix2(){
    if(m_matrixData != nullptr){
        delete[] m_matrixData;
    }
}

//configuration functions
template <class T>
bool qbMatrix2<T>::resize(int numRows, int numCols){
  if((numRows <= 0) || (numCols <= 0)){
   throw std::system_error(errno,
            std::system_category(), "Number of columns and number of rows have to be greater than 0!");
    return false;
  }
    m_nRows = numRows;
    m_nCols = numCols;
    m_nElems = (m_nRows * m_nCols);
    delete[] m_matrixData;
    m_matrixData = new T[m_nElems];
    if(m_matrixData != nullptr){
        for(int i = 0; i < m_nElems; i++){
            m_matrixData[i] = 0.0;
        }
       return true;
    } else {
        return false;
    }
}

template <class T>
T qbMatrix2<T>::getElement(int row, int col){
  if((row < 0) || (col < 0)){
    throw std::system_error(errno,
            std::system_category(), "Number of column and/or row cannot be smaller than 0!");
    return -1;
  }
    int linearIdx = sub2Ind(row, col);
    if(linearIdx >= 0){
        return m_matrixData[linearIdx];
    } else {
        return 0.0;
    }
}

template <class T>
bool qbMatrix2<T>::setElement(int row, int col, T elemVal){
  if((row < 0) || (col < 0)){
   throw std::system_error(errno,
            std::system_category(), "Number of column and/or row cannot be smaller than 0!");
    return false;
  }

  if(elemVal == NULL){
    throw std::system_error(errno,
            std::system_category(), "ERROR! Element value cannot be null!");
    return false;
  }
    int linearIdx = sub2Ind(row, col);
    if(linearIdx >= 0){
       m_matrixData[linearIdx] = elemVal;
       return true;
    } else {
        return false;
    }
}

template <class T>
int qbMatrix2<T>::getNumRows(){
    return m_nRows;
}

template <class T>
int qbMatrix2<T>::getNumCols(){
    return m_nCols;
}

// matrix + matrix
template <class U>
qbMatrix2<U> operator+ (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs){
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElems = numRows * numCols;
    U *sumResult = new U[numElems];
    for(int i = 0; i < numElems; i++){
        sumResult[i] = lhs.m_matrixData[i] + rhs.m_matrixData[i];
    }    
    qbMatrix2<U> result(numRows, numCols, sumResult);
    delete[] sumResult;
    return result;
}

// scaler + matrix
template <class U>
qbMatrix2<U> operator+ (const U& lhs, const qbMatrix2<U>& rhs){
    int numRows = rhs.m_nRows;
    int numCols = rhs.m_nCols;
    int numElems = numRows * numCols;
    U *sumResult = new U[numElems];
    for(int i = 0; i < numElems; i++){
        sumResult[i] = lhs + rhs.m_matrixData[i];
    }    
    qbMatrix2<U> result(numRows, numCols, sumResult);
    delete[] sumResult;
    return result;
}

// matrix + scaler
template <class U>
qbMatrix2<U> operator+ (const qbMatrix2<U>& lhs, const U& rhs){
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElems = numRows * numCols;
    U *sumResult = new U[numElems];
    for(int i = 0; i < numElems; i++){
        sumResult[i] = lhs.m_matrixData[i] + rhs;
    }    
    qbMatrix2<U> result(numRows, numCols, sumResult);
    delete[] sumResult;
    return result;
}

// matrix - matrix
template <class U>
qbMatrix2<U> operator- (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs){
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElems = numRows * numCols;
    U *subtractResult = new U[numElems];
    for(int i = 0; i < numElems; i++){
        subtractResult[i] = lhs.m_matrixData[i] - rhs.m_matrixData[i];
    }    
    qbMatrix2<U> result(numRows, numCols, subtractResult);
    delete[] subtractResult;
    return result;
}

// scaler - matrix
template <class U>
qbMatrix2<U> operator- (const U& lhs, const qbMatrix2<U>& rhs){
    int numRows = rhs.m_nRows;
    int numCols = rhs.m_nCols;
    int numElems = numRows * numCols;
    U *subtractResult = new U[numElems];
    for(int i = 0; i < numElems; i++){
        subtractResult[i] = lhs - rhs.m_matrixData[i];
    }    
    qbMatrix2<U> result(numRows, numCols, subtractResult);
    delete[] subtractResult;
    return result;
}

// matrix - scaler
template <class U>
qbMatrix2<U> operator- (const qbMatrix2<U>& lhs, const U& rhs){
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElems = numRows * numCols;
    U *subtractResult = new U[numElems];
    for(int i = 0; i < numElems; i++){
        subtractResult[i] = lhs.m_matrixData[i] - rhs;
    }    
    qbMatrix2<U> result(numRows, numCols, subtractResult);
    delete[] subtractResult;
    return result;
}

// overloading * operator, scaler * matrix
template <class U>
qbMatrix2<U> operator* (const U& lhs, const qbMatrix2<U>& rhs){
    int numRows = rhs.m_nRows;
    int numCols = rhs.m_nCols;
    int numElems = numRows * numCols;
    U *prodResult = new U[numElems];
    for(int i = 0; i < numElems; ++i){
        sumResult[i] = lhs * rhs.m_matrixData[i];
    }    
    qbMatrix2<U> result(numRows, numCols, prodResult);
    delete[] prodResult;
    return result;
}

// matrix * scaler
template <class U>
qbMatrix2<U> operator* (const qbMatrix2<U>& lhs, const U& rhs){
    int numRows = rhs.m_nRows;
    int numCols = rhs.m_nCols;
    int numElems = numRows * numCols;
    U *prodResult = new U[numElems];
    for(int i = 0; i < numElems; ++i){
        sumResult[i] = lhs.m_matrixData[i] * rhs;
    }    
    qbMatrix2<U> result(numRows, numCols, prodResult);
    delete[] prodResult;
    return result;
}

// matrix * matrix
template <class U>
qbMatrix2<U> operator* (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs){
    //standard matrix multiplication condition
   if(lhs.m_nCols == rhs.m_nRows){
      U *tempResult = new U[lhs.m_nRows * rhs.m_nCols];
    //loop through each row of the LHS matrix
     for(int lhsRow = 0; lhsRow < lhs.m_nRows; lhsRow++){
         //loop through each column of RHS matrix
         for(int rhsCol = 0; rhsCol < rhs.m_nCols; rhsCol++){
             U elementResult = 0.0;
            //loop through each element of this row
             for(int lhsCol = 0; lhsCol < lhs.m_nCols; lhsCol++){
                 //compute the LHS matrix linear index
                 int lhs_linearIdx = (lhsRow * lhs.m_nCols) + lhsCol;
                 //compute the RHS matrix linear index (based on LHS cols)
                 // rhs matrix row number equals to lhs column number
                 int rhs_linearIdx = (lhsCol * rhs.m_nCols) + rhsCol;

                 //perform the calculation on these elements
                 elementResult += (lhs.m_matrixData[lhs_linearIdx] * rhs.m_matrixData[rhs_linearIdx]);
             }

             int resultLinearIndex = (lhsRow * rhs.m_nCols) + rhsCol;
             tempResult[resultLinearIndex] = elementResult;
          }        
      }
   qbMatrix2<U> result(lhs.m_nRows, rhs.m_nCols, tempResult);
   delete[] tempResult;
   return result;
  } 
  else {
     qbMatrix2<U> result(1, 1);
     throw std::system_error(errno,
         std::system_category(), "ERROR! Number of rows in the first matrix should equal to the number of columns at the second matrix!");
     return result;
  }
}

template<class T>
bool qbMatrix2<T>::operator== (const qbMatrix2<T>& rhs){
    bool isEqual = true;
    
    if((this->m_nRows != rhs.m_nRows) && (this->m_nCols != rhs.m_nCols)){
        isEqual = !isEqual;
        return isEqual;
    }

    for(int i = 0; i < this->m_nElems; ++i){
        if(this->m_matrixData[i] != rhs.m_matrixData[i]){
            isEqual = !isEqual;
        }
    }
    return isEqual;
}

//private functions
template <class T>
int qbMatrix2<T>::sub2Ind(int row, int col){
    if((row < m_nRows) && (row >=0) && (col < m_nCols) && (col >= 0)){
        return (row * m_nCols) + col;
    } else {
        throw std::system_error(errno,
            std::system_category(), "Number of column and/or row cannot be smaller than 0!");
        return -1;
   }
}

#endif // QBMATRIX_H_