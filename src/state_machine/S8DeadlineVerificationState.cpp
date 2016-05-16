/**
 *  S8DeadlineVerificationState.cpp
 *
 *	Corresponds to S8 State in the Task Builder State Machine Model Diagram
 *
 *  Version: 0.0.0.0
 *  Created on: 14/05/2016
 *  Modified on: *********
 *  Authors: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *           Luís Victor Pessiqueli Bonin (luis-bonin@hotmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "mrta_vc/state_machine/S8DeadlineVerificationState.h"
#include "mrta_vc/state_machine/MachineController.h"

/**
 * Constructor
 */
mrta_vc::state_machine::S8DeadlineVerificationState::S8DeadlineVerificationState(mrta_vc::state_machine::MachineController* controller) : mrta_vc::state_machine::AbstractState(controller, "How urgent?")
{
}

/**
 * Destructor
 */
mrta_vc::state_machine::S8DeadlineVerificationState::~S8DeadlineVerificationState()
{
}

/**
 *
 */
void mrta_vc::state_machine::S8DeadlineVerificationState::process(std::string answer)
{
  mrta_vc::state_machine::S8DeadlineVerificationState::process(answer);
  if (isDeadline(answer))
  {
    mrta_vc::state_machine::AbstractState::getController()->getTask().setDeadline(getDeadline(answer));
    next(answer);
  } 
  else if (isDuration(answer))
  {
    mrta_vc::state_machine::AbstractState::getController()->getTask().setDeadline(getDuration(answer));
    next(answer);
  }
  else if (answer == "")
 {
    mrta_vc::state_machine::AbstractState::getController()->getTask().setDeadline(ros::Time::now() + ros::Duration(DEFAULT_DURATION));
    next(answer);
  }
}

/**
 *
 */
void mrta_vc::state_machine::S8DeadlineVerificationState::next(std::string answer)
{
  mrta_vc::state_machine::MachineController* controller = mrta_vc::state_machine::AbstractState::getController();
  controller->setNext(controller->getS9());
}

/**
 *
 */
bool mrta_vc::state_machine::S8DeadlineVerificationState::isDeadline(std::string answer)
{
  return false;
}

/**
 *
 */
bool mrta_vc::state_machine::S8DeadlineVerificationState::isDuration(std::string answer)
{
  return false;
}

/**
 *
 */
ros::Time mrta_vc::state_machine::S8DeadlineVerificationState::getDeadline(std::string answer)
{
  return ros::Time::now() + ros::Duration(DEFAULT_DURATION);
}

/**
 *
 */
ros::Duration mrta_vc::state_machine::S8DeadlineVerificationState::getDuration(std::string answer)
{
  return ros::Duration(DEFAULT_DURATION);
}
