#include "AutonomousCommandGroup.h"

AutonomousCommandGroup :: AutonomousCommandGroup() : CommandBase("AutonomousCommandGroup")
 {
  requires(CommandBase.chassis);
    requires(CommandBase.shooter);
    requires(CommandBase.firingPin);
    frisbeeCount = Preferences.getInstance().getInt("AUTONOMOUS_FRISBEE_COUNT", 3);
    waitTime     = Preferences.getInstance().getDouble("AUTONOMOUS_WAIT_TIME", 0.5);
	    
    addSequential(new ShooterSpinFast());
    
    for(int i=1; i <= frisbeeCount; i++)
    {
      addSequential(new WaitCommand(waitTime));
      addSequential(new ShooterFire());
    }
    
    IsFinished = true;
}

void AutonomousCommandGroup :: Initialize()
 {

}

void AutonomousCommandGroup :: Execute() 
{

}

bool AutonomousCommandGroup::IsFinished()
{
    return IsFinished;
}