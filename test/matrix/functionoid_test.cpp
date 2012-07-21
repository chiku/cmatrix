// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

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

Describe(CMatrix_When_Receiving_A_Functionoid_With_One_Parameter)
{
    Describe(On_Map)
    {
        Matrix<double> twoByTwoMatrix;
        Matrix<double> expectedMatrix;

        void SetUp()
        {
            twoByTwoMatrix.setSize(2, 2);
            twoByTwoMatrix(0, 0) = 1.0; twoByTwoMatrix(0, 1) = 2.0;
            twoByTwoMatrix(1, 0) = 3.0; twoByTwoMatrix(1, 1) = 4.0;

            expectedMatrix.setSize(2, 2);
            expectedMatrix(0, 0) = 2.0; expectedMatrix(0, 1) = 3.0;
            expectedMatrix(1, 0) = 4.0; expectedMatrix(1, 1) = 5.0;
        }

        It(AppliesItToAllMembers)
        {
            Assert::That(twoByTwoMatrix.map(new testFunctionoidWithOneParameter), Equals(expectedMatrix));
        }

        It(DoesNotMutate)
        {
            twoByTwoMatrix.map(new testFunctionoidWithOneParameter);
            Assert::That(twoByTwoMatrix, !Equals(expectedMatrix));
        }
    };
};

Describe(CMatrix_When_Receiving_A_Functionoid_With_Two_Parameters)
{
    Describe(On_Fill_By_Position)
    {
        Matrix<double> twoByTwoMatrix;
        Matrix<double> expectedMatrix;

        void SetUp()
        {
            twoByTwoMatrix.setSize(2, 2);
            expectedMatrix.setSize(2, 2);
            expectedMatrix(0, 0) = 0.0; expectedMatrix(0, 1) = 1.0;
            expectedMatrix(1, 0) = 1.0; expectedMatrix(1, 1) = 2.0;
        }

        It(AppliesItToAllMembers)
        {
            Assert::That(twoByTwoMatrix.fillByPosition(new testFunctionoidWithTwoParameters), Equals(expectedMatrix));
        }

        It(Mutates)
        {
            twoByTwoMatrix.fillByPosition(new testFunctionoidWithTwoParameters);
            Assert::That(twoByTwoMatrix == expectedMatrix);
        }
    };

    Describe(On_Fill_By_Position_And_Shift)
    {
        Matrix<double> threeByThreeMatrix;
        Matrix<double> expectedMatrix;

        void SetUp()
        {
            threeByThreeMatrix.setSize(3, 3);
            expectedMatrix.setSize(3, 3);
            expectedMatrix(0, 0) = -2.0; expectedMatrix(0, 1) = -1.0; expectedMatrix(0, 2) = 0.0;
            expectedMatrix(1, 0) = -1.0; expectedMatrix(1, 1) =  0.0; expectedMatrix(1, 2) = 1.0;
            expectedMatrix(2, 0) =  0.0; expectedMatrix(2, 1) =  1.0; expectedMatrix(2, 2) = 2.0;
        }

        It(AppliesItToAllMembers)
        {
            Assert::That(threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1), Equals(expectedMatrix));
        }

        It(Mutates)
        {
            threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1);
            Assert::That(threeByThreeMatrix, Equals(expectedMatrix));
        }
    };

    Describe(On_Fill_By_Position_And_Shift_And_Scale)
    {
        Matrix<double> threeByThreeMatrix;
        Matrix<double> expectedMatrix;

        void SetUp()
        {
            threeByThreeMatrix.setSize(3, 3);
            expectedMatrix.setSize(3, 3);
            expectedMatrix(0, 0) = 1.0; expectedMatrix(0, 1) = -2.0; expectedMatrix(0, 2) =  -5.0;
            expectedMatrix(1, 0) = 3.0; expectedMatrix(1, 1) =  0.0; expectedMatrix(1, 2) =  -3.0;
            expectedMatrix(2, 0) = 5.0; expectedMatrix(2, 1) =  2.0; expectedMatrix(2, 2) =  -1.0;
        }

        It(AppliesItToAllMembers)
        {
            Assert::That(threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1, 2.0, -3.0), Equals(expectedMatrix));
        }

        It(Mutates)
        {
            threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1, 2.0, -3.0);
            Assert::That(threeByThreeMatrix, Equals(expectedMatrix));
        }
    };
};
