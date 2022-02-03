#define BOOST_TEST_DYN_LINK

#include "matrixIO.hpp"
#include <boost/test/unit_test.hpp>
#include <Eigen/Dense>

using namespace Eigen;

struct MatrixIoFixture{
    MatrixIoFixture(){

        expected_eigen_matrix = MatrixXd(3,3);

        expected_eigen_matrix(0,0) = 0.680375;
        expected_eigen_matrix(0,1) = 0.59688;
        expected_eigen_matrix(0,2) = -0.329554;

        expected_eigen_matrix(1,0) = -0.211234;
        expected_eigen_matrix(1,1) = 0.823295;
        expected_eigen_matrix(1,2) = 0.536459;

        expected_eigen_matrix(2,0) = 0.566198;
        expected_eigen_matrix(2,1) = -0.604897;
        expected_eigen_matrix(2,2) = -0.444451;

    }

    MatrixXd expected_eigen_matrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIoTests, MatrixIoFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openData){

    MatrixXd actual_eigen_matrix = matrixIO::openData("../data/m3.csv", 3);

    BOOST_TEST(actual_eigen_matrix(0,0) == expected_eigen_matrix(0,0));
    BOOST_TEST(actual_eigen_matrix(0,1) == expected_eigen_matrix(0,1));
    BOOST_TEST(actual_eigen_matrix(0,2) == expected_eigen_matrix(0,2));

    BOOST_TEST(actual_eigen_matrix(1,0) == expected_eigen_matrix(1,0));
    BOOST_TEST(actual_eigen_matrix(1,1) == expected_eigen_matrix(1,1));
    BOOST_TEST(actual_eigen_matrix(1,2) == expected_eigen_matrix(1,2));

    BOOST_TEST(actual_eigen_matrix(2,0) == expected_eigen_matrix(2,0));
    BOOST_TEST(actual_eigen_matrix(2,1) == expected_eigen_matrix(2,1));
    BOOST_TEST(actual_eigen_matrix(2,2) == expected_eigen_matrix(2,2));
}


BOOST_AUTO_TEST_SUITE_END()

