// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

Describe(cmatrix_mutators)
{
	Describe(When_adding_an_element_at_negative_boundary)
	{
		It(throws_an_exception)
		{
			Matrix<double> matrix(2, 2);
            std::string expectedMessage = "Invalid attempt to add element at negative row (-2) or column (2) to matrix [2, 2]";
            AssertThrows(Exception::InvalidSizeReset, matrix.mutateToInclude(0.0, -2, 2));
            Assert::That(LastException<Exception::InvalidSizeReset>().what(), Equals(expectedMessage));
		}
	};
};

} // namespace cmatrix
