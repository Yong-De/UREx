#include "geometry_msgs/msg/point.hpp"
#include <functional>
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/subscription.hpp>
#include <rclcpp/utilities.hpp>

class ManipulatorSub : public rclcpp::Node {
  public:
    ManipulatorSub() : Node("manipulator_node") {
        subscription_ = this->create_subscription<geometry_msgs::msg::Point>(
            "camera_setpoint", 10,
            std::bind(&ManipulatorSub::topic_callback, this,
                      std::placeholders::_1));
    }

  private:
    void topic_callback(const geometry_msgs::msg::Point &message) const {
        RCLCPP_INFO(this->get_logger(), "Received Target: '%.2f, %.2f, %.2f'",
                    message.x, message.y, message.z);
    }
    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ManipulatorSub>());
    rclcpp::shutdown();
    return 0;
}
