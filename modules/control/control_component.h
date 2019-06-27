#pragma once

#include <memory>

#include "cyber/class_loader/class_loader.h"
#include "cyber/component/component.h"
#include "modules/control/proto/chassis.pb.h"
#include "modules/control/proto/control.pb.h"

namespace apollo {
namespace control {

using apollo::control::Chassis;
using apollo::control::Control_Command;
using apollo::cyber::Component;
using apollo::cyber::Writer;

class ControlComponent : public Component<> {
 public:
  bool Init() override;

  ControlComponent();
  ~ControlComponent();

  void ChassisFeedback();
  void GenerateCommand();
  void TestCommand();

 private:
  std::shared_ptr<Writer<Chassis>> chassis_writer_ = nullptr;
  std::shared_ptr<Writer<Control_Command>> control_writer_ = nullptr;

  // Uart arduino_;

  std::future<void> chassis_feedback_;
};

CYBER_REGISTER_COMPONENT(ControlComponent)
}  // namespace control
}  // namespace apollo