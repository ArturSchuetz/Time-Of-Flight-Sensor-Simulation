#include <OpenGL3xRenderDevice/Device/Textures/BowOGL3xTextureUnits.h>
#include <OpenGL3xRenderDevice/Device/Textures/BowOGL3xTexture2D.h>
#include <OpenGL3xRenderDevice/Device/Textures/BowOGL3xTextureSampler.h>
#include <OpenGL3xRenderDevice/Device/Textures/BowOGL3xTextureUnit.h>
#include <RenderDevice/BowRenderDevicePredeclares.h>
#include <CoreSystems/BowLogger.h>

#include <GL/glew.h>
#if defined(_WIN32)
#include <GL/wglew.h>
#endif
#include <algorithm>

namespace bow {

	OGLTextureUnits::OGLTextureUnits() : m_numberOfTextureUnits(0)
	{
		// Device.NumberOfTextureUnits is not initialized yet.
		//		
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_numberOfTextureUnits);
		m_numberOfTextureUnits = (m_numberOfTextureUnits < 31 ? m_numberOfTextureUnits : 31);

		for (int i = 0; i < m_numberOfTextureUnits; ++i)
		{
			m_textureUnits[i] = OGLTextureUnitPtr(new OGLTextureUnit(i, this));
		}
		m_dirtyTextureUnits = std::list<ICleanable*>();
		m_lastTextureUnit = m_textureUnits[m_numberOfTextureUnits - 1];
	}

	void OGLTextureUnits::Clean()
	{
		for (auto it = m_dirtyTextureUnits.begin(); it != m_dirtyTextureUnits.end(); it++)
		{
			(*it)->Clean();
		}
		m_dirtyTextureUnits.clear();
		m_lastTextureUnit->CleanLastTextureUnit();
	}

	void OGLTextureUnits::NotifyDirty(ICleanable* value)
	{
		m_dirtyTextureUnits.push_back(value);
	}

	int OGLTextureUnits::GetMaxTextureUnits()
	{
		return m_numberOfTextureUnits;
	}

	void OGLTextureUnits::SetTexture(int index, OGLTexture2DPtr texture)
	{
		m_textureUnits[index]->SetTexture(texture);
	}

	void OGLTextureUnits::SetSampler(int index, OGLTextureSamplerPtr sampler)
	{
		m_textureUnits[index]->SetSampler(sampler);
	}

}
