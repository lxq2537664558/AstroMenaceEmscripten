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


#include "RendererInterface.h"



extern	int tmpPrimCountGL;
extern	eDevCaps OpenGL_DevCaps;






//------------------------------------------------------------------------------------
// данный для индекс буфера
//------------------------------------------------------------------------------------
int VertexIndexCount = 0;
GLuint *VertexIndex = 0;
GLuint *IndexVBO = 0;

//------------------------------------------------------------------------------------
// Инициализация данных индекс буфера
//------------------------------------------------------------------------------------
void vw_Internal_InitializationIndexBufferData()
{
	VertexIndexCount = 0;
	VertexIndex = 0;
	IndexVBO = 0;
}
//------------------------------------------------------------------------------------
// Чистка памяти данных индекс буфера
//------------------------------------------------------------------------------------
void vw_Internal_ReleaseIndexBufferData()
{
	if (VertexIndex != 0){delete [] VertexIndex; VertexIndex = 0;}
	VertexIndexCount = 0;
	if (IndexVBO != 0){vw_DeleteVBO(*IndexVBO); delete IndexVBO; IndexVBO=0;}
}





//------------------------------------------------------------------------------------
// устанавливаем указатели, готовимся к прорисовке
//------------------------------------------------------------------------------------
GLuint *vw_SendVertices_EnableStatesAndPointers(int NumVertices, int DataFormat, void *Data, int Stride, unsigned int *VBO, unsigned int RangeStart, unsigned int *DataIndex, unsigned int *DataIndexVBO)
{
	// если ничего не передали
	if (Data == 0 && VBO == 0) return 0;

	// флаг нужно ли с вбо делать
	bool NeedVBO = true;
	if (VBO == 0) NeedVBO = false;


	// обязательно в байты, т.к. делаем смещение в байтах!
	BYTE *TMP = (BYTE *)Data;

	// чтобы знать сколько отступать, кол-во ед. элементов, в нашем случае float
	intptr_t AddStride = 0;
	// кол-во текстур
	int TextQ = DataFormat & 0x000000F;
	// длина блока
	int TextSize = 2;
	int TextCoordType = 1; // float
	switch (DataFormat & 0x0F00000)
	{
		case 0x0100000: TextSize = 1;	break;
		case 0x0200000: TextSize = 2;	break;
		case 0x0300000: TextSize = 3;	break;
		case 0x0400000: TextSize = 4;	break;
		// short
		case 0x0500000: TextSize = 1; TextCoordType = 2;	break;
		case 0x0600000: TextSize = 2; TextCoordType = 2;	break;
		case 0x0700000: TextSize = 3; TextCoordType = 2;	break;
		case 0x0800000: TextSize = 4; TextCoordType = 2;	break;
	}

	if (NeedVBO) vw_BindVBO(RI_ARRAY_BUFFER, *VBO);


	// делаем установку поинтеров + ставим смещения для прорисовки
	if ((DataFormat & 0x000F000) == RI_3f_XYZ)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		if (NeedVBO)
			glVertexPointer(3, GL_FLOAT, Stride, (intptr_t *)(AddStride));
		else
			glVertexPointer(3, GL_FLOAT, Stride, TMP + AddStride);
		AddStride += 3*sizeof(GLfloat);
	}
	if ((DataFormat & 0x000F000) == RI_3i_XYZ)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		if (NeedVBO)
			glVertexPointer(3, GL_INT, Stride, (BYTE *)(AddStride));
		else
			glVertexPointer(3, GL_INT, Stride, TMP + AddStride);
		AddStride += 3*sizeof(GLint);
	}
	if ((DataFormat & 0x000F000) == RI_3s_XYZ)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		if (NeedVBO)
			glVertexPointer(3, GL_SHORT, Stride, (BYTE *)(AddStride));
		else
			glVertexPointer(3, GL_SHORT, Stride, TMP + AddStride);
		AddStride += 3*sizeof(GLshort);
	}

	if ((DataFormat & 0x000F000) == RI_2f_XY)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		if (NeedVBO)
			glVertexPointer(2, GL_FLOAT, Stride, (BYTE *)(AddStride));
		else
			glVertexPointer(2, GL_FLOAT, Stride, TMP + AddStride);
		AddStride += 2*sizeof(GLfloat);
	}
	if ((DataFormat & 0x000F000) == RI_2s_XY)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		if (NeedVBO)
			glVertexPointer(2, GL_SHORT, Stride, (BYTE *)(AddStride));
		else
			glVertexPointer(2, GL_SHORT, Stride, TMP + AddStride);
		AddStride += 2*sizeof(GLshort);
	}


	if ((DataFormat & 0x0000F00) == RI_3f_NORMAL)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
		if (NeedVBO)
			glNormalPointer(GL_FLOAT, Stride, (BYTE *)(AddStride));
		else
			glNormalPointer(GL_FLOAT, Stride, TMP + AddStride);
		AddStride += 3*sizeof(GLfloat);
	}


	if ((DataFormat & 0x00000F0) == RI_4f_COLOR)
	{
		glEnableClientState(GL_COLOR_ARRAY);
		if (NeedVBO)
			glColorPointer(4, GL_FLOAT, Stride, (BYTE *)(AddStride));
		else
			glColorPointer(4, GL_FLOAT, Stride, TMP + AddStride);
		AddStride += 4*sizeof(GLfloat);
	}
	if ((DataFormat & 0x00000F0) == RI_4ub_COLOR)
	{
		glEnableClientState(GL_COLOR_ARRAY);
		if (NeedVBO)
			glColorPointer(4, GL_UNSIGNED_BYTE, Stride, (BYTE *)(AddStride));
		else
			glColorPointer(4, GL_UNSIGNED_BYTE, Stride, TMP + AddStride);
		AddStride += 4*sizeof(GLubyte);
	}


	if (TextQ > 0)// текстурные коорд. есть...
	{
		for (int i=0; i<TextQ; i++)
		{
			glClientActiveTexture(GL_TEXTURE0+i);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			switch (TextCoordType)
			{
				case 1:
				{
					if (NeedVBO)
						glTexCoordPointer(TextSize, GL_FLOAT, Stride, (BYTE *)(AddStride));
					else
						glTexCoordPointer(TextSize, GL_FLOAT, Stride, TMP + AddStride);
					if ((DataFormat & 0xF000000) == RI_SEPARATE_TEX_COORD) AddStride += TextSize*sizeof(GLfloat);
				}
				break;
				case 2:
				{
					if (NeedVBO)
						glTexCoordPointer(TextSize, GL_SHORT, Stride, (BYTE *)(AddStride));
					else
						glTexCoordPointer(TextSize, GL_SHORT, Stride, TMP + AddStride);
					if ((DataFormat & 0xF000000) == RI_SEPARATE_TEX_COORD) AddStride += TextSize*sizeof(GLshort);
				}
				break;
			}
		}
	}



	// указатель на смещение (в случае вбо) или на массив индексов
	GLuint *VertexIndexPointer = 0;
	// если нет своего, ставим общей массив индексов
	if (DataIndexVBO == 0 && DataIndex == 0)
	{
		// собираем если нужно массив индексов
		if ((unsigned int)VertexIndexCount < (unsigned int)(NumVertices+RangeStart))
		{
			if (VertexIndex != 0){delete [] VertexIndex; VertexIndex = 0;}
			VertexIndexCount = 0;

			VertexIndex = new GLuint[NumVertices+RangeStart]; if (VertexIndex == 0) return 0;

			VertexIndexCount = NumVertices+RangeStart;
			for (unsigned int i=0; i<NumVertices+RangeStart; i++) VertexIndex[i] = i;

			// если держим VBO, все это один раз сразу запихиваем в видео память
			if (true)
			{
				// прежде всего удаляем старый буфер, если он был
				if (IndexVBO != 0){vw_DeleteVBO(*IndexVBO); delete IndexVBO; IndexVBO=0;}
				// создаем новый
				IndexVBO = new GLuint;
				if (!vw_BuildIBO(VertexIndexCount, VertexIndex, IndexVBO))
				{
					delete IndexVBO; IndexVBO=0;
				}
			}
		}

		VertexIndexPointer = VertexIndex+RangeStart;

		// собственно включаем индекс-вбо
		if (true)
		if (IndexVBO != 0)
		{
			vw_BindVBO(RI_ELEMENT_ARRAY_BUFFER, *IndexVBO);
			VertexIndexPointer = NULL;
			VertexIndexPointer = VertexIndexPointer+RangeStart;
		}
	}
	else
	{	// если массив или вбо индексов передали, просто подключаем их
		VertexIndexPointer = DataIndex+RangeStart;

		// собственно включаем индекс-вбо
		if (true)
		if (DataIndexVBO != 0)
		{
			vw_BindVBO(RI_ELEMENT_ARRAY_BUFFER, *DataIndexVBO);
			VertexIndexPointer = NULL;
			VertexIndexPointer = VertexIndexPointer+RangeStart;
		}
	}

	// возвращаем индексы основной программе
	return VertexIndexPointer;
}





