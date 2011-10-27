/*
 * Copyright 2005, 2006, 2007, 2008, 2009, 2010, 
 *
 * Olivier Stasse
 *
 * JRL, CNRS/AIST
 *
 * This file is part of walkGenJrl.
 * walkGenJrl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * walkGenJrl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Lesser Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License
 * along with walkGenJrl.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Research carried out within the scope of the 
 *  Joint Japanese-French Robotics Laboratory (JRL)
 */
#include <jrl/walkgen/pgtypes.hh>

namespace PatternGeneratorJRL
{
  struct COMPosition_s & COMPosition::operator=(const COMState_s &aCS)
  {
    for(unsigned int i=0;i<3;i++)
      {
	x[i] = aCS.x[i];
	y[i] = aCS.y[i];
	z[i] = aCS.z[i];
      };
    yaw     = aCS.yaw[0];  
    pitch   = aCS.pitch[0];
    roll    = aCS.roll[0];  
    return *this;
  }

  struct COMState_s & COMState::operator=(const COMPosition_s &aCS)
  {
    for(unsigned int i=0;i<3;i++)
      {
	x[i] = aCS.x[i];
	y[i] = aCS.y[i];
	z[i] = aCS.z[i];
      };
    yaw[0]   = aCS.yaw;   yaw[1]   = yaw[2]   = 0.0;
    pitch[0] = aCS.pitch; pitch[1] = pitch[2] = 0.0;
    roll[0]  = aCS.roll;  roll[1]  = roll[2]  = 0.0;
    return *this;
  }
      
  void COMState::reset() 
  {
    for(unsigned int i=0;i<3;i++)
      { 
	x[i] = 0.0; y[i] = 0.0; z[i] = 0.0;
	yaw[i] = 0.0; pitch[i] = 0.0; roll[i] = 0.0;
      }
  }

  COMState_s::COMState_s()
  {
    reset();
  }

}
