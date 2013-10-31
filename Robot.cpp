#include "WPILib.h"
#define PORT_DRIVE_VIC_1 5
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_SPEED 1
#define PORT_JS_TURN 2
#define PORT_JS_CONTROL 3
#define PORT_SHOOTER 3
#define PORT_SHOOTER 4


class MyRobot : public SimpleRobot {
  Victor leftVic1;
  Victor leftVic2;
  Victor rightVic1;
  Victor rightVic2;

  Victor shooterVic1;
  Victor shooterVic2;
  
  Joystick speedStick;
  Joystick turnStick;
  Joystick controlStick;
  
  enum{
    idle,
    spin-up,
    extending,
    receding
  }shooterState
  
  public :
    MyRobot() : 
    leftVic1(PORT_DRIVE_VIC_1),
    leftVic2(PORT_DRIVE_VIC_2),
    rightVic1(PORT_DRIVE_VIC_3),
    rightVic2(PORT_DRIVE_VIC_4),
    speedStick(PORT_JS_SPEED),
    turnStick(PORT_JS_TURN),
    controlStick(PORT_JS_CONTROL)
  {}
   void Autonoumousinit() {
    
  }

  
    void AutonomousPeriodic() {
      leftVic1.Set(0.5);
      leftVic2.Set(0.5);
      rightVic1.Set(0.0);
      rightVic2.Set(0.0);
      Wait(2.0);
      
      leftVic1.Set(0.0);
      leftVic2.Set(0.0);
      rightVic1.Set(-0.5);
      rightVic2.Set(-0.5);
      Wait(2.0);
      
      leftVic1.Set(0.5);
      leftVic2.Set(0.5);
      rightVic1.Set(-0.5);
      rightVic2.Set(-0.5);
      Wait(4.0);
      
      leftVic1.Set(0.0);
      leftVic2.Set(0.0);
      rightVic1.Set(0.0);
      rightVic2.Set(0.0);
  }
  void AutonomousDisabled(){
    
  }
  void Teleopinit(){
    
  }
  void TeleopPeriodic(){
    leftVic1.Set(speedStick.GetY)()+turnStick.GetX());
    leftVic2.Set(speedStick.GetY()+turnStick.GetX));
    rightVic1.Set(-(speedStick.GetY()-turnStick.GetX));
    rightVic2.Set(-(speedStick.GetY()-turnStick.GetX));
    
    if(shooterState == idle){
      
    }
    
  }
  void TeleopDisabled(){

    
  }
  
};

START_ROBOT_CLASS(MyRobot);
