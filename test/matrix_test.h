// Written by     : Chirantan Mitra

#ifndef MATRIX_TEST_H
#define MATRIX_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <matrix.h>

#define CPPUNIT_ASSERT_THROW_WITH_MESSAGE(expression, ExceptionType, expectedExceptionMessage) do   \
{                                                                                                   \
    std::string actualExceptionMessage;                                                             \
    bool cpputExceptionThrown = false;                                                              \
    try {                                                                                           \
        expression;                                                                                 \
    }                                                                                               \
    catch ( const ExceptionType &exception ) {                                                      \
        cpputExceptionThrown = true;                                                                \
        actualExceptionMessage = exception.what();                                                  \
    }                                                                                               \
                                                                                                    \
     if ( cpputExceptionThrown ) {                                                                  \
        std::string quotes("\"");                                                                   \
        CPPUNIT_NS::Message message( std::string("Expected the exception message to be ")           \
                                    + quotes + expectedExceptionMessage + quotes                    \
                                    + std::string(" but was ") + quotes                             \
                                    + actualExceptionMessage + quotes);                             \
        CPPUNIT_NS::Asserter::failIf( !(expectedExceptionMessage == actualExceptionMessage),        \
                                      CPPUNIT_NS::Message( message ),                               \
                                      CPPUNIT_SOURCELINE() );                                       \
        break;                                                                                      \
    }                                                                                               \
    CPPUNIT_NS::Asserter::fail("Expected exception: " #ExceptionType " not thrown.",                \
                                CPPUNIT_SOURCELINE() );                                             \
} while ( false )


using namespace CMatrix;

class MatrixTest : public CPPUNIT_NS :: TestFixture
{
    CPPUNIT_TEST_SUITE (MatrixTest);

    CPPUNIT_TEST (noop);
    
    CPPUNIT_TEST_SUITE_END ();

    protected:
        void noop();
};

CPPUNIT_TEST_SUITE_REGISTRATION (MatrixTest);

#endif
