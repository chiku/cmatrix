// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_Properties)
{
    It(IsSquareWhenNumberOfRowsAndColumnsAreEqual)
    {
        Matrix<double> firstMatrix(1, 1);
        Matrix<double> secondMatrix(3, 3);

        Assert::That(firstMatrix.isSquare(), IsTrue());
        Assert::That(secondMatrix.isSquare(), IsTrue());
    }

    It(IsNotSquareWhenNumberOfRowsAndColumnsAreUnequal)
    {
        Matrix<double> firstMatrix(1, 2);
        Matrix<double> secondMatrix(3, 2);

        Assert::That(firstMatrix.isSquare(), IsFalse());
        Assert::That(secondMatrix.isSquare(), IsFalse());
    }

    Describe(When_Square)
    {
        It(IsUnitIfAllDiagonalElementsAreOneAndOthersAreZero)
        {
            Matrix<double> firstMatrix(1, 1);
            Matrix<double> secondMatrix(2, 2);

            firstMatrix(0, 0) = 1.0;
            secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
            secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

            Assert::That(firstMatrix.isUnit(), IsTrue());
            Assert::That(secondMatrix.isUnit(), IsTrue());
        }

        It(IsNotUnitIfSomeDiagonalElementsAreNotOne)
        {
            Matrix<double> firstMatrix(1, 1);
            Matrix<double> secondMatrix(2, 2);

            firstMatrix(0, 0) = -1.0;
            secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
            secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = -1.0;

            Assert::That(firstMatrix.isUnit(), IsFalse());
            Assert::That(secondMatrix.isUnit(), IsFalse());
        }

        It(IsNotUnitIfSomeNonDiagonalElementsAreNotZero)
        {
            Matrix<double> firstMatrix(1, 1);
            Matrix<double> secondMatrix(2, 2);

            firstMatrix(0, 0) = -1.0;
            secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 1.0;
            secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

            Assert::That(firstMatrix.isUnit(), IsFalse());
            Assert::That(secondMatrix.isUnit(), IsFalse());
        }
    };

    Describe(When_Not_Square)
    {
        It(IsNotUnit)
        {
            Matrix<double> matrix(1, 2);

            matrix(0, 0) = 1.0;    matrix(0, 1) = 0.0;

            Assert::That(matrix.isUnit(), IsFalse());
        }
    };

    It(IsZeroIfAllElementsAreZero)
    {
        Matrix<double> matrix(1, 2);

        matrix(0, 0) = 0.0;    matrix(0, 1) = 0.0;

        Assert::That(matrix.isZero(), IsTrue());
    }

    It(IsNotZeroIfOneElementIsNotZero)
    {
        Matrix<double> matrix(1, 2);

        matrix(0, 0) = 0.0;    matrix(0, 1) = 1.0;

        Assert::That(matrix.isZero(), IsFalse());
    }
};
