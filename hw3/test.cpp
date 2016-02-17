#include "gtest/gtest.h"

#include "llistint.h"

#include <iostream>
#include <sstream>


class ListTest: public testing::Test{
protected:
	ListTest(){}
	
	virtual ~ListTest(){}

	virtual void SetUp()
	{
		test.insert(0,1);
    	test.insert(1,2);
    	test.insert(2,3);
    	test.insert(3,4);
    	concat.insert(0,5);
    	concat.insert(1,6);
    	concat.insert(2,7);
    	concat.insert(3,8);
	}

	LListInt test, concat, copy;

};

/*TEST_F(ListTest, CopyTest)
{
	copy = LListint(test);
	EXPECT_EQ(copy.get(0), 1);
	EXPECT_EQ(copy.get(1), 2);
	EXPECT_EQ(copy.get(2), 3);
	EXPECT_EQ(copy.get(3), 4);
} */

TEST_F(ListTest, AssignTest)
{
	copy = concat;
	EXPECT_EQ(copy.get(0), 5);
	EXPECT_EQ(copy.get(1), 6);
	EXPECT_EQ(copy.get(2), 7);
	EXPECT_EQ(copy.get(3), 8);
}

TEST_F(ListTest, ConcatTest)
{
	copy = test + concat;
	EXPECT_EQ(copy.get(0), 1);
	EXPECT_EQ(copy.get(1), 2);
	EXPECT_EQ(copy.get(2), 3);
	EXPECT_EQ(copy.get(3), 4);
	EXPECT_EQ(copy.get(4), 5);
	EXPECT_EQ(copy.get(5), 6);
	EXPECT_EQ(copy.get(6), 7);
	EXPECT_EQ(copy.get(7), 8);
}

TEST_F(ListTest, AccessTest)
{	
	EXPECT_EQ(copy[0], 1);
	EXPECT_EQ(copy[1], 2);
	EXPECT_EQ(copy[2], 3);
	EXPECT_EQ(copy[3], 4);

}