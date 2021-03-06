/**
 *  SkillLevels.h
 *
 *  Version: 1.0.0.0
 *  Created on: 04/04/2016
 *  Modified on: *********
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef SKILL_LEVELS_H_
#define SKILL_LEVELS_H_

#include <string>
#include <vector>

namespace unifei 
{
	namespace expertinos
	{
		namespace mrta_vc
		{
			namespace tasks
			{
				namespace levels
				{
					typedef enum 
					{
						NONE,
						LOW,
						MODERATE,
						HIGH,
						RESOURCEFUL
					} SkillLevelEnum;
				}
				
				typedef levels::SkillLevelEnum SkillLevelEnum;

				class SkillLevels
				{

        public:
          static SkillLevelEnum toEnumerated(int code);
          static SkillLevelEnum toEnumerated(std::string name);
					static int toCode(SkillLevelEnum enumerated);
					static std::string toString(SkillLevelEnum enumerated);
					static SkillLevelEnum getDefault();
					static std::vector<SkillLevelEnum> getAll();
					static int compare(SkillLevelEnum level1, SkillLevelEnum level2);
					static bool isSufficient(SkillLevelEnum level, SkillLevelEnum desired_level);

				};
			}
		}
	}
}



#endif /* SKILL_LEVELS_H_ */
