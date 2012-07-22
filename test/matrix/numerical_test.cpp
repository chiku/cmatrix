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

        // void MatrixTest::two1x2And2x1MatricesWhenAddedThrowException(void)
        // {
        //     Matrix<double> oneByTwoMatrix(1, 2);
        //     Matrix<double> twoByOneMatrix(2, 1);

        //     std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
        //     CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix + twoByOneMatrix,
        //                                         Exception::IncompatibleAddition,
        //                                         expectedMessage );
        // }

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

        // void MatrixTest::two1x2And1x1MatricesWhenSubtractedThrowException(void)
        // {
        //     Matrix<double> oneByTwoMatrix(1, 2);
        //     Matrix<double> oneByOneMatrix(1, 1);

        //     std::string expectedMessage = "Cannot subtract [1, 1] from [1, 2]";
        //     CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix - oneByOneMatrix,
        //                                         Exception::IncompatibleSubtraction,
        //                                         expectedMessage );
        // }
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

        // void MatrixTest::two1x2And2x1MatricesWhenAddedByShortHandThrowException(void)
        // {
        //     Matrix<double> oneByTwoMatrix(1, 2);
        //     Matrix<double> twoByOneMatrix(2, 1);

        //     std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
        //     CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix += twoByOneMatrix,
        //                                         Exception::IncompatibleAddition,
        //                                         expectedMessage );
        // }
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

        // void MatrixTest::two1x2And2x1MatricesWhenAddedByShortHandThrowException(void)
        // {
        //     Matrix<double> oneByTwoMatrix(1, 2);
        //     Matrix<double> twoByOneMatrix(2, 1);

        //     std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
        //     CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix += twoByOneMatrix,
        //                                         Exception::IncompatibleAddition,
        //                                         expectedMessage );
        // }
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

        // void MatrixTest::two1x2And1x1MatricesWhenMultipliedThrowException(void)
        // {
        //     Matrix<double> oneByTwoMatrix(1, 2);
        //     Matrix<double> oneByOneMatrix(1, 1);

        //     std::string expectedMessage = "Cannot multiply [1, 2] with [1, 1]";
        //     CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix * oneByOneMatrix,
        //                                         Exception::IncompatibleMultiplication,
        //                                         expectedMessage );
        // }
    };
};