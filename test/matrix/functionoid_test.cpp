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

Describe(CMatrix_when_receiving_a_functionoid_with_one_parameter)
{
    Describe(On_map)
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

        It(applies_it_to_all_members)
        {
            Assert::That(twoByTwoMatrix.map(new testFunctionoidWithOneParameter), Equals(expectedMatrix));
        }

        It(does_not_mutate)
        {
            twoByTwoMatrix.map(new testFunctionoidWithOneParameter);
            Assert::That(twoByTwoMatrix, !Equals(expectedMatrix));
        }
    };
};

Describe(CMatrix_when_receiving_a_functionoid_with_two_parameters)
{
    Describe(On_fill_by_position)
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

        It(applies_it_to_all_members)
        {
            Assert::That(twoByTwoMatrix.fillByPosition(new testFunctionoidWithTwoParameters), Equals(expectedMatrix));
        }

        It(mutates)
        {
            twoByTwoMatrix.fillByPosition(new testFunctionoidWithTwoParameters);
            Assert::That(twoByTwoMatrix == expectedMatrix);
        }
    };

    Describe(On_fill_by_position_and_shift)
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

        It(applies_it_to_all_members)
        {
            Assert::That(threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1), Equals(expectedMatrix));
        }

        It(mutates)
        {
            threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1);
            Assert::That(threeByThreeMatrix, Equals(expectedMatrix));
        }
    };

    Describe(On_fill_by_position_and_shift_and_scale)
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

        It(applies_it_to_all_members)
        {
            Assert::That(threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1, 2.0, -3.0), Equals(expectedMatrix));
        }

        It(mutates)
        {
            threeByThreeMatrix.fillByPosition(new testFunctionoidWithTwoParameters, 1, 1, 2.0, -3.0);
            Assert::That(threeByThreeMatrix, Equals(expectedMatrix));
        }
    };
};