//------------------------------------------------------------------------------------
// выключаем все после прорисовки
//------------------------------------------------------------------------------------
void vw_SendVertices_DisableStatesAndPointers(int DataFormat, unsigned int *VBO, unsigned int *VAO)
{
	// флаг нужно ли с вaо делать
	{
		// флаг нужно ли с вбо делать
		bool NeedVBO = true;
		if (VBO == 0) NeedVBO = false;


		if ((DataFormat & 0x0000F00) != 0) glDisableClientState(GL_NORMAL_ARRAY);
		if ((DataFormat & 0x00000F0) != 0) glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		// кол-во текстур
		int TextQ = DataFormat & 0x000000F;
		for (int i=TextQ-1; i>=0; i--)
		{
			glClientActiveTexture(GL_TEXTURE0+i);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}


		// сбрасываем индексный и вертексный буфера, если они были установлены
		if (IndexVBO != 0) vw_BindVBO(RI_ELEMENT_ARRAY_BUFFER, 0);
		if (NeedVBO) vw_BindVBO(RI_ARRAY_BUFFER, 0);
	}
}






//------------------------------------------------------------------------------------
// Процедура передачи последовательности вертексов для прорисовки
//------------------------------------------------------------------------------------
void vw_SendVertices(int PrimitiveType, int NumVertices, int DataFormat, void *Data, int Stride, unsigned int *VBO, unsigned int RangeStart, unsigned int *DataIndex, unsigned int *DataIndexVBO, unsigned int *VAO)
{
	// если ничего не передали
	if (Data == 0 && VBO == 0 && VAO == 0) return;
	// флаг нужно ли с вaо делать


	// устанавливаем все необходимые указатели для прорисовки и получаем индексы
	GLuint *VertexIndexPointer = 0;

	{
		VertexIndexPointer = vw_SendVertices_EnableStatesAndPointers(NumVertices, DataFormat, Data, Stride, VBO, RangeStart, DataIndex, DataIndexVBO);
	}

// 1) Нельзя использовать short индексы (глючит в линуксе на картах нвидия, проверял на 97.55 драйвере)
// 2) Нельзя рисовать через glBegin-glEnd и glDrawArray - проблемы в линуксе у ati драйверов (на glDrawArray вообще сегфолтит)
// 3) С glDrawRangeElements могут быть неприятные сюрпризы на маках (интел+интел видео), сегфолты даже если учесть все ограничения (вертекс и индекс)


	// рисуем
	switch(PrimitiveType)
	{
		case RI_POINTS:
			glDrawElements(GL_POINTS,NumVertices,GL_UNSIGNED_INT,VertexIndexPointer);
			tmpPrimCountGL += NumVertices;
			break;

		case RI_LINES:
			glDrawElements(GL_LINES,NumVertices,GL_UNSIGNED_INT,VertexIndexPointer);
			tmpPrimCountGL += NumVertices/2;
			break;

		case RI_TRIANGLES:
			glDrawElements(GL_TRIANGLES,NumVertices,GL_UNSIGNED_INT,VertexIndexPointer);
			tmpPrimCountGL += NumVertices/3;
			break;

		case RI_TRIANGLE_STRIP:
			glDrawElements(GL_TRIANGLE_STRIP,NumVertices,GL_UNSIGNED_INT,VertexIndexPointer);
			tmpPrimCountGL += NumVertices-2;
			break;

		case RI_TRIANGLE_FAN:
			glDrawElements(GL_TRIANGLE_FAN,NumVertices,GL_UNSIGNED_INT,VertexIndexPointer);
			tmpPrimCountGL += NumVertices-2;
			break;

		case RI_QUADS:
			glDrawElements(GL_QUADS,NumVertices,GL_UNSIGNED_INT,VertexIndexPointer);
			tmpPrimCountGL += NumVertices/4;
			break;

		default:
			fprintf(stderr, "Error in vw_SendVertices function call, wrong PrimitiveType.\n");
			return;
	}


	// выключаем все что включали
	vw_SendVertices_DisableStatesAndPointers(DataFormat, VBO, VAO);

}
