#include "geometry_msgs/msg/point.hpp"
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/timer.hpp>
#include <rclcpp/utilities.hpp>

using namespace std::chrono_literals;

class PlannerPub : public rclcpp::Node {
  public:
    PlannerPub() : Node("planner_node") {
        publisher_ = this->create_publisher<geometry_msgs::msg::Point>(
            "camera_setpoint", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&PlannerPub::timer_callback, this));
    }

  private:
    void timer_callback() {
        auto message = geometry_msgs::msg::Point();
        message.x = 1.5;
        message.y = 0.0;
        message.z = 0.3;
        RCLCPP_INFO(this->get_logger(),
                    "Publishing Setpoint: '%.2f, %.2f, %.2f'", message.x,
                    message.y, message.z);
        publisher_->publish(message);
    }
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PlannerPub>());
    rclcpp::shutdown();
    return 0;
}
