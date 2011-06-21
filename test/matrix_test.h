// Written by     : Chirantan Mitra

#ifndef MATRIX_TEST_H
#define MATRIX_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <matrix_implementation.cpp>

using namespace CMatrix;

class MatrixTest : public CPPUNIT_NS :: TestFixture
{
    CPPUNIT_TEST_SUITE (MatrixTest);

    CPPUNIT_TEST (sizeIsInvalidWithRowAsZero);
    CPPUNIT_TEST (sizeIsInvalidWithColumnAsZero);
    CPPUNIT_TEST (sizeIsValidWithRowAndColumnGreaterThanZero);

    CPPUNIT_TEST (sizeKnowsItsRows);
    CPPUNIT_TEST (sizeKnowsItsColumns);
    CPPUNIT_TEST (sizeKnowsItsElementCount);

    CPPUNIT_TEST (matrixOfSize2x3Has2Rows);
    CPPUNIT_TEST (matrixOfSize2x3Has3Columns);
    CPPUNIT_TEST (matrixOfSize2x3Has6Elements);
    CPPUNIT_TEST (matrixOfSize1x1CanStoreValueProperly);
    CPPUNIT_TEST (matrixOfSize2x3CanStoreValueProperly);
    CPPUNIT_TEST (matrixSizeCanBeSpecifiedAfterCreation);
    CPPUNIT_TEST (attemptToAccessInvalidCellThrowsException);

    CPPUNIT_TEST (matrixCanBeProperlyAssignedUsingEqualsOperator);
    CPPUNIT_TEST (matrixCanBeProperlyAssignedUsingCopyConstructor);

    CPPUNIT_TEST (matrixSizeNotSetAsNaturalNumbersThrowsException);
    CPPUNIT_TEST (matrixSizeOnResettingAfterOnceSetThrowsException);
    CPPUNIT_TEST (matrixSizeOnResettingToSameSizeAfterOnceSetDoesNotThrowException);


    CPPUNIT_TEST (matricesWithDifferentRowsAreUnequal);
    CPPUNIT_TEST (matricesWithDifferentColumnsAreUnequal);
    CPPUNIT_TEST (matricesOfEqualSizeWithOneDifferentMemberAreUnequal);
    CPPUNIT_TEST (matricesOfEqualSizeWithSameMembersAreEqual);

    CPPUNIT_TEST (matrixOfMatricesCanBeCreated);
    CPPUNIT_TEST (matricesOfMatricesWithEqualMatrixAreEqual);
    CPPUNIT_TEST (matricesOfMatricesWithUnequalMatrixAreUnequal);

    CPPUNIT_TEST (two2x2MatricesCanBeProperlyAdded);
    CPPUNIT_TEST (three2x2MatricesCanBeProperlyAdded);
    CPPUNIT_TEST (two1x2And2x1MatricesWhenAddedThrowException);
    CPPUNIT_TEST (two2x2MatricesCanBeProperlyAddedByShortHand);
    CPPUNIT_TEST (two1x2And2x1MatricesWhenAddedByShortHandThrowException);
    CPPUNIT_TEST (a2x2MatricesReturnsItselfOnUnaryAddition);

    CPPUNIT_TEST (two2x2MatricesCanBeProperlySubtracted);
    CPPUNIT_TEST (two1x2And1x1MatricesWhenSubtractedThrowException);
    CPPUNIT_TEST (two2x2MatricesCanBeProperlySubtractedByShortHand);
    CPPUNIT_TEST (two1x2And2x1MatricesWhenSubtractedByShortHandThrowException);
    CPPUNIT_TEST (a2x2MatricesReturnsAdditiveInverseOnUnarySubtraction);

    CPPUNIT_TEST (two2x2MatricesCanBeProperlyMultiplied);
    CPPUNIT_TEST (one1x2AndOne2x1MatricesCanBeProperlyMultiplied);
    CPPUNIT_TEST (two1x2And1x1MatricesWhenMultipliedThrowException);
    
    CPPUNIT_TEST (twoMatrixOfMatricesCanBeProperlyAdded);

    CPPUNIT_TEST (a2x2MatrixOnGettingAFunctionoidForOneParameterAppliesItToAllMembers);
    CPPUNIT_TEST (a2x2MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPosition);
    CPPUNIT_TEST (a3x3MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPositionAndShift);
    CPPUNIT_TEST (a3x3MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPositionAndShiftAndScale);

