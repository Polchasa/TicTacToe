#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include "../src/player.cpp"

using namespace std;

TEST(TestClassPlayer, SetGetPlayerName) {
  Player p;

  p.setName("ABC");

  string value = p.getName();

  EXPECT_STREQ(value.c_str(), "ABC");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}