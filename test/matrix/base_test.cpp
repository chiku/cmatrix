// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_Base)
{
    Describe(When_Of_Size_2x3_For_Double)
    {
        It(Has2Rows)
        {
            Matrix<double> twoByThreeMatrix(2, 3);
            Assert::That(twoByThreeMatrix.rows(), Equals(2L));
        }

        It(Has3Columns)
        {
            Matrix<double> twoByThreeMatrix(2, 3);
            Assert::That(twoByThreeMatrix.columns(), Equals(3));
        }

        It(HasATotalOf6Elements)
        {
            Matrix<double> twoByThreeMatrix(2, 3);
            Assert::That(twoByThreeMatrix.elements(), Equals(6));
        }

        It(CanStoreRetrievableValuesAtAll6Locations)
        {
            Matrix<double> twoByThreeMatrix(2, 3);
            twoByThreeMatrix(0, 0) = -2;
            twoByThreeMatrix(0, 1) = -1;
            twoByThreeMatrix(0, 2) =  0;
            twoByThreeMatrix(1, 0) =  1;
            twoByThreeMatrix(1, 1) =  2;
            twoByThreeMatrix(1, 2) =  3;
            Assert::That(twoByThreeMatrix(0, 0), Equals(-2.0));
            Assert::That(twoByThreeMatrix(0, 1), Equals(-1.0));
            Assert::That(twoByThreeMatrix(0, 2), Equals( 0.0));
            Assert::That(twoByThreeMatrix(1, 0), Equals(1.0));
            Assert::That(twoByThreeMatrix(1, 1), Equals(2.0));
            Assert::That(twoByThreeMatrix(1, 2), Equals(3.0));
        }
    };

    Describe(When_Of_Size_1x1)
    {
        It(StoresRetrievableIntegerValues)
        {
            Matrix<int> oneByOneIntMatrix(1, 1);
            oneByOneIntMatrix(0, 0) = 10;
            Assert::That(oneByOneIntMatrix(0, 0), Equals(10));
        }

        It(StoresRetrievableDoubleValues)
        {
            Matrix<double> oneByOneDoubleMatrix(1, 1);
            oneByOneDoubleMatrix(0, 0) = 10.0;
            Assert::That(oneByOneDoubleMatrix(0, 0), Equals(10.0));
        }
    };

    Describe(When_Setting_Size_1x1_After_Creation)
    {
        Matrix<double> oneByOneMatrix;

        void SetUp()
        {
            oneByOneMatrix.setSize(1, 1);
        }

        It(Has1Row)
        {
            Assert::That(oneByOneMatrix.rows(), Equals(1L));
        }

        It(Has1Column)
        {
            Assert::That(oneByOneMatrix.columns(), Equals(1L));
        }

        It(StoresRetrievableValue)
        {
            oneByOneMatrix(0, 0) = 1.0;
            Assert::That(oneByOneMatrix(0, 0), Equals(1.0));
        }
    };

    It(ThrowsExceptionOnAttemptToAccessOutsizeRowBounds)
    {
        Matrix<double> oneByTwoMatrix(1, 2);
        std::string expectedMessage = "Invalid attempt to access (1, 1) which lies outside bounds [1, 2]";
        AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(1, 1));
        Assert::That(LastException<Exception::AccessOutOfBound>().what(), Equals(expectedMessage));
    }

    It(ThrowsExceptionOnAttemptToAssignOutsizeRowBounds)
    {
        Matrix<double> oneByTwoMatrix(1, 2);
        std::string expectedMessage = "Invalid attempt to access (1, 1) which lies outside bounds [1, 2]";
        AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(1, 1) = 5);
        Assert::That(LastException<Exception::AccessOutOfBound>().what(), Equals(expectedMessage));
    }

    It(ThrowsExceptionOnAttemptToAccessOutsizeColumnBounds)
    {
        Matrix<double> oneByTwoMatrix(1, 2);
        std::string expectedMessage = "Invalid attempt to access (0, 2) which lies outside bounds [1, 2]";
        AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(0, 2));
        Assert::That(LastException<Exception::AccessOutOfBound>().what(), Equals(expectedMessage));
    }

    It(ThrowsExceptionOnAttemptToAssignOutsizeColumnBounds)
    {
        Matrix<double> oneByTwoMatrix(1, 2);
        std::string expectedMessage = "Invalid attempt to access (0, 2) which lies outside bounds [1, 2]";
        AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(0, 2) = 5);
        Assert::That(LastException<Exception::AccessOutOfBound>().what(), Equals(expectedMessage));
    }

    Describe(When_Copied_By_Equals_Operator)
    {
        Matrix<double> firstTwoByTwoMatrix;

        void SetUp()
        {
            firstTwoByTwoMatrix.setSize(2, 2);
            firstTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0;
        }

        It(EqualsTheOriginalMatrix)
        {
            Matrix<double> secondTwoByTwoMatrix;
            secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            Assert::That(firstTwoByTwoMatrix, Equals(secondTwoByTwoMatrix));
        }

        It(DoesNotEqualTheOriginalMatrixIfOneElementIsChangedForCopiedMatrix)
        {
            Matrix<double> secondTwoByTwoMatrix;
            secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            secondTwoByTwoMatrix(1, 1) = -4.0;
            Assert::That(firstTwoByTwoMatrix, !Equals(secondTwoByTwoMatrix));
        }

        It(ChangedToCopiedMatrixDoNotAffectTheOriginalMatrix)
        {
            Matrix<double> secondTwoByTwoMatrix;
            secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            secondTwoByTwoMatrix(1, 1) = -4.0;
            Assert::That(firstTwoByTwoMatrix(1, 1), Equals(4.0));
        }
    };

    Describe(When_Copied_By_Copy_Constructor)
    {
        Matrix<double> firstTwoByTwoMatrix;

        void SetUp()
        {
            firstTwoByTwoMatrix.setSize(2, 2);
            firstTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0;
        }

        It(EqualsTheOriginalMatrix)
        {
            Matrix<double> secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            Assert::That(firstTwoByTwoMatrix, Equals(secondTwoByTwoMatrix));
        }

        It(DoesNotEqualTheOriginalMatrixIfOneElementIsChangedForCopiedMatrix)
        {
            Matrix<double> secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            secondTwoByTwoMatrix(1, 1) = -4.0;
            Assert::That(firstTwoByTwoMatrix, !Equals(secondTwoByTwoMatrix));
        }

        It(ChangedToCopiedMatrixDoNotAffectTheOriginalMatrix)
        {
            Matrix<double> secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            secondTwoByTwoMatrix(1, 1) = -4.0;
            Assert::That(firstTwoByTwoMatrix(1, 1), Equals(4.0));
        }
    };

    It(ThrowsExceptionWhenMatrixSizeDuringCreationAreNotNaturalNumbers)
    {
        std::string expectedMessage = "Invalid attempt to set rows to 0 and columns to 0";
        AssertThrows(Exception::InvalidSizeSet, Matrix<double> bad0x0Matrix(0, 0));
        Assert::That(LastException<Exception::InvalidSizeSet>().what(), Equals(expectedMessage));
    }

    It(ThrowsExceptionWhenSettingMatrixSizeAfterCreationAreNotNaturalNumbers)
    {
        Matrix<double> bad0x0Matrix;
        std::string expectedMessage = "Invalid attempt to set rows to 1 and columns to 0";
        AssertThrows(Exception::InvalidSizeSet, bad0x0Matrix.setSize(1, 0));
        Assert::That(LastException<Exception::InvalidSizeSet>().what(), Equals(expectedMessage));
    }

    It(ThrowsExceptionWhenResettingToDifferentSizeWhenAlreadySet)
    {
        Matrix<double> first1x1Matrix(1, 1);
        std::string firstExpectedMessage = "Invalid attempt to reset rows to 2 and columns to 2 from [1, 1]";
        AssertThrows(Exception::InvalidSizeReset, first1x1Matrix.setSize(2, 2));
        Assert::That(LastException<Exception::InvalidSizeReset>().what(), Equals(firstExpectedMessage));

        Matrix<double> second1x1Matrix(1, 1);
        std::string secondExpectedMessage = "Invalid attempt to reset rows to 2 and columns to 0 from [1, 1]";
        AssertThrows(Exception::InvalidSizeReset, second1x1Matrix.setSize(2, 0));
        Assert::That(LastException<Exception::InvalidSizeReset>().what(), Equals(secondExpectedMessage));
    }

    It(DoesNotThrowExceptionWhenResettingToSameSizeWhenAlreadySet)
    {
        Matrix<double> first1x1Matrix(1, 1);
        first1x1Matrix.setSize(1, 1);
    }


    Describe(Does_Not_Equal_Matrix)
    {
        It(WithDifferentRowCount)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByTwoMatrix(2, 2);

            Assert::That(oneByTwoMatrix == twoByTwoMatrix, IsFalse());
            Assert::That(oneByTwoMatrix != twoByTwoMatrix, IsTrue());
        }

        It(WithDifferentColumnCount)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByThreeMatrix(1, 3);

            Assert::That(oneByTwoMatrix == oneByThreeMatrix, IsFalse());
            Assert::That(oneByTwoMatrix != oneByThreeMatrix, IsTrue());
        }

        It(WithADifferentElement)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) =  1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0;

            Assert::That(firstTwoByTwoMatrix == secondTwoByTwoMatrix, IsFalse());
            Assert::That(firstTwoByTwoMatrix != secondTwoByTwoMatrix, IsTrue());
        }
    };

    Describe(Equals_Another_Matrix)
    {
        It(WhitSameRowCountAndColumnCountAndSameElementsInSamePosition)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

            Assert::That(firstTwoByTwoMatrix == secondTwoByTwoMatrix, IsTrue());
            Assert::That(firstTwoByTwoMatrix != secondTwoByTwoMatrix, IsFalse());
        }
    };


    Describe(Matrix_Of_Matrices)
    {
        It(HasRetrievableValues)
        {
            Matrix<double> firstMatrix(1, 1);
            Matrix<double> secondMatrix(1, 1);
            Matrix<Matrix <double> > matrixOfMatrices(1, 2);

            firstMatrix(0, 0) = 1.0;
            secondMatrix(0, 0) = 2.0;
            matrixOfMatrices(0, 0) = firstMatrix;
            matrixOfMatrices(0, 1) = secondMatrix;

            Assert::That(matrixOfMatrices(0, 0)(0, 0), Equals(1.0));
            Assert::That(matrixOfMatrices(0, 1)(0, 0), Equals(2.0));
        }

        It(EqualsAnotherMatrixOfMatricesWhenAllComponentMatricesAreEquals)
        {
            Matrix<Matrix <double> > firstMatrix(1, 2);
            Matrix<Matrix <double> > secondMatrix(1, 2);

            Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
            Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);

            firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  1.0;
            firstMatrix0x1(0, 0) =  3.0; secondMatrix0x1(0, 0) =  3.0;
            firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) = -1.0;

            firstMatrix(0, 0) = firstMatrix0x0; secondMatrix(0, 0) = secondMatrix0x0;
            firstMatrix(0, 1) = firstMatrix0x1; secondMatrix(0, 1) = secondMatrix0x1;

            Assert::That(firstMatrix == secondMatrix), IsTrue();
        }

        It(DoesNotEqualAnotherMatrixOfMatricesWhenOneComponentMatrixIsNotEqual)
        {
            Matrix<Matrix <double> > firstMatrix(1, 2);
            Matrix<Matrix <double> > secondMatrix(1, 2);

            Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
            Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);

            firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  1.0;
            firstMatrix0x1(0, 0) =  3.0; secondMatrix0x1(0, 0) =  3.0;
            firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) =  1.0;

            firstMatrix(0, 0) = firstMatrix0x0; secondMatrix(0, 0) = secondMatrix0x0;
            firstMatrix(0, 1) = firstMatrix0x1; secondMatrix(0, 1) = secondMatrix0x1;

            Assert::That(firstMatrix != secondMatrix, IsTrue());
        }
    };
};
