// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_Numerical)
{
    Describe(When_Adding)
    {
        It(Two2x2MatricesHasAResultantWithEachPositionTheSumOfTheTwoMatrices)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);
            Matrix<double> expectedSum(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = 0.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) = 4.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedSum(1, 0) = 0.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 8.0;

            Assert::That(firstTwoByTwoMatrix + secondTwoByTwoMatrix, Equals(expectedSum));
        }

        It(Three2x2MatricesHasAResultantWithEachPositionTheSumOfTheThreeMatrices)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);
            Matrix<double> thirdTwoByTwoMatrix(2, 2);
            Matrix<double> expectedSum(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; thirdTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = -1.0; 
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; thirdTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) =  6.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; thirdTwoByTwoMatrix(1, 0) =  3.0; expectedSum(1, 0) =  3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; thirdTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 12.0;

            Assert::That(firstTwoByTwoMatrix + secondTwoByTwoMatrix + thirdTwoByTwoMatrix, Equals(expectedSum));
        }

        It(Two1x2And2x1MatricesThrowsException)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);

            std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
            AssertThrows(Exception::IncompatibleAddition, oneByTwoMatrix + twoByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleAddition>().what(), Equals(expectedMessage));
        }

        It(TwoMatrixOfMatricesHasAResultantWithEachPositionTheSumOfTheComponentMatrices)
        {
            Matrix<Matrix <double> > firstMatrixOfMatrices(1, 2);
            Matrix<Matrix <double> > secondMatrixOfMatrices(1, 2);
            Matrix<Matrix <double> > expectedSum(1, 2);

            Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
            Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);
            Matrix<double> expectedSum0x0(1, 1);    Matrix<double> expectedSum0x1(2, 1);

            firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  2.0; expectedSum0x0(0, 0) =  3.0;
            firstMatrix0x1(0, 0) =  1.0; secondMatrix0x1(0, 0) = -2.0; expectedSum0x1(0, 0) = -1.0;
            firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) =  2.0; expectedSum0x1(1, 0) =  1.0;

            firstMatrixOfMatrices(0, 0) = firstMatrix0x0; secondMatrixOfMatrices(0, 0) = secondMatrix0x0; expectedSum(0, 0) = expectedSum0x0;
            firstMatrixOfMatrices(0, 1) = firstMatrix0x1; secondMatrixOfMatrices(0, 1) = secondMatrix0x1; expectedSum(0, 1) = expectedSum0x1;

            Assert::That(firstMatrixOfMatrices + secondMatrixOfMatrices, Equals(expectedSum));
        }
    };

    Describe(When_Subtracting)
    {
        It(Two2x2MatricesHasAResultantWithEachPositionTheDifferenceOfTheSecondFromTheFirst)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);
            Matrix<double> expectedDifference(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedDifference(0, 0) = 2.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedDifference(0, 1) = 0.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedDifference(1, 0) = 6.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedDifference(1, 1) = 0.0;

            Assert::That(firstTwoByTwoMatrix - secondTwoByTwoMatrix, Equals(expectedDifference));
        }

        It(A1x2MatrixFromA1x1MatrixThrowsException)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByOneMatrix(1, 1);
            std::string expectedMessage = "Cannot subtract [1, 1] from [1, 2]";
            AssertThrows(Exception::IncompatibleSubtraction, oneByTwoMatrix - oneByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleSubtraction>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_Adding_By_Short_Hand)
    {
        Matrix<double> firstTwoByTwoMatrix;
        Matrix<double> secondTwoByTwoMatrix;
        Matrix<double> expectedSum;

        void SetUp()
        {
            firstTwoByTwoMatrix.setSize(2, 2);
            secondTwoByTwoMatrix.setSize(2, 2);
            expectedSum.setSize(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = 0.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) = 4.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedSum(1, 0) = 0.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 8.0;
        }

        It(Two2x2MatricesHasAResultantWithEachPositionTheSumOfTheTwoMatrices)
        {
            Assert::That(firstTwoByTwoMatrix += secondTwoByTwoMatrix, Equals(expectedSum));
        }

        It(MutatesTheFirstMatrix)
        {
            firstTwoByTwoMatrix += secondTwoByTwoMatrix;
            Assert::That(firstTwoByTwoMatrix, Equals(expectedSum));
        }

        It(A1x2MatrixAndA2x1MatrixThrowsException)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);

            std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
            AssertThrows(Exception::IncompatibleAddition, oneByTwoMatrix += twoByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleAddition>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_Subtracting_By_Short_Hand)
    {
        Matrix<double> firstTwoByTwoMatrix;
        Matrix<double> secondTwoByTwoMatrix;
        Matrix<double> expectedDifference;

        void SetUp()
        {
            firstTwoByTwoMatrix.setSize(2, 2);
            secondTwoByTwoMatrix.setSize(2, 2);
            expectedDifference.setSize(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedDifference(0, 0) = 2.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedDifference(0, 1) = 0.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedDifference(1, 0) = 6.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedDifference(1, 1) = 0.0;
        }

        It(Two2x2MatricesHasAResultantWithEachPositionTheDifferenceOfTheSecondFromTheFirst)
        {
            Assert::That(firstTwoByTwoMatrix -= secondTwoByTwoMatrix, Equals(expectedDifference));
        }

        It(MutatesTheFirstMatrix)
        {
            firstTwoByTwoMatrix -= secondTwoByTwoMatrix;
            Assert::That(firstTwoByTwoMatrix, Equals(expectedDifference));
        }

        It(A2x1MatrixFromA1x2MatrixThrowsException)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);

            std::string expectedMessage = "Cannot subtract [2, 1] from [1, 2]";
            AssertThrows(Exception::IncompatibleSubtraction, oneByTwoMatrix -= twoByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleSubtraction>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_Unary_Adding)
    {
        It(ReturnsAMatrixWhoseEachElementIsSameAsTheOriginal)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

            Assert::That(+firstTwoByTwoMatrix, Equals(secondTwoByTwoMatrix));
        }
    };

    Describe(When_Unary_Subtracting)
    {
        It(ReturnsAMatrixWhoseEachElementIsTheAdditiveInverseOfTheOriginal)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) =  1.0; secondTwoByTwoMatrix(0, 0) = -1.0;
            firstTwoByTwoMatrix(0, 1) =  2.0; secondTwoByTwoMatrix(0, 1) = -2.0;
            firstTwoByTwoMatrix(1, 0) = -3.0; secondTwoByTwoMatrix(1, 0) =  3.0;
            firstTwoByTwoMatrix(1, 1) =  4.0; secondTwoByTwoMatrix(1, 1) = -4.0;

            Assert::That(-firstTwoByTwoMatrix, Equals(secondTwoByTwoMatrix));
        }
    };

    Describe(When_Multipling)
    {
        It(Two2x2MatricesHaveAResultantWithEachPositionTheSumOfVectorMultiplicationOfTheTwo)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);
            Matrix<double> expectedProduct(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedProduct(0, 0) = -7.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedProduct(0, 1) = 10.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedProduct(1, 0) = -15.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedProduct(1, 1) = 22.0;

            Assert::That(firstTwoByTwoMatrix * secondTwoByTwoMatrix, Equals(expectedProduct));
        }

        It(A1x2AndA2x1MatrixHaveAResultantWithEachPositionTheSumOfVectorMultiplicationOfTheTwo)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);
            Matrix<double> expectedProduct(1, 1);

            oneByTwoMatrix(0, 0) = 1.0; oneByTwoMatrix(0, 1) = -1.0;
            twoByOneMatrix(0, 0) = 2.0; twoByOneMatrix(1, 0) =  2.0;
            expectedProduct(0, 0) = 0.0;

            Assert::That(oneByTwoMatrix * twoByOneMatrix, Equals(expectedProduct));
        }

        It(A1x2MatrixWithA1x1MatrixThrowsException)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByOneMatrix(1, 1);

            std::string expectedMessage = "Cannot multiply [1, 2] with [1, 1]";
            AssertThrows(Exception::IncompatibleMultiplication, oneByTwoMatrix * oneByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleMultiplication>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_scaling)
    {
        Matrix<double> matrix;
        Matrix<double> result;

        void SetUp()
        {
            matrix.setSize(2, 1);
            matrix(0, 0) = -5.0;
            matrix(1, 0) = 4.0;

            result = matrix.scale(0.5);
        }

        It(TheResultHasSameSize)
        {
            Assert::That(result.rows(), Equals(2));
            Assert::That(result.columns(), Equals(1));
        }

        It(MultipliesEachTermWithTheFactor)
        {
            Assert::That(result(0, 0), Equals(-2.5));
            Assert::That(result(1, 0), Equals(2.0));
        }

        It(DoesNotMutateTheOriginalMatrix)
        {
            Assert::That(matrix.rows(), Equals(2));
            Assert::That(matrix.columns(), Equals(1));

            Assert::That(matrix(0, 0), Equals(-5.0));
            Assert::That(matrix(1, 0), Equals(4.0));
        }
    };
};
