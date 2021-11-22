#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class OpticalFlowNode : public rclcpp::Node
{
    public:
        OpticalFlowNode()
            : Node("optical_flow_node"), count_(0)
        {
            publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
            timer_ = this->create_wall_timer(
                    500ms, std::bind(&OpticalFlowNode::timer_callback, this));
            /* Start optical flow algorithm here, maybe in its own thread. */
        }

    private:
        void timer_callback()
        {
            auto message = std_msgs::msg::String();
            message.data = "Hello, world! " + std::to_string(count_++);
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            publisher_->publish(message);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OpticalFlowNode>());
    rclcpp::shutdown();
    return 0;
}
