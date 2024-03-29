#pragma once
#include "CoreSystems/Geometry/Indices/BowIndicesUnsignedShort.h"

namespace bow {
	
	IndicesUnsignedShort::IndicesUnsignedShort() :IIndicesBase(IndicesType::UnsignedShort), Values(std::vector<unsigned short>())
	{
	}

	IndicesUnsignedShort::IndicesUnsignedShort(int capacity) : IIndicesBase(IndicesType::UnsignedShort), Values(std::vector<unsigned short>(capacity))
	{
	}

	unsigned int IndicesUnsignedShort::Size()
	{
		return (unsigned int)Values.size();
	}

	IndicesUnsignedShort::~IndicesUnsignedShort()
	{
		Values.clear();
	}

}
