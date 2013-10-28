#ifndef AutonomousCommandGroup_h
#define AutonomousCommandGroup_h

#include "CommandBase.h"

class AutonomousCommandGroup: public CommandBase {
	public:
		AutonomousCommandGroup();
		~AutonomousCommandGroup);
		void Initialize();
		void Execute();        
		bool IsFinished();        
};

#endif