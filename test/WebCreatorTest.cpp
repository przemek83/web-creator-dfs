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
