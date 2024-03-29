#pragma once
#include <RenderDevice/RenderDevice_api.h>
#include <RenderDevice/BowRenderDevicePredeclares.h>

namespace bow {

	enum class TextureMinificationFilter : char
	{
		Nearest,
		Linear,
		NearestMipmapNearest,
		LinearMipmapNearest,
		NearestMipmapLinear,
		LinearMipmapLinear,
	};

	enum class TextureMagnificationFilter : char
	{
		Nearest,
		Linear
	};

	enum class TextureWrap : char
	{
		Clamp,
		Repeat,
		MirroredRepeat
	};

	class ITextureSampler
	{
	protected:
		ITextureSampler(TextureMinificationFilter minificationFilter, TextureMagnificationFilter magnificationFilter, TextureWrap wrapS, TextureWrap wrapT, float maximumAnistropy) : MinificationFilter(minificationFilter), MagnificationFilter(magnificationFilter), WrapS(wrapS), WrapT(wrapT), MaximumAnistropy(maximumAnistropy) {}

	public:
		virtual ~ITextureSampler() {}

		const TextureMinificationFilter MinificationFilter;
		const TextureMagnificationFilter MagnificationFilter;
		const TextureWrap WrapS;
		const TextureWrap WrapT;
		const float MaximumAnistropy;
	};


}
