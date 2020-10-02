#include "gtest/gtest.h"

#include "../WebCreator.h"

TEST(WebCreator, checkConnectionEmptyWeb)
{
    WebCreator webCreator;
    EXPECT_EQ(webCreator.connectionExist("1.1.1.1.1", "2.2.2.2.2"), false);
}

TEST(WebCreator, checkConnectionOneElementWeb)
{
    WebCreator webCreator;
    webCreator.addConnection("1.1.1.1.1", "2.2.2.2.2");
    EXPECT_EQ(webCreator.connectionExist("1.1.1.1.1", "2.2.2.2.2"), true);
}

TEST(WebCreator, checkConnectionOneElementWebReversed)
{
    WebCreator webCreator;
    webCreator.addConnection("2.2.2.2.2", "1.1.1.1.1");
    EXPECT_EQ(webCreator.connectionExist("1.1.1.1.1", "2.2.2.2.2"), true);
}

TEST(WebCreator, testCreationOfNonTrivialWeb)
{
    WebCreator creator;
    creator.addConnection("100.100.100.1", "100.100.100.2");
    creator.addConnection("100.100.100.1", "100.100.100.3");
    creator.addConnection("100.100.100.10", "100.100.100.11");
    EXPECT_EQ(creator.connectionExist("100.100.100.1", "100.100.100.3"), true);
    EXPECT_EQ(creator.connectionExist("100.100.100.10", "100.100.100.2"),
              false);
    EXPECT_EQ(creator.connectionExist("100.100.100.10", "100.100.100.11"),
              true);
    creator.addConnection("100.100.100.11", "100.100.100.2");
    EXPECT_EQ(creator.connectionExist("100.100.100.10", "100.100.100.3"), true);
    EXPECT_EQ(creator.connectionExist("100.100.100.100", "100.100.100.103"),
              false);
}
