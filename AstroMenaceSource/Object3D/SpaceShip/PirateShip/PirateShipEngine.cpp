/************************************************************************************

	AstroMenace (Hardcore 3D space shooter with spaceship upgrade possibilities)
	Copyright © 2006-2013 Michael Kurinnoy, Viewizard


	AstroMenace is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AstroMenace is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AstroMenace. If not, see <http://www.gnu.org/licenses/>.


	Web Site: http://www.viewizard.com/
	Project: http://sourceforge.net/projects/openastromenace/
	E-mail: viewizard@viewizard.com

*************************************************************************************/


/// подключаем нужные файлы
#include "PirateShip.h"






//-----------------------------------------------------------------------------
// Создание двигателя
//-----------------------------------------------------------------------------
void SetPirateShipEngine(eParticleSystem *ParticleSystem, int EngineType)
{

	ParticleSystem->Texture[0] = vw_FindTextureByName("DATA/GFX/flare1.tga");
	ParticleSystem->Direction = VECTOR3D(0.0f, 0.0f, -1.0f);

	switch(EngineType)
	{
		case 1:
			ParticleSystem->ColorStart.r = 0.60f;
			ParticleSystem->ColorStart.g = 0.60f;
			ParticleSystem->ColorStart.b = 0.30f;
			ParticleSystem->ColorEnd.r = 0.30f;
			ParticleSystem->ColorEnd.g = 1.00f;
			ParticleSystem->ColorEnd.b = 0.30f;
			ParticleSystem->AlphaStart = 1.00f;
			ParticleSystem->AlphaEnd   = 0.00f;
			ParticleSystem->SizeStart  = 0.10f;
			ParticleSystem->SizeVar    = 0.20f;
			ParticleSystem->SizeEnd    = 0.40f;
			ParticleSystem->Speed      = 6.00f;
			ParticleSystem->SpeedOnCreation	   = -1.00f;
			ParticleSystem->SpeedVar   = 2.00f;
			ParticleSystem->Theta      = 5.00f;
			ParticleSystem->Life       = 0.40f;
			ParticleSystem->ParticlesPerSec = 100;
			ParticleSystem->CreationType = 1;
			ParticleSystem->CreationSize = VECTOR3D(0.4f,0.4f,0.4f);
			ParticleSystem->AlphaShowHide= true;
			ParticleSystem->Light = vw_CreatPointLight(VECTOR3D(0.0f,0.0f,0.0f), 0.45f, 0.8f, 0.3f, 0.0f, 0.1f);
			ParticleSystem->LightNeedDeviation = true;
			break;
		case 2:
			ParticleSystem->ColorStart.r = 0.60f;
			ParticleSystem->ColorStart.g = 0.60f;
			ParticleSystem->ColorStart.b = 0.30f;
			ParticleSystem->ColorEnd.r = 0.30f;
			ParticleSystem->ColorEnd.g = 1.00f;
			ParticleSystem->ColorEnd.b = 0.30f;
			ParticleSystem->AlphaStart = 1.00f;
			ParticleSystem->AlphaEnd   = 0.00f;
			ParticleSystem->SizeStart  = 0.30f;
			ParticleSystem->SizeVar    = 0.30f;
			ParticleSystem->SizeEnd    = 0.60f;
			ParticleSystem->Speed      = 8.00f;
			ParticleSystem->SpeedOnCreation	   = -1.00f;
			ParticleSystem->SpeedVar   = 2.00f;
			ParticleSystem->Theta      = 5.00f;
			ParticleSystem->Life       = 0.40f;
			ParticleSystem->ParticlesPerSec = 100;
			ParticleSystem->CreationType = 1;
			ParticleSystem->CreationSize = VECTOR3D(0.6f,0.6f,0.1f);
			ParticleSystem->AlphaShowHide= true;
			ParticleSystem->Light = vw_CreatPointLight(VECTOR3D(0.0f,0.0f,0.0f), 0.45f, 0.8f, 0.3f, 0.0f, 0.1f);
			ParticleSystem->LightNeedDeviation = true;
			break;
		case 3:
			ParticleSystem->ColorStart.r = 0.60f;
			ParticleSystem->ColorStart.g = 0.60f;
			ParticleSystem->ColorStart.b = 0.30f;
			ParticleSystem->ColorEnd.r = 0.30f;
			ParticleSystem->ColorEnd.g = 1.00f;
			ParticleSystem->ColorEnd.b = 0.30f;
			ParticleSystem->AlphaStart = 1.00f;
			ParticleSystem->AlphaEnd   = 0.00f;
			ParticleSystem->SizeStart  = 0.30f;
			ParticleSystem->SizeVar    = 0.30f;
			ParticleSystem->SizeEnd    = 0.60f;
			ParticleSystem->Speed      = 10.00f;
			ParticleSystem->SpeedOnCreation	   = -1.00f;
			ParticleSystem->SpeedVar   = 2.00f;
			ParticleSystem->Theta      = 5.00f;
			ParticleSystem->Life       = 0.50f;
			ParticleSystem->ParticlesPerSec = 100;
			ParticleSystem->CreationType = 1;
			ParticleSystem->CreationSize = VECTOR3D(1.0f,0.1f,1.0f);
			ParticleSystem->AlphaShowHide= true;
			ParticleSystem->Direction = VECTOR3D(0.0f, -1.0f, 0.0f);
			ParticleSystem->Light = vw_CreatPointLight(VECTOR3D(0.0f,0.0f,0.0f), 0.45f, 0.8f, 0.3f, 0.0f, 0.05f);
			ParticleSystem->LightNeedDeviation = true;
			break;
		case 4:
			ParticleSystem->ColorStart.r = 0.60f;
			ParticleSystem->ColorStart.g = 0.60f;
			ParticleSystem->ColorStart.b = 0.30f;
			ParticleSystem->ColorEnd.r = 0.30f;
			ParticleSystem->ColorEnd.g = 1.00f;
			ParticleSystem->ColorEnd.b = 0.30f;
			ParticleSystem->AlphaStart = 1.00f;
			ParticleSystem->AlphaEnd   = 0.00f;
			ParticleSystem->SizeStart  = 0.30f;
			ParticleSystem->SizeVar    = 0.20f;
			ParticleSystem->SizeEnd    = 0.10f;
			ParticleSystem->Speed      = 3.00f;
			ParticleSystem->SpeedOnCreation	   = -1.00f;
			ParticleSystem->SpeedVar   = 2.00f;
			ParticleSystem->Theta      = 180.00f;
			ParticleSystem->Life       = 0.50f;
			ParticleSystem->ParticlesPerSec = 100;
			ParticleSystem->AlphaShowHide= true;
			ParticleSystem->Direction = VECTOR3D(0.0f, 1.0f, 0.0f);
			ParticleSystem->Light = vw_CreatPointLight(VECTOR3D(0.0f,0.0f,0.0f), 0.45f, 0.8f, 0.3f, 0.0f, 0.1f);
			ParticleSystem->LightNeedDeviation = true;
			break;
		case 5:
			ParticleSystem->ColorStart.r = 0.60f;
			ParticleSystem->ColorStart.g = 0.60f;
			ParticleSystem->ColorStart.b = 0.30f;
			ParticleSystem->ColorEnd.r = 0.30f;
			ParticleSystem->ColorEnd.g = 1.00f;
			ParticleSystem->ColorEnd.b = 0.30f;
			ParticleSystem->AlphaStart = 1.00f;
			ParticleSystem->AlphaEnd   = 0.00f;
			ParticleSystem->SizeStart  = 0.30f;
			ParticleSystem->SizeVar    = 0.30f;
			ParticleSystem->SizeEnd    = 0.60f;
			ParticleSystem->Speed      = 8.00f;
			ParticleSystem->SpeedOnCreation	   = -1.00f;
			ParticleSystem->SpeedVar   = 2.00f;
			ParticleSystem->Theta      = 5.00f;
			ParticleSystem->Life       = 0.40f;
			ParticleSystem->ParticlesPerSec = 100;
			ParticleSystem->CreationType = 1;
			ParticleSystem->CreationSize = VECTOR3D(1.0f,1.0f,1.0f);
			ParticleSystem->AlphaShowHide= true;
			ParticleSystem->Light = vw_CreatPointLight(VECTOR3D(0.0f,0.0f,0.0f), 0.45f, 0.8f, 0.3f, 0.0f, 0.05f);
			ParticleSystem->LightNeedDeviation = true;
			break;

		default:
			fprintf(stderr, "Error in SetPirateShipEngine function call, wrong EngineType.\n");
			break;
	}

}

