#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>

TEST(RclcppTests, CreateNode) {
  auto const node =
        std::make_shared<rclcpp::Node>("test", rclcpp::NodeOptions{});
  EXPECT_NE(node.get(), nullptr);
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
