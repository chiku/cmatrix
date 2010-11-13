// Written by     : Chirantan Mitra

#include <matrix_test.h>

class testFunctionoidWithOneParameter
{
    public:
        double operator() (double x) 
        { 
            return x + 1.0;
        }
};

class testFunctionoidWithTwoParameters
{
    public:
        double operator() (double x, double y) 
        { 
            return x + y;
        }
};

 
void MatrixTest::a2x2MatrixOnGettingAFunctionoidForOneParameterAppliesItToAllMembers()
{
    Matrix<double> twoByTwoMatrix(2, 2);
    twoByTwoMatrix(0, 0) = 1.0; twoByTwoMatrix(0, 1) = 2.0;
    twoByTwoMatrix(1, 0) = 3.0; twoByTwoMatrix(1, 1) = 4.0;
    
    Matrix<double> expectedMatrix(2, 2);
    expectedMatrix(0, 0) = 2.0; expectedMatrix(0, 1) = 3.0;
    expectedMatrix(1, 0) = 4.0; expectedMatrix(1, 1) = 5.0;
     
    CPPUNIT_ASSERT (twoByTwoMatrix.map(new testFunctionoidWithOneParameter) == expectedMatrix);    
    CPPUNIT_ASSERT (twoByTwoMatrix != expectedMatrix);    
}
 
void MatrixTest::a2x2MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPosition()
{
    Matrix<double> twoByTwoMatrix(2, 2);    
    Matrix<double> expectedMatrix(2, 2);
    expectedMatrix(0, 0) = 0.0; expectedMatrix(0, 1) = 1.0;
    expectedMatrix(1, 0) = 1.0; expectedMatrix(1, 1) = 2.0;
     
    CPPUNIT_ASSERT (twoByTwoMatrix.fillByPosition(new testFunctionoidWithTwoParameters) == expectedMatrix);    
    CPPUNIT_ASSERT (twoByTwoMatrix == expectedMatrix);    
}
 
void MatrixTest::a3x3MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPositionAndShift()
{
    Matrix<double> threeByThreeMatrix(3, 3);
    Matrix<double> expectedMatrix(3, 3);
    expectedMatrix(0, 0) = -2.0; expectedMatrix(0, 1) = -1.0; expectedMatrix(0, 2) = 0.0;
    expectedMatrix(1, 0) = -1.0; expectedMatrix(1, 1) =  0.0; expectedMatrix(1, 2) = 1.0;
    expectedMatrix(2, 0) =  0.0; expectedMatrix(2, 1) =  1.0; expectedMatrix(2, 2) = 2.0;
     
    CPPUNIT_ASSERT (threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1) == expectedMatrix);    
    CPPUNIT_ASSERT (threeByThreeMatrix == expectedMatrix);    
}
 
void MatrixTest::a3x3MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPositionAndShiftAndScale()
{
    Matrix<double> threeByThreeMatrix(3, 3);
    Matrix<double> expectedMatrix(3, 3);
    expectedMatrix(0, 0) = 1.0; expectedMatrix(0, 1) = -2.0; expectedMatrix(0, 2) =  -5.0;
    expectedMatrix(1, 0) = 3.0; expectedMatrix(1, 1) =  0.0; expectedMatrix(1, 2) =  -3.0;
    expectedMatrix(2, 0) = 5.0; expectedMatrix(2, 1) =  2.0; expectedMatrix(2, 2) =  -1.0;
     
    CPPUNIT_ASSERT (threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1, 2.0, -3.0) == expectedMatrix);    
    CPPUNIT_ASSERT (threeByThreeMatrix == expectedMatrix);    
}