    CPPUNIT_TEST (matrixWithEqualNumberOfRowsAndColumnsIsSquare);
    CPPUNIT_TEST (matrixWithUnequalNumberOfRowsAndColumnsIsNotSquare);
    CPPUNIT_TEST (squareMatrixWithAllDiagonalElementsAsOneAndOthersAsZeroIsUnit);
    CPPUNIT_TEST (squareMatrixWithNotAllDiagonalElementsAsOneOthersAsZeroIsNotUnit);
    CPPUNIT_TEST (squareMatrixWithAllDiagonalElementsAsOneOthersAsNotZeroIsNotUnit);
    CPPUNIT_TEST (nonSquareMatrixIsNotUnit);
    CPPUNIT_TEST (matrixWithAllElementsAsZeroIsZero);
    CPPUNIT_TEST (matrixWithOneNonZeroElementIsNotZero);

    CPPUNIT_TEST_SUITE_END ();

    public:
        void setUp();
        void tearDown();

    protected:
        void sizeIsInvalidWithRowAsZero();
        void sizeIsInvalidWithColumnAsZero();
        void sizeIsValidWithRowAndColumnGreaterThanZero();

        void sizeKnowsItsRows();
        void sizeKnowsItsColumns();
        void sizeKnowsItsElementCount();

        void matrixOfSize2x3Has2Rows();
        void matrixOfSize2x3Has3Columns();
        void matrixOfSize2x3Has6Elements();
        void matrixOfSize1x1CanStoreValueProperly();
        void matrixOfSize2x3CanStoreValueProperly();
        void matrixSizeCanBeSpecifiedAfterCreation();
        void attemptToAccessInvalidCellThrowsException();

        void matrixCanBeProperlyAssignedUsingEqualsOperator();
        void matrixCanBeProperlyAssignedUsingCopyConstructor();

        void matrixSizeNotSetAsNaturalNumbersThrowsException();
        void matrixSizeOnResettingAfterOnceSetThrowsException();
        void matrixSizeOnResettingToSameSizeAfterOnceSetDoesNotThrowException();


        void matricesWithDifferentRowsAreUnequal();
        void matricesWithDifferentColumnsAreUnequal();
        void matricesOfEqualSizeWithOneDifferentMemberAreUnequal();
        void matricesOfEqualSizeWithSameMembersAreEqual();

        void matrixOfMatricesCanBeCreated();
        void matricesOfMatricesWithEqualMatrixAreEqual();
        void matricesOfMatricesWithUnequalMatrixAreUnequal();

        void two2x2MatricesCanBeProperlyAdded();
        void three2x2MatricesCanBeProperlyAdded();
        void two1x2And2x1MatricesWhenAddedThrowException();
        void two2x2MatricesCanBeProperlyAddedByShortHand();
        void two1x2And2x1MatricesWhenAddedByShortHandThrowException();
        void a2x2MatricesReturnsItselfOnUnaryAddition();

        void two2x2MatricesCanBeProperlySubtracted();
        void two1x2And1x1MatricesWhenSubtractedThrowException();
        void two2x2MatricesCanBeProperlySubtractedByShortHand();
        void two1x2And2x1MatricesWhenSubtractedByShortHandThrowException();
        void a2x2MatricesReturnsAdditiveInverseOnUnarySubtraction();

        void two2x2MatricesCanBeProperlyMultiplied();
        void one1x2AndOne2x1MatricesCanBeProperlyMultiplied();
        void two1x2And1x1MatricesWhenMultipliedThrowException();

        void twoMatrixOfMatricesCanBeProperlyAdded();

        void a2x2MatrixOnGettingAFunctionoidForOneParameterAppliesItToAllMembers();
        void a2x2MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPosition();
        void a3x3MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPositionAndShift();
        void a3x3MatrixOnGettingAFunctionoidForTwoParametersAppliesItToAllMembersByPositionAndShiftAndScale();

        void matrixWithEqualNumberOfRowsAndColumnsIsSquare();
        void matrixWithUnequalNumberOfRowsAndColumnsIsNotSquare();
        void squareMatrixWithAllDiagonalElementsAsOneAndOthersAsZeroIsUnit();
        void squareMatrixWithNotAllDiagonalElementsAsOneOthersAsZeroIsNotUnit();
        void squareMatrixWithAllDiagonalElementsAsOneOthersAsNotZeroIsNotUnit();
        void nonSquareMatrixIsNotUnit();
        void matrixWithAllElementsAsZeroIsZero();
        void matrixWithOneNonZeroElementIsNotZero();
};


#endif

